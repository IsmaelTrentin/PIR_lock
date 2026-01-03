#include <p32xxxx.h>

#include "libmc/uart.h"
#include "modules/pir.h"

#include "isrs.h"
#include "main.h"

volatile unsigned long TIMER1_MS = 0;

static unsigned int cnrf0_last_press_time = 0;

// -1 is disabled
// 0 enables it and at the next cycle it'll start counting ms.
volatile int TIMER_AFK = -1;

void __attribute__((interrupt(IPL1AUTO), vector(_TIMER_1_VECTOR)))
ihandler_t1() {
    IFS0bits.T1IF = 0;

    TIMER1_MS++;

    if (TIMER_AFK != -1) {
        TIMER_AFK++;
    }

    if (TIMER_AFK >= LIBMC_AFK_MAX_TIME_MS) {
        // disable child timer
        TIMER_AFK = -1;
        state.sleeping = 1;
        state.authorized = 0;

        events.went_afk = 1;
        // NOTE: do not remove. it is bad to have it in the ISR
        // but without it the uart comms do not terminate
        // immediately since its a blocking functions.
        // thanks to the ISR we can disable the read flags
        // and terminate the function prematurely.
        uart_terminate_read();
    }
}

void __attribute__((interrupt(IPL1AUTO), vector(_TIMER_2_VECTOR)))
ihandler_t2() {
    IFS0bits.T2IF = 0;
}

// pressed down -> on
// released up -> off
void __attribute__((interrupt(IPL1AUTO), vector(_CHANGE_NOTICE_VECTOR)))
ihandler_cn() {
    IFS1bits.CNFIF = 0;
    IFS1bits.CNBIF = 0;

    unsigned int now = _CP0_GET_COUNT();
    // debounce delay to prevent multiple triggers
    if (now - cnrf0_last_press_time < DEBOUNCE_DELAY) return;
    cnrf0_last_press_time = now;

    if (CNSTATBbits.CNSTATB0) {
        // RB0 changed
        int pressed = (PORTBbits.RB0 == 1);

        if (pressed) {
            state.locked = 1;

            events.locked = 1;
        }
    }
    if (CNSTATBbits.CNSTATB9) {
        // RB9 changed
        int movement_detected = pir_read();

        if (state.sensor_enabled && state.locked && movement_detected) {
            state.locked = 0;

            events.sensor_detect = 1;
        }
    }
    if (CNSTATFbits.CNSTATF0) {
        // RF0 changed
        // read pin to check if CN is from released to pressed
        int pressed = (PORTFbits.RF0 == 1);

        // if pin is 1 then the button is pressed down,
        // otherwise the button is at rest.
        if (pressed) {
            if (state.sleeping == 1) {
                state.sleeping = 0;
                // also starts timer for 5s -> if no input go back to sleep
                TIMER_AFK = 0;

                events.auth_request = 1;
            }
        }
    }
    
    PORTB;
    PORTF;
}