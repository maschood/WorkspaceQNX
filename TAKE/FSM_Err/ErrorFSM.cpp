/**
 * SE2 WiSe 2012
 * ErrorFSM
 *
 * ErrorFSM handles errors that can take place on the Festo system.
 * It reacts on messages by the ISRHandler (stop, estop), the pucks
 * and RS232.
 * It has its own channel where it is receiving pulse messages sent by
 * ISRHandler, pucks or the RS232. Reply is sent using a special reply
 * channel on which the pucks can listen to.
 *
 * @file ErrorFSM.cpp
 * @author Chris Addo
 *         Jens Eberwein
 *         Tristan Rudat
 *         Martin Slowikowski
 * @date 2012-11-29
 * @version 0.3
 */

#include "ErrorFSM.h"

ErrorFSM* ErrorFSM::instance = NULL;
Mutex* ErrorFSM::errfsmInstanceMutex = new Mutex();

ErrorFSM::ErrorFSM() {
	state = ERR_STATE_IDLE;
	oldState = -1;
	aHal = ActorHAL::getInstance();
	lc = LightController::getInstance();
	disp = Dispatcher::getInstance();
	th = TimerHandler::getInstance();

	//Create channel for pulse notification
	if ((ownChid = ChannelCreate(0)) == -1) {
		printf("ErrorFSM: Error in ChannelCreate\n");
	}

	if ((replyChid = ChannelCreate(0)) == -1) {
		printf("ErrorFSM: Error in ChannelCreate\n");
	}

	if ((replyCoid = ConnectAttach(0, 0, replyChid, _NTO_SIDE_CHANNEL, 0)) == -1) {
		printf("ErrorFSM: Error in ConnectAttach\n");
	}
}

ErrorFSM::~ErrorFSM() {
	if (instance != NULL) {
		delete instance;
		instance = NULL;
		errfsmInstanceMutex->~Mutex();
	}
}

ErrorFSM* ErrorFSM::getInstance() {
	if (!instance) {
		errfsmInstanceMutex->lock();
		if (!instance) {
			instance = new ErrorFSM;
#ifdef DEBUG_ErrorFSM
			printf("Debug ErrorFSM: New ErrorFSM instance created\n");
#endif
		}
		errfsmInstanceMutex->unlock();
	}

	return instance;
}

void ErrorFSM::execute(void*) {
	int rc;
	struct _pulse pulse;
	int pulseVal;
	int pulseCode;
	bool isSbStartOpen = false;
	bool isEstopPressed = false;
	bool isStopPressed = false;
	bool isEngineStopped = false;
	bool error = false;
	bool isSbSlideClosed = false;

	while (!isStopped()) {
#ifdef DEBUG_ErrorFSM
		//printf("errorfsm before recv\n");
#endif
		rc = MsgReceivePulse(ownChid, &pulse, sizeof(pulse), NULL);
		if (rc < 0) {
			printf("ErrorFSM: Error in recv pulse\n");
			if (isStopped()) {
				break;
			}
		}
		pulseCode = pulse.code;
		pulseVal = pulse.value.sival_int;
#ifdef DEBUG_ErrorFSM
		//printf("errorfsm after recv; code: %d, value: %d\n", pulseCode, pulseVal);
#endif

		if((pulseVal == RS232_ESTOP || pulseVal == BTN_ESTOP_PRESSED) && !isEstopPressed){
			isEstopPressed = true;
			th->pauseAllTimers();
			disp->setEstop(true);
			state = ERR_STATE_ESTOP;
			if(pulseVal == BTN_ESTOP_PRESSED){
				RS232_1::getInstance()->sendMsg(RS232_ESTOP);
			}
#ifdef DEBUG_ErrorFSM
			printf("Debug Error FSM: Error -> ERR_STATE_ESTOP\n");
#endif
		} else if(pulseVal == BTN_STOP_PRESSED && !isStopPressed && !error){
			isStopPressed = true;
			th->pauseAllTimers();
			isEngineStopped = aHal->isEngineStopped();
			oldState = state;
			state = ERR_STATE_STOP;
#ifdef DEBUG_ErrorFSM
			printf("Debug Error FSM: Error -> ERR_STATE_STOP\n");
#endif
		}

		switch (state) {
		//Bei idle nur auf Pucks hoeren, IRQs interessieren uns nicht ...
		case ERR_STATE_IDLE:
			if (pulseCode == PULSE_FROM_PUCK) {
				//naechsten zustand vorbereiten mit licht band anhalten und so ...
				switch (pulseVal) {
				case ERR_STATE_SLIDE_FULL:
					th->pauseAllTimers();
					aHal->engineFullStop();
					lc->upcomingNotReceipted();
					error = true;
#ifdef DEBUG_ErrorFSM
					printf("Debug Error FSM: Error -> ERR_STATE_SLIDE_FULL\n");
#endif
					break;
				case ERR_STATE_TURNOVER:
					th->pauseAllTimers();
					PuckHandler::getInstance()->resetAllSenseorFuncCounters();
					PuckHandler::getInstance()->errorOccured();
					aHal->engineFullStop();
					lc->manualTurnover();
					error = true;
					//disp->setError(true);
#ifdef DEBUG_ErrorFSM
					printf("Debug Error FSM: Error -> ERR_STATE_TURNOVER\n");
#endif
					break;
				case ERR_STATE_ERROR:
					th->pauseAllTimers();
					isEngineStopped = aHal->isEngineStopped();
					disp->setError(true);
					aHal->engineFullStop();
					lc->upcomingNotReceipted();
					error = true;
#ifdef DEBUG_ErrorFSM
					printf("Debug Error FSM: Error -> ERR_STATE_ERROR\n");
#endif
					break;
				case ERR_STATE_ERROR_MIN:
					th->pauseAllTimers();
					isEngineStopped = aHal->isEngineStopped();
					disp->setError(true);
					aHal->engineFullStop();
					lc->upcomingNotReceiptedTimerMin();
					error = true;
#ifdef DEBUG_ErrorFSM
					printf("Debug Error FSM: Error -> ERR_STATE_ERROR_MIN\n");
#endif
					break;
				case ERR_STATE_ERROR_MAX:
					th->pauseAllTimers();
					isEngineStopped = aHal->isEngineStopped();
					disp->setError(true);
					aHal->engineFullStop();
					lc->upcomingNotReceiptedTimerMax();
					error = true;
#ifdef DEBUG_ErrorFSM
					printf("Debug Error FSM: Error -> ERR_STATE_ERROR_MAX\n");
#endif
					break;
				/*case ERR_STATE_CRITICAL_ERROR:
					disp->setError(true);
					th->pauseAllTimers();
					aHal->engineFullStop();
					lc->upcomingNotReceipted();
					error = true;
#ifdef DEBUG_ErrorFSM
					printf("Debug Error FSM: Error -> ERR_STATE_CRITICAL_ERROR\n");
#endif
					break;*/
				case ERR_STATE_TURNOVER_BAND2:
					th->pauseAllTimers();
					aHal->engineFullStop();
					lc->upcomingNotReceipted();
					error = true;
#ifdef DEBUG_ErrorFSM
					printf("Debug Error FSM: Error -> ERR_STATE_TURNOVER_BAND2\n");
#endif
					break;
				default:
					printf("nop\n");
				}
				// zustand setzen und wieder ab nach oben im recv blocken
				state = pulseVal;
				PuckHandler::getInstance()->printQueueStatus();
			}
			break;
		case ERR_STATE_SLIDE_FULL:
			aHal->engineFullStop();
			lc->upcomingNotReceipted();
			if (pulseCode == PULSE_FROM_ISRHANDLER) {
				if (pulseVal == SB_SLIDE_CLOSED) {
					lc->goneUnreceipted();
					isSbSlideClosed = true;
				} else if (pulseVal == BTN_RESET_PRESSED) {
					lc->upcomingReceipted();
					state = ERR_STATE_SLIDE_FULL_RECEIPTED;
				}
			}
			break;
		case ERR_STATE_SLIDE_FULL_RECEIPTED:
			if (pulseCode == PULSE_FROM_ISRHANDLER) {
				if(pulseVal == SB_SLIDE_CLOSED){
					isSbSlideClosed = true;
				} else if(pulseVal == BTN_START_PRESSED && isSbSlideClosed){
					lc->operatingNormal();
					//msg puck error solved, reihenfolge unstop und msg puck?!
					sendPuckReply();
					aHal->engineFullUnstop();
					error = false;
					isSbSlideClosed = false;
					th->continueAllTimers();
					state = ERR_STATE_IDLE;
				}
			}
			break;
		case ERR_STATE_TURNOVER:
			aHal->engineFullStop();
			lc->manualTurnover();
			if(pulseCode == PULSE_FROM_ISRHANDLER){
				if(pulseVal == SB_END_OPEN){
					lc->operatingNormal();
					//msg puck error solved, reihenfolge unstop und msg puck?!
					//sendPuckReply();
					//aHal->engineFullUnstop();
					error = false;
					//disp->setError(false);
					//th->continueAllTimers();
					state = ERR_STATE_IDLE;
				}
			}
			break;
		case ERR_STATE_ERROR:
			aHal->engineFullStop();
			lc->upcomingNotReceipted();
			if(pulseCode == PULSE_FROM_ISRHANDLER){
				if(pulseVal == BTN_RESET_PRESSED){
					lc->upcomingReceipted();
					PuckHandler::getInstance()->reInitFirstElemInSegBools();
					PuckHandler::getInstance()->resetAllSenseorFuncCounters();
					state = ERR_STATE_ERROR_RECEIPTED;
				}
			}
			break;
		case ERR_STATE_ERROR_RECEIPTED:
			if(pulseCode == PULSE_FROM_ISRHANDLER){
				if(pulseVal == BTN_START_PRESSED){
					lc->operatingNormal();
					aHal->engineFullUnstop();
					if(isEngineStopped){
						aHal->engineStop();
					}
					error = false;
					disp->setError(false);
					th->continueAllTimers();
					state = ERR_STATE_IDLE;
				}
			}
			break;
		case ERR_STATE_ERROR_MIN:
			aHal->engineFullStop();
			lc->upcomingNotReceiptedTimerMin();
			if(pulseCode == PULSE_FROM_ISRHANDLER){
				if(pulseVal == BTN_RESET_PRESSED){
					lc->upcomingReceipted();
					PuckHandler::getInstance()->reInitFirstElemInSegBools();
					PuckHandler::getInstance()->resetAllSenseorFuncCounters();
					state = ERR_STATE_ERROR_RECEIPTED_MIN;
				}
			}
			break;
		case ERR_STATE_ERROR_RECEIPTED_MIN:
			if(pulseCode == PULSE_FROM_ISRHANDLER){
				if(pulseVal == BTN_START_PRESSED){
					lc->operatingNormal();
					aHal->engineFullUnstop();
					if(isEngineStopped){
						aHal->engineStop();
					}
					error = false;
					disp->setError(false);
					th->continueAllTimers();
					state = ERR_STATE_IDLE;
				}
			}
			break;
		case ERR_STATE_ERROR_MAX:
			aHal->engineFullStop();
			lc->upcomingNotReceiptedTimerMax();
			if(pulseCode == PULSE_FROM_ISRHANDLER){
				if(pulseVal == BTN_RESET_PRESSED){
					lc->upcomingReceipted();
					PuckHandler::getInstance()->reInitFirstElemInSegBools();
					PuckHandler::getInstance()->resetAllSenseorFuncCounters();
					state = ERR_STATE_ERROR_RECEIPTED_MAX;
				}
			}
			break;
		case ERR_STATE_ERROR_RECEIPTED_MAX:
			if(pulseCode == PULSE_FROM_ISRHANDLER){
				if(pulseVal == BTN_START_PRESSED){
					lc->operatingNormal();
					aHal->engineFullUnstop();
					if(isEngineStopped){
						aHal->engineStop();
					}
					error = false;
					disp->setError(false);
#ifdef BAND_2
					sendPuckReply();
#endif
					th->continueAllTimers();
					state = ERR_STATE_IDLE;
				}
			}
			break;
/*		case ERR_STATE_CRITICAL_ERROR:
			aHal->engineFullStop();
			lc->upcomingNotReceipted();
			if(pulseCode == PULSE_FROM_ISRHANDLER){
				if(pulseVal == BTN_RESET_PRESSED){
					lc->upcomingReceipted();
					state = ERR_STATE_ERROR_RECEIPTED;
				}
			}
			break;
		case ERR_STATE_CRITICAL_ERROR_RECEIPTED:
			if(pulseCode == PULSE_FROM_ISRHANDLER){
				if(pulseVal == BTN_START_PRESSED){
					lc->operatingNormal();
					aHal->engineFullUnstop();
					state = ERR_STATE_IDLE;
					error = false;
				}
			}
			break;*/
		case ERR_STATE_TURNOVER_BAND2:
			aHal->engineFullStop();
			lc->upcomingNotReceipted();
			if(pulseCode == PULSE_FROM_ISRHANDLER){
				if(pulseVal == BTN_RESET_PRESSED){
					lc->upcomingReceipted();
					state = ERR_STATE_TURNOVER_BAND2_RECEIPTED;
				}
			}
			break;
		case ERR_STATE_TURNOVER_BAND2_RECEIPTED:
			if(pulseCode == PULSE_FROM_ISRHANDLER){
				if(pulseVal == SB_START_OPEN){
					isSbStartOpen = true;
				} else if(pulseVal == BTN_START_PRESSED && isSbStartOpen){
					isSbStartOpen = false;
					lc->operatingNormal();
					//msg puck error solved, reihenfolge unstop und msg puck?!
					sendPuckReply();
					aHal->engineFullUnstop();
					error = false;
					th->continueAllTimers();
					state = ERR_STATE_IDLE;
				}
			}
			break;
		case ERR_STATE_ESTOP:
			aHal->engineFullStop();
			lc->eStop();
			aHal->gate(false);
			unblockWaitingPucks();
			if(pulseCode == PULSE_FROM_ISRHANDLER){
				if(pulseVal == BTN_ESTOP_RELEASED && isEstopPressed){
					lc->upcomingReceipted();
					state = ERR_STATE_ESTOP_RECEIPTED;
				}
			}
			break;
		case ERR_STATE_ESTOP_RECEIPTED:
			if(pulseCode == PULSE_FROM_ISRHANDLER){
				if(pulseVal == BTN_RESET_PRESSED){
					isEstopPressed = false;
					PuckHandler::getInstance()->reset();
					th->reset();
					lc->lightsOff();
					if(disp->isRunning()){
						lc->operatingNormal();
					}
					aHal->engineFullUnstop();
					aHal->revokeEngineRight();
					disp->setEstop(false);
					disp->setError(false);

					error = false;
					isSbStartOpen = false;
					isEstopPressed = false;
					isStopPressed = false;
					isEngineStopped = false;
					isSbSlideClosed = false;
					state = ERR_STATE_IDLE;
				}
			}
			break;
		case ERR_STATE_STOP:
			aHal->engineFullStop();
			lc->bandHalted();
			if(pulseCode == PULSE_FROM_ISRHANDLER){
				if(pulseVal == BTN_START_PRESSED){
					isStopPressed = false;
					lc->operatingNormal();
					aHal->engineFullUnstop();
					if(isEngineStopped){
						aHal->engineStop();
					}
					th->continueAllTimers();
					state = oldState;
				}
			}
			break;
		default:
			printf("nop\n");
		}
	}
}

void ErrorFSM::stop() {
	HAWThread::stop();

	if (ConnectDetach(replyCoid) == -1) {
		printf("ErrorFSM: Error in ConnectDetach\n");
	}

	if (ChannelDestroy(replyChid) == -1) {
		printf("ErrorFSM: Error in ChannelDestroy\n");
	}

	if (ChannelDestroy(ownChid) == -1) {
		printf("ErrorFSM: Error in ChannelDestroy\n");
	}
}

void ErrorFSM::shutdown() {
}

int ErrorFSM::getErrorFSMChid() {
	return ownChid;
}

int ErrorFSM::getReplyChid() {
	return replyChid;
}

void ErrorFSM::sendPuckReply(){
	int rc = MsgSendPulse(replyCoid, SIGEV_PULSE_PRIO_INHERIT, PULSE_FROM_ERR_FSM, 0/*ERROR_SOLVED*/);
	if (rc < 0) {
		printf("ErrorFSM: Error in MsgSendPulse\n");
	}
}

void ErrorFSM::unblockWaitingPucks(){
	if (ConnectDetach(replyCoid) == -1) {
		printf("ErrorFSM: Error in ConnectDetach\n");
	}

	if (ChannelDestroy(replyChid) == -1) {
		printf("ErrorFSM: Error in ChannelDestroy\n");
	}

	if ((replyChid = ChannelCreate(0)) == -1) {
		printf("ErrorFSM: Error in ChannelCreate\n");
	}

	if ((replyCoid = ConnectAttach(0, 0, replyChid, _NTO_SIDE_CHANNEL, 0)) == -1) {
		printf("ErrorFSM: Error in ConnectAttach\n");
	}
}
