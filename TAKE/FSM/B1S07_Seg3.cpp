/*
 * B1S07_Seg3.cpp
 *
 *  Created on: 25.11.2012
 *      Author: martin
 */

#include "B1S07_Seg3.h"

B1S07_Seg3::B1S07_Seg3(Controller* controller) : BaseState(controller) {
	this->controller = controller;

#ifdef DEBUG_STATE_PRINTF
	printf("DEBUG STATE: Puck%d -> B1S07_Seg3\n", this->controller->getID());
#endif

	this->controller->setFirstElementInSegment(puckHandler->checkIfFirstElemInSeg3(this->controller));
}

B1S07_Seg3::~B1S07_Seg3() {
}

void B1S07_Seg3::sbEndOpen() {
	if (controller->isFirstElementInSegment() && !controller->isError()) {
#ifdef DEBUG_STATE_PRINTF
		printf("B1S07_Seg3::sbEndOpen() -> I(%d) is element at first in SEG3 ... && error = %d\n", controller->getID(),controller->isError());
#endif
		if(this->controller->isSegTimerMinCalled()){
			controller->resetSegTimers();

			puckHandler->removePuckFromSeg3();
			new (this) B1S08_End(controller);
		} else {

			printf("Debug State <B1S07_Seg3>: ERROR<ERR_STATE_ERROR_MIN> called by puck%d\n", controller->getID());

			int errorfsmChid = errfsm->getErrorFSMChid();
			int errorfsmCoid;
			int rc;

			if ((errorfsmCoid = ConnectAttach(0, 0, errorfsmChid, _NTO_SIDE_CHANNEL, 0)) == -1) {
				printf("B1S07_Seg3: Error in ConnectAttach\n");
			}

			rc = MsgSendPulse(errorfsmCoid, SIGEV_PULSE_PRIO_INHERIT, PULSE_FROM_PUCK, ERR_STATE_ERROR_MIN);
			if (rc < 0) {
				printf("B1S07_Seg3: Error in MsgSendPulse");
			}

			if (ConnectDetach(errorfsmCoid) == -1) {
				printf("B1S07_Seg3: Error in ConnectDetach\n");
			}
		}
 	} else {
		new (this) B1S07_Seg3(controller);
	}
}

void B1S07_Seg3::timerGateClose() {
	actorHAL->gate(false);
	timerHandler->deleteTimer(this->controller->gateTimer);
	this->controller->gateTimer = NULL;
}

void B1S07_Seg3::timerSeg3Min() {
	if(controller->isFirstElementInSegment()) {
		controller->setSegTimerMinCalled(true);
	}
}

void B1S07_Seg3::timerSeg3Max() {
	if(controller->isFirstElementInSegment()) {

		puckHandler->removePuckFromSeg3();
		puckHandler->removePuckFromBand(controller);
		if(puckHandler->isBandEmpty()){
			actorHAL->engineStop();
		}
		controller->resetController();

		printf("Debug State <B1S07_Seg3>: ERROR<ERR_STATE_ERROR_MAX> called by puck%d\n", controller->getID());

		int errorfsmChid = errfsm->getErrorFSMChid();
		int errorfsmCoid;
		int rc;

		if ((errorfsmCoid = ConnectAttach(0, 0, errorfsmChid, _NTO_SIDE_CHANNEL, 0)) == -1) {
			printf("B1S07_Seg3: Error in ConnectAttach\n");
		}

		//rc = MsgSendPulse(errorfsmCoid, SIGEV_PULSE_PRIO_INHERIT, PULSE_FROM_PUCK, ERR_STATE_CRITICAL_ERROR);
		rc = MsgSendPulse(errorfsmCoid, SIGEV_PULSE_PRIO_INHERIT, PULSE_FROM_PUCK, ERR_STATE_ERROR_MAX);
		if (rc < 0) {
			printf("B1S07_Seg3: Error in MsgSendPulse");
		}

		if (ConnectDetach(errorfsmCoid) == -1) {
			printf("B1S07_Seg3: Error in ConnectDetach\n");
		}
	}
}
