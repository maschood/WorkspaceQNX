/*
 * B1S04_Seg2.h
 *
 *  Created on: 03.06.2013
 * @author Erik Matthiessen
 *         Denis Rycka
 *         Nil�fer G�ng�r
 *         Maschhood Ahmad
 *
 */

#ifndef B1S04_SEG2_H_
#define B1S04_SEG2_H_

#include "BaseState.h"
#include "B1S05_Gate.h"

class B1S04_Seg2: public BaseState {
public:
	B1S04_Seg2(Controller* controller);
	void msMetalTrue();
	virtual ~B1S04_Seg2();

	void sbGateOpen();
	void timerSeg2Min();
	void timerSeg2Max();
};

#endif /* B1S04_SEG2_H_ */
