// with this config we have:
// SYSCLK = 80MHz
// PBCLK = 40MHz
// remember to put these in libmc_config.h

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
#include "libmc/audio.h"
#include "libmc/rgb.h"

#include "libmc_config.h"

void main() {
    timer1_init(1, LIBMC_PBCLK_HZ, 1, 0);
    audio_init();
    lcd_init();
    rgb_init();

    rgb_setb(RED);
    lcd_clear();
    lcd_homepos();
    
    audio_play_success();

    lcd_print(" -- PIR LOCK -- ");
    lcd_line_2();
    lcd_print("--- GROUP 04 ---");

    while (1);
}
