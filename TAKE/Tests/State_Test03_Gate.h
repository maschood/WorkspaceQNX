/*
 * B1S01_Entry.h
 *
 *  Created on: 24.11.2012
 *      Author: martin
 */

#ifndef TEST_GATE_H_
#define TEST_GATE_H_

#include "BaseState.h"
#include "State_Test04_Slide.h"

class State_Test03_Gate: public BaseState {
public:
	State_Test03_Gate(Controller* controller);

	void sbGateClosed();
	virtual ~State_Test03_Gate();
};

#endif /* TEST_GATE_H_ */
