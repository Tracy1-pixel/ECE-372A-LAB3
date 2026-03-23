// Author: 
// Net ID: 
// Date: 
// Assignment: Lab 3
//----------------------------------------------------------------------//

#include "timer.h"
//You many use any timer you wish for the microsecond delay and the millisecond delay


/* Initialize timer 1, you should not turn the timer on here. Use CTC mode  .*/
void initTimer1(){
  TCCR1A = 0x00;              // Normal port operation
  TCCR1B = (1 << WGM12);      // CTC mode (TOP = OCR1A)
  TCNT1 = 0x0000;             
}

/* This delays the program an amount of microseconds specified by unsigned int delay.
*/
void delayUs(unsigned int delay){
  for (unsigned int i = 0; i < delay; i++) {
    TCNT1 = 0;
    OCR1A = 16;                      // 1us @ 16MHz with prescaler = 1
    TCCR1B |= (1 << CS10);           // Start timer (prescaler = 1)

    while (!(TIFR1 & (1 << OCF1A))); // Wait until compare match

    TCCR1B &= ~(1 << CS10);          // Stop timer
    TIFR1 |= (1 << OCF1A);           // Clear flag
  }
}

/* Initialize timer 0, you should not turn the timer on here.
* You will need to use CTC mode */
void initTimer0(){
  TCCR0A = (1 << WGM01);     // CTC mode
  TCCR0B = 0x00;             // Timer stopped
  TCNT0 = 0x00;
}

/* This delays the program an amount specified by unsigned int delay.
* Use timer 0. Keep in mind that you need to choose your prescalar wisely
* such that your timer is precise to 1 millisecond and can be used for
* 100-2000 milliseconds
*/
void delayMs(unsigned int delay){
   for (unsigned int i = 0; i < delay; i++) {
    TCNT0 = 0;
    OCR0A = 249;                     // 1ms @ 16MHz with prescaler = 64
    TCCR0B = (1 << CS01) | (1 << CS00); // Start timer (prescaler = 64)

    while (!(TIFR0 & (1 << OCF0A))); // Wait for compare match

    TCCR0B = 0x00;                  // Stop timer
    TIFR0 |= (1 << OCF0A);          // Clear flag
  }
}