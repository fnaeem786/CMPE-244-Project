#include "tasks.hpp"
#include "examples/examples.hpp"
#include <stdio.h>
#include "LPC17xx.h"
#include "sys_config.h"
#include "utilities.h"
#include "i2c_base.hpp"
#include "i2c2.hpp"
#include "matrix.hpp"
#include "shaker.hpp"
#include "alarm.hpp"
#include "rtc_alarm.h"
#include "audio.hpp"
#include "eint.h"
#include "gpio.hpp"




SemaphoreHandle_t binary_sem_signal = xSemaphoreCreateBinary();

void button_interrupt(void)
{
	long task_woken = 0;
	//	puts("Serving semaphore");

		xSemaphoreGiveFromISR(binary_sem_signal, &task_woken);
		if(task_woken){
			//check if task was woken when semaphore was given
			portYIELD_FROM_ISR(task_woken);
			/*
			 * Task1--->
			 * 			ISR--> GIVE SEM THEN WE ALSO YIELD
			 * 							Get back to semaphore_eater task right after interrupt exits, not task 1
			 * 	optimizing system such that as soon as interrupt occrus we will go back to semaphore_eater since it is a high priority task
			 */
		}
	//	puts("Semaphore served");
}


class alarmTask : public scheduler_task
{
public:

	alarmTask(uint8_t priority) : scheduler_task("alarmTask", 2048, priority){

	}

	bool init(void)
	{
		audioObj.initAudio();	//initialize audio interface
		GPIO myPin(P2_6);
		myPin.setAsInput();
		eint3_enable_port2(6, eint_rising_edge, button_interrupt);
		alarmStates state = ALARM1;

		return true;
	}

	bool run(void *p)
	{

//		puts("playing audio");
//		audioObj.playAudio(0x01);
//		delay_ms(2000);
//		audioObj.playAudio(0x02);


		/*
		 *
		 * 		 ALARM SEMAPHORE
		 *
		 */
		if (xSemaphoreTake(timeSem, portMAX_DELAY)){
			//alarmObj.wakeUp();
			//LEDPtr.ledPattern(police);
			//audioObj.playAudio(1);

			switch(state){
			case WAIT_FOR_ALARM:
				//do nothing
				break;
			case ALARM1:
				alarmObj.activateAlarmLevel1;
				state = ALARM2;
				break;
			case ALARM2:
				alarmObj.activateAlarmLevel2;
				state = ALARM3;
				break;
			case ALARM3:
				alarmObj.activateAlarmLevel3;
				state = ALARM4;
				break;
			case ALARM4:
				alarmObj.activateAlarmLevel4;
				state = ALARM5;
				break;
			case ALARM5:
				alarmObj.activateAlarmLevel5;
				if(user_out_of_bed){
					state = ALARM1;  //user is out of bed, reset to alarm1 for the next time
				}
				else{
					state = ALARM5;  //repeat alarm until user gets out of bed
				}
				break;
			}


		}
		vTaskDelay(1000);
		return true;
	}
private:
	SemaphoreHandle_t timeSem = xSemaphoreCreateBinary();
	alarm& alarmObj = alarm::getInstance();
	matrix& matrixObj = matrix::getInstance();
	shaker& shakerObj = shaker::getInstance();
	audio& audioObj = audio::getInstance();

	enum alarmStates {
		WAIT_FOR_ALARM,
		ALARM1,
		ALARM2,
		ALARM3,
		ALARM4,
		ALARM5
	};

	alarmStates state;

};

int main(void){

	/**
	 * A few basic tasks for this bare-bone system :
	 *      1.  Terminal task provides gateway to interact with the board through UART terminal.
	 *      2.  Remote task allows you to use remote control to interact with the board.
	 *      3.  Wireless task responsible to receive, retry, and handle mesh network.
	 *
	 * Disable remote task if you are not using it.  Also, it needs SYS_CFG_ENABLE_TLM
	 * such that it can save remote control codes to non-volatile memory.  IR remote
	 * control codes can be learned by typing the "learn" terminal command.
	 */
	scheduler_add_task(new terminalTask(PRIORITY_HIGH));
	scheduler_add_task(new alarmTask(PRIORITY_HIGH));

	/* Consumes very little CPU, but need highest priority to handle mesh network ACKs */
	scheduler_add_task(new wirelessTask(PRIORITY_CRITICAL));

	/* Change "#if 0" to "#if 1" to run period tasks; @see period_callbacks.cpp */
#if 0
	scheduler_add_task(new periodicSchedulerTask());
#endif

	/* The task for the IR receiver */
	// scheduler_add_task(new remoteTask  (PRIORITY_LOW));

	/* Your tasks should probably used PRIORITY_MEDIUM or PRIORITY_LOW because you want the terminal
	 * task to always be responsive so you can poke around in case something goes wrong.
	 */

	/**
	 * This is a the board demonstration task that can be used to test the board.
	 * This also shows you how to send a wireless packets to other boards.
	 */
#if 0
	scheduler_add_task(new example_io_demo());
#endif

	/**
	 * Change "#if 0" to "#if 1" to enable examples.
	 * Try these examples one at a time.
	 */
#if 0
	scheduler_add_task(new example_task());
	scheduler_add_task(new example_alarm());
	scheduler_add_task(new example_logger_qset());
	scheduler_add_task(new example_nv_vars());
#endif

	/**
	 * Try the rx / tx tasks together to see how they queue data to each other.
	 */
#if 0
	scheduler_add_task(new queue_tx());
	scheduler_add_task(new queue_rx());
#endif

	/**
	 * Another example of shared handles and producer/consumer using a queue.
	 * In this example, producer will produce as fast as the consumer can consume.
	 */
#if 0
	scheduler_add_task(new producer());
	scheduler_add_task(new consumer());
#endif

	/**
	 * If you have RN-XV on your board, you can connect to Wifi using this task.
	 * This does two things for us:
	 *   1.  The task allows us to perform HTTP web requests (@see wifiTask)
	 *   2.  Terminal task can accept commands from TCP/IP through Wifly module.
	 *
	 * To add terminal command channel, add this at terminal.cpp :: taskEntry() function:
	 * @code
	 *     // Assuming Wifly is on Uart3
	 *     addCommandChannel(Uart3::getInstance(), false);
	 * @endcode
	 */
#if 0
	Uart3 &u3 = Uart3::getInstance();
	u3.init(WIFI_BAUD_RATE, WIFI_RXQ_SIZE, WIFI_TXQ_SIZE);
	scheduler_add_task(new wifiTask(Uart3::getInstance(), PRIORITY_LOW));
#endif

	scheduler_start(); ///< This shouldn't return
	return -1;
}
