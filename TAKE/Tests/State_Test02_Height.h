/*
 * B1S01_Entry.h
 *
 *  Created on: 24.11.2012
 *      Author: martin
 */

#ifndef TEST_HEIGHT_H_
#define TEST_HEIGHT_H_

#include "BaseState.h"
#include "State_Test03_Gate.h"

class State_Test02_Height: public BaseState {
public:
	State_Test02_Height(Controller* controller);

	void sbHeightcontrolClosed();
	virtual ~State_Test02_Height();
};

#endif /* TEST_HEIGHT_H_ */
