#include "libmc/lcd.h"
#include "libmc/uart.h"

void lcd_print_homescreen() {
    lcd_clear();
    lcd_homepos();
    lcd_clear();
    lcd_homepos();
    lcd_print(" -- PIR LOCK -- ");
    lcd_line_2();
    lcd_print("--- GROUP 04 ---");
}

void uart_put_global_menu(int state_activated) {
    uart_puts(state_activated ? "1. Deactivate\n" : "1. Activate\n" );
    uart_puts("2. Change password\n");
    uart_puts("3. Print logs\n");
    uart_puts("4. Clear logs\n");
}