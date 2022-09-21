#ifdef TEST

#include "unity.h"

#include "superloop.h"
#include "mock_led.h"
#include "mock_timer.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_superloop_init_should_initializePeripherals(void)
{
    led_init_Expect();
    timer_init_Expect();

    superloop_init();
}

void test_superloop_run_should_toggleLedIfDeadlineReached(void)
{
    timer_deadline_reached_IgnoreAndReturn(false);
    
    superloop_run();

    timer_deadline_reached_IgnoreAndReturn(true);
    timer_get_stamp_IgnoreAndReturn(0);
    led_toggle_Expect();

    superloop_run();
}

#endif // TEST
