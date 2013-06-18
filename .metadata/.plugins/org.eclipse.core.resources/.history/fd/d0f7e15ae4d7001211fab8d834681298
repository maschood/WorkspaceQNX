/*
 * B2S06_Slide.cpp
 *
 *  Created on: 08.06.2013
 * @author Erik Matthiessen
 *         Denis Rycka
 *         Nilüfer Güngör
 *         Maschhood Ahmad
 *
 */

#include "B2S06_Slide.h"

B2S06_Slide::B2S06_Slide(Controller* controller) : BaseState(controller) {
	this->controller = controller;

	this->controller->slideTimer = timerHandler->createTimer(puckHandler->getDispChid(), TIME_VALUE_SLIDE_FULL_SEC, TIME_VALUE_SLIDE_FULL_MSEC, TIMER_SLIDE_FULL);
	this->controller->slideTimer->start();

#ifdef DEBUG_STATE_PRINTF
	printf("DEBUG STATE: Puck%d -> B2S06_Slide \n", this->controller->getID());
#endif
}

B2S06_Slide::~B2S06_Slide() {
}

void B2S06_Slide::sbSlideClosed(){
	printf("0");

	puckHandler->removePuckFromBand(controller);
	hal_a->engine_stop();

	printf("1");

	bool tmpBand1Waiting = controller->isBand1Waiting();
	printf("2");

	controller->resetController();
	printf("3");

	if(tmpBand1Waiting){
		rs232_1->sendMsg(RS232_BAND2_READY);
		HAL_A::getInstance()->engine_right(false);
		HAL_A::getInstance()->engine_unstop();

		controller->handOverTimer = timerHandler->createTimer(puckHandler->getDispChid(), TIME_VALUE_HAND_OVER_SEC, TIME_VALUE_HAND_OVER_MSEC, TIMER_HAND_OVER);
		timerHandler->startTimer(controller->handOverTimer);
	}
	printf("4");

}

void B2S06_Slide::timerSlideFull(){
	new (this) B2S10_ERR_SlideFull(controller);
}
