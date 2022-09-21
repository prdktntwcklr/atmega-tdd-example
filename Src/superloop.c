/* superloop.c */

#include "superloop.h"
#include "led.h"
#include "timer.h"

#define TOGGLE_INTERVAL_IN_MS (1000U)

/*
 * @brief Initializes the peripherals needed in the superloop.
 */
extern void superloop_init(void)
{
    led_init();
    timer_init();
}

/*
 * @brief Runs the superloop. Returns TRUE by default.
 */
extern bool superloop_run(void)
{
    static uint16_t last_toggle_stamp = 0;

    if(timer_deadline_reached(last_toggle_stamp + TOGGLE_INTERVAL_IN_MS))
    {
        last_toggle_stamp = timer_get_stamp();

        led_toggle();
    }

    return true;
}
