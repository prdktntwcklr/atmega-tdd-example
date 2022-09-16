#ifdef TEST

#include "unity.h"

#include "led.h"

extern uint8_t DDRD;
extern uint8_t PORTD;

void setUp(void)
{
}

void tearDown(void)
{
}

void test_led_ledInitShouldSetCorrectLedAsOutput(void)
{
    DDRD = 0x00;
    led_init();
    TEST_ASSERT_EQUAL_HEX8(0x08, DDRD);

    DDRD = 0x55;
    led_init();
    TEST_ASSERT_EQUAL_HEX8(0x5D, DDRD);

    DDRD = 0xFF;
    led_init();
    TEST_ASSERT_EQUAL_HEX8(0xFF, DDRD);
}

void test_led_ledToggleShouldToggleLedCorrectly(void)
{
    PORTD = 0x00;
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

#endif // TEST
