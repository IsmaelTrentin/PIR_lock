#include <p32xxxx.h>

void __attribute__((interrupt(IPL1AUTO), vector(_TIMER_1_VECTOR)))
ihandler_t1() {
    IFS0bits.T1IF = 0;
}

void __attribute__((interrupt(IPL1AUTO), vector(_TIMER_2_VECTOR)))
ihandler_t2() {
    IFS0bits.T2IF = 0;
}
