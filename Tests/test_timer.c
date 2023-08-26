/* test_timer.c */

#ifdef TEST

#include "unity.h"

#define EXTERN

#include "testable_mcu_registers.h"
#include "timer.h"
#include "mock_led.h"

void setUp(void)
{
    TIMSK0 = 0x00;
    TCNT0 = 0x00;
    TCCR0B = 0x00;
}

void tearDown(void) {}

void test_timer_init_should_setUpRegistersCorrectly(void)
{
    timer_init();

    TEST_ASSERT_EQUAL_HEX8(0x01, TIMSK0);
    TEST_ASSERT_EQUAL_HEX8(0x63, TCNT0);
    TEST_ASSERT_EQUAL_HEX8(0x03, TCCR0B);
}

void test_timer_overflow_isr_should_incrementTimeStampBy10(void)
{
    timer_init();
    TEST_ASSERT_EQUAL(0, timer_get_stamp());

    testable_isr_timer0_ovf_vect();
    TEST_ASSERT_EQUAL(10, timer_get_stamp());
}

void test_timer_set_stamp_should_setTimeStampCorrectly(void)
{
    timer_set_stamp(560);
    TEST_ASSERT_EQUAL(560, timer_get_stamp());

    testable_isr_timer0_ovf_vect();
    TEST_ASSERT_EQUAL(570, timer_get_stamp());
}

void test_timer_deadline_reached_should_returnReachedDeadlinesCorrectly(void)
{
    timer_set_stamp(200);
    TEST_ASSERT_FALSE(timer_deadline_reached(250));

    timer_set_stamp(300);
    TEST_ASSERT_TRUE(timer_deadline_reached(250));
}

#endif // TEST
