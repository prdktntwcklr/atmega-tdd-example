/* test_led.c */

#ifdef TEST

#include "unity.h"

#define EXTERN

#include "testable_mcu_registers.h"
#include "led.h"

void setUp(void)
{
    /* reset data direction and port registers */
    DDRD = 0x00;
    PORTD = 0x00;
}

void tearDown(void) {}

void test_led_ledInitShouldSetCorrectLedAsOutputAndTurnLedOff(void)
{
    led_init();
    TEST_ASSERT_EQUAL_HEX8(0x08, DDRD);
    TEST_ASSERT_EQUAL_HEX8(0x00, PORTD);

    DDRD = 0x55;
    PORTD = 0x55;
    led_init();
    TEST_ASSERT_EQUAL_HEX8(0x5D, DDRD);
    TEST_ASSERT_EQUAL_HEX8(0x55, PORTD);

    DDRD = 0xFF;
    PORTD = 0xFF;
    led_init();
    TEST_ASSERT_EQUAL_HEX8(0xFF, DDRD);
    TEST_ASSERT_EQUAL_HEX8(0xF7, PORTD);
}

void test_led_shouldTurnOnAndOffCorrectly(void)
{
    led_turn_on();
    TEST_ASSERT_EQUAL_HEX8(0x08, PORTD);
    led_turn_off();
    TEST_ASSERT_EQUAL_HEX8(0x00, PORTD);

    PORTD = 0x4A;
    led_turn_on();
    TEST_ASSERT_EQUAL_HEX8(0x4A, PORTD);
    led_turn_off();
    TEST_ASSERT_EQUAL_HEX8(0x42, PORTD);
}

void test_led_ledToggleShouldToggleLedCorrectly(void)
{
    led_toggle();
    TEST_ASSERT_EQUAL_HEX8(0x08, PORTD);

    led_toggle();
    TEST_ASSERT_EQUAL_HEX8(0x00, PORTD);

    PORTD = 0x37;
    led_toggle();
    TEST_ASSERT_EQUAL_HEX8(0x3F, PORTD);

    led_toggle();
    TEST_ASSERT_EQUAL_HEX8(0x37, PORTD);
}

void test_led_shouldReportOnOffStateCorrectly(void)
{
    led_init();
    TEST_ASSERT_TRUE(led_is_off());

    led_turn_on();
    TEST_ASSERT_TRUE(led_is_on());

    led_toggle();
    TEST_ASSERT_TRUE(led_is_off());
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_led_ledInitShouldSetCorrectLedAsOutputAndTurnLedOff);
    RUN_TEST(test_led_shouldTurnOnAndOffCorrectly);
    RUN_TEST(test_led_ledToggleShouldToggleLedCorrectly);
    RUN_TEST(test_led_shouldReportOnOffStateCorrectly);
    return UNITY_END();
}

#endif // TEST
