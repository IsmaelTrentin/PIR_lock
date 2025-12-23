#pragma once

extern unsigned int uart_brg;

void uart_config_pins();
void uart_init(int baud, int priority, int subpriority);

int uart_putc(int c);
char uart_getc();
void uart_puts(char data[]);
void uart_gets(char dataOut[80]);