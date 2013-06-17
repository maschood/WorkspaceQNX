/*
 * B1S05_Gate.h
 *
 *  Created on: 03.06.2013
 * @author Erik Matthiessen
 *         Denis Rycka
 *         Nilüfer Güngör
 *         Maschhood Ahmad
 *
 */

#ifndef B1S05_GATE_H_
#define B1S05_GATE_H_

#include "BaseState.h"
#include "B1S06_Slide.h"
#include "B1S07_Seg3.h"

class B1S05_Gate: public BaseState {
public:
	B1S05_Gate(Controller* controller);
	virtual ~B1S05_Gate();

	void sbGateClosed();
	void sbSlideOpen();
};

#endif /* B1S05_GATE_H_ */
