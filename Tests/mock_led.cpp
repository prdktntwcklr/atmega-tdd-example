#include "CppUTestExt/MockSupport.h"

extern "C"
{
    #include "led.h"
}

void led_init()
{
    mock().actualCall("led_init");
}

void led_toggle()
{
	mock().actualCall("led_toggle");
}
