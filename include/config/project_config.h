#ifndef PROJECT_CONFIG
#define PROJECT_CONFIG

// CLOCK
#define PROJECT_CONFIG_SYSCLK_HZ 80000000UL
#define PROJECT_CONFIG_PBCLK_HZ  40000000UL

#endif

// print compile time error when 
#ifndef PROJECT_CONFIG
#error "project_config.h PROJECT_CONFIG missing file or declaration"
#endif

#ifndef PROJECT_CONFIG_SYSCLK_HZ
#error "project_config.h PROJECT_CONFIG_SYSCLK_HZ not defined"
#endif

#ifndef PROJECT_CONFIG_PBCLK_HZ
#error "project_config.h PROJECT_CONFIG_PBCLK_HZ not defined"
#endif

