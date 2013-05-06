/*
 * HAL_ISR.cpp
 *
 *  Created on: 29.04.2013
 *      Author:
 */

#include "HAL_ISR.h"
#include <stdint.h>



const struct sigevent* isr_handler (void *arg, int id){
	struct sigevent *event = (struct sigevent *) arg;

}

HAL_ISR::HAL_ISR() {
	initInterrupt();
}

HAL_ISR::~HAL_ISR() {

}



void HAL_ISR::initInterrupt(){
	this->chid = ChannelCreate(0);
	if (chid == -1){
		cout<< "Fehler: Channel schon vorhanden" << endl;
	}

	this->coid = ConnectAttach(0, 0 , chid,_NTO_SIDE_CHANNEL , 0);

	if(coid == -1){
		cout<< "Fehler: Connect konnte nicht erfolgen" << endl;
	}

	/*
	 * Ist dazu
	 */
//	isr_id = InterruptAttach (int intr, const struct sigevent * (*handler) (void *, int),const void *area, int size, unsigned flags);
	isr_id = InterruptAttachEvent()
}


int HAL_ISR::getChid(){
	return chid;
}

int HAL_ISR::getCoid(){
	return coid;
}
