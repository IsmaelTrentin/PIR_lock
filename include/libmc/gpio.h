#pragma once

typedef volatile unsigned int REG_SELECTOR_T;

// registers
void set_reg(REG_SELECTOR_T *mode, unsigned int bitId, unsigned int value);

// leds
void led_ansel(int ledId, int value);
void led_tris(int ledId, int value);
void led_lat(int ledId, int value);
int led_port(int ledId);
void led_turn_on(int ledId);
void led_turn_off(int ledId);
void led_toggle(int ledId);
void led_init_all();
void led_turn_off_all();
void led_turn_on_all();

// switches
void sw_init_all();
int sw_read(int swId);

// buttons
#define BTN_UP 0
#define BTN_LEFT 1
#define BTN_CENTER 2
#define BTN_RIGHT 3
#define BTN_DOWN 4

void btn_init_all();
int btn_read(int btn_id);