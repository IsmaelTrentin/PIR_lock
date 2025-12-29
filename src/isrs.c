#include <p32xxxx.h>

#include "isrs.h"
#include "libmc/uart.h"
#include "main.h"

extern volatile State state;
extern volatile Events events;

static unsigned int tm1_ms = 0;
static unsigned int cnrf0_last_press_time = 0;

// -1 is disabled
// 0 enables it and at the next cycle it'll start counting ms.
volatile int tmr_afk = -1;

void __attribute__((interrupt(IPL1AUTO), vector(_TIMER_1_VECTOR)))
ihandler_t1() {
    IFS0bits.T1IF = 0;

    tm1_ms++;

    if (tmr_afk != -1) {
        tmr_afk++;
    }

    if (tmr_afk >= 5000) {
        // disable child timer
        tmr_afk = -1;
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
ihandler_cn_rf0() {
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
                tmr_afk = 0;

                events.auth_request = 1;
            }
        }
    }
    
    PORTB;
    PORTF;
}