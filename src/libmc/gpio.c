#include <p32xxxx.h>
#include "libmc/gpio.h"

void set_reg(REG_SELECTOR_T *mode, unsigned int bitId, unsigned int value) {
    *mode = value << bitId;
}

// LEDS

/*
LD0 LED0 TMS/CTED1/RA0
LD1 LED1 TCK/CTED2/RA1
LD2 LED2 SCL2/RA2
LD3 LED3 SDA2/RA3
LD4 LED4 TDI/CTED9/RA4
LD5 LED5 TDO/RA5
LD6 LED6 TRCLK/RA6
LD7 LED7 TRD3/CTED8/RA7
 */

void led_ansel(int ledId, int value) {
    if (value == 0) {
        set_reg(&ANSELACLR, ledId, 1);
    } else if (value == 1) {
        set_reg(&ANSELASET, ledId, 1);
    }
}

void led_tris(int ledId, int value) {
    if (value == 0) {
        set_reg(&TRISACLR, ledId, 1);
    } else if (value == 1) {
        set_reg(&TRISASET, ledId, 1);
    }
}

void led_lat(int ledId, int value) {
    if (value == 0) {
        set_reg(&LATACLR, ledId, 1);
    } else if (value == 1) {
        set_reg(&LATASET, ledId, 1);
    }
}

int led_port(int ledId) {
    int mask = 0x0 & (1u << ledId);
    return PORTA & mask;
}

void led_turn_on(int ledId) {
    led_lat(ledId, 1);
}

void led_turn_off(int ledId) {
    led_lat(ledId, 0);
}

void led_toggle(int ledId) {
    set_reg(&LATAINV, ledId, 1);
}

void led_init_all() {
    ANSELA = 0x0;
    TRISA = 0x0;
}

void led_turn_off_all() {
    LATA = 0x0;
}

void led_turn_on_all() {
    // 2^8 - 1
    LATA = 0xFF;
}

// SWITCHES

/*
SW0 SW0 RPF3/RF3
SW1 SW1 RPF5/PMA8/RF5
SW2 SW2 RPF4/PMA9/RF4
SW3 SW3 RPD15/RD15
SW4 SW4 RPD14/RD14
SW5 SW5 AN11/PMA12/RB11
SW6 SW6 CVREFOUT/AN10/RPB10/CTED11PMA13/RB10
SW7 SW7 AN9/RPB9/CTED4/RB9 TRIG_2
 */

void sw_init_all() {
    // All the pins must be defined as digital input: their corresponding TRIS
    // bit must be set to 1, and analog function
    // must be disabled for pins routed to SW5, SW6, and SW7.

    TRISFbits.TRISF3 = 1; // RF3 (SW0) configured as input
    TRISFbits.TRISF5 = 1; // RF5 (SW1) configured as input
    TRISFbits.TRISF4 = 1; // RF4 (SW2) configured as input
    TRISDbits.TRISD15 = 1; // RD15 (SW3) configured as input
    TRISDbits.TRISD14 = 1; // RD14 (SW4) configured as input
    TRISBbits.TRISB11 = 1; // RB11 (SW5) configured as input
    ANSELBbits.ANSB11 = 0; // RB11 (SW5) disabled analog
    TRISBbits.TRISB10 = 1; // RB10 (SW6) configured as input
    ANSELBbits.ANSB10 = 0; // RB10 (SW6) disabled analog
    TRISBbits.TRISB9 = 1; // RB9 (SW7) configured as input
    ANSELBbits.ANSB9 = 0; // RB9 (SW7) disabled analog
}

int sw_read(int swId) {
    switch (swId) {
        case 0:
            return PORTFbits.RF3; // read SW0
        case 1:
            return PORTFbits.RF5;
        case 2:// read SW1
            return PORTFbits.RF4;
        case 3:// read SW2
            return PORTDbits.RD15;
        case 4:// read SW3
            return PORTDbits.RD14;
        case 5:// read SW4
            return PORTBbits.RB11;
        case 6:// read SW5
            return PORTBbits.RB10;
        case 7:// read SW6
            return PORTBbits.RB9; // read SW7
    }

    return -1;
}

// BUTTONS

/*
 BTNU RB1
 BTNL RB0
 BTNC RF0
 BTNR RB8
 BTND RA15
 */

void btn_init_all() {
    TRISBbits.TRISB1 = 1; // RB1 (BTNU) configured as input
    ANSELBbits.ANSB1 = 0; // RB1 (BTNU) disabled analog

    TRISBbits.TRISB0 = 1; // RB1 (BTNL) configured as input
    ANSELBbits.ANSB0 = 0; // RB1 (BTNL) disabled analog

    TRISFbits.TRISF4 = 1; // RF0 (BTNC) configured as input

    TRISBbits.TRISB8 = 1; // RB8 (BTNR) configured as input
    ANSELBbits.ANSB8 = 0; // RB8 (BTNR) disabled analog

    TRISAbits.TRISA15 = 1; // RA15 (BTND) configured as input
}

int btn_read(int btn_id) {
    switch (btn_id) {
        case 0:
            return PORTBbits.RB1;
        case 1:
            return PORTBbits.RB0;
        case 2:
            return PORTFbits.RF0;
        case 3:
            return PORTBbits.RB8;
        case 4:
            return PORTAbits.RA15;
    }

    return -1;
}