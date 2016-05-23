/*
 * audio.hpp
 *
 *  Created on: May 20, 2016
 *      Author: Farhan Naeem
 */

#ifndef L4_IO_AUDIO_HPP_
#define L4_IO_AUDIO_HPP_


#include "singleton_template.hpp"
#include <string.h>
#include <storage.hpp>
#include "uart2.hpp"

class audio : public SingletonTemplate<audio>
{

public:
	void initAudio();
	void playAudio(unsigned char command);



protected:
	friend class SingletonTemplate<audio>;

private:
	Uart2& u2 = Uart2::getInstance();


};


#endif /* L4_IO_AUDIO_HPP_ */




