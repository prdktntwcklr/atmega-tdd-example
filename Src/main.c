/* main.c */

#include "main.h"
#include "led.h"
#include <util/delay.h>

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
