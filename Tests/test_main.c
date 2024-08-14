/* test_main.c */

#ifdef TEST

#include <stdbool.h>

#include "unity.h"
#include "fff.h"

DEFINE_FFF_GLOBALS;

FAKE_VOID_FUNC(superloop_init);
FAKE_VOID_FUNC(low_power_init);
FAKE_VOID_FUNC(low_power_enter);
FAKE_VALUE_FUNC(bool, superloop_run);

#include "main.h"

void setUp(void)
{
    RESET_FAKE(superloop_init);
    RESET_FAKE(low_power_init);
    RESET_FAKE(low_power_enter);
    RESET_FAKE(superloop_run);
}

void tearDown(void) {}

void test_main_should_initPeripheralsThenRunMainLoop(void)
{
    superloop_run_fake.return_val = false;
    testable_main();
    TEST_ASSERT_EQUAL(1, superloop_init_fake.call_count);
    TEST_ASSERT_EQUAL(1, low_power_init_fake.call_count);
    TEST_ASSERT_EQUAL(1, superloop_run_fake.call_count);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_main_should_initPeripheralsThenRunMainLoop);
    return UNITY_END();
}

#endif // TEST
