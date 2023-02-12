#ifdef UNIT_TESTS

#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTestExt/MockSupport.h"

extern "C"
{
    #include "superloop.h"
}

TEST_GROUP(Superloop_Test)
{ 
    void setup()
    {
    }

    void teardown() 
    {
        mock().checkExpectations();
        mock().clear();
    }
};

TEST(Superloop_Test, SuperloopInitShouldInitializePeripherals)
{
    mock().expectOneCall("led_init");
    mock().expectOneCall("timer_init");
    superloop_init();
}

TEST(Superloop_Test, SuperloopRunShouldToggleLedIfDeadlineReached)
{
    mock().expectOneCall("timer_deadline_reached").withParameter("deadline", 0).andReturnValue(false);
    
    superloop_run();

    mock().expectOneCall("timer_deadline_reached").withParameter("deadline", 0).andReturnValue(true);
    mock().expectOneCall("led_toggle");

    superloop_run();
}

int main(int argc, char** argv)
{
    return RUN_ALL_TESTS(argc, argv);
}

#endif // UNIT_TESTS
