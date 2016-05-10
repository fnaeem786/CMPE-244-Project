#include <stdio.h>
#include "io.hpp"
#include "gpio.hpp"
#include "utilities.h"
#include "LPC17xx.h"

#include "shaker.hpp"


int main(void){

    shaker &obj = shaker::getInstance();

    obj.shakePattern(longVib);

    delay_ms(3000);

    obj.shakePattern(shortVib);

    delay_ms(3000);

    obj.shakePattern(SOS);

    delay_ms(3000);

    obj.shakePattern(pulse);

    return 0;
}
