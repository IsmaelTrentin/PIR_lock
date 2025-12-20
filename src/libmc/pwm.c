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

void pwm_oc2_init(int octsel, int pr) {
    OC2CON = 0;
    OC2CONbits.OCTSEL = octsel;
    OC2CONbits.OCM = 0b110;
    OC2R = pr;
    OC2RS = pr;
    OC2CONbits.ON = 1;
}

void pwm_oc5_init(int octsel, int pr) {
    OC5CON = 0;
    OC5CONbits.OCTSEL = octsel;
    OC5CONbits.OCM = 0b110;
    OC5R = pr;
    OC5RS = pr;
    OC5CONbits.ON = 1;
}