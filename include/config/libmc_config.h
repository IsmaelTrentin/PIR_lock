#ifndef LIBMC_CONFIG_H
#define LIBMC_CONFIG_H

// LIB
// - AUDIO
#define LIBMC_AUDIO_SUCCESS_DELAY 62UL
#define LIBMC_AUDIO_ERROR_DELAY 100UL
// - UART
#define LIBMC_UART_BUFF_SIZE 80
#define LIBMC_UART_BAUD 9600

#endif

// print compile time error when 
#ifndef LIBMC_CONFIG_H
#error "libmc_config.h LIBMC_CONFIG_H missing file or declaration"
#endif

#ifndef LIBMC_UART_BUFF_SIZE
#error "libmc_config.h LIBMC_UART_BUFF_SIZE not defined"
#endif

#ifndef LIBMC_UART_BAUD
#error "libmc_config.h LIBMC_UART_BAUD not defined"
#endif
