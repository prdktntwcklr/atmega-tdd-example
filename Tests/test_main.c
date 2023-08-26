/* test_main.c */

#ifdef TEST

#include "unity.h"

#include "main.h"
#include "mock_low_power.h"
#include "mock_superloop.h"

void setUp(void) {}

void tearDown(void) {}

void test_main_should_initPeripheralsThenRunMainLoop(void)
{
    superloop_init_Expect();
    low_power_init_Expect();
    low_power_enter_Ignore();

    superloop_run_ExpectAndReturn(true);
    superloop_run_ExpectAndReturn(true);
    superloop_run_ExpectAndReturn(false);

    TEST_ASSERT_EQUAL(0, testable_main());
}

#endif // TEST
