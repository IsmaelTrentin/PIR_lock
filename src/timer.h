#pragma once

/* Pragma definitio for clock configuration 
// Device Config Bits in DEVCFG1 :
# pragma config FNOSC = FRCPLL // Select XTPLL , HSPLL , ECPLL , FRCPLL in
FNOXC mux
# pragma config FSOSCEN = OFF // Disable Secondary oscillator
# pragma config POSCMOD = XT // external crystal / resonator
oscillator modes
# pragma config OSCIOFNC = ON // CLKO Enable Configuration bit
# pragma config FPBDIV = DIV_2 // Peripheral Bus Clock Divisor
// Device Config Bits in DEVCFG2 :
# pragma config FPLLIDIV = DIV_2 // PLL Input Divider
# pragma config FPLLMUL = MUL_20 // PLL Multiplier
# pragma config FPLLODIV = DIV_2 // PLL Output Divider
// disable JTAG
# pragma config JTAGEN = OFF
# pragma config FWDTEN = OFF
 */

int timer_calc_pr(int T_ms, int f_clk_Hz, int prescaler);
void timer_init_2(int T_ms, int f_clk_Hz, int prescaler, int priority, int subpriority);
void delay_ms(int ms);
void delay_ms_t1(unsigned int ms);