/*
 * B2S07_Seg3.h
 *
 *  Created on: 08.06.2013
 * @author Erik Matthiessen
 *         Denis Rycka
 *         Nilüfer Güngör
 *         Maschhood Ahmad
 *
 */

#ifndef B2S07_SEG3_H_
#define B2S07_SEG3_H_

#include "BaseState.h"
#include "B2S08_End.h"

class B2S07_Seg3: public BaseState {
public:
	B2S07_Seg3(Controller* controller);
	virtual ~B2S07_Seg3();

	void sbEndOpen();
	void timerGateClose();
	void timerSeg3Min();
	void timerSeg3Max();
};

#endif /* B2S07_SEG3_H_ */
