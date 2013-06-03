/*
 * B2S05_Gate.h
 *
 *  Created on: 25.11.2012
 *      Author: martin
 */

#ifndef B2S05_GATE_H_
#define B2S05_GATE_H_

#include "BaseState.h"
#include "B2S06_Slide.h"
#include "B2S07_Seg3.h"

class B2S05_Gate: public BaseState {
public:
	B2S05_Gate(Controller* controller);
	virtual ~B2S05_Gate();

	void sbGateClosed();
	void sbSlideOpen();
};

#endif /* B2S05_GATE_H_ */
