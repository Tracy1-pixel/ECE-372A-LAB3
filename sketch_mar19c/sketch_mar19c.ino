// Author:
// Net ID:
// Date:
// Assignment:     Lab 3
//
// Description: This file contains a programmatic overall description of the
// program. It should never contain assignments to special function registers
// for the exception key one-line code such as checking the state of the pin.
//
// Requirements:
//----------------------------------------------------------------------//





#include <avr/io.h>
#include "led.h"
#include "switch.h"
#include "timer.h"
#include "lcd.h"
#include <avr/interrupt.h>
// defines


/*
 * Define a set of states that can be used in the state machine using an enum.
 */
// typedef enum .......


// Initialize states.  Remember to use volatile 
#define SLOW_DELAY 500
#define FAST_DELAY 250


/*
 * Define a set of states that can be used in the state machine using an enum.
 */
// typedef enum .......
typedef enum {SLOW, FAST} State;


// Initialize states.  Remember to use volatile 
volatile State currentState = FAST;
volatile unsigned char buttonPressed = 0;



int main(){

  unsigned char count = 0;

  initTimer1();
  initLCD();
  initSwitchPB3();
  initLED();
  initTimer0();
  sei(); // Enable global interrupts.
  moveCursor(0, 0); // moves the cursor to 0,0 position
  writeString("Current mode: ");
  moveCursor(0, 1);  // moves the cursor to 1,0 position
  writeString("Fast");

// while loop
  while(1){
    turnOnLEDWithChar(count);

    moveCursor(0, 1);
    if(currentState == FAST){
      writeString("Fast");
      writeString("    ");
      delayMs(FAST_DELAY);
    }
    else{
      writeString("Slow");
      writeString("    ");
      delayMs(SLOW_DELAY);
    }

    count++;
    if(count > 15){
      count = 0;
    }
  }
  return 0;
}

/* Implement an Pin Change Interrupt which handles the switch being
* pressed and released. When the switch is pressed and released, the LEDs
* change at twice the original rate. If the LEDs are already changing at twice
* the original rate, it goes back to the original rate.
*/
ISR(PCINT0_vect){
  if(!(PINB & (1 << PB3))){
    buttonPressed = 1;
  }
  else if(buttonPressed){
    if(currentState == FAST){
      currentState = SLOW;
    }
    else{
      currentState = FAST;
    }
    buttonPressed = 0;
  }
}
