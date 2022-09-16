#include "led.h"

#ifndef TEST
#include "avr/io.h"
#else
#include "testable_micro_registers.h"
#endif

#define LED_DDR  (DDRD)
#define LED_PORT (PORTD)
#define LED_PIN  (3U)

extern void led_init(void)
{
	/* configure LED pin as output */
	LED_DDR |= (1 << LED_PIN);
}

extern void led_toggle(void)
{
	/* toggle LED pin */
	LED_PORT ^= (1 << LED_PIN);
}
