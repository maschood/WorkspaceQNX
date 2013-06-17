/*
 * B2S03_Height.h
 *
 *  Created on: 08.06.2013
 * @author Erik Matthiessen
 *         Denis Rycka
 *         Nil�fer G�ng�r
 *         Maschhood Ahmad
 *
 */

#ifndef B2S03_HEIGHT_H_
#define B2S03_HEIGHT_H_

#include "BaseState.h"
#include "B2S04_Seg2.h"

class B2S03_Height: public BaseState {
public:
	B2S03_Height(Controller* controller);
	void sbHeightcontrolClosed();
	virtual ~B2S03_Height();
};

#endif /* B2S03_HEIGHT_H_ */
