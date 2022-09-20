#ifdef TEST

#include "unity.h"

#include "superloop.h"
#include "mock_led.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_superloop_init_should_initializeLed(void)
{
    led_init_Expect();

    superloop_init();
}

void test_superloop_run_should_toggleLed(void)
{
    led_toggle_Expect();

    superloop_run();
}

#endif // TEST
