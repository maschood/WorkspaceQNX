/*
 * B2S02_Seg1.h
 *
 *  Created on: 08.06.2013
 * @author Erik Matthiessen
 *         Denis Rycka
 *         Nilüfer Güngör
 *         Maschhood Ahmad
 *
 */

#ifndef B2S02_SEG1_H_
#define B2S02_SEG1_H_

#include "BaseState.h"
#include "B2S03_Height.h"

class B2S02_Seg1: public BaseState {
public:
	B2S02_Seg1(Controller* controller);

	void sbHeightcontrolOpen();
	void timerSeg1Min();
	void timerSeg1Max();

	virtual ~B2S02_Seg1();
};

#endif /* B2S02_SEG1_H_ */
