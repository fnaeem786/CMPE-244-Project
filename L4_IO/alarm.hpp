/*
 * alarm.hpp
 *
 *  Created on: May 19, 2016
 *      Author: Rabeel Elahi
 */

#ifndef L2_DRIVERS_ALARM_HPP_
#define L2_DRIVERS_ALARM_HPP_


#include "singleton_template.hpp"
#include "rtc_alarm.h"
#include "matrix.hpp"
#include "shaker.hpp"
#include <string.h>
#include <storage.hpp>
#include "alarm.hpp"
#include "audio.hpp"

class alarm : public SingletonTemplate<alarm>
{

public:

	void setAlarm(alarm_time_t time);
	void stopAlarm();
	void snoozeAlarm();
	void wakeUp();
	//void button_interrupt(void); // P2.8
	alarm_time_t getAlarmTime();

	SemaphoreHandle_t binary_sem_signal = xSemaphoreCreateBinary();




protected:
	//matrix();
	friend class SingletonTemplate<alarm>;

private:

	alarm_time_t time;
	SemaphoreHandle_t clockSem = xSemaphoreCreateBinary();

	audio& audioObj = audio::getInstance();

};


#endif /* L2_DRIVERS_ALARM_HPP_ */




