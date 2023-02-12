#ifdef UNIT_TESTS

#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTestExt/MockSupport.h"

#define EXTERN

extern "C"
{
    #include "main.h"
}

TEST_GROUP(Main_Test)
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

void setUp(void)
{
}

void tearDown(void)
{
}

TEST(Main_Test, MainShouldInitPeripheralsThenRunMainLoop)
{
    mock().expectOneCall("superloop_init");
    mock().expectOneCall("low_power_init");
    
    mock().expectOneCall("superloop_run").andReturnValue(false);

    LONGS_EQUAL(0, testable_main());
}

int main(int argc, char** argv)
{
    return RUN_ALL_TESTS(argc, argv);
}

#endif // TEST
