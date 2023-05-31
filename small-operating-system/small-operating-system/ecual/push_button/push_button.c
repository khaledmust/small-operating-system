#include "push_button.h"
#include "../../mcal/gpio/gpio.h"

/**
 * @brief Initializes the direction of the PB pins as input pins.
 * This is done by using the GPIO_setPinDirection function from the GPIO driver
 * @param[in] pb_name Specifies the PB to be initialized.
 * This parameter can be on of the en_PB_Names enum:
 * - PB1
 * - PB2
 * - PB3
 * - PB4
 * @return PB_STATUS_SUCCESS
 * @return PB_STATUS_FAILED
 */
en_PB_State PB_init(en_PB_Names pb_name) {
    switch (pb_name) {
        case PB1:
            GPIO_setPinDirection(PB1_PORT_ID, PB1_PIN_ID, GPIO_PIN_INPUT);
            break;
        case PB2:
            GPIO_setPinDirection(PB2_PORT_ID, PB2_PIN_ID, GPIO_PIN_INPUT);
            break;
        case PB3:
            GPIO_setPinDirection(PB3_PORT_ID, PB3_PIN_ID, GPIO_PIN_INPUT);
            break;
        case PB4:
            GPIO_setPinDirection(PB4_PORT_ID, PB4_PIN_ID, GPIO_PIN_INPUT);
            break;
        default:
            return PB_STATUS_FAILED;
    }
    return PB_STATUS_SUCCESS;
}

/**
 * @brief Reads the current status of the push button and stores it in the supplied pointer.
 * This is done by using the GPIO_readPin function from the GPIO driver
 * @param[in] pb_name Specifies the PB to be initialized.
 * This parameter can be on of the en_PB_Names enum:
 * - PB1
 * - PB2
 * - PB3
 * - PB4
 * @param[out] p_pb_status A pointer to the variable where the state of the push button is stored.
 * @return PB_STATUS_SUCCESS
 * @return PB_STATUS_FAILED
 */
en_PB_State PB_status(en_PB_Names pb_name, uint8 *p_pb_status) {
    switch (pb_name) {
        case PB1:
            GPIO_readPin(PB1_PORT_ID, PB1_PIN_ID, p_pb_status);
            break;
        case PB2:
            GPIO_readPin(PB2_PORT_ID, PB2_PIN_ID, p_pb_status);
            break;
        case PB3:
            GPIO_readPin(PB3_PORT_ID, PB3_PIN_ID, p_pb_status);
            break;
        case PB4:
            GPIO_readPin(PB4_PORT_ID, PB4_PIN_ID, p_pb_status);
            break;
        default:
            return PB_STATUS_FAILED;
    }
    return PB_STATUS_SUCCESS;
}