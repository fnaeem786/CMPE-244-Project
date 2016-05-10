/*
 * shaker.hpp
 *
 *  Created on: May 8, 2016
 *      Author: Michael Jaradah
 */

#ifndef SHAKER_HPP_
#define SHAKER_HPP_

#include "lpc_pwm.hpp"
#include <stdint.h>
#include "singleton_template.hpp"



typedef enum{
    SOS, pulse, longVib, shortVib, random, classical
}vibration_t;


class shaker  : public SingletonTemplate<shaker>
{
    public:
        /*
         * Function to pick the shaking pattern
         * Defined patterns are SOS, Pulse, High, Low, Dance
         * Passes name to switch/case statement
         */
        void shakePattern(vibration_t name);

        /*
         * Function to customize the shaking pattern
         * Function takes the frequency, pulse duration, and time delay
         * Passes frequency to init function
         */
        void customPattern(uint8_t frequency, uint8_t pulseLength, uint8_t timeDelay);

    protected:

        friend class SingletonTemplate<shaker>;
};

#endif /* SHAKER_HPP_ */
