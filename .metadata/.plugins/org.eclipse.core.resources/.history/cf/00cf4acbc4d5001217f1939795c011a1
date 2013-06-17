/*
 * B1S08_End.h
 *
 *  Created on: 25.11.2012
 *      Author: martin
 */

#ifndef B1S08_END_H_
#define B1S08_END_H_

#include "BaseState.h"
#include "B1S09_ERR_TurnOver.h"
#include "B1S11_ReadyWait.h"

class B1S08_End: public BaseState {
public:
	B1S08_End(Controller* controller);
	virtual ~B1S08_End();

	void rs232PuckArrivedOnBand2();
	void sbEndClosed();
	void timerHandOver();
};

#endif /* B1S08_END_H_ */
