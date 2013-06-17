/*
 * B1S11_ReadyWait.cpp
 *
 *  Created on: 05.06.2013
 * @author Erik Matthiessen
 *         Denis Rycka
 *         Nilüfer Güngör
 *         Maschhood Ahmad
 *
 */

#include "B1S11_ReadyWait.h"

B1S11_ReadyWait::B1S11_ReadyWait(Controller* controller) : BaseState(controller) {
	this->controller = controller;
	timerHandler->pauseAllTimers();

#ifdef DEBUG_STATE_PRINTF
	printf("DEBUG STATE: Puck%d -> B1S11_ReadyWait \n", this->controller->getID());
#endif
	hal_a->engine_full_stop();
	rs232_1->sendMsg(RS232_BAND1_WAITING);

	controller->band2AckTimer = timerHandler->createTimer(puckHandler->getDispChid(), TIME_VALUE_BAND2_ACK_SEC, TIME_VALUE_BAND2_ACK_MSEC, TIMER_BAND2_ACK);
	controller->band2AckTimer->start();
}

B1S11_ReadyWait::~B1S11_ReadyWait() {
}

void B1S11_ReadyWait::rs232Band2Ack(){
	timerHandler->deleteTimer(controller->band2AckTimer);
	controller->band2AckTimer = NULL;
}

void B1S11_ReadyWait::timerBand2Ack(){
	timerHandler->deleteTimer(controller->band2AckTimer);
	controller->band2AckTimer = NULL;
}

void B1S11_ReadyWait::rs232Band2Ready(){
	controller->puckType = PUCK_HANDOVER;
	hal_a->engine_full_unstop();

	puckHandler->errorResolved();

	rs232_1->sendMsg(RS232_PUCK_ACC);

	controller->handOverTimer = timerHandler->createTimer(puckHandler->getDispChid(), TIME_VALUE_HAND_OVER_SEC, TIME_VALUE_HAND_OVER_MSEC, TIMER_HAND_OVER);
	timerHandler->continueAllTimers();

	timerHandler->startTimer(controller->handOverTimer);

	new (this) B1S08_End(controller);
}
