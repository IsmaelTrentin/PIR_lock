#pragma once

extern unsigned int PbusClock;
extern unsigned int UartBrg;

void uart_config_pins();
void uart_config(int baud, int priority, int subpriority);

int uart_putU4(int c);
char uart_getU4();
void uart_putU4_string(char data[]);
void uart_getU4_string(char dataOut[80]);