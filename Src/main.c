/* main.c */

#include "main.h"
#include "superloop.h"

#ifndef TEST
#include <util/delay.h>
#else
#define _delay_ms(...) (void)(0)
#endif

#ifndef TEST
int main(void)
#else
int testable_main(void)
#endif
{
	superloop_init();
	
	while(superloop_run())
	{
		_delay_ms(1000);
	}
	
	return 0;
}
