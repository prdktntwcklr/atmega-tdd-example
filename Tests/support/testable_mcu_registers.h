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
#define OCIE0B (2U)
#define OCIE0A (1U)
#define TOIE0  (0U)

EXTERN uint8_t TCNT0;

EXTERN uint8_t TCCR0B;
#define FOC0A (7U)
#define FOC0B (6U)
#define WGM02 (3U)
#define CS02  (2U)
#define CS01  (1U)
#define CS00  (0U)

#endif
