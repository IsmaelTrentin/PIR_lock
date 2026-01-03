#include <p32xxxx.h>

#include "config/libmc_config.h"
#include "config/modules_config.h"

void pir_init() {
    MODULES_CONFIG_PIR_TRIS = 1;
    MODULES_CONFIG_PIR_ANSEL = 0;
}

void pir_cn_config_rb9() {
    CNCONBbits.ON = 0;
    CNENBbits.CNIEB9 = 1;
    CNPDBbits.CNPDB9 = 1;
    IFS1bits.CNBIF = 0;
    IEC1bits.CNBIE = 1;
    IPC8bits.CNIP = 1;
    IPC8bits.CNIS = 3;
    CNCONBbits.ON = 1;

    PORTB;
}

int pir_read() {
    int val = PORTBbits.RB9;
    return val;
}
