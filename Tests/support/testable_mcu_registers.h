/* testable_mcu_registers.h */

#ifndef TESTABLE_MCU_REGISTERS_H
#define TESTABLE_MCU_REGISTERS_H

#include "stdint.h"

#ifndef EXTERN
#define EXTERN extern
#endif

EXTERN uint8_t DDRD;
EXTERN uint8_t PORTD;

EXTERN uint8_t TIMSK0;
#define OCIE0B  2
#define OCIE0A  1
#define TOIE0   0

EXTERN uint8_t TCNT0;

EXTERN uint8_t TCCR0B;
#define FOC0A   7
#define FOC0B   6
#define WGM02   3
#define CS02    2
#define CS01    1
#define CS00    0

#endif
