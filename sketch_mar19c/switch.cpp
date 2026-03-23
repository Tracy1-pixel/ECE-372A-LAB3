// Description: This file implements the initialization of an external
// switch.
//----------------------------------------------------------------------//

#include "switch.h"
#include <avr/io.h>

/*
 * Initializes pull-up resistor on PB3 and sets it into input mode
 */
void initSwitchPB3(){
  DDRB &= ~(1 << PB3);   // PB3 be the ibput
  PORTB |= (1 << PB3);   // pull-up 

  PCICR |= (1 << PCIE0);     
  PCMSK0 |= (1 << PCINT3);   
}