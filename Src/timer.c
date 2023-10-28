#include "timer.h"

#ifndef TEST
#include "avr/io.h"
#include "avr/interrupt.h"
#else
#include "testable_mcu_registers.h"
#define cli() (void)(0);
#define sei() (void)(0);
#endif

#define TIMER_FULL_VAL   (255U)
#define TIMER_TICKS_VAL  (156U)
#define TIMER_RELOAD_VAL ((TIMER_FULL_VAL) - (TIMER_TICKS_VAL))
#define TIMER_INC_VAL    (10U)

static volatile uint16_t time_stamp = 0U;

/**
 * @brief Initializes the timer peripheral.
 */
extern void timer_init(void)
{
    /* disable global interrupts */
    cli();

    /* enable Timer/Counter0 overflow interrupt */
    TIMSK0 |= (1U << TOIE0);

    /* enable global interrupts */
    sei();

    /* load Timer/Counter0 register */
    TCNT0 = TIMER_RELOAD_VAL;

    /* set clock to clk/64, this starts the timer */
    TCCR0B |= ((1U << CS01) | (1U << CS00));
}

/**
 * @brief Sets the time_stamp to a specific value.
 */
extern void timer_set_stamp(uint16_t stamp)
{
    /* disable Timer/Counter0 overflow interrupt */
    TIMSK0 &= ~(1U << TOIE0);

    time_stamp = stamp;

    /* enable Timer/Counter0 overflow interrupt */
    TIMSK0 |= (1U << TOIE0);
}

/**
 * @brief Returns the current time_stamp value.
 */
extern uint16_t timer_get_stamp(void)
{
    /* disable Timer/Counter0 overflow interrupt */
    TIMSK0 &= ~(1U << TOIE0);

    uint16_t ret_val = time_stamp;

    /* enable Timer/Counter0 overflow interrupt */
    TIMSK0 |= (1U << TOIE0);

    return ret_val;
}

/**
 * @brief Returns TRUE if the deadline has been reached or passed.
 */
extern bool timer_deadline_reached(uint16_t deadline)
{
    return ((int16_t)(time_stamp - deadline) >= 0);
}

/**
 * @brief Timer/Counter0 Overflow Interrupt
 */
#ifndef TEST
ISR(TIMER0_OVF_vect)
#else
void testable_isr_timer0_ovf_vect(void)
#endif
{
    time_stamp += TIMER_INC_VAL;

    /* reload Timer/Counter0 register */
    TCNT0 = TIMER_RELOAD_VAL;
}
