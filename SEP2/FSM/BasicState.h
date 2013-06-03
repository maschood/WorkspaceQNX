/*
 * BasicState.h
 *
 *  Created on: 03.06.2013
 *      Author: maschood
 */

#ifndef BASICSTATE_H_
#define BASICSTATE_H_

#include "DISPATCHER/HALCallInterface.h"
#include "HAL_A.h"
#include <stdio.h>
#include "RS232_1.h"
#include "Controller.h"

class BasicState: public HALCallInterface  {
public:
	BasicState();
	virtual ~BasicState();

	virtual void PART_IN_0(void) {}
	virtual void PART_IN_1(void) {}
	virtual void PART_HEIGHT_0(void) {}
	virtual void PART_HEIGHT_1(void) {}
	virtual void PART_IN_GATE_0(void) {}
	virtual void PART_IN_GATE_1(void) {}
	virtual void PART_METALL(void) {}
	virtual void GATE_STATUS_0(void) {}
	virtual void GATE_STATUS_1(void) {}
	virtual void SLIDE_FULL_0(void) {}
	virtual void SLIDE_FULL_1(void) {}
	virtual void PART_OUT_0(void) {}
	virtual void PART_OUT_1(void) {}
	virtual void START_BTN_PRESSED(void) {}
	virtual void START_BTN_RELEASED(void) {}
	virtual void STOP_BTN_PRESSED(void) {}
	virtual void STOP_BTN_RELEASED(void) {}
	virtual void RESET_BTN_PRESSED(void) {}
	virtual void RESET_BTN_RELEASED(void) {}
	virtual void ESTOP_BTN_PRESSED(void) {}
	virtual void ESTOP_BTN_RELEASED(void) {}

protected:

	HAL_A* hal_a;
};

#endif /* BASICSTATE_H_ */
