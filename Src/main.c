/* main.c */

#include "main.h"
#include "low_power.h"
#include "superloop.h"

#ifndef UNIT_TESTS
int main(void)
#else
int testable_main(void)
#endif
{
	superloop_init();
	low_power_init();
	
	while(superloop_run())
	{
		low_power_enter();
	}
	
	return 0;
}
