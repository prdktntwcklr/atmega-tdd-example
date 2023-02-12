#include "CppUTestExt/MockSupport.h"

extern "C"
{
    #include "superloop.h"
}

void superloop_init()
{
    mock().actualCall("superloop_init");
}

bool superloop_run()
{
    return mock().actualCall("superloop_run")
        .returnBoolValue();   
}
