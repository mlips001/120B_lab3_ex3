/*	Author: mlips001
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;

	unsigned char tempA = 0x00;
	unsigned char tempC = 0x00;
	unsigned char tempAB = 0x00;

    /* Insert your solution below */
    while (1) {
 		tempC= 0x00;
		tempA = PINA & 0x0F;
		tempAB = PINA & 0x70;

		if(tempA == 1 || tempA == 2){
			tempC = 0x20 | 0x40;
		}

		else if(tempA == 3 || tempA == 4){
			tempC = 0x30 | 0x40;
		}

		else if(tempA == 5 || tempA == 6){
			tempC = 0x38;
		}

		else if(tempA == 7 || tempA == 8 || tempA == 9){
			tempC = 0x3C;
		}

		else if(tempA == 10 || tempA == 11 || tempA == 12){
			tempC = 0x3E;
		}

		else if(tempA == 13 || tempA == 14 || tempA == 15){
			tempC = 0x3F;
		}
		else{
			tempC = 0x40;
		}
		tempAB = tempAB >> 4;

		if(tempAB == 3){
			tempC = tempC | 0x80;

		}

		PORTC = tempC;
	
    }
    return 1;
}
