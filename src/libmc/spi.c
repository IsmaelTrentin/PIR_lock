#include <p32xxxx.h>
#include "libmc/timer.h"
#include "libmc/spi.h"

void spi1_init() {
    // RF2 as Digital Input SDI for flash, SDO for MCU 
    TRISFbits.TRISF2 = 1; 
    // RF7 as Digital Output SDO for flash, SDI for MCU
    TRISFbits.TRISF7 = 0; 
    // RF6 as Digital Output SCK
    TRISFbits.TRISF6 = 0; 
    
    // SDO1 - RF2 output PPS
    RPF2R = 0x08; 
    // SDI - RF7 input PPS
    SDI1R = 0x0F; 

    // RF8 as Digital Output Chip Selection - see #define
    TCS = 0; 
    // Chip select low - see #define
    CS = 1; 
    
    // SPI on, 8-bit master,CKE=1,CKP=0
    SPI1CON = 0x8120; 
    // SPI Master enable
    SPI1CONbits.MSTEN = 1; 
    // Set for SPI Mode 0
    SPI1CONbits.CKE = 1; 
    // Enable SPI1
    SPI1CONbits.ON = 1; 
    // F_sck = Fpb / (2 * (15 + 1))
    // 1.25 MHz clock
    SPI1BRG = 15; 
}

// send one byte of data and receive one back at the same time
int spi1_write(short byte) {
    // wait for TX buffer to be empty
    while (!SPI1STATbits.SPITBE);	
    // write to buffer for TX
    SPI1BUF = byte; 
    // wait for transfer complete
    while (!SPI1STATbits.SPIRBF); 
    // read the received value
    return (int)SPI1BUF; 
}

void flash_wait_ready() {
    CS = 0;
    // WIP bit = 1 while busy
    while (spi1_write(0x05) & 0x01) { } 
    CS = 1;
}

int flash_get_id() {
    //get ID = 15
    // select the Serial EEPROM
    CS = 0; 

    // get ID
    spi1_write(0xAB); 
    spi1_write(0);
    spi1_write(0);
    spi1_write(0);
    // send dummy, read data  
    spi1_write(0); 

    CS = 1;
    return SPI1BUF;
}

void flash_erase() {
    // write enable
    CS = 0;
    spi1_write(0x06);
    CS = 1;
    timer1_delay_ms(10);
    
    // full erase CMD
    CS = 0;
    spi1_write(0x60);
    CS = 1;
    timer1_delay_ms(10);
    
    // write disable
    CS = 0;
    spi1_write(0x04);
    CS = 1;

    flash_wait_ready();
}

int flash_read_mem(int addr) {
    int tmp = 0;

    // send a read command
    // select the Serial EEPROM
    CS = 0; 
    // send command Read Data, ignore data
    spi1_write(0x03); 
    // send MSB of memory address
    spi1_write(addr >> 16); 
    // send LSB of memory address
    spi1_write(addr >> 8); 
    // send LSB of memory address
    spi1_write(addr); 

    // send dummy, read data 
    tmp = spi1_write(0); 

    // terminate the read sequence
    CS = 1; 
    return tmp;
}

void flash_write_mem(int addr, short byte) {
    short value = 0;
    int address = 0;
    
    value = byte;
    address = addr;
    // write enable
    CS = 0;
    spi1_write(0x06);
    CS = 1;
    
    // send a Write command
    // select the Serial EEPROM
    CS = 0; 
    // send command, ignore data Page Program
    spi1_write(0x02); 
    // send MSB of memory address
    spi1_write(address >> 16); 
    // send LSB of memory address
    spi1_write(address >> 8); 
    // send LSB of memory address
    spi1_write(address); 
    // send the actual data
    spi1_write(value); 
    // send more data here to perform a page write
    // ?
    // start actual EEPROM write cycle
    CS = 1; 
    
    // write disable
    CS = 0;
    spi1_write(0x04);
    CS = 1;

    flash_wait_ready();
}
