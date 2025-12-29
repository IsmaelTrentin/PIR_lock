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
// DO NOT REMOVE!!!
// this contains the ISRs. if you remove it,
// no timer1 ISR is present and the micro freezes
// since it stays stuck in the timer1 ISR (1ms).
#include "isrs.h"

extern volatile int tmr_afk;
volatile State state = {
    .sensor_enabled  = 0,
    .authorized = 0,
    .sleeping = 1,
    .locked = 1,
    .password = "0000",
};
volatile Events events = {
    .locked = 0,
    .went_afk = 0,
};

void main() {
    /* INIT */
    __builtin_disable_interrupts();

    timer1_init(1, LIBMC_PBCLK_HZ, 1, 0);
    // TODO: add uart config params to a possible config.h
    uart_init(9600, 0b110, 0b011);
    audio_init();
    lcd_init();
    rgb_init();
    led_init_all();
    btn_init_all();
    btn_cn_config_rf0();
    btn_cn_config_rb0();
    pir_init();
    servo_init();

    INTCONbits.MVEC = 1;
    __builtin_enable_interrupts();

    /* SETUP */
    char data[LIBMC_UART_BUFF_SIZE] = {};

    led_turn_off_all();
    lcd_print_homescreen();
    servo_set_deg(SERVO_CLOSED_LOCK_DEG);

    /* PROGRAM LIFECYCLE */
    while (1) {
        led_lat(7, state.authorized);
        led_lat(6, state.locked);
        led_lat(5, state.sleeping);
        led_lat(4, state.sensor_enabled);

        if (events.locked) {
            events.locked = 0;
            audio_play_error();
            servo_set_deg(SERVO_CLOSED_LOCK_DEG);
        }
        if (events.went_afk) {
            events.went_afk = 0;
            uart_terminate_read();
            uart_puts("\ntimed out\n");
            lcd_print_homescreen();
        }

        if (state.sensor_enabled) {
            rgb_setb(BLUE);
            if (state.locked) {
                int read = pir_read();
                if (read && state.locked) {
                    state.locked = 0;
                    audio_play_note(440, 100);
                    servo_set_deg(SERVO_OPENED_LOCK_DEG);
                }
            }
        } else {
            rgb_setb(RED);
        }

        if (state.authorized == 0 && state.sleeping == 0) {
            uart_puts("\ninsert password: ");
            lcd_clear();
            lcd_print("awaiting UART...");

            int terminated = uart_gets(data);
            if (!terminated) {
                if (strcmp(data, state.password) == 0) {
                    state.authorized = 1;
                    state.sleeping = 0;
                    // reset afk timer
                    tmr_afk = 0;

                    lcd_print_homescreen();
                    audio_play_success();
                } else {
                    uart_puts("bad password\n");
                }
            }
        }

        if (state.authorized) {
            if (tmr_afk == -1) {
                tmr_afk = 0;
            }

            uart_put_global_menu(state.sensor_enabled);
            lcd_clear();
            lcd_print("awaiting UART...");

            int terminated = uart_gets(data);
            if (!terminated) {
                // resets 5s time out delay on action
                tmr_afk = 0;
                int opt = atoi(data);
                switch (opt) {
                    case 1:
                        if (state.sensor_enabled == 0) {
                            state.sensor_enabled = 1;
                        } else {
                            state.sensor_enabled = 0;
                            state.locked = 1;
                            servo_set_deg(SERVO_CLOSED_LOCK_DEG);
                        }

                        // if activate:
                        // activate sensor -> if 1: open and register access and play sound
                        // if gets timed out -> STAYS ON AND RECORDING, but behaves like before asking pwd
                        // if pressd another button -> close lock

                        // if deactivate:
                        // sensor deactiate, 
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
        }
    }
}
