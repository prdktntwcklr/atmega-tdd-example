#ifndef LED_H
#define LED_H

#include "stdbool.h"

void led_init(void);
void led_turn_on(void);
void led_turn_off(void);
void led_toggle(void);
bool led_is_on(void);
bool led_is_off(void);

#endif // LED_H
