/*
 * alarm.cpp
 *
 *  Created on: May 19, 2016
 *      Author: Rabeel Elahi
 */


#include "utilities.h"
#include <stdio.h>
#include "alarm.hpp"




void alarm::setAlarm(alarm_time_t timeFromUser)
{
	time = timeFromUser;
	rtc_alarm_create(time, &clockSem);

}

void alarm::stopAlarm()
{

	audioObj.playAudio(0xFF); //stop audio (command - 0xFF)

	//TODO: Michael: <turn off shaker function>
	//TODO: Farhan:  <turn off sound function>
	//TODO: Rabeel:  <blink time on matrices function>
	//TODO: Sara: 	 <trigger specific LED pattern function(red & blue police style?)>
}

void alarm::snoozeAlarm()
{
	// adds 10 minutes to initial alarm that was set
	time.sec+=10;
	rtc_alarm_create(time, &clockSem);
}

void alarm::wakeUp()
{
	vibration_t pattern = SOS;
	matrix& matrixObj = matrix::getInstance();
	shaker& shakerObj = shaker::getInstance();
	//audio& audioObj = audio::getInstance();
	matrixObj.flashDisplay(5);
	shakerObj.shakePattern(pattern);
}

alarm_time_t alarm::getAlarmTime(){

	return time;
	/*
	 *	Use this code to translate time variable to char string
	 *	char buffer[16] = {0};
	 *	sprintf(buffer, "%u : %u : %u", time.hour, time.min, time.sec);
	 *
	 */

}



