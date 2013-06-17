/*
 * B2S03_Height.cpp
 *
 *  Created on: 08.06.2013
 * @author Erik Matthiessen
 *         Denis Rycka
 *         Nil�fer G�ng�r
 *         Maschhood Ahmad
 *
 */


#include "B2S03_Height.h"

B2S03_Height::B2S03_Height(Controller* controller) : BaseState(controller) {
	this->controller = controller;

#ifdef DEBUG_STATE_PRINTF
	printf("DEBUG STATE: Puck%d -> B2S03_Height \n", this->controller->getID());
#endif

	timerHandler->pauseAllTimers();
	hal_a->engine_stop();
	controller->puckType = hal_s->getHeightPuckType();
	std::cout << "TYP: "<< controller->puckType<< endl;
	hal_a->engine_unstop();
	timerHandler->continueAllTimers();
}

B2S03_Height::~B2S03_Height() {
}

void B2S03_Height::sbHeightcontrolClosed() {
	puckHandler->resetAllSenseorFuncCounters();

	this->controller->setSegTimerMinCalled(false);
	this->controller->segTimerMin = timerHandler->createTimer(puckHandler->getDispChid(), TIME_VALUE_SEG2_MIN_SEC, TIME_VALUE_SEG2_MIN_MSEC, TIMER_SEG2_MIN);
	this->controller->segTimerMax = timerHandler->createTimer(puckHandler->getDispChid(), TIME_VALUE_SEG2_MAX_SEC, TIME_VALUE_SEG2_MAX_MSEC, TIMER_SEG2_MAX);
	timerHandler->startTimer(this->controller->segTimerMin);
	timerHandler->startTimer(this->controller->segTimerMax);

	new (this) B2S04_Seg2(controller);
}
