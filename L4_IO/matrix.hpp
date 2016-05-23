/*
 * matrix.hpp
 *
 *  Created on: May 7, 2016
 *      Author: Rabeel Elahi
 */

#ifndef L2_DRIVERS_MATRIX_HPP_
#define L2_DRIVERS_MATRIX_HPP_

#include "singleton_template.hpp"
#include "i2c1.hpp"


class matrix : public SingletonTemplate<matrix>
{

public:

	bool init(uint8_t displayAddress, uint8_t dimmingRate, uint8_t blinkRate);
	void writeDisplays(char string[]);
	void clearDisplay();
	void setTime(char string[]);
	void scroll(char string[]);
	void flashDisplay(uint8_t frequency);
	void setBrightness(uint8_t brightness);




protected:
	//matrix();
	friend class SingletonTemplate<matrix>;
private:
	I2C1& i2c = I2C1::getInstance();
};

typedef struct
{
	uint8_t display1_addr = 0;
	uint8_t display2_addr = 0;
	uint8_t display3_addr = 0;
	uint8_t display4_addr = 0;
}displayAddress_t;




#endif /* L2_DRIVERS_MATRIX_HPP_ */
