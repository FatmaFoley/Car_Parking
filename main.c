/*
 * main.c
 *
 *  Created on: Sep 27, 2025
 *      Author: Fatma Foley
 */

#include "buzzer.h"
#include "lcd.h"
#include "leds.h"
#include "std_types.h"
#include "ultrasonic_sensor.h"
#include <avr/io.h>
#include <avr/delay.h>

// Global variable to store the measured distance from the ultrasonic sensor
uint16 g_distance;

int main()
{
    // Initialize peripherals
    Buzzer_init();
    LCD_init();
    LEDS_init();
    Ultrasonic_init();

    /* Enable Global Interrupt I-Bit (bit 7 in SREG) for ICU operation */
    SREG |= (1 << 7);

    while(1)
    {
        // Display label "Distance=" at row 0, column 0 on LCD
        LCD_displayStringRowColumn(0, 0, "Distance=");

        // Get distance reading from ultrasonic sensor
        g_distance = Ultrasonic_readDistance();

        // Move cursor to row 0, column 9 to display distance value
        LCD_moveCursor(0, 9);

        // Display the distance integer value on LCD
        LCD_intgerToString(g_distance);

        // Formatting spaces for alignment depending on distance digits
        if ((g_distance >= 10) && (g_distance < 100))
        {
            LCD_displayStringRowColumn(0, 11, " ");
        }
        else if (g_distance < 10)
        {
            LCD_displayStringRowColumn(0, 10, "  ");
        }

        // Display unit "cm" after the distance value
        LCD_displayString("cm");

        // Control LEDs and buzzer based on distance ranges

        if (g_distance > 20)
        {
            // Distance greater than 20 cm: all LEDs off, buzzer off, clear second line on LCD
            LED_off(LEDS_RED_LED_ID);
            LED_off(LEDS_GREEN_LED_ID);
            LED_off(LEDS_BLUE_LED_ID);
            Buzzer_off();
            LCD_displayStringRowColumn(1, 6, "    ");
        }
        else if (g_distance >= 16)
        {
            // Distance between 16 and 20 cm: only red LED on, buzzer off, clear second line
            LED_on(LEDS_RED_LED_ID);
            LED_off(LEDS_GREEN_LED_ID);
            LED_off(LEDS_BLUE_LED_ID);
            Buzzer_off();
            LCD_displayStringRowColumn(1, 6, "    ");
        }
        else if (g_distance >= 11)
        {
            // Distance between 11 and 15 cm: red and green LEDs on, blue LED off, buzzer off, clear line
            LED_on(LEDS_RED_LED_ID);
            LED_on(LEDS_GREEN_LED_ID);
            LED_off(LEDS_BLUE_LED_ID);
            Buzzer_off();
            LCD_displayStringRowColumn(1, 6, "    ");
        }
        else if (g_distance >= 6)
        {
            // Distance between 6 and 10 cm: all three LEDs on, buzzer off, clear line
            LED_on(LEDS_RED_LED_ID);
            LED_on(LEDS_GREEN_LED_ID);
            LED_on(LEDS_BLUE_LED_ID);
            Buzzer_off();
            LCD_displayStringRowColumn(1, 6, "    ");
        }
        else
        {
            // Distance less than 6 cm: sound buzzer, show "Stop" message, blink all LEDs
            Buzzer_on();
            LCD_displayStringRowColumn(1, 6, "Stop");
            LED_on(LEDS_RED_LED_ID);
            LED_on(LEDS_GREEN_LED_ID);
            LED_on(LEDS_BLUE_LED_ID);
            _delay_ms(1000);
            LED_off(LEDS_RED_LED_ID);
            LED_off(LEDS_GREEN_LED_ID);
            LED_off(LEDS_BLUE_LED_ID);
            _delay_ms(1000);
        }
    }
}
