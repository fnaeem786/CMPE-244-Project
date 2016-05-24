/*
 * user_interface_task.h
 *
 *  Created on: May 23, 2016
 *      Author: Fnaeem
 */

#ifndef L5_APPLICATION_USER_INTERFACE_TASK_HPP_
#define L5_APPLICATION_USER_INTERFACE_TASK_HPP_

#include <scheduler_task.hpp>
#include "FreeRTOS.h"
#include "semphr.h"
#include "rtc_alarm.h"
#include "singleton_template.hpp"


class user_interface_task: public scheduler_task {
public:
	user_interface_task();
    bool init(void);
    bool run(void *p);
private:
	alarm& alarmObj = alarm::getInstance();

};

#endif /* L5_APPLICATION_USER_INTERFACE_TASK_HPP_ */
