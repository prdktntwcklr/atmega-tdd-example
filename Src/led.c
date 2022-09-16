#include "led.h"

#ifndef TEST
#include "avr/io.h"
#else
#include "stdint.h"
uint8_t DDRD = 0;
#define DDD3 3
uint8_t PORTD = 0;
#define PD3 3
#endif

extern void led_init(void)
{
	/* configure LED pin as output */
	DDRD |= (1 << DDD3);
}

extern void led_toggle(void)
{
	/* toggle LED pin */
	PORTD ^= (1 << PD3);
}
