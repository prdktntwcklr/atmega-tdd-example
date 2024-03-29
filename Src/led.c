#include "led.h"

#ifndef TEST
#include "avr/io.h"
#else
#include "testable_mcu_registers.h"
#endif

#define LED_DDR  (DDRD)
#define LED_PORT (PORTD)
#define LED_PIN  (3U)

/**
 * @brief Initializes the LED and defaults to off.
 */
extern void led_init(void)
{
    /* configure LED pin as output */
    LED_DDR |= (1U << LED_PIN);
    led_turn_off();
}

/**
 * @brief Turns the LED on.
 */
extern void led_turn_on(void)
{
    LED_PORT |= (1U << LED_PIN);
}

/**
 * @brief Turns the LED off.
 */
extern void led_turn_off(void)
{
    LED_PORT &= ~(1U << LED_PIN);
}

/**
 * @brief Toggles the LED.
 */
extern void led_toggle(void)
{
    LED_PORT ^= (1U << LED_PIN);
}

/**
 * @brief Returns TRUE if the LED is on.
 */
extern bool led_is_on(void)
{
    return ((LED_PORT) & (1U << LED_PIN));
}

/**
 * @brief Returns TRUE if the LED is off.
 */
extern bool led_is_off(void)
{
    return !(led_is_on());
}
