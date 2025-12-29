#pragma once

#include "modules/servo.h"

#define SERVO_CLOSED_LOCK_DEG SERVO_MIN_DEG
#define SERVO_OPENED_LOCK_DEG SERVO_MAX_DEG

typedef struct State {
    int authorized;
    int locked;
    int sleeping;
    int sensor_enabled;
    char *password;
} State;

typedef struct Events {
    int auth_request;
    int auth_success;
    int went_afk;
    int sensor_detect;
    int locked;
} Events;
