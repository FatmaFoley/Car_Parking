/*
 * ultrasonic_sensor.c
 *
 *  Created on: Sep 27, 2025
 *      Author: Fatma Foley
 */

#include "ultrasonic_sensor.h"
#include "icu.h"
#include "gpio.h"
#include <avr/delay.h>

// ICU configuration: prescaler F_CPU/8 and trigger on rising edge
ICU_ConfigType icu_config = {F_CPU_8, RAISING};

// Global variables to count edges and store pulse high time
uint8 g_edgeCount = 0;
uint16 g_timeHigh = 0;

// Initialize Ultrasonic sensor driver
void Ultrasonic_init(void)
{
    ICU_init(&icu_config);  // Initialize ICU with specified configuration
    ICU_setCallBack(Ultrasonic_edgeProcessing); // Set callback for ICU interrupt
    // Set ultrasonic trigger pin as output
    GPIO_setupPinDirection(ULTRASONIC_TRIG_PORT_ID, ULTRASONIC_TRIG_PIN_ID, PIN_OUTPUT);
}

// Send trigger pulse to ultrasonic sensor to start measurement
void Ultrasonic_Trigger(void)
{
    GPIO_writePin(ULTRASONIC_TRIG_PORT_ID, ULTRASONIC_TRIG_PIN_ID, LOGIC_LOW);   // Ensure trigger pin low
    _delay_us(10);                                                               // Wait for 10 microseconds
    GPIO_writePin(ULTRASONIC_TRIG_PORT_ID, ULTRASONIC_TRIG_PIN_ID, LOGIC_HIGH);  // Set trigger pin high to start pulse
    _delay_us(10);                                                               // Keep trigger high for 10 microseconds
    GPIO_writePin(ULTRASONIC_TRIG_PORT_ID, ULTRASONIC_TRIG_PIN_ID, LOGIC_LOW);   // Set trigger pin low to finish pulse
}

// Trigger the sensor and return the calculated distance in centimeters
uint16 Ultrasonic_readDistance(void)
{
    Ultrasonic_Trigger();  // Send trigger pulse
    {
        // Convert the high time duration of the echo pulse to distance
        // Formula: distance (cm) = pulse duration / 117.6 + 1 (rounding offset)
        return (uint16)((g_timeHigh / 117.6) + 1);
    }
}

// ICU edge processing callback function called on each edge detected
void Ultrasonic_edgeProcessing(void)
{
    g_edgeCount++;  // Increment edge count on each interrupt

    if(g_edgeCount == 1)
    {
        // First edge detected: rising edge signals start of echo pulse
        ICU_clearTimerValue();          // Reset timer to zero to start measurement
        ICU_setEdgeDetectionType(FALLING);  // Switch to detect falling edge next (end of pulse)
    }
    else if(g_edgeCount == 2)
    {
        // Second edge detected: falling edge signals end of echo pulse
        g_timeHigh = ICU_getInputCaptureValue();  // Capture the duration of the high pulse
        ICU_setEdgeDetectionType(RAISING);        // Reset to detect rising edge for next measurement
        g_edgeCount = 0;                           // Reset edge counter for next measurement cycle
    }
}
