#include "libmc_config.h"
#include <string.h>

#include "main.h"
#include "isrs.h"
#include "logging.h"

volatile static unsigned int LOG_ID_SEQ = 0;

char* log_enum_str(LogEventType type) {
    switch (type) {
        case 0:
            return "OPEN";
        case 1:
            return "CLOSE";
    }

    return "log_enum_str: bad input";
}

unsigned int log_get_storage_idx() {
    return LOG_ID_SEQ % LIBMC_LOGS_MAXN;
}

void log_init_arr() {
    for (int i = 0; i < LIBMC_LOGS_MAXN; i ++) {
        Log init_log = {
            .id = -1,
            .timestamp = 0,
            .type = 0
        };

        logs[i] = init_log;
    }
}

void log_append(LogEventType type) {
    Log new_log = {
        .id = LOG_ID_SEQ,
        .timestamp = TIMER1_MS / 1000,
        .type = type,
    };
    logs[log_get_storage_idx()] = new_log;

    LOG_ID_SEQ++;
}

void log_erase_all() {
    // 0 is safe since we have primitives values in the struct
    // and our `LogEventType` enum defines a 0 value.
    log_init_arr();
    LOG_ID_SEQ = 0;
}