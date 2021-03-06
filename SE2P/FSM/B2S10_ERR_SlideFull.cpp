/*
 * B2S10_ERR_SlideFull.cpp
 *
 *  Created on: 09.06.2013
 * @author Erik Matthiessen
 *         Denis Rycka
 *         Nil�fer G�ng�r
 *         Maschhood Ahmad
 *
 */

#include "B2S10_ERR_SlideFull.h"

B2S10_ERR_SlideFull::B2S10_ERR_SlideFull(Controller* controller) : BaseState(controller) {
	this->controller = controller;

#ifdef DEBUG_STATE_PRINTF
	printf("DEBUG STATE: Puck%d -> B2S10_ERR_SlideFull \n", this->controller->getID());
#endif

	printf("Debug State <B2S10_ERR_SlideFull>: ERROR<ERR_STATE_SLIDE_FULL> called by puck%d\n", controller->getID());

	int replyChid = errfsm->getReplyChid();
	int errorfsmChid = errfsm->getErrorFSMChid();
	int errorfsmCoid;
	int rc;

	struct _pulse pulse;

	if ((errorfsmCoid = ConnectAttach(0, 0, errorfsmChid, _NTO_SIDE_CHANNEL, 0)) == -1) {
		printf("B2S10_ERR_SlideFull: Error in ConnectAttach\n");
	}

	rc = MsgSendPulse(errorfsmCoid, SIGEV_PULSE_PRIO_INHERIT, PULSE_FROM_PUCK, ERR_STATE_SLIDE_FULL);
	if (rc < 0) {
		printf("B2S10_ERR_SlideFull: Error in MsgSendPulse");
	}

	rc = MsgReceivePulse(replyChid, &pulse, sizeof(pulse), NULL);
	if (rc < 0) {
		printf("B2S10_ERR_SlideFull: Error in recv pulse\n");
	}

	if (ConnectDetach(errorfsmCoid) == -1) {
		printf("B2S10_ERR_SlideFull: Error in ConnectDetach\n");
	}

	//new (this) B2S06_Slide(this->controller); //TODO: not necessary

	//TODO: Diagramme anpassen

	//new (this) B2S06_Slide(this->controller);
	puckHandler->removePuckFromBand(controller);
	hal_a->engine_stop();

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

B2S10_ERR_SlideFull::~B2S10_ERR_SlideFull() {
}
