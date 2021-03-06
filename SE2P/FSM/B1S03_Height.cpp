/*
 * B1S03_Height.cpp
 *
 *  Created on: 03.06.2013
 * @author Erik Matthiessen
 *         Denis Rycka
 *         Nil�fer G�ng�r
 *         Maschhood Ahmad
 *
 */

#include "B1S03_Height.h"

B1S03_Height::B1S03_Height(Controller* controller) : BaseState(controller) {
	this->controller = controller;
	timerHandler->pauseAllTimers();

#ifdef DEBUG_STATE_PRINTF
	printf("DEBUG STATE: Puck%d -> B1S03_Height \n", this->controller->getID());
#endif
	hal_a->engine_stop();
	controller->puckType = hal_s->getHeightPuckType();
	hal_a->engine_unstop();
	timerHandler->continueAllTimers();
}

B1S03_Height::~B1S03_Height() {
}

void B1S03_Height::sbHeightcontrolClosed() {
	puckHandler->resetAllSenseorFuncCounters();
	puckHandler->addPuckToSeg2(controller);

	this->controller->setSegTimerMinCalled(false);
	this->controller->segTimerMin = timerHandler->createTimer(puckHandler->getDispChid(), TIME_VALUE_SEG2_MIN_SEC, TIME_VALUE_SEG2_MIN_MSEC, TIMER_SEG2_MIN);
	this->controller->segTimerMax = timerHandler->createTimer(puckHandler->getDispChid(), TIME_VALUE_SEG2_MAX_SEC, TIME_VALUE_SEG2_MAX_MSEC, TIMER_SEG2_MAX);
	timerHandler->startTimer(this->controller->segTimerMin);
	timerHandler->startTimer(this->controller->segTimerMax);

	new (this) B1S04_Seg2(controller);
}
