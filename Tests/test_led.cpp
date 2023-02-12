#ifdef UNIT_TESTS

#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"

#define EXTERN

extern "C"
{
    #include "testable_mcu_registers.h"
    #include "led.h"
}

TEST_GROUP(Led_Test)
{ 
    void setup()
    {
        /* reset data direction and port registers */
        DDRD = 0x00;
        PORTD = 0x00;
    }

    void teardown() 
    {
    }
};

TEST(Led_Test, LedInitShouldSetCorrectLedAsOutputAndTurnLedOff)
{
    led_init();
    LONGS_EQUAL(0x08, DDRD);
    LONGS_EQUAL(0x00, PORTD);

    DDRD = 0x55;
    PORTD = 0x55;
    led_init();
    LONGS_EQUAL(0x5D, DDRD);
    LONGS_EQUAL(0x55, PORTD);

    DDRD = 0xFF;
    PORTD = 0xFF;
    led_init();
    LONGS_EQUAL(0xFF, DDRD);
    LONGS_EQUAL(0xF7, PORTD);
}

TEST(Led_Test, ShouldTurnOnAndOffCorrectly)
{
    led_turn_on();
    LONGS_EQUAL(0x08, PORTD);
    led_turn_off();
    LONGS_EQUAL(0x00, PORTD);

    PORTD = 0x4A;
    led_turn_on();
    LONGS_EQUAL(0x4A, PORTD);
    led_turn_off();
    LONGS_EQUAL(0x42, PORTD);    
}

TEST(Led_Test, LedToggleShouldToggleLedCorrectly)
{
    led_toggle();
    LONGS_EQUAL(0x08, PORTD);

    led_toggle();
    LONGS_EQUAL(0x00, PORTD);

    PORTD = 0x37;
    led_toggle();
    LONGS_EQUAL(0x3F, PORTD);

    led_toggle();
    LONGS_EQUAL(0x37, PORTD);    
}

TEST(Led_Test, ShouldReportOnOffStateCorrectly)
{
    led_init();
    CHECK(led_is_off());
    
    led_turn_on();
    CHECK(led_is_on());
    
    led_toggle();
    CHECK(led_is_off());
}

int main(int argc, char** argv)
{
    return RUN_ALL_TESTS(argc, argv);
}

#endif // UNIT_TESTS
