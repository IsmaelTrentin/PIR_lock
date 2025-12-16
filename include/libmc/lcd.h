#pragma once

#define LCDDATA 1 // RS = 1 ; access data register
#define LCDCMD 0 // RS = 0 ; access command register
#define PMDATA PMDIN // PMP data buffer
#define lcd_is_busy() lcd_read(LCDCMD) & 0x80

#define lcd_printc(d) lcd_write(LCDDATA, (d))
#define lcd_cmd(c) lcd_write(LCDCMD, (c))
#define lcd_homepos() lcd_write(LCDCMD, 2)
#define lcd_clear() lcd_write(LCDCMD, 1)
#define lcd_next_line() lcd_write(LCDCMD, 0x60)

void lcd_init();
int lcd_pmp_is_busy();
void lcd_wait_pmp();
void lcd_wait_busy();
char lcd_read(int addr);
void lcd_write(int addr, char c);
void lcd_print(char * s);