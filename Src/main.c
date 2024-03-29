#include "main.h"
#include "low_power.h"
#include "superloop.h"

#ifndef TEST
int main(void)
#else
int testable_main(void)
#endif
{
    superloop_init();
    low_power_init();

    while(superloop_run()) // NOLINT
    {
        low_power_enter();
    }

    return 0;
}
