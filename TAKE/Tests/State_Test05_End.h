/*
 * B1S01_Entry.h
 *
 *  Created on: 24.11.2012
 *      Author: martin
 */

#ifndef STATE_TEST_END_H_
#define STATE_TEST_END_H_

#include "BaseState.h"

class State_Test05_Slide: public BaseState {
public:
	State_Test05_Slide(Controller* controller);

	void sbEndClosed();
	virtual ~State_Test05_Slide();
};

#endif /* STATE_TEST_END_H_ */
