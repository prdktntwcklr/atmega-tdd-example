#ifndef TESTABLE_MICRO_REGISTERS_H
#define TESTABLE_MICRO_REGISTERS_H

#include "stdint.h"

#ifndef EXTERN
#define EXTERN extern
#endif

EXTERN uint8_t DDRD;
EXTERN uint8_t PORTD;

#define DDD3 3
#define PD3 3

#endif