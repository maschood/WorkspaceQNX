/*
 * B2S11_ERR_MetalRerverse.h
 *
 *  Created on: 09.06.2013
 * @author Erik Matthiessen
 *         Denis Rycka
 *         Nil�fer G�ng�r
 *         Maschhood Ahmad
 *
 */


#ifndef B2S11_ERR_METALRERVERSE_H_
#define B2S11_ERR_METALRERVERSE_H_

#include "BaseState.h"
#include "B2S01_Entry.h"

class B2S11_ERR_MetalRerverse: public BaseState {
public:
	B2S11_ERR_MetalRerverse(Controller* controller);
	virtual ~B2S11_ERR_MetalRerverse();
};

#endif /* B2S11_ERR_METALRERVERSE_H_ */
