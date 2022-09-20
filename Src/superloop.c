/* superloop.c */

#include "superloop.h"
#include "led.h"

extern void superloop_init(void)
{
    led_init();
}

extern bool superloop_run(void)
{
    led_toggle();

    return true;
}