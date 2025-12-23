#include <p32xxxx.h>

void multivector_mode() {
    __builtin_disable_interrupts();
    INTCONbits.MVEC = 1;
    __builtin_enable_interrupts();
}

// UART
void int_enable_uart(int priority, int subpriority) {
    IFS2bits.U4RXIF = 0;
    IFS2bits.U4TXIF = 0;

    IPC9bits.U4IP = priority; // group of 3 bits, 7 -> max priority
    IPC9bits.U4IS = subpriority;
    IEC2bits.U4EIE = 0;
    IEC2bits.U4RXIE = 1; // interrupt on incoming byte is on
    IEC2bits.U4TXIE = 0; // interrupt when tx buffer is empty is off
}

// TIMER 1
void int_enable_timer_1(int priority, int subpriority) {
    IPC1bits.T1IP = priority; // group of 3 bits, 7 -> max priority
    IPC1bits.T1IS = subpriority;
    IEC0bits.T1IE = 1;
}

// TIMER 2
void int_enable_timer_2(int priority, int subpriority) {
    IPC2bits.T2IP = priority; // group of 3 bits, 7 -> max priority
    IPC2bits.T2IS = subpriority;
    IEC0bits.T2IE = 1;
}

// TIMER 3
void int_enable_timer_3(int priority, int subpriority) {
    IPC3bits.T3IP = priority; // group of 3 bits, 7 -> max priority
    IPC3bits.T3IS = subpriority;
    IEC0bits.T3IE = 1;
}
