#ifndef LED_H_
#define LED_H_
#include "../../utilities/registers.h"

/**
 * @defgroup LED_PORT_PIN_CONFIGURATION
 * @{
 */
#define BLUE_LED_PORT_ID    PORTC_ID ///< The port ID where the blue LED is connected to.
#define BLUE_LED_PIN_ID     PIN2_ID ///< The pin number where the blue LED is connected to.

#define GREEN_LED_PORT_ID   PORTC_ID ///< The port ID where the green LED is connected to.
#define GREEN_LED_PIN_ID    PIN1_ID ///< The pin number where the green LED is connected to.

#define RED_LED_PORT_ID     PORTC_ID ///< The port ID where the red LED is connected to.
#define RED_LED_PIN_ID      PIN0_ID ///< The pin number where the red LED is connected to.
/**@}*/

/**
 * @enum en_LED_Names
 * @brief Specifies the names of the connected LEDs.
 */
typedef enum {
    blue, green, red
}en_LED_Names;

/**
 * @enum en_LED_State
 * @brief Specifies the exit state of LED driver functions.
 */
typedef enum {
    LED_STATUS_SUCCESS, LED_STATUS_FAILED
}en_LED_State;

/**
 * @brief Initializes the direction of the LED pins as output pins.
 * @param[in] led_name Specifies the LED to be initialized.
 * This parameter can be on of the en_LED_Names enum:
 * - blue
 * - green
 * - red
 * @return LED_STATUS_SUCCESS
 * @return LED_STATUS_FAILED
 */
en_LED_State LED_init(en_LED_Names led_name);

/**
 * @brief Turns on the specified LED.
 * @param led_name Specifies the LED to be initialized.
 * This parameter can be on of the en_LED_Names enum:
 * - blue
 * - green
 * - red
 * @return LED_STATUS_SUCCESS
 * @return LED_STATUS_FAILED
 */
en_LED_State LED_on(en_LED_Names led_name);

/**
 * @brief Turns off the specified LED.
 * @param led_name Specifies the LED to be initialized.
 * This parameter can be on of the en_LED_Names enum:
 * - blue
 * - green
 * - red
 * @return LED_STATUS_SUCCESS
 * @return LED_STATUS_FAILED
 */
en_LED_State LED_off(en_LED_Names led_name);

/**
 *
 * @param led_name Toggles the state of the specified LED.
 * @return Specifies the LED to be initialized.
 * This parameter can be on of the en_LED_Names enum:
 * - blue
 * - green
 * - red
 *  @return LED_STATUS_SUCCESS
 * @return LED_STATUS_FAILED
 */
en_LED_State LED_toggle(en_LED_Names led_name);

#endif /* LED_H_ */