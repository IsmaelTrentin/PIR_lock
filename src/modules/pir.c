#include <p32xxxx.h>

#include "libmc_config.h"

void pir_init() {
    LIBMC_PIR_TRIS = 1;
    LIBMC_PIR_ANSEL = 0;
}

int pir_read() {
    int val = PORTBbits.RB9;
    return val;
}
