/* main.c */

#include "main.h"
#include "superloop.h"
#include "avr/interrupt.h"
#include "avr/sleep.h"

#ifndef TEST
int main(void)
#else
int testable_main(void)
#endif
{
	superloop_init();
	set_sleep_mode(SLEEP_MODE_IDLE);
	
	while(superloop_run())
	{
		/* send mcu to sleep, sequence recommended in avr/sleep.h */
		cli();
		if(true)
		{
			sleep_enable();
			sei();
			sleep_cpu();
			sleep_disable();
		}
		sei();
	}
	
	return 0;
}
