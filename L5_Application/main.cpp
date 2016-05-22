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

// shared object enum
typedef enum {
	shared_matrixObject,
	shared_shakerObject,
	shared_alarmObject,
	shared_LEDObject,
	shared_audioObject
} sharedHandleId_t;

// void pointers are a special type of pointers that can point to object of any type, pretty dope
typedef void* alarmHandle_t;
typedef void* shakerHandle_t;
typedef void* matrixHandle_t;
typedef void* audioHandle_t;

class alarmTask : public scheduler_task
{
public:

	alarmTask(uint8_t priority) : scheduler_task("alarmTask", 2048, priority){
		addSharedObject(shared_alarmObject, &alarmObj);

		audioObj.initAudio();

		// might want to move these to another task? idk
		addSharedObject(shared_matrixObject, &matrixObj);
		addSharedObject(shared_shakerObject, &shakerObj);
		addSharedObject(shared_audioObject, &audioObj);
	}

	bool run(void *p)
	{


		audioObj.playAudio(1);



		//get matrix shared object
		matrixHandle_t sharedMatrix = getSharedObject(shared_matrixObject); // getSharedObject returns a void pointer
		//must cast void* to proper type, in this case the matrix class type in order to access member variables and functions
		matrix *matrixPtr = (matrix*)sharedMatrix;

		// same thing as above
		matrixHandle_t sharedShaker = getSharedObject(shared_shakerObject);
		shaker *shakerPtr = (shaker*)sharedShaker;



		if (xSemaphoreTake(timeSem, portMAX_DELAY)){
			alarmObj.wakeUp(matrixPtr, shakerPtr);
			//LEDPtr.ledPattern(police);
			audioObj.playAudio(1);
		}

		//if(capacative button pressed){}
		alarmObj.stopAlarm(matrixPtr, shakerPtr);

		//if(capacitive button pressed once){}
		alarmObj.snoozeAlarm(10);

		//printf("%i\n", (int)rtc_gettime().sec);
		vTaskDelay(1000);
		return true;
	}
private:
	SemaphoreHandle_t timeSem = xSemaphoreCreateBinary();
	alarm& alarmObj = alarm::getInstance();

	// might want to move these to another task?
	matrix& matrixObj = matrix::getInstance();
	shaker& shakerObj = shaker::getInstance();
	audio& audioObj = audio::getInstance();


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
