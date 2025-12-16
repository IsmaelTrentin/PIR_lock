#include <p32xxxx.h>
#include "libmc/lcd.h"
#include "libmc/timer.h"

void lcd_init() {
    ANSELE = 0x0000; //RE0:7 as digital
    TRISE = 0x0000; // RE0:7 as digital input , or 0x0000 as out is the same
    TRISDbits.TRISD4 = 0; // RD4 as digital output ENpin
    TRISDbits.TRISD5 = 0; // RD5 as digital output RWpin
    ANSELBbits.ANSB15 = 0; //RB15 ad digital
    TRISBbits.TRISB15 = 0; // RB15 as digital output RSpin

    // PMP initialization
    PMCON = 0x83BF; // Enable the PMP , long waits
    PMMODE = 0x3FF; // Master Mode 1
    PMAEN = 0x0001; // PMA0 enabled

    timer1_delay_ms(20);
    PMADDR = LCDCMD; // command register ( ADDR = 0)
    PMDATA = 0x38; // 8 - bit interface , 2 lines , 5 x7
    timer1_delay_ms(1); // >48 us
    PMDATA = 0x0c; // ON , no cursor , no blink
    timer1_delay_ms(1); // >48 us
    PMDATA = 0x01; // clear display
    timer1_delay_ms(2); // >1.6 ms
    PMDATA = 0x06; // increment cursor , no shift
    timer1_delay_ms(2); // >1.6 ms
}

int lcd_pmp_is_busy() {
    // PMP busy
    return PMMODEbits.BUSY;
}

void lcd_wait_pmp() {
    while (lcd_pmp_is_busy()) {
    }
}

void lcd_wait_busy() {
    while (lcd_is_busy()) {
    }
}

char lcd_read(int addr) {
    int dummy;

    lcd_wait_pmp();

    PMADDR = addr; // select the command address
    dummy = PMDATA; // init read cycle , dummy read

    lcd_wait_pmp();

    return PMDATA; // read the status register
}

void lcd_write(int addr, char c) {
    lcd_wait_busy();
    lcd_wait_pmp();

    PMADDR = addr; // RS (0 or 1) for LCD
    PMDATA = c;
}

void lcd_line_1() {
    lcd_write(0, 0x80);
}

void lcd_line_2() {
    lcd_write(0, 0x80 | 0x40);
}

void lcd_print(char *s) {
    while (*s) {
        lcd_printc(*s++);
    }
}