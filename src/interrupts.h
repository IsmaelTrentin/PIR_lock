#pragma once

/* 
 * **********************************************************
 * Alternative definition for Multiple vector mode Interrupt with respect to INTEnableSystemMultiVectoredInt() used if plib.h are included
 * call the MACRO "macro_enable_interrupts()"
 * **********************************************************
 */
#define macro_enable_interrupts()\
{  unsigned int val = 0;\
   asm volatile("mfc0 %0,$13":"=r"(val));\ 
   val |= 0x00800000;\
   asm volatile("mtc0 %0,$13" : "+r"(val));\
   INTCONbits.MVEC = 1;\
   __builtin_enable_interrupts();}

 
#define INT_VN_TIMER2 8
#define INT_VN_UART4 39   
   
void multivector_mode();

void int_enable_uart(int priority, int subpriority);
void int_reset_uart_rx();
void int_reset_uart_tx();
int int_getf_uart_rx();
int int_getf_uart_tx();

void int_enable_timer_2(int priority, int subpriority);
void int_reset_timer2();