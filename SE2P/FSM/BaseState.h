/**
 *  Created on: 04.05.2013
 * @author Erik Matthiessen
 *         Denis Rycka
 *         Nil�fer G�ng�r
 *         Maschhood Ahmad
 *
 */

#ifndef BASESTATE_H_
#define BASESTATE_H_

#include <stdio.h>
#include "CallInterface.h"
#include "PuckHandler.h"
#include "HAL_A.h"
#include "HAL_S.h"
#include "ErrorFSM.h"
#include "RS232_1.h"
#include "TimerHandler.h"
#include "time_values.h"
#include "Dispatcher.h"

#define DEBUG_STATE_PRINTF

class BaseState: public CallInterface {
public:
	/**
	 * Standard constructor, all private defined variables are
	 * instanciated here.
	 */
	BaseState(Controller* controller);

	/**
	 * BasteState is derived from CallInterface, all methods already commented
	 * in CallInterface.h
	 * All methods are implemented in this class as empty method stubs. If one is called
	 * and not overwritten by the substate its corresponding call from this superclass
	 * is a NOOP.
	 */
	virtual void sbStartOpen();
	virtual void sbStartClosed();
	virtual void sbHeightcontrolOpen();
	virtual void sbHeightcontrolClosed();
	virtual void sbGateOpen();
	virtual void sbGateClosed();
	virtual void msMetalTrue();
	virtual void sbSlideOpen();
	virtual void sbSlideClosed();
	virtual void sbEndOpen();
	virtual void sbEndClosed();
	virtual void btnStartPressed();
	virtual void btnStartReleased();
	virtual void btnStopPressed();
	virtual void btnStopReleased();
	virtual void btnResetPressed();
	virtual void btnResetReleased();
	virtual void btnEstopPressed();
	virtual void btnEstopReleased();

	virtual void rs232Band2Ack();
	virtual void rs232Band2Ready();
	virtual void rs232Band1Waiting();
	virtual void rs232PuckArrivedOnBand2();

	virtual void timerGateClose();
	virtual void timerSlideFull();
	virtual void timerSeg1Min();
	virtual void timerSeg1Max();
	virtual void timerSeg2Min();
	virtual void timerSeg2Max();
	virtual void timerSeg3Min();
	virtual void timerSeg3Max();
	virtual void timerHandOver();
	virtual void timerBand2Ack();

	/**
	 * Standard destructor
	 */
	virtual ~BaseState();

protected:

	Dispatcher* disp;
	/**
	 * Instance of the ActorHAL to work with
	 */
	HAL_A* hal_a;

	/**
	 * Instance of the SensorHAL to work with
	 */
	HAL_S* hal_s;

	/**
	 * Instance of the PuckHandler to work with
	 */
	PuckHandler* puckHandler;

	/**
	 * Instance of the Controller to work with
	 */
	Controller* controller;

	/**
	 * Instance of the ErrorFSM to work with
	 */
	ErrorFSM* errfsm;

	/**
	 * Instance of the RS232 port 1 to work with
	 */
	RS232_1* rs232_1;

	/**
	 * Instance of the TimerHandler to work with
	 */
	TimerHandler* timerHandler;
};

#endif /* BASESTATE_H_ */
