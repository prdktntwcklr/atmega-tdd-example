/* main.c */

#include "main.h"
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRD |= (1 << 3);
	
	while(1)
	{
		PORTD ^= (1 << 3);
		_delay_ms(1000);
	}
	
	return 0;
}
