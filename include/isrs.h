#pragma once

#include <p32xxxx.h>

// ~10ms @ 80MHz
#define DEBOUNCE_DELAY 800000  

extern volatile unsigned long TIMER1_MS;
extern volatile int TIMER_AFK;

void ihandler_t1();
void ihandler_t2();

void ihandler_cn();