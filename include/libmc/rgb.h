#pragma once

#define RED 0b100
#define GREEN 0b010
#define BLUE 0b001
#define PURPLE RED | BLUE

void rgb_init();
void rgb_set_r(unsigned int value);
void rgb_set_g(unsigned int value);
void rgb_set_b(unsigned int value);
void rgb_set(unsigned int r, unsigned int g, unsigned int b);
void rgb_setb(unsigned int val);