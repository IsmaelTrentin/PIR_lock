#include <p32xxxx.h>
#include "libmc/pwm.h"
#include "libmc/timer.h"
#include "modules/servo.h"

#include "libmc_config.h"

int us_to_ticks(int us) {
    // 1 tick = PBCLK/64 = 625KHz -> 1/625KHz = 1.6us
    // 
    // 625000ticks / 1000000us because we have 625k ticks a second.
    // therefore we have 0.625 ticks/us (correct since 1tick=1.6us)
    // to avoid floating point numbers and perform caluclations
    // with integers, we use the following equivalent form:
    return (us * 625) / 1000;
}

void servo_init() {
    // servo needs 20ms pwm period
    timer3_init(20, 64, 0b110);
    // octsel=1 -> uses timer 3
    pwm_oc5_init(1, us_to_ticks(500));

    ANSELBbits.ANSB8 = 0;
    TRISBbits.TRISB8 = 0;
    // mapped to OC5 output
    RPB8R = 0b1011;
}

void servo_set_us(int us) {
    if (us < SERVO_MIN_US) {
        us = SERVO_MIN_US;
    }
    if (us > SERVO_MAX_US) {
        us = SERVO_MAX_US;
    }

    OC5RS = us_to_ticks(us);
}

// uses linear map:
// y = y1 + ((x - x1) * (y2 - y1)) / (x2 - x1)
void servo_set_deg(float deg) {
    if (deg < SERVO_MIN_DEG) {
        deg = SERVO_MIN_DEG;
    }
    if (deg > SERVO_MAX_DEG) {
        deg = SERVO_MAX_DEG;
    }

    int new_factor = (SERVO_MAX_US - SERVO_MIN_US) / (SERVO_MAX_DEG - SERVO_MIN_DEG);
    int us = SERVO_MIN_US + (long)deg * new_factor;
    servo_set_us(us);
}

void servo_sweep(int delay_ms) {
    for(int i = 0; i <= SERVO_MAX_DEG; i += 10) {
        servo_set_deg(i);
        timer1_delay_ms(delay_ms);
    }
}

void servo_sweep_reverse(int delay_ms) {
    for(int i = SERVO_MAX_DEG; i > 0; i -= 10) {
        servo_set_deg(i);
        timer1_delay_ms(delay_ms);
    }
}
