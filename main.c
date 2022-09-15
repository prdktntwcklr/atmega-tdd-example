/* main.c */

#include "main.h"
//#include <avr/io.h>
#include <stdint.h>
#include <util/delay.h>

#define _MMIO_BYTE(mem_addr) (*(volatile uint8_t *)(mem_addr))

#define DDRD  _MMIO_BYTE(0x2A)
#define PORTD _MMIO_BYTE(0x2B)

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