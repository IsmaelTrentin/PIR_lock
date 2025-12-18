#include <p32xxxx.h>

// octsel = 0 uses Timer2
// octsel = 1 uses Timer3
// timer init must be done before calling this
void pwm_oc1_init(int octsel, int pr) {
    OC1CON = 0;
    OC1CONbits.OCTSEL = octsel; // 0=T2 1=T3
    OC1CONbits.OCM = 0b110; // PWM mode, no fault pin
    OC1R = pr;
    OC1RS = pr;
    OC1CONbits.ON = 1;
}