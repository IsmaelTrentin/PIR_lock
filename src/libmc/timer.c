#include <p32xxxx.h>
#include "libmc/interrupts.h"

#include "libmc_config.h"

int timer_calc_pr(int T_ms, int f_clk_Hz, int prescaler) {
    return (f_clk_Hz / prescaler / 1000) * T_ms - 1;
}

void timer1_init(int T_ms, int f_clk_Hz, int priority, int subpriority) {
    T1CONbits.ON = 0; // disable timer 1
    T1CONbits.TCS = 0; // select PB clock bit 1
    //T1CONbits.TGATE = 0; // select PB clock bit 2
    T1CONbits.TCKPS = 3; // 0=1:1, 1=1:8, 2=1:64, 3=1:256
    // Use PBCLK (by default PBCLK = SYSCLK unless changed)

    PR1 = timer_calc_pr(T_ms, f_clk_Hz, 256);
    TMR1 = 0;

    int_enable_timer_1(priority, subpriority);


    T1CONbits.ON = 1;
}

void timer2_init(int T_ms, int f_clk_Hz, int priority, int subpriority) {
    T2CONbits.ON = 0; // disable timer 2
    T2CONbits.TCS = 0; // select PB clock bit 1
    T2CONbits.TGATE = 0; // select PB clock bit 2
    T2CONbits.T32 = 0; // 0->16 1->32
    T2CONbits.TCKPS = 3; // 0=1:1 1=1:2 2=1:4 3=1:8

    // set period register
    PR2 = timer_calc_pr(T_ms, f_clk_Hz, 8);
    TMR2 = 0;

    // setup interrupt
    int_enable_timer_2(priority, subpriority);

    // enable timer 2
    T2CONbits.ON = 1;
}

// TODO: auto infer prescaler value using presc_bitconfig
// with left shifting (2 powers)
void timer3_init(int T_ms, int prescaler, int presc_bitconfig) {
    T3CONbits.ON = 0; // disable timer 3
    T3CONbits.TCS = 0; // select PB clock bit 1
    T3CONbits.TGATE = 0; // select PB clock bit 2
    T3CONbits.TCKPS = presc_bitconfig;

    // set period register
    PR3 = timer_calc_pr(T_ms, LIBMC_PBCLK_HZ, prescaler);
    TMR3 = 0;

    // enable timer 3
    T3CONbits.ON = 1;
}

void timer1_delay_ms(unsigned int ms) {
    while (ms--) {
        TMR1 = 0;
        while (TMR1 < PR1);
    }
}

void timer2_delay_ms(unsigned int ms) {
    while (ms--) {
        TMR2 = 0;
        while (TMR2 < PR2);
    }
}

void timer3_delay_ms(unsigned int ms) {
    while (ms--) {
        TMR3 = 0;
        while (TMR3 < PR3);
    }
}