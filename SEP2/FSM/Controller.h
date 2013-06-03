/*
 * Controller.h
 *
 *  Created on: 03.06.2013
 *      Author: maschood
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_


#include "DISPATCHER/HALCallInterface.h"
#include "BasicState.h"
class BasicState;
#include "HAL_A.h"

#include <iostream.h>

class Controller : public HALCallInterface  {
public:
	Controller(int id);
	virtual ~Controller();

	void PART_IN_0();
	void PART_IN_1();

	void PART_HEIGHT_0();
	void PART_HEIGHT_1();

	void PART_IN_GATE_0();
	void PART_IN_GATE_1();

	void PART_METALL();

	void GATE_STATUS_0();
	void GATE_STATUS_1();

	void SLIDE_FULL_0();
	void SLIDE_FULL_1();

	void PART_OUT_0();
	void PART_OUT_1();

	//Port C
	void START_BTN_PRESSED();
	void START_BTN_RELEASED();

	void STOP_BTN_PRESSED();
	void STOP_BTN_RELEASED();

	void RESET_BTN_PRESSED();
	void RESET_BTN_RELEASED();

	void ESTOP_BTN_PRESSED();
	void ESTOP_BTN_RELEASED();

private:

	int id;
	BasicState* state;
};


#endif /* CONTROLLER_H_ */
