#pragma once

#include <p32xxxx.h>

// ~10ms @ 80MHz
#define DEBOUNCE_DELAY 800000  

void ihandler_t1();
void ihandler_t2();

void ihandler_cn();