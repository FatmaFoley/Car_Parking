/*
 * ultrasonic_sensor.h
 *
 *  Created on: Sep 27, 2025
 *      Author: Fatma Foley
 */

#ifndef ULTRASONIC_SENSOR_H_
#define ULTRASONIC_SENSOR_H_

#include "std_types.h"

// Global variable to hold the measured distance value
extern uint16 g_distance;

// Definitions for the ultrasonic sensor trigger and echo pins and ports
#define ULTRASONIC_TRIG_PORT_ID        PORTD_ID
#define ULTRASONIC_TRIG_PIN_ID         PIN7_ID
#define ULTRASONIC_ECO_PORT_ID         PORTD_ID
#define ULTRASONIC_ECO_PIN_ID          PIN6_ID

// Speed of sound in cm/microsecond used for distance calculation
#define SOUND_WAVE_SPEED               0.0343  /* cm/usec */

// Function prototypes for ultrasonic sensor operations

// Initialize the ultrasonic sensor hardware and ICU driver
void Ultrasonic_init(void);

// Send trigger pulse to start ultrasonic measurement
void Ultrasonic_Trigger(void);

// Read and return the distance measured by the ultrasonic sensor in cm
uint16 Ultrasonic_readDistance(void);

// ICU interrupt callback to process signal edges (rising/falling) from the echo pin
void Ultrasonic_edgeProcessing(void);

#endif /* ULTRASONIC_SENSOR_H_ */
