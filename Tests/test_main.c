#ifdef TEST

#include "unity.h"

#include "main.h"
#include "mock_led.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_main_should_callLedInit(void)
{
    led_init_Expect();
    led_toggle_Ignore();

    testableMain();
}

#endif // TEST
