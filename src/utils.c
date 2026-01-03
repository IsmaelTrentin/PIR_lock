#include <stdio.h>

#include "libmc/lcd.h"
#include "libmc/uart.h"

#include "config/program_config.h"

#include "logging.h"
#include "main.h"

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
    if (state_activated == 0) {
        uart_puts("2. Change password\n");
    }
    uart_puts("3. Print logs\n");
    uart_puts("4. Clear logs\n");
    uart_puts("5. Log out\n");
}

void uart_put_logs() {
    uart_puts("-- LOGS --\n");

    int printed_n = 0;
    for (int i = 0; i < PROGRAM_CONFIG_LOGS_MAXN; i ++) {
        if (logs[i].id == -1) continue;

        Log log = logs[i];
        char buff[50];

        snprintf(
            buff,
            sizeof(buff),
            "{id: %d, timestamp: %d, type: %s}\n",
            log.id,
            log.timestamp,
            log_enum_str(log.type)
        );
        uart_puts(buff);
        printed_n++;
    }

    if (printed_n == 0) {
        uart_puts("<empty>\n");
    }

    uart_puts("\n");
}