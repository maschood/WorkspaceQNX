/*
 * B1S02_Seg1.h
 *
 *  Created on: 03.06.2013
 * @author Erik Matthiessen
 *         Denis Rycka
 *         Nil�fer G�ng�r
 *         Maschhood Ahmad
 *
 */

#ifndef B1S02_SEG1_H_
#define B1S02_SEG1_H_

#include "BaseState.h"
#include "B1S03_Height.h"

class B1S02_Seg1: public BaseState {
public:
	B1S02_Seg1(Controller* controller);

	void sbHeightcontrolOpen();
	void timerSeg1Min();
	void timerSeg1Max();

	virtual ~B1S02_Seg1();
};

#endif /* B1S02_SEG1_H_ */
