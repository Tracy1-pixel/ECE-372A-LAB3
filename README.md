# ECE 372A Lab 3 ——LCD and LED Control Systems

## Project Overview
This experiment implements an integrated system for LCD display and LED control based on an AVR microcontroller. By utilizing low-level register manipulation (without relying on Arduino libraries), the system performs LCD character display, LED counting control, and key-triggered interrupt switching functions.

The system is capable of adjusting the LED blinking speed in response to key inputs, while simultaneously displaying the current operational status in real-time on the LCD.
---

## Features
- LCD Display Function (Two-line display)
- LED Binary Counting (Cycles from 0 to 15)
- Speed ​​Switching via Key Interrupt (Fast / Slow)
- Microsecond-level Delay Control (for LCD commands)
- Millisecond-level Timing Control (for LED blinking)
- Register-based Low-level Programming (No Arduino libraries used)

---

## System Operation Principles
- LEDs utilize PORTD (PD0–PD3) to output the binary count.
- Key PB3 triggers an interrupt to toggle the counting speed.
- LCD Interface:
- PORTA (PA0–PA3) serves as the data lines.
- PORTB4 (Enable)
- PORTB6 (RS)

The system manages timing via timers and determines the current LED counting rate using a state variable.

---

## Display Content
The LCD displays the following:

First Line: "Current count rate is:"

Second Line: "Fast" or "Slow"

---

## Key Technical Concepts
- Bit Manipulation (Bit Masking / Bit Shifting)
- Interrupt Service Routines (ISR)
- Timer Configuration
- GPIO Control (PORT Operations)
- Embedded Systems Programming (AVR)

---

## File Descriptions
- `main.cpp`: Main program logic
- `lcd.cpp`: Implementation of LCD control functions
- `timer.cpp`: Timer implementation (Microseconds / Milliseconds)
- `switch.cpp`: Switch initialization and interrupt handling
- `led.cpp`: LED control functions

---

## How to Run
1. Open the project in the Arduino IDE / AVR environment.
2. Compile and upload the code to the ATmega2560.
3. Connect the circuit (LCD + LED + Switch).
4. Power on the device to run the program.

---

## Project Requirements Summary
- Use of Arduino libraries is prohibited (with the exception of Serial debugging).
- Specific pins must be used:
- LCD: PORTA + PORTB
- LED: PORTD
- Switch: PB3
- The LCD must correctly display two lines of text.
- Precise timing delays and interrupt control must be implemented.

---

## Author Information
- Name: Changyuan Chen
- Course: ECE 372A
- Lab: Lab 3
