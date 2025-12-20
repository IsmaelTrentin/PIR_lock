#include <p32xxxx.h>
#include "libmc/pwm.h"
#include "libmc/timer.h"

#include "libmc_config.h"

#define SERVO_MIN_US 1000
#define SERVO_MAX_US 2000

void servo_init() {
    ANSELBbits.ANSB6 = 0;
    TRISBbits.TRISB6 = 0;
    RPB6R = 0b1011; // mapped to OC2 output

    timer3_init(1, LIBMC_PBCLK_HZ, 1, 0);
    PR3 = 12500; // presc=64 t=20ms
    pwm_oc2_init(1, 0);
}

static inline int us_to_ticks(int us) {
    // 1 tick = 1.6 us
    return (us * 625) / 1000;
}

void servo_set_us(int us) {
    if (us < SERVO_MIN_US) us = SERVO_MIN_US;
    if (us > SERVO_MAX_US) us = SERVO_MAX_US;

    OC2RS = us_to_ticks(us);
}

void servo_set_angle(int deg) {
    if (deg > 180) deg = 180;

    int us = SERVO_MIN_US +
            ((SERVO_MAX_US - SERVO_MIN_US) * deg) / 180;

    servo_set_us(us);
}
