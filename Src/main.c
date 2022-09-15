/* main.c */

#include "main.h"
#include <avr/io.h>
#include <util/delay.h>

static void led_init(void);
static void led_toggle(void);

int main(void)
{
	led_init();
	
	while(1)
	{
		led_toggle();
		_delay_ms(1000);
	}
	
	return 0;
}

static void led_init(void)
{
	/* configure LED pin as output */
	DDRD |= (1 << DDD3);
}

static void led_toggle(void)
{
	/* toggle LED pin */
	PORTD ^= (1 << PD3);
}