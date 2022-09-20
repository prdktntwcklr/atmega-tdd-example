/* superloop.c */

#include "superloop.h"
#include "led.h"
#include "timer.h"

extern void superloop_init(void)
{
    led_init();
    timer_init();
}

extern bool superloop_run(void)
{
    //led_toggle();

    return true;
}
