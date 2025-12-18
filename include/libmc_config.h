#ifndef LIBMC_CONFIG_H
#define LIBMC_CONFIG_H

#define LIBMC_SYSCLK_HZ 80000000UL
#define LIBMC_PBCLK_HZ  40000000UL
#define LIBMC_AUDIO_SUCCESS_DELAY 62UL
#define LIBMC_AUDIO_ERROR_DELAY 100UL

#endif

// print compile time error when 
#ifndef LIBMC_CONFIG_H
#error "libmc_config.h LIBMC_CONFIG_H missing file or declaration"
#endif

#ifndef LIBMC_PBCLK_HZ
#error "LIBMC_PBCLK_HZ not defined"
#endif
