/*
 * shaker.cpp
 *
 *  Created on: May 8, 2016
 *      Author: Michael Jaradah
 */


#include "utilities.h"
//#include <stdio.h>
#include "shaker.hpp"
#include "lpc_pwm.hpp"


void shaker::shakePattern(vibration_t name){

	// Declare our pattern selection variable and initialize to the users desired state
	vibration_t patternSelect = name;

	//Enabling the PWM for the PWM Pin2.1
	//Setting the name of the shaker puck to "Puck"
	PWM puck(PWM::pwm1, 55);

	/*
	 * Switch case statement for the selection of the vibration patterns
	 * Possible cases are: SOS, pulse, longVib, shortVib, random, classical
	 * If a selection is made that does not exist, an error message is displayed
	 */
	switch(patternSelect)
	{
	case SOS:
		for(int i=0; i<3; i++){
			puck.set(55);
			delay_ms(100);
			puck.set(0);
			delay_ms(100);
		}
		delay_ms(400);

		for(int i=0; i<3; i++){
			puck.set(55);
			delay_ms(500);
			puck.set(0);
			delay_ms(200);
		}

		for(int i=0; i<3; i++){
			puck.set(55);
			delay_ms(100);
			puck.set(0);
			delay_ms(100);
		}
		break;

	case pulse:
		for(int i=0; i<2; i++){
			puck.set(55);
			delay_ms(200);
			puck.set(0);
			delay_ms(200);
		}

		delay_ms(500);

		for(int i=0; i<2; i++){
			puck.set(55);
			delay_ms(200);
			puck.set(0);
			delay_ms(200);
		}

		break;

	case longVib:
		for(int i=0; i<4; i++){
			puck.set(55);
			delay_ms(2000);
			puck.set(0);
			delay_ms(500);
		}
		break;

	case shortVib:
		for(int j=0; j<4; j++){
			for(int i=0; i<2; i++){
				puck.set(55);
				delay_ms(100);
				puck.set(0);
				delay_ms(100);
			}
			delay_ms(1200);
		}
		break;

	case setOn:
		puck.set(55);
		break;

	case setOff:
		puck.set(0);
		break;

	default:
		//printf("Error: Pattern Selection Unavailable\n");
		break;
	}

}

void shaker::customPattern(uint8_t frequency, uint8_t dutyCycle, uint8_t pulseLength, uint8_t timeDelay){
	//Enabling the PWM for the PWM Pin2.1
	//Setting the name of the shaker puck to "Puck"
	PWM puck(PWM::pwm1, frequency);

	for(int i=0; i< pulseLength; i++){
		puck.set(dutyCycle);
		delay_ms(timeDelay);
	}
	puck.set(0);
}
