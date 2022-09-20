#include "timer.h"
#include "led.h"
#include "avr/io.h"
#include "avr/interrupt.h"

/*
 * @brief 
 */
extern void timer_init(void)
{
    /* TODO: set timer ticks to 244 which corresponds to freq of 4.00230533 Hz */

    cli();                                 /* disable global interrupts */
    TIMSK0 |= (1 << TOIE0);                /* enable Timer/Counter0 overflow interrupt */
    sei();                                 /* enable global interrupts */
    TCCR0B |= ((1 << CS02) | (1 << CS00)); /* set clock to clk/1024, this starts the timer */
}

/*
 * @brief Timer/Counter0 Overflow Interrupt
 */
ISR(TIMER0_OVF_vect)
{
    static int count = 0;

    if(++count == 1)
    {
        led_toggle();
        count = 0;
    }
}
