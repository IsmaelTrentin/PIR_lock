#pragma once

#define SPI_SECTOR_SIZE 4
#define SPI_SECTOR_COUNT 1024
#define SPI_ADDR_START 0x0
#define SPI_ADDR_END 0x3FFFFF

// select line for Serial Flash ROM
#define CS LATFbits.LATF8 
// TRIS control for CS pin
#define TCS TRISFbits.TRISF8 

void spi1_init();
int spi1_write(short byte);

int flash_get_id();
void flash_erase();
int flash_read_mem(int addr);
void flash_write_mem(int addr, short byte);
