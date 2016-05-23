/*
 * audio.cpp
 *
 *  Created on: May 20, 2016
 *      Author: Farhan Naeem
 */


#include "utilities.h"
#include <stdio.h>
#include "audio.hpp"

void audio::initAudio(){

	printf("Initializing Audio Interface...\n");
	u2.init(9600);


}

void audio::playAudio(unsigned char command){
	/* Command Table (8 bit):
	 * 1 - Play "1.wav"
	 * 2 - Play "2.wav"
	 * 3 - Play "3.wav"
	 * 4 - Play "4.wav"
	 * 5 - Play "5.wav"
	 * 6 - Play "6.wav"
	 * 255 - Stop
	 */
	//use terminal to control audio
//	printf("Enter audio command\n");
//	char character[1];
//	scanf("%c",character);
//	u2.put((const char*)character);
//
	printf("Audio player command: %d\n", command);
	u2.put((const char*)command);
}
