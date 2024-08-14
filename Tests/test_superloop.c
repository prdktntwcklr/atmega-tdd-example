/* test_superloop.c */

#ifdef TEST

#include <stdbool.h>
#include <stdint.h>

#include "unity.h"
#include "fff.h"

DEFINE_FFF_GLOBALS;

FAKE_VOID_FUNC(led_init);
FAKE_VOID_FUNC(timer_init);
FAKE_VALUE_FUNC(bool, timer_deadline_reached);
FAKE_VOID_FUNC(led_toggle);

#include "superloop.h"

void setUp(void)
{
    RESET_FAKE(led_init);
    RESET_FAKE(timer_init);
    RESET_FAKE(timer_deadline_reached);
    RESET_FAKE(led_toggle);
}

void tearDown(void) {}

void test_superloop_init_should_initializePeripherals(void)
{
    superloop_init();
    TEST_ASSERT_EQUAL(1, led_init_fake.call_count);
    TEST_ASSERT_EQUAL(1, timer_init_fake.call_count);
}

void test_superloop_run_should_toggleLedIfDeadlineReached(void)
{
    timer_deadline_reached_fake.return_val = true;

    superloop_run();

    TEST_ASSERT_EQUAL(1, led_toggle_fake.call_count);
}

void test_superloop_run_should_notToggleLedIfDeadlineNotYetReached(void)
{
    timer_deadline_reached_fake.return_val = false;

    superloop_run();

    TEST_ASSERT_EQUAL(0, led_toggle_fake.call_count);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_superloop_init_should_initializePeripherals);
    RUN_TEST(test_superloop_run_should_toggleLedIfDeadlineReached);
    RUN_TEST(test_superloop_run_should_notToggleLedIfDeadlineNotYetReached);
    return UNITY_END();
}

#endif // TEST
