/*
 * leds.c
 *
 *  Created on: Sep 22, 2025
 *      Author: Fatma Foley
 */

/******************************************************************************
 *                             Include Files                                   *
 ******************************************************************************/


#include "leds.h"
#include "gpio.h"

/*
 * Function: LEDS_init
 * -------------------
 * Configures the red, green, and blue LED pins as output pins and
 * ensures all LEDs are initially turned off.
 */
void LEDS_init(void)
{
    /* Set direction of all LED pins as output */
    GPIO_setupPinDirection(LEDS_RED_LED_PORT_ID, LEDS_RED_LED_PIN_ID, PIN_OUTPUT);
    GPIO_setupPinDirection(LEDS_GREEN_LED_PORT_ID, LEDS_GREEN_LED_PIN_ID, PIN_OUTPUT);
    GPIO_setupPinDirection(LEDS_BLUE_LED_PORT_ID, LEDS_BLUE_LED_PIN_ID, PIN_OUTPUT);

    /* Turn off all LEDs initially (logic level for OFF) */
    GPIO_writePin(LEDS_RED_LED_PORT_ID, LEDS_RED_LED_PIN_ID, LEDS_LED_OFF);
    GPIO_writePin(LEDS_GREEN_LED_PORT_ID, LEDS_GREEN_LED_PIN_ID, LEDS_LED_OFF);
    GPIO_writePin(LEDS_BLUE_LED_PORT_ID, LEDS_BLUE_LED_PIN_ID, LEDS_LED_OFF);
}

/*
 * Function: LED_on
 * ----------------
 * Turns on the specified LED by setting its pin to the configured ON logic level.
 *
 *  id: The ID identifying which LED to turn on (red, green, or blue).
 */
void LED_on(LED_ID id)
{
    switch(id)
    {
        case LEDS_RED_LED_ID:
            GPIO_writePin(LEDS_RED_LED_PORT_ID, LEDS_RED_LED_PIN_ID, LEDS_LED_ON);
            break;
        case LEDS_GREEN_LED_ID:
            GPIO_writePin(LEDS_GREEN_LED_PORT_ID, LEDS_GREEN_LED_PIN_ID, LEDS_LED_ON);
            break;
        case LEDS_BLUE_LED_ID:
            GPIO_writePin(LEDS_BLUE_LED_PORT_ID, LEDS_BLUE_LED_PIN_ID, LEDS_LED_ON);
            break;
    }
}

/*
 * Function: LED_off
 * -----------------
 * Turns off the specified LED by setting its pin to the configured OFF logic level.
 *
 *  id: The ID identifying which LED to turn off (red, green, or blue).
 */
void LED_off(LED_ID id)
{
    switch(id)
    {
        case LEDS_RED_LED_ID:
            GPIO_writePin(LEDS_RED_LED_PORT_ID, LEDS_RED_LED_PIN_ID, LEDS_LED_OFF);
            break;
        case LEDS_GREEN_LED_ID:
            GPIO_writePin(LEDS_GREEN_LED_PORT_ID, LEDS_GREEN_LED_PIN_ID, LEDS_LED_OFF);
            break;
        case LEDS_BLUE_LED_ID:
            GPIO_writePin(LEDS_BLUE_LED_PORT_ID, LEDS_BLUE_LED_PIN_ID, LEDS_LED_OFF);
            break;
    }
}
