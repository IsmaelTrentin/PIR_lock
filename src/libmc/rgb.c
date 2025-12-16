// Simple implementation for the RGB module of the BasysMX board.
// This is a naive implementation since it does not use PWM to
// achieve all possible colors, it instead just sets 0 or 1 to the
// RGB pins limiting the possible colors.

#include <p32xxxx.h>

void rgb_init() {
    // BasysMX370L RGB pins:
    // R=RD2, G=RD12, B=RD3

    // set pins to output
    //    TRISDbits.TRISD2 = 0;
    //    TRISDbits.TRISD12 = 0;
    //    TRISDbits.TRISD3 = 0;
    TRISDCLR = 0x100C;
    // set pins to digital;
    ANSELDCLR = 0x100C;
}

void rgb_set_r(unsigned int value) {
    LATDbits.LATD2 = value;
}

void rgb_set_g(unsigned int value) {
    LATDbits.LATD12 = value;
}

void rgb_set_b(unsigned int value) {
    LATDbits.LATD3 = value;
}

void rgb_set(unsigned int r, unsigned int g, unsigned int b) {
    rgb_set_r(r);
    rgb_set_g(g);
    rgb_set_b(b);
}

void rgb_setb(unsigned int val) {
    rgb_set((val & 0b100) >> 2,
            (val & 0b010) >> 1,
            (val & 0b001));
}
