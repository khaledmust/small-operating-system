#include "led.h"
#include "../../mcal/gpio/gpio.h"

/**
 * @brief Initializes the direction of the LED pins as output pins.
 * This is done by using the GPIO_setPinDirection function from the GPIO driver.
 * @param[in] led_name Specifies the LED to be initialized.
 * This parameter can be on of the en_LED_Names enum:
 * - blue
 * - green
 * - red
 * @return LED_STATUS_SUCCESS
 * @return LED_STATUS_FAILED
 */
en_LED_State LED_init(uint8 led_name) {
    switch (led_name) {
        case blue:
            GPIO_setPinDirection(BLUE_LED_PORT_ID, BLUE_LED_PIN_ID, GPIO_PIN_OUTPUT);
            break;
        case green:
            GPIO_setPinDirection(GREEN_LED_PORT_ID, GREEN_LED_PIN_ID, GPIO_PIN_OUTPUT);
            break;
        case red:
            GPIO_setPinDirection(RED_LED_PORT_ID, RED_LED_PIN_ID, GPIO_PIN_OUTPUT);
            break;
        default:
            return LED_STATUS_FAILED;
    }
    return LED_STATUS_SUCCESS;
}

/**
 * @brief Turns on the specified LED.
 * This is done by using the GPIO_writePin function from the GPIO driver.
 * @param led_name Specifies the LED to be initialized.
 * This parameter can be on of the en_LED_Names enum:
 * - blue
 * - green
 * - red
 * @return LED_STATUS_SUCCESS
 * @return LED_STATUS_FAILED
 */
en_LED_State LED_on(uint8 led_name) {
    switch (led_name) {
        case blue:
            GPIO_writePin(BLUE_LED_PORT_ID, BLUE_LED_PIN_ID, GPIO_PIN_HIGH);
            break;
        case green:
            GPIO_writePin(GREEN_LED_PORT_ID, GREEN_LED_PIN_ID, GPIO_PIN_HIGH);
            break;
        case red:
            GPIO_writePin(RED_LED_PORT_ID, RED_LED_PIN_ID, GPIO_PIN_HIGH);
            break;
        default:
            return LED_STATUS_FAILED;
    }
    return LED_STATUS_SUCCESS;
}

/**
 * @brief Turns off the specified LED.
 * This is done by using the GPIO_writePin function from the GPIO driver.
 * @param led_name Specifies the LED to be initialized.
 * This parameter can be on of the en_LED_Names enum:
 * - blue
 * - green
 * - red
 * @return LED_STATUS_SUCCESS
 * @return LED_STATUS_FAILED
 */
en_LED_State LED_off(uint8 led_name) {
    switch (led_name) {
        case blue:
            GPIO_writePin(BLUE_LED_PORT_ID, BLUE_LED_PIN_ID, GPIO_PIN_LOW);
            break;
        case green:
            GPIO_writePin(GREEN_LED_PORT_ID, GREEN_LED_PIN_ID, GPIO_PIN_LOW);
            break;
        case red:
            GPIO_writePin(RED_LED_PORT_ID, RED_LED_PIN_ID, GPIO_PIN_LOW);
            break;
        default:
            return LED_STATUS_FAILED;
    }
    return LED_STATUS_SUCCESS;
}

/**
 *
 * @param led_name Toggles the state of the specified LED.
 * This is done by using the GPIO_togglePin function from the GPIO driver.
 * @return Specifies the LED to be initialized.
 * This parameter can be on of the en_LED_Names enum:
 * - blue
 * - green
 * - red
 *  @return LED_STATUS_SUCCESS
 * @return LED_STATUS_FAILED
 */
en_LED_State LED_toggle(uint8 led_name) {
    switch (led_name) {
        case blue:
            GPIO_togglePin(BLUE_LED_PORT_ID, BLUE_LED_PIN_ID);
            break;
        case green:
            GPIO_togglePin(GREEN_LED_PORT_ID, GREEN_LED_PIN_ID);
            break;
        case red:
            GPIO_togglePin(RED_LED_PORT_ID, RED_LED_PIN_ID);
            break;
        default:
            return LED_STATUS_FAILED;
    }
    return LED_STATUS_SUCCESS;
}