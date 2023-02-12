#include "CppUTestExt/MockSupport.h"

extern "C"
{
    #include "timer.h"
}

void timer_init()
{
    mock().actualCall("timer_init");
}

uint16_t timer_get_stamp()
{
    return mock().actualCall("timer_get_stamp")
        .returnUnsignedIntValue(); 
}

bool timer_deadline_reached(uint16_t deadline)
{
    return mock().actualCall("timer_deadline_reached")
        .withParameter("deadline", deadline)
        .returnBoolValue();    
}
