/* low_power.c */

#include "low_power.h"
#include "stdbool.h"

#include "avr/interrupt.h"
#include "avr/sleep.h"

/**
 * @brief Initializes the low power mode.
 */
void low_power_init(void)
{
    set_sleep_mode(SLEEP_MODE_IDLE);
}

/**
 * @brief Enters the low power mode.
 *
 * @note  Sequence recommended in avr/sleep.h.
 */
void low_power_enter(void)
{
    cli();
    if(true) /* possible to add condition here */
    {
        sleep_enable();
        sei();
        sleep_cpu();
        sleep_disable();
    }
    sei();
}
