/* test_main.c */

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

void test_main_should_initLED(void)
{
    led_init_Expect();
    led_toggle_Ignore();

    TEST_ASSERT_EQUAL(0, testableMain());
}

#endif // TEST
