/*
 * time_display_task.cpp
 *
 *  Created on: May 23, 2016
 *      Author: Fnaeem
 */

#include <time_display_task.hpp>

time_display_task::time_display_task() :
    scheduler_task("ex_alarm", 4 * 512, PRIORITY_LOW),
    mAlarmMin(NULL)
{

}
bool time_display_task::init(void)
{
    mAlarmMin = xSemaphoreCreateBinary();

    return (mAlarmMin != NULL);
}

bool time_display_task::taskEntry(void)
{
    rtc_alarm_create_recurring(everyMinute, &mAlarmMin);

    return true;
}

bool time_display_task::run(void *p)
{
     if (xSemaphoreTake(mAlarmMin, 0)) {
        puts("A minute has elapsed!");

        //update time display here!
        //matrixObj.setTime();
    }

    return true;
}
