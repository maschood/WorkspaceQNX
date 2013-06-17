/*
 * B1S11_ReadyWait.h
 *
 *  Created on: 01.12.2012
 *      Author: martin
 */

#ifndef B1S11_READYWAIT_H_
#define B1S11_READYWAIT_H_

#include "BaseState.h"
#include "B1S08_End.h"

class B1S11_ReadyWait: public BaseState {
public:
	B1S11_ReadyWait(Controller* controller);
	virtual ~B1S11_ReadyWait();

	void rs232Band2Ack();
	void rs232Band2Ready();
	void timerBand2Ack();
};

#endif /* B1S11_READYWAIT_H_ */
