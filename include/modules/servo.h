#pragma once

// actual values should be 500-2500 but our servo
// fails to support them without stalling
#define SERVO_MIN_US 750
#define SERVO_MAX_US 2200
#define SERVO_MIN_DEG 0
#define SERVO_MAX_DEG 180

int us_to_ticks(int us);

void servo_init();
void servo_set_deg(float deg);
void servo_sweep(int delay_ms);
void servo_sweep_reverse(int delay_ms);