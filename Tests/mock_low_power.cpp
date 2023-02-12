#include "CppUTestExt/MockSupport.h"

extern "C"
{
    #include "low_power.h"
}

void low_power_init()
{
    mock().actualCall("low_power_init");
}

void low_power_enter()
{
    mock().actualCall("low_power_enter");
}
