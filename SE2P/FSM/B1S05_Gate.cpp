/*
 * B1S05_Gate.cpp
 *
 *  Created on: 03.06.2013
 * @author Erik Matthiessen
 *         Denis Rycka
 *         Nilüfer Güngör
 *         Maschhood Ahmad
 *
 */

#include "B1S05_Gate.h"

B1S05_Gate::B1S05_Gate(Controller* controller) : BaseState(controller) {
	this->controller = controller;

#ifdef DEBUG_STATE_PRINTF
	printf("DEBUG STATE: Puck%d -> B1S05_Gate \n", this->controller->getID());
#endif

	if(this->controller->puckType == PUCK_ACCEPTED || this->controller->puckType == PUCK_TURNOVER || this->controller->puckType == PUCK_METAL_TURNOVER){
		hal_a->gate(true);

		this->controller->gateTimer = timerHandler->createTimer(puckHandler->getDispChid(), TIME_VALUE_CLOSE_GATE_SEC, TIME_VALUE_CLOSE_GATE_MSEC, TIMER_GATE_CLOSE);
		timerHandler->startTimer(this->controller->gateTimer);
	}
}

B1S05_Gate::~B1S05_Gate() {
}

void B1S05_Gate::sbGateClosed(){
	puckHandler->resetAllSenseorFuncCounters();

	if(this->controller->puckType == PUCK_ACCEPTED || this->controller->puckType == PUCK_TURNOVER || this->controller->puckType == PUCK_METAL_TURNOVER){
		puckHandler->addPuckToSeg3(controller);

		this->controller->setSegTimerMinCalled(false);
		this->controller->segTimerMin = timerHandler->createTimer(puckHandler->getDispChid(), TIME_VALUE_SEG3_MIN_SEC, TIME_VALUE_SEG3_MIN_MSEC, TIMER_SEG3_MIN);
		this->controller->segTimerMax = timerHandler->createTimer(puckHandler->getDispChid(), TIME_VALUE_SEG3_MAX_SEC, TIME_VALUE_SEG3_MAX_MSEC, TIMER_SEG3_MAX);
		timerHandler->startTimer(this->controller->segTimerMin);
		timerHandler->startTimer(this->controller->segTimerMax);

		new (this) B1S07_Seg3(controller);
	}
}

void B1S05_Gate::sbSlideOpen(){
	new (this) B1S06_Slide(controller);
}

