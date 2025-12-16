#pragma once

int timer_calc_pr(int T_ms, int f_clk_Hz, int prescaler);

void timer1_init(int T_ms, int f_clk_Hz, int priority, int subpriority);
void timer1_delay_ms(unsigned int ms);

void timer2_init(int T_ms, int f_clk_Hz, int priority, int subpriority);
void timer2_delay_ms(unsigned int ms);

void timer3_init(int T_ms, int f_clk_Hz, int priority, int subpriority);
void timer3_delay_ms(unsigned int ms);
