/*
 * shaker.cpp
 *
 *  Created on: May 8, 2016
 *      Author: Michael Jaradah
 */


#include "utilities.h"
#include <stdio.h>
#include "shaker.hpp"
#include "lpc_pwm.hpp"



void shaker::shakePattern(vibration_t name){

    // Declare our pattern selection variable and initialize to the users desired state
    vibration_t patternSelect = name;

    PWM shaker(PWM::pwm1, 55);


    /*
     * Switch case statement for the selection of the vibration patterns
     * Possible cases are: SOS, pulse, longVib, shortVib, random, classical
     * If a selection is made that does not exist, an error message is displayed
     */

    switch(patternSelect)
    {
        case SOS:
            for(int i=0; i<3; i++){
                shaker.set(55);
                delay_ms(100);
                shaker.set(0);
                delay_ms(100);
            }
            delay_ms(400);

            for(int i=0; i<3; i++){
                shaker.set(55);
                delay_ms(500);
                shaker.set(0);
                delay_ms(200);
            }

            for(int i=0; i<3; i++){
                shaker.set(55);
                delay_ms(100);
                shaker.set(0);
                delay_ms(100);
            }
            break;

        case pulse:
            for(int i=0; i<2; i++){
                shaker.set(55);
                delay_ms(200);
                shaker.set(0);
                delay_ms(100);
            }

            delay_ms(500);

            for(int i=0; i<2; i++){
                shaker.set(55);
                delay_ms(200);
                shaker.set(0);
                delay_ms(100);
            }

            break;

        case longVib:
            for(int i=0; i<4; i++){
                shaker.set(55);
                delay_ms(2000);
                shaker.set(0);
                delay_ms(500);
            }
            break;

        case shortVib:
            for(int j=0; j<4; j++){
                for(int i=0; i<2; i++){
                    shaker.set(55);
                    delay_ms(100);
                    shaker.set(0);
                    delay_ms(100);
                }
                delay_ms(1200);
            }
            break;

        case random:

            break;

        default:
            printf("Error: Pattern Selection Unavailable\n");
    }

}

void shaker::customPattern(uint8_t frequency, uint8_t pulseLength, uint8_t timeDelay){

}
