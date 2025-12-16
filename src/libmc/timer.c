#include <p32xxxx.h>
#include "libmc/interrupts.h"

int timer_calc_pr(int T_ms, int f_clk_Hz, int prescaler) {
    return (T_ms * 0.001 * f_clk_Hz) / prescaler;
}

void timer_init_2(int T_ms, int f_clk_Hz, int prescaler, int priority, int subpriority) {
    // config
    T2CONbits.ON = 0; // disable timer 2
    T2CONbits.TCS = 0; // select PB clock bit 1
    T2CONbits.TGATE = 0; // select PB clock bit 2
    T2CONbits.T32 = 0; // 0->32 1->16
    T2CONbits.TCKPS = 0b111;

    // set period register
    PR2 = timer_calc_pr(T_ms, f_clk_Hz, prescaler);
    TMR2 = 0;

    // setup interrupt
    int_enable_timer_2(priority, subpriority);

    // enable timer 2
    T2CONbits.ON = 1;
}

void delay_ms(int ms) {
    while (ms--) {
        while (TMR2 < PR2); // 1ms timer
    }
}

void t1_init() {
    // Timer1 OFF
    T1CONbits.ON = 0;
    // Select prescaler = 1:256
    T1CONbits.TCKPS = 3; // 0=1:1, 1=1:8, 2=1:64, 3=1:256
    // Use PBCLK (by default PBCLK = SYSCLK unless changed)
    T1CONbits.TCS = 0;
    T1CONbits.ON = 1;
}

void delay_ms_t1(unsigned int ms) {
    // Calculate ticks needed for 1 ms
    unsigned int ticksPerMs = (40000000 / 256 / 1000);

    while (ms--) {
        TMR1 = 0; // Reset counter
        
        while (TMR1 < ticksPerMs); // Wait 1 ms
    }
}