/*
 * B2S01_Entry.h
 *
 *  Created on: 08.06.2013
 * @author Erik Matthiessen
 *         Denis Rycka
 *         Nil�fer G�ng�r
 *         Maschhood Ahmad
 *
 */

#ifndef B2S01_ENTRY_H_
#define B2S01_ENTRY_H_

#include "BaseState.h"
#include "B2S02_Seg1.h"

class B2S01_Entry: public BaseState {
public:
	B2S01_Entry(Controller* controller);

	void sbStartOpen();
	void sbStartClosed();

	virtual ~B2S01_Entry();
};

#endif /* B2S01_ENTRY_H_ */
