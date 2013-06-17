/*
 * B1S03_Height.h
 *
 *  Created on: 03.06.2013
 * @author Erik Matthiessen
 *         Denis Rycka
 *         Nilüfer Güngör
 *         Maschhood Ahmad
 *
 */

#ifndef B1S03_HEIGHT_H_
#define B1S03_HEIGHT_H_

#include "BaseState.h"
#include "B1S04_Seg2.h"

class B1S03_Height: public BaseState {
public:
	B1S03_Height(Controller* controller);
	void sbHeightcontrolClosed();
	virtual ~B1S03_Height();
};

#endif /* B1S03_HEIGHT_H_ */
