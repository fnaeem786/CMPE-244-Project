/*
 * user_interface_task.cpp
 *
 *  Created on: May 23, 2016
 *      Author: Fnaeem
 */

#include <user_interface_task.hpp>

user_interface_task::user_interface_task():
	scheduler_task("user_interface_task", 3 * 512, PRIORITY_LOW)
{
	// TODO Auto-generated constructor stub

}


bool user_interface_task::init(void){

}
bool user_interface_task::run(void *p){
	/*
	 * 			SNOOZE BUTTON SEMAPHORE
	 */
	if(xSemaphoreTake(binary_sem_signal, portMAX_DELAY)){
		puts("Snooze button pressed");
		alarmObj.stopAlarm();
		alarmObj.snoozeAlarm();
		delay_ms(200); //delay for debouncing?
	}

	//clear the semaphore once again in case it was set during the delay due to bouncing of the signal
	xSemaphoreTake(binary_sem_signal, 0);
}







