#ifndef PROGRAM_CONFIG_H
#define PROGRAM_CONFIG_H

// PROGRAM
#define PROGRAM_CONFIG_LOGS_MAXN 10
#define PROGRAM_CONFIG_AFK_MAX_TIME_MS 5000

#endif

// print compile time error when 
#ifndef PROGRAM_CONFIG_H
#error "program_config.h PROGRAM_CONFIG_H missing file or declaration"
#endif

#ifndef PROGRAM_CONFIG_LOGS_MAXN
#error "program_config.h PROGRAM_CONFIG_LOGS_MAXN not defined"
#endif

#ifndef PROGRAM_CONFIG_AFK_MAX_TIME_MS
#error "program_config.h PROGRAM_CONFIG_AFK_MAX_TIME_MS not defined"
#endif
