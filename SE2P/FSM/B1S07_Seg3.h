/*
 * B1S07_Seg3.h
 *
 *  Created on: 03.06.2013
 * @author Erik Matthiessen
 *         Denis Rycka
 *         Nilüfer Güngör
 *         Maschhood Ahmad
 *
 */

#ifndef B1S07_SEG3_H_
#define B1S07_SEG3_H_

#include "BaseState.h"
#include "B1S08_End.h"

class B1S07_Seg3: public BaseState {
public:
	B1S07_Seg3(Controller* controller);
	virtual ~B1S07_Seg3();

	void sbEndOpen();
	void timerGateClose();
	void timerSeg3Min();
	void timerSeg3Max();
};

#endif /* B1S07_SEG3_H_ */
