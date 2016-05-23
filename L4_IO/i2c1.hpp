/*
 * i2c1.hpp
 *
 *  Created on: May 20, 2016
 *      Author: Rabeel Elahi
 */

#ifndef L2_DRIVERS_I2C1_HPP_
#define L2_DRIVERS_I2C1_HPP_


#include "singleton_template.hpp"
#include "i2c_base.hpp"


/*
 * I2C1 Singleton Driver
 * Using a wrapper around I2C_Base class which gives the the base address of the I2C1 memory map
 */
class I2C1 : public I2C_Base, public SingletonTemplate<I2C1>
{
public:
	bool init(unsigned int speedInKhz); // Initializes I2C1
private:
	I2C1(); // private constructor for singleotn class
	friend class SingletonTemplate<I2C1>; // friend class used for singleton template
};
#endif /* L2_DRIVERS_I2C1_HPP_ */
