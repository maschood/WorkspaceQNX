/**
 * @file HAL_ISR.cpp
  Created on: 30.04.2013
 * @author Erik Matthiessen
 *         Denis Rycka
 *         Nilüfer Güngör
 *         Maschhood Ahmad
 */

#include "HAL_ISR.h"

HAL_ISR* HAL_ISR::instance = NULL;
Mutex* HAL_ISR::hal_isrInstanceMutex = new Mutex();

HAL_ISR::HAL_ISR() {
	hal_s = HAL_S::getInstance();
	disp = Dispatcher::getInstance();
	errfsm = ErrorFSM::getInstance();
	lc = LightController::getInstance();
	dispatcherChid = disp->getChid();
	errfsmChid = errfsm->getErrorFSMChid();

	//Connect to channels
	if ((dispatcherCoid= ConnectAttach(0, 0, dispatcherChid, _NTO_SIDE_CHANNEL, 0)) == -1) {
		printf("HAL_ISR: Error in ConnectAttach\n");
	}

	if ((errfsmCoid = ConnectAttach(0, 0, errfsmChid, _NTO_SIDE_CHANNEL, 0)) == -1) {
		printf("HAL_ISR: Error in ConnectAttach\n");
	}
}

HAL_ISR::~HAL_ISR() {
	if (instance != NULL) {
		delete instance;
		instance = NULL;
		hal_isrInstanceMutex->~Mutex();
	}
}

HAL_ISR* HAL_ISR::getInstance() {
	if (!instance) {
		hal_isrInstanceMutex->lock();
		if (!instance) {
			instance = new HAL_ISR;
		}
		hal_isrInstanceMutex->unlock();
	}

	return instance;
}

void HAL_ISR::execute(void*) {

	struct _pulse pulse;
	int oldVector = DEFAULT_ISR_VAL;
	int newVector = 0;
	int rc;
	int action = -1;

	while (!isStopped()) {
		rc = MsgReceivePulse(hal_s->getChid(), &pulse, sizeof(pulse), NULL);
		if (rc < 0) {
			printf("HAL_ISR: Error in recv pulse\n");
			if (isStopped()) {
				break;
			}
		}

		newVector = pulse.value.sival_int;
		int i;
		bool newVal;

		for (i = 0; i < 12; i++) {
			if (((newVector >> i) & 1) != ((oldVector >> i) & 1)) {
				newVal = (newVector >> i) & 1;

				switch (i) {
				case 0:
					if (newVal) {
						action = SB_START_CLOSED;
					} else {
						action = SB_START_OPEN;
					}
					break;
				case 1:
					if (newVal) {
						action = SB_HEIGHTCONTROL_CLOSED;
					} else {
						action = SB_HEIGHTCONTROL_OPEN;
					}
					break;
				case 2:
					// Check type/height of pucks only over A/D, no IRQ forwarded!
					if (newVal) {
					} else {
					}
					break;
				case 3:
					if (newVal) {
						action = SB_GATE_CLOSED;
					} else {
						action = SB_GATE_OPEN;
					}
					break;
				case 4:
					// Only IRQ needed is, if puck contains metal; other one not forwarded
					if (newVal) {
						action = MS_METAL_TRUE;
					} else {
					}
					break;
				case 5:
					// IRQs not needed, so will not be forwarded
					if (newVal) {
					} else {
					}
					break;
				case 6:
					if (newVal) {
						action = SB_SLIDE_CLOSED;
					} else {
				action = SB_SLIDE_OPEN;
					}
					break;
				case 7:
					if (newVal) {
						action = SB_END_CLOSED;
					} else {
						action = SB_END_OPEN;
					}
					break;
				case 8:
					if (newVal) {
						lc->ledStart(true);
						action = BTN_START_PRESSED;
					} else {
						lc->ledStart(false);
						action = BTN_START_RELEASED;
					}
					break;
				case 9:
					if (newVal) {
						action = BTN_STOP_RELEASED;
					} else {
						action = BTN_STOP_PRESSED;
					}
					break;
				case 10:
					if (newVal) {
						lc->ledReset(true);
						action = BTN_RESET_PRESSED;
					} else {
						lc->ledReset(false);
						action = BTN_RESET_RELEASED;
					}
					break;
				case 11:
					if (newVal) {
						action = BTN_ESTOP_RELEASED;
					} else {
						action = BTN_ESTOP_PRESSED;
					}
					break;
				default:
					printf("no pulse! HAL_ISR switch def value\n");
				}

				if(action != -1){
					rc = MsgSendPulse(dispatcherCoid, SIGEV_PULSE_PRIO_INHERIT, PULSE_FROM_ISRHANDLER, action);
					if (rc < 0) {
						printf("HAL_ISR: Error in MsgSendPulse");
					}

					rc = MsgSendPulse(errfsmCoid, SIGEV_PULSE_PRIO_INHERIT, PULSE_FROM_ISRHANDLER, action);
					if (rc < 0) {
						printf("HAL_ISR: Error in MsgSendPulse");
					}
					action = -1;
				}
			}
		}
		oldVector = newVector;

	}
}
void HAL_ISR::stop() {
	HAWThread::stop();
	hal_s->stopInterrupt();

	if (ConnectDetach(dispatcherCoid) == -1) {
		printf("ISRHandler: Error in ConnectDetach\n");
	}

	if (ConnectDetach(errfsmCoid) == -1) {
		printf("ISRHandler: Error in ConnectDetach\n");
	}
}

void HAL_ISR::shutdown() {
}
