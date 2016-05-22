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

class alarm : public SingletonTemplate<alarm>
{

public:

	void setAlarm(alarm_time_t time);
	void stopAlarm(matrix *matrixObj, shaker *shakerObj);
	void snoozeAlarm(uint8_t minutes);
	void wakeUp(matrix *matrixObj, shaker *shakerObj);
	alarm_time_t getAlarmTime();




protected:
	//matrix();
	friend class SingletonTemplate<alarm>;

private:

	alarm_time_t time;
	SemaphoreHandle_t clockSem = xSemaphoreCreateBinary();
	audio& audioObj = audio::getInstance();

};


#endif /* L2_DRIVERS_ALARM_HPP_ */




