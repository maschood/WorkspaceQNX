/*
 * B2S10_ERR_SlideFull.h
 *
 *  Created on: 27.11.2012
 *      Author: aba079
 */

#ifndef B2S10_ERR_SLIDEFULL_H_
#define B2S10_ERR_SLIDEFULL_H_

#include "BaseState.h"
#include "B2S06_Slide.h"

class B2S10_ERR_SlideFull: public BaseState {
public:
	B2S10_ERR_SlideFull(Controller* controller);
	virtual ~B2S10_ERR_SlideFull();
};

#endif /* B2S10_ERR_SLIDEFULL_H_ */
