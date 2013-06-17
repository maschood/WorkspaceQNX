/*
 * B1S01_Entry.cpp
 *
 *  Created on: 03.06.2013
 * @author Erik Matthiessen
 *         Denis Rycka
 *         Nil�fer G�ng�r
 *         Maschhood Ahmad
 *
 */

#include "B1S01_Entry.h"

B1S01_Entry::B1S01_Entry(Controller* controller) : BaseState(controller) {
	this->controller = controller;
	puckHandler->addPuckToBand(this->controller);

#ifdef DEBUG_STATE_PRINTF
	printf("DEBUG STATE: Puck%d -> B1S01_Entry \n", this->controller->getID());
#endif
	if(this->controller->puckType == PUCK_METAL_TURNOVER){
			hal_a->engine_full_stop();

		}


}

B1S01_Entry::~B1S01_Entry() {
}

void B1S01_Entry::sbStartOpen() {
	if(puckHandler->isOnlyOneElemeOnBand()){
		hal_a->engine_right(false);
		hal_a->engine_unstop();
	}
}

void B1S01_Entry::sbStartClosed() {
	puckHandler->addPuckToSeg1(controller);

	this->controller->setSegTimerMinCalled(false);
	this->controller->segTimerMin = timerHandler->createTimer(puckHandler->getDispChid(), TIME_VALUE_SEG1_MIN_SEC, TIME_VALUE_SEG1_MIN_MSEC, TIMER_SEG1_MIN);
	this->controller->segTimerMax = timerHandler->createTimer(puckHandler->getDispChid(), TIME_VALUE_SEG1_MAX_SEC, TIME_VALUE_SEG1_MAX_MSEC, TIMER_SEG1_MAX);
	timerHandler->startTimer(this->controller->segTimerMin);
	timerHandler->startTimer(this->controller->segTimerMax);

	new (this) B1S02_Seg1(controller);
}

