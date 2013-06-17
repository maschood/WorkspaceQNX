/*
 * B1S01_Entry.h
 *
 *  Created on: 03.06.2013
 * @file address.h
 * @author Erik Matthiessen
 *         Denis Rycka
 *         Nilüfer Güngör
 *         Maschhood Ahmad
 *
 */

#ifndef B1S01_ENTRY_H_
#define B1S01_ENTRY_H_

#include "BaseState.h"
#include "B1S02_Seg1.h"

class B1S01_Entry: public BaseState {
public:
	B1S01_Entry(Controller* controller);

	void sbStartOpen();
	void sbStartClosed();

	virtual ~B1S01_Entry();
};

#endif /* B1S01_ENTRY_H_ */
