/* main.c */

#include "main.h"
#include "led.h"

#ifndef TEST
#include <util/delay.h>
#else
#define _delay_ms(...) (void)(0)
#endif

#ifndef TEST
#define FOREVER (1)
#else
#define FOREVER (0)
#endif

#ifndef TEST
int main(void)
#else
int testableMain(void)
#endif
{
	led_init();
	
	while(FOREVER)
	{
		led_toggle();
		_delay_ms(1000);
	}
	
	return 0;
}
