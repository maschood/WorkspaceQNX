/*
 * B1S10_ERR_SlideFull.cpp
 *
 *  Created on: 27.11.2012
 *      Author: aba079
 */

#include "B1S10_ERR_SlideFull.h"

B1S10_ERR_SlideFull::B1S10_ERR_SlideFull(Controller* controller) : BaseState(controller) {
	this->controller = controller;

#ifdef DEBUG_STATE_PRINTF
	printf("DEBUG STATE: Puck%d -> B1S10_ERR_SlideFull \n", this->controller->getID());
#endif

	printf("Debug State <B1S10_ERR_SlideFull>: ERROR<ERR_STATE_SLIDE_FULL> called by puck%d\n", controller->getID());

	int replyChid = errfsm->getReplyChid();
	int errorfsmChid = errfsm->getErrorFSMChid();
	int errorfsmCoid;
	int rc;

	struct _pulse pulse;

	if ((errorfsmCoid = ConnectAttach(0, 0, errorfsmChid, _NTO_SIDE_CHANNEL, 0)) == -1) {
		printf("B1S10_ERR_SlideFull: Error in ConnectAttach\n");
	}

	rc = MsgSendPulse(errorfsmCoid, SIGEV_PULSE_PRIO_INHERIT, PULSE_FROM_PUCK, ERR_STATE_SLIDE_FULL);
	if (rc < 0) {
		printf("B1S10_ERR_SlideFull: Error in MsgSendPulse");
	}

	rc = MsgReceivePulse(replyChid, &pulse, sizeof(pulse), NULL);
	if (rc < 0) {
		printf("B1S10_ERR_SlideFull: Error in recv pulse\n");
	}

	if (ConnectDetach(errorfsmCoid) == -1) {
		printf("B1S10_ERR_SlideFull: Error in ConnectDetach\n");
	}

	//new (this) B1S06_Slide(this->controller); //TODO: not necessary

	//TODO: Diagramme anpassen
	puckHandler->removePuckFromBand(controller);
	if(puckHandler->isBandEmpty()){
		actorHAL->engineStop();
	}
	controller->resetController();
}

B1S10_ERR_SlideFull::~B1S10_ERR_SlideFull() {
}
