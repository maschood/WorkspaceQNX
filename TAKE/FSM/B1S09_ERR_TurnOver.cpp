/*
 * B1S09_ERR_TurnOver.cpp
 *
 *  Created on: 27.11.2012
 *      Author: aba079
 */

#include "B1S09_ERR_TurnOver.h"

B1S09_ERR_TurnOver::B1S09_ERR_TurnOver(Controller* controller) : BaseState(controller) {
	this->controller = controller;

#ifdef DEBUG_STATE_PRINTF
	printf("DEBUG STATE: Puck%d -> B1S09_ERR_TurnOver \n", this->controller->getID());
#endif

	printf("Debug State <B1S09_ERR_TurnOver>: ERROR<ERR_STATE_TURNOVER> called by puck%d\n", controller->getID());

	//int replyChid = errfsm->getReplyChid();
	int errorfsmChid = errfsm->getErrorFSMChid();
	int errorfsmCoid;
	int rc;

	//struct _pulse pulse;

	if ((errorfsmCoid = ConnectAttach(0, 0, errorfsmChid, _NTO_SIDE_CHANNEL, 0)) == -1) {
		printf("B1S09_ERR_TurnOver: Error in ConnectAttach\n");
	}

	rc = MsgSendPulse(errorfsmCoid, SIGEV_PULSE_PRIO_INHERIT, PULSE_FROM_PUCK, ERR_STATE_TURNOVER);
	if (rc < 0) {
		printf("B1S09_ERR_TurnOver: Error in MsgSendPulse");
	}
/*
	rc = MsgReceivePulse(replyChid, &pulse, sizeof(pulse), NULL);
	if (rc < 0) {
		printf("B1S09_ERR_TurnOver: Error in recv pulse\n");
	}
*/
	//this->controller->puckType = PUCK_ACCEPTED;

	if (ConnectDetach(errorfsmCoid) == -1) {
		printf("B1S09_ERR_TurnOver: Error in ConnectDetach\n");
	}

	//new (this) B1S08_End(this->controller);
}

B1S09_ERR_TurnOver::~B1S09_ERR_TurnOver() {
}

void B1S09_ERR_TurnOver::sbEndOpen() {
	this->controller->puckType = PUCK_ACCEPTED;
	new (this) B1S08_End(this->controller);
}

void B1S09_ERR_TurnOver::sbEndClosed() {
	puckHandler->resetAllSenseorFuncCounters();
}

