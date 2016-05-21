/*
 * matrix.hpp
 *
 *  Created on: May 7, 2016
 *      Author: Rabeel Elahi
 */

#ifndef L2_DRIVERS_MATRIX_HPP_
#define L2_DRIVERS_MATRIX_HPP_

#include "singleton_template.hpp"
#include "i2c2.hpp"


class matrix : public SingletonTemplate<matrix>
{

public:

	bool init(uint8_t displayAddress, uint8_t dimmingRate, uint8_t blinkRate, I2C2 *i2c);
	void writeDisplays(char string[], I2C2 *i2c);
	void clearDisplay(I2C2 *i2c);
	void setTime(char string[], I2C2 *i2c);
	void scroll(char string[], I2C2 *i2c);
	void flashDisplay();



protected:
	//matrix();
	friend class SingletonTemplate<matrix>;
};

typedef struct
{
	uint8_t display1_addr = 0;
	uint8_t display2_addr = 0;
	uint8_t display3_addr = 0;
	uint8_t display4_addr = 0;
}displayAddress_t;




#endif /* L2_DRIVERS_MATRIX_HPP_ */
