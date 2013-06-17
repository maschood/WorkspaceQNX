/*
 * B1S09_ERR_TurnOver.h
 *
 *  Created on: 03.06.2013
 * @author Erik Matthiessen
 *         Denis Rycka
 *         Nilüfer Güngör
 *         Maschhood Ahmad
 *
 */

#ifndef B1S09_ERR_TURNOVER_H_
#define B1S09_ERR_TURNOVER_H_

#include "BaseState.h"
#include "B1S08_End.h"

class B1S09_ERR_TurnOver: public BaseState {
public:
	B1S09_ERR_TurnOver(Controller* controller);

	void sbEndOpen();
	void sbEndClosed();
	virtual ~B1S09_ERR_TurnOver();
};

#endif /* B1S09_ERR_TURNOVER_H_ */
