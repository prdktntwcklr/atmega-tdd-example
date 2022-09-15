#include "led.h"
#include <avr/io.h>

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
