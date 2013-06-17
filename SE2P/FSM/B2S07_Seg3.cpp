/*
 * B2S07_Seg3.cpp
 *
 *  Created on: 08.06.2013
 * @author Erik Matthiessen
 *         Denis Rycka
 *         Nil�fer G�ng�r
 *         Maschhood Ahmad
 *
 */

#include "B2S07_Seg3.h"

B2S07_Seg3::B2S07_Seg3(Controller* controller) : BaseState(controller) {
	this->controller = controller;

#ifdef DEBUG_STATE_PRINTF
	printf("DEBUG STATE: Puck%d -> B2S07_Seg3\n", this->controller->getID());
#endif
}

B2S07_Seg3::~B2S07_Seg3() {
}

void B2S07_Seg3::sbEndOpen() {
	if(this->controller->isSegTimerMinCalled()){
		controller->resetSegTimers();

		hal_a->engine_stop();
		new (this) B2S08_End(controller);
	} else {

		printf("Debug State <B2S07_Seg3>: ERROR<ERR_STATE_ERROR_MIN> called by puck%d\n", controller->getID());

		int errorfsmChid = errfsm->getErrorFSMChid();
		int errorfsmCoid;
		int rc;

		if ((errorfsmCoid = ConnectAttach(0, 0, errorfsmChid, _NTO_SIDE_CHANNEL, 0)) == -1) {
			printf("B2S07_Seg3: Error in ConnectAttach\n");
		}

		rc = MsgSendPulse(errorfsmCoid, SIGEV_PULSE_PRIO_INHERIT, PULSE_FROM_PUCK, ERR_STATE_ERROR_MIN);
		if (rc < 0) {
			printf("B2S07_Seg3: Error in MsgSendPulse");
		}

		if (ConnectDetach(errorfsmCoid) == -1) {
			printf("B2S07_Seg3: Error in ConnectDetach\n");
		}
	}
}

void B2S07_Seg3::timerGateClose() {
	hal_a->gate(false);
	timerHandler->deleteTimer(controller->gateTimer);
	//controller->gateTimer = NULL;
}

void B2S07_Seg3::timerSeg3Min() {
	controller->setSegTimerMinCalled(true);
}

void B2S07_Seg3::timerSeg3Max() {

	puckHandler->removePuckFromBand(controller);
	hal_a->engine_stop();

	printf("Debug State <B2S07_Seg3>: ERROR<ERR_STATE_ERROR_MAX> called by puck%d\n", controller->getID());

	int replyChid = errfsm->getReplyChid();
	int errorfsmChid = errfsm->getErrorFSMChid();
	int errorfsmCoid;
	int rc;

	struct _pulse pulse;

	if ((errorfsmCoid = ConnectAttach(0, 0, errorfsmChid, _NTO_SIDE_CHANNEL, 0)) == -1) {
		printf("B2S07_Seg3: Error in ConnectAttach\n");
	}

	//rc = MsgSendPulse(errorfsmCoid, SIGEV_PULSE_PRIO_INHERIT, PULSE_FROM_PUCK, ERR_STATE_CRITICAL_ERROR);
	rc = MsgSendPulse(errorfsmCoid, SIGEV_PULSE_PRIO_INHERIT, PULSE_FROM_PUCK, ERR_STATE_ERROR_MAX);
	if (rc < 0) {
		printf("B2S07_Seg3: Error in MsgSendPulse");
	}

	rc = MsgReceivePulse(replyChid, &pulse, sizeof(pulse), NULL);
	if (rc < 0) {
		printf("B2S07_Seg3: Error in recv pulse\n");
	}

	if (ConnectDetach(errorfsmCoid) == -1) {
		printf("B2S07_Seg3: Error in ConnectDetach\n");
	}

	bool tmpBand1Waiting = controller->isBand1Waiting();

	controller->resetController();

	if(tmpBand1Waiting){
		rs232_1->sendMsg(RS232_BAND2_READY);
		HAL_A::getInstance()->engine_right(false);
		HAL_A::getInstance()->engine_unstop();

		controller->handOverTimer = timerHandler->createTimer(puckHandler->getDispChid(), TIME_VALUE_HAND_OVER_SEC, TIME_VALUE_HAND_OVER_MSEC, TIMER_HAND_OVER);
		timerHandler->startTimer(controller->handOverTimer);
	}
}
