#ifndef LIBMC_CONFIG_H
#define LIBMC_CONFIG_H

// CLOCK
#define LIBMC_SYSCLK_HZ 80000000UL
#define LIBMC_PBCLK_HZ  40000000UL

// LIB
// - AUDIO
#define LIBMC_AUDIO_SUCCESS_DELAY 62UL
#define LIBMC_AUDIO_ERROR_DELAY 100UL
// - UART
#define LIBMC_UART_BUFF_SIZE 80

// MODULES
// - PIR sensor
// connected to ANALOG DEBUG HEADER through T2 (RB9)
#define LIBMC_PIR_TRIS TRISBbits.TRISB9
#define LIBMC_PIR_ANSEL ANSELBbits.ANSB9
#define LIBMC_PIR_PORT PORTBbits.RB9

#endif

// print compile time error when 
#ifndef LIBMC_CONFIG_H
#error "libmc_config.h LIBMC_CONFIG_H missing file or declaration"
#endif

#ifndef LIBMC_PBCLK_HZ
#error "libmc_config.h LIBMC_PBCLK_HZ not defined"
#endif

#ifndef LIBMC_UART_BUFF_SIZE
#error "libmc_config.h LIBMC_UART_BUFF_SIZE not defined"
#endif

#ifndef LIBMC_PIR_TRIS
#error "libmc_config.h LIBMC_PIR_TRIS missing TRIS pin config"
#endif
#ifndef LIBMC_PIR_ANSEL
#error "libmc_config.h LIBMC_PIR_ANSEL missing ANSEL pin config"
#endif
#ifndef LIBMC_PIR_PORT
#error "libmc_config.h LIBMC_PIR_PORT missing PORT pin config"
#endif
