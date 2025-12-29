#pragma once

#include "modules/servo.h"

#define SERVO_CLOSED_LOCK_DEG SERVO_MIN_DEG
#define SERVO_OPENED_LOCK_DEG SERVO_MAX_DEG

typedef struct State {
    int sensor_enabled;
    int authorized;
    int sleeping;
    int locked;
    char *password;
} State;

typedef struct Events {
    int locked;
    int went_afk;
} Events;
