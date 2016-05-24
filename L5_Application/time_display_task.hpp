/*
 * time_display_task.hpp
 *
 *  Created on: May 23, 2016
 *      Author: Fnaee
 */

#ifndef L5_APPLICATION_TIME_DISPLAY_TASK_HPP_
#define L5_APPLICATION_TIME_DISPLAY_TASK_HPP_

#include <scheduler_task.hpp>
#include "FreeRTOS.h"
#include "semphr.h"
#include "rtc_alarm.h"

class time_display_task: public scheduler_task {
public:
	time_display_task();
    bool init(void);        ///< We create our semaphores heres
    bool taskEntry(void);   ///< We enable the alarms here.
    bool run(void *p);      ///< We run our code here
private:
    SemaphoreHandle_t mAlarmMin;
    matrix& matrixObj = matrix::getInstance();
};

#endif /* L5_APPLICATION_TIME_DISPLAY_TASK_HPP_ */
