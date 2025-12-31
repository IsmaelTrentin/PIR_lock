// with this config we have:
// SYSCLK = 80MHz
// PBCLK = 40MHz
// remember to put these in libmc_config.h

/* Disable JTAG to use RA0 */
#pragma config JTAGEN = OFF
#pragma config FWDTEN = OFF
/* Device Config Bits in DEVCFG1 : */
#pragma config FNOSC = PRIPLL
#pragma config FSOSCEN = OFF
#pragma config POSCMOD = XT
#pragma config OSCIOFNC = ON
#pragma config FPBDIV = DIV_2
/* Device Config Bits in DEVCFG2 : */
#pragma config FPLLIDIV = DIV_2
#pragma config FPLLMUL = MUL_20
#pragma config FPLLODIV = DIV_1
/* Enable clock config */
#pragma config FCKSM = CSECMD

#include <p32xxxx.h>
#include <string.h>

#include "libmc/lcd.h"
#include "libmc/timer.h"
#include "libmc/audio.h"
#include "libmc/rgb.h"
#include "libmc/uart.h"
#include "libmc/gpio.h"
#include "modules/pir.h"
#include "modules/servo.h"

#include "libmc_config.h"
#include "main.h"
#include "utils.h"
// NOTE: 
// DO NOT REMOVE!!!
// this contains the ISRs. if you remove it,
// no timer1 ISR is present and the micro freezes
// since it stays stuck in the timer1 ISR (1ms).
#include "isrs.h"

extern volatile int tmr_afk;
char data[LIBMC_UART_BUFF_SIZE] = {};
volatile State state = {
    .authorized = 0,
    .locked = 1,
    .sleeping = 1,
    .sensor_enabled  = 0,
    .password = "0000",
};
volatile Events events = {
    .auth_request = 0,
    .auth_success = 0,
    .went_afk = 0,
    .locked = 0,
    .sensor_detect = 0,
};

void debug_leds() {
    led_lat(7, state.authorized);
    led_lat(6, state.locked);
    led_lat(5, state.sleeping);
    led_lat(4, state.sensor_enabled);
}

void handle_events() {
    // TODO: theres is a bug when after opening the lock, if
    // we request an auth, uart_gets never finishes.
    // the cause is probably uart_terminate_read!
    if (events.auth_request) {
        events.auth_request = 0;
        // if we haven't given a password yet and a wake up
        // request through BTNC has been dispatched, meaning
        // we are not sleeping anymore, we can initiate the
        // auth process and start the 5s afk timer.
        if (state.authorized == 0 && state.sleeping == 0) {
            uart_puts("-- PIR LOCK Auth --\n");

            int terminated = 0;
            int ok = 0;
            while (ok == 0 && terminated == 0) {
                uart_puts("master password: ");

                // debug led to check when uart is blocking cpu cycles
                led_lat(0, 1);
                terminated = uart_gets(data);
                led_lat(0, 0);
                if (!terminated) {
                    if (strcmp(data, state.password) == 0) {
                        state.authorized = 1;
                        state.sleeping = 0;
                        // reset afk timer
                        tmr_afk = 0;
                        ok = 1;

                        events.auth_success = 1;
                    } else {
                        state.authorized = 0;
                        ok = 0;

                        uart_puts("bad password\n");
                    }
                }
            }
        }
    }
    if (events.auth_success) {
        events.auth_success = 0;
        lcd_print_homescreen();
        audio_play_success();
    }
    if (events.went_afk) {
        events.went_afk = 0;
        uart_terminate_read();
        uart_puts("\ntimed out\n");
        lcd_print_homescreen();
    }
    if (events.locked) {
        events.locked = 0;
        servo_set_deg(SERVO_CLOSED_LOCK_DEG);
    }
    if (events.sensor_detect) {
        events.sensor_detect = 0;
        audio_play_note(440, 100);
        servo_set_deg(SERVO_OPENED_LOCK_DEG);
        // TODO: register log
    }
}

void handle_menu_options(int opt) {
    switch (opt) {
        case 1:
            if (state.sensor_enabled == 0) {
                state.sensor_enabled = 1;
            } else {
                state.sensor_enabled = 0;
                state.locked = 1;
                servo_set_deg(SERVO_CLOSED_LOCK_DEG);
            }

            break;
        case 2:
            // TODO: handle change password
            break;
        case 3:
            // TODO: handle show logs
            break;
        case 4:
            // TODO: handle clear logs
            break;
        default:
            uart_puts("invalid option\n");
            break;
    }
}
void main() {
    /* INIT */
    __builtin_disable_interrupts();

    timer1_init(1, LIBMC_PBCLK_HZ, 1, 0);
    uart_init(LIBMC_UART_BAUD, 0b110, 0b011);
    audio_init();
    lcd_init();
    rgb_init();
    led_init_all();
    btn_init_all();
    btn_cn_config_rf0();
    btn_cn_config_rb0();
    // NOTE:
    // connections: 
    // - power -> SERVO_1_VBAR (needs 5V)
    // - gnd   -> SERVO_1_GND
    // - data  -> T2 pin (Analog Debug Header) that is RB9 (see libmc_config.h)
    pir_init();
    // NOTE:
    // connections:
    // - power -> SERVO_0_VBAR (needs 5V)
    // - gnd   -> SERVO_0_GND
    // - pwm   -> SERVO_0_PWM on RB8
    servo_init();

    INTCONbits.MVEC = 1;
    __builtin_enable_interrupts();

    /* SETUP */
    led_turn_off_all();
    lcd_print_homescreen();
    servo_set_deg(SERVO_CLOSED_LOCK_DEG);

    /* PROGRAM LIFECYCLE */
    while (1) {
        debug_leds();

        handle_events();

        if (state.sensor_enabled) {
            rgb_setb(BLUE);

            // we only read if the lock is closed.
            if (state.locked) {
                // TODO: create CN interrupt so that we can read
                // at every moment. at this moment we need to wait
                // for the went_afk event since it terminates UART
                // comms to be able to read the sensor.
                int read = pir_read();
                // read state.locked again to ensure that
                // we only open if the lock is closed.
                if (read && state.locked) {
                    state.locked = 0;

                    events.sensor_detect = 1;
                }
            }
        } else {
            rgb_setb(RED);
        }

        if (state.authorized && state.sleeping == 0) {
            if (tmr_afk == -1) {
                tmr_afk = 0;
            }

            uart_put_global_menu(state.sensor_enabled);

            // debug led to check when uart is blocking cpu cycles
            led_lat(0, 1);
            int terminated = uart_gets(data);
            led_lat(0, 0);
            if (!terminated) {
                // resets 5s time out delay on action
                tmr_afk = 0;
                int opt = atoi(data);
                handle_menu_options(opt);
            }
        }
    }
}
