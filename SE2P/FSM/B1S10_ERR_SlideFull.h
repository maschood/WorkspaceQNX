/*
 * B1S10_ERR_SlideFull.h
 *
 *  Created on: 03.06.2013
 * @author Erik Matthiessen
 *         Denis Rycka
 *         Nilüfer Güngör
 *         Maschhood Ahmad
 *
 */

#ifndef B1S10_ERR_SLIDEFULL_H_
#define B1S10_ERR_SLIDEFULL_H_

#include "BaseState.h"
#include "B1S06_Slide.h"

class B1S10_ERR_SlideFull: public BaseState {
public:
	B1S10_ERR_SlideFull(Controller* controller);
	virtual ~B1S10_ERR_SlideFull();
};

#endif /* B1S10_ERR_SLIDEFULL_H_ */
