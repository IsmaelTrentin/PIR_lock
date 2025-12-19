/* Disable JTAG to use RA0 */
#pragma config JTAGEN = OFF
#pragma config FWDTEN = OFF
/* Device Config Bits in DEVCFG1 : */
#pragma config FNOSC = PRIPLL
#pragma config FSOSCEN = OFF
#pragma config POSCMOD = XT
#pragma config OSCIOFNC = ON
#pragma config FPBDIV = DIV_2
/* Device Config Bits in DEVCFG2 : */
#pragma config FPLLIDIV = DIV_2
#pragma config FPLLMUL = MUL_20
#pragma config FPLLODIV = DIV_1
/* Enable clock config */
#pragma config FCKSM = CSECMD

#include <p32xxxx.h>
#include "libmc/lcd.h"
#include "libmc/timer.h"

int PBCLK_Hz = 40000000;
// test

void main() {
    timer1_init(1, PBCLK_Hz, 1, 0);
    lcd_init();

    lcd_clear();
    lcd_homepos();

    lcd_print(" -- PIR LOCK -- ");
    lcd_line_2();
    lcd_print("--- GROUP 04 ---");

    while (1);
}