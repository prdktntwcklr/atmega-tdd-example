#ifdef UNIT_TESTS

#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"

#define EXTERN

extern "C"
{
    #include "timer.h"
    #include "testable_mcu_registers.h"
}

TEST_GROUP(Timer_Test)
{ 
    void setup()
    {
        TIMSK0 = 0x00;
        TCNT0 = 0x00;
        TCCR0B = 0x00;
    }

    void teardown() 
    {
    }
};

TEST(Timer_Test, TimerInitShouldSetUpRegistersCorrectly)
{
    timer_init();

    LONGS_EQUAL(0x01, TIMSK0);
    LONGS_EQUAL(0x63, TCNT0);
    LONGS_EQUAL(0x03, TCCR0B);
}

TEST(Timer_Test, TimerOverflowIsrShouldIncrementTimeStampBy10)
{
    timer_init();
    LONGS_EQUAL(0, timer_get_stamp());

    testable_isr_timer0_ovf_vect();
    LONGS_EQUAL(10, timer_get_stamp());
}

TEST(Timer_Test, TimerSetStampShouldSetTimeStampCorrectly)
{
    timer_set_stamp(560);
    LONGS_EQUAL(560, timer_get_stamp());

    testable_isr_timer0_ovf_vect();
    LONGS_EQUAL(570, timer_get_stamp());
}

TEST(Timer_Test, TimerDeadlineReachedShouldReturnReachedDeadlinesCorrectly)
{
    timer_set_stamp(200);
    CHECK_FALSE(timer_deadline_reached(250));

    timer_set_stamp(300);
    CHECK(timer_deadline_reached(250));
}

int main(int argc, char** argv)
{
    return RUN_ALL_TESTS(argc, argv);
}

#endif // TEST
