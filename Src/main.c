/* main.c */

#include "main.h"
#include "superloop.h"

#ifndef TEST
int main(void)
#else
int testable_main(void)
#endif
{
	superloop_init();
	
	while(superloop_run())
	{
		// TODO: enter power saving mode here
	}
	
	return 0;
}
