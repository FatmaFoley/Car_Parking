/*
 * leds.h
 *
 *  Created on: Sep 22, 2025
 *      Author: Fatma Foley
 */

#ifndef LEDS_H_
#define LEDS_H_

/******************************************************************************
 *                             Include Files                                   *
 ******************************************************************************/


#include "std_types.h"


/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/* Define ports and pins connected to the LEDs */
#define LEDS_RED_LED_PORT_ID              PORTC_ID
#define LEDS_RED_LED_PIN_ID               PIN0_ID
#define LEDS_GREEN_LED_PORT_ID            PORTC_ID
#define LEDS_GREEN_LED_PIN_ID             PIN1_ID
#define LEDS_BLUE_LED_PORT_ID             PORTC_ID
#define LEDS_BLUE_LED_PIN_ID              PIN2_ID

/* Define IDs used to identify the LEDs in functions */
#define LEDS_RED_LED_ID                   (1u)
#define LEDS_GREEN_LED_ID                 (2u)
#define LEDS_BLUE_LED_ID                  (3u)

/* Define logic levels to turn the LEDs off and on */
#define LEDS_LED_OFF                     LOGIC_LOW
#define LEDS_LED_ON                      LOGIC_HIGH

/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/

/* LED_ID type used to identify specific LEDs */
typedef unsigned char LED_ID;

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/*
 * Initializes all LEDs (red, green, blue) pins as output and turns them off.
 */
void LEDS_init(void);

/*
 * Turns on the specified LED.
 * Parameters:
 *   id - The LED identifier (LEDS_RED_LED_ID, LEDS_GREEN_LED_ID, or LEDS_BLUE_LED_ID)
 */
void LED_on(LED_ID id);

/*
 * Turns off the specified LED.
 * Parameters:
 *   id - The LED identifier (LEDS_RED_LED_ID, LEDS_GREEN_LED_ID, or LEDS_BLUE_LED_ID)
 */
void LED_off(LED_ID id);

#endif /* LEDS_H_ */
