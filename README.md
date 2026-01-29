🚗 Car Parking Sensor System
📌 Project Overview

This project implements a Car Parking Sensor System using an ATmega32 microcontroller.
The system helps drivers park safely by measuring the distance between the vehicle and nearby obstacles using an ultrasonic sensor, then providing visual and audio feedback through LEDs, LCD, and a buzzer.

🎯 Project Objective

Measure distance between the car and obstacles

Display distance in real-time on LCD

Provide visual warnings using LEDs

Activate buzzer when object is too close

Improve parking safety using embedded systems

⚙️ System Features
🔹 Distance Measurement

Uses HC-SR04 Ultrasonic Sensor

Calculates distance using echo pulse timing

Distance displayed in centimeters on LCD

🔹 Visual Indicators (LEDs)
Distance	LED Behavior
≤ 5 cm	All LEDs blinking
6 – 10 cm	Red + Green + Blue ON
11 – 15 cm	Red + Green ON
16 – 20 cm	Red ON
> 20 cm	All LEDs OFF
🔹 Buzzer Alert

Activated when distance ≤ 5 cm

Warns driver to stop immediately

🔹 LCD Display

Displays measured distance

Displays "STOP" when distance ≤ 5 cm

🧰 Hardware Components

ATmega32 Microcontroller

HC-SR04 Ultrasonic Sensor

16×2 LCD Display

Red, Green, Blue LEDs

Buzzer

Connecting Wires

🔌 Pin Configuration
LCD (4-bit Mode)
LCD Pin	MCU Pin
RS	PA1
EN	PA2
D4–D7	PA3 – PA6
RW	GND
Ultrasonic Sensor
Signal	Pin
Trigger	PD7
Echo	PD6
LEDs
LED	Pin
Red	PC0
Green	PC1
Blue	PC2
Buzzer
Device	Pin
Buzzer	PC5
🧠 System Operation

Ultrasonic sensor sends trigger pulse

Echo time is measured using ICU

Distance is calculated

LCD displays distance

LEDs and buzzer react according to distance

System updates continuously

🧩 Software Architecture

✔ Layered Architecture

Application Layer

HAL Layer

MCAL Layer

🧪 Drivers Used

GPIO Driver

ICU Driver

Ultrasonic Driver

LCD Driver

Buzzer Driver

⚡ System Requirements

Microcontroller: ATmega32

Clock Frequency: 16 MHz

LCD Mode: 4-bit

Programming Language: Embedded C

🎥 Reference Video

https://youtu.be/bhtyP1ZBiJg

👩‍💻 Author

Fatma Foley
Embedded Systems – Mini Project
Car Parking Sensor System

📌 Notes

Project follows embedded layered architecture

ICU is used for accurate distance measurement

Suitable for learning real-time embedded systems

✨ Feel free to fork, modify, or improve the project
