#include "led.h"
#include <avr/io.h>

#define sbi(byte, bit) ((byte) |= (bit))
#define tbi(byte, bit) ((byte) ^= (bit))

extern void led_init(void)
{
	/* configure LED pin as output */
	sbi(DDRD, (1 << DDD3));
}

extern void led_toggle(void)
{
	/* toggle LED pin */
	tbi(PORTD, (1 << PD3));
}
