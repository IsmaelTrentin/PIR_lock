#include <p32xxxx.h>
#include "libmc/uart.h"
#include "libmc/interrupts.h"

#include "libmc_config.h"

// UART_TX RF12
// UART_RX RF13

unsigned int uart_brg = 0;
volatile int rx_got_byte = 0;
volatile char last_char = '\n';

void uart_config_pins() {
    // config TX
    TRISFbits.TRISF12 = 0; // TX digital output
    RPF12R = 0x2; // U4TX mapped to RPF12

    // config RX
    TRISFbits.TRISF13 = 1; // RX digital input
    U4RXR = 0x9; // U4RX mapped to RPF13
}

void uart_init(int baud, int priority, int subpriority) {
    uart_config_pins();

    U4MODE = 0x0;

    // baud rate generator config
    //    UartBrg = (PbusClock + (8 * baud)) / (16 * baud) - 1;
    uart_brg = (int) (((float) LIBMC_PBCLK_HZ / (16 * baud) - 1) + 0.5);
    U4BRG = uart_brg;
    U4STAbits.UTXEN = 1;
    U4STAbits.URXEN = 1;
    // 8bit data no parity
    U4MODEbits.PDSEL = 0b00; 
    // 1 stop bit
    U4MODEbits.STSEL = 0;
    U4MODEbits.ON = 1;

    // setup interrupt
    int_enable_uart(priority, subpriority);
}

void __attribute__((interrupt(ipl6), vector(_UART_4_VECTOR))) ihandler_uart4() {
    if (IFS2bits.U4RXIF == 1) {
        if (U4STAbits.OERR) {
            U4STAbits.OERR = 0;
        }

        if (U4STAbits.URXDA) {
            last_char = U4RXREG;
            rx_got_byte = 1;
        }

        IFS2bits.U4RXIF = 0;
    }
}

void uart_putc(int c) {
    while (U4STAbits.UTXBF == 1);
    U4TXREG = c;
}

char uart_getc() {
    while (rx_got_byte == 0);
    rx_got_byte = 0;

    return last_char;
}

void uart_puts(char data[]) {
    char *pData = data;

    while (*pData) {
        uart_putc((*(pData++)));
    }
}

void uart_gets(char data_out[LIBMC_UART_BUFF_SIZE]) {
    int i = 0;
    char c;

    while (1) {
        c = uart_getc();

        if (c == '\r' || c == '\n')
            break;

        if (i < LIBMC_UART_BUFF_SIZE - 1) {
            data_out[i++] = c;
        }
    }

    data_out[i] = '\0';
}