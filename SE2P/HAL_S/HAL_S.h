/**
 * @file HAL_S.h
  Created on: 30.04.2013
 * @author Erik Matthiessen
 *         Denis Rycka
 *         Nilüfer Güngör
 *         Maschhood Ahmad
 */

#ifndef HAL_S_H_
#define HAL_S_H_

#include <stdlib.h>
#include <iostream>
#include "sys/siginfo.h"
#include "FestoSelection.h"

#include "Addresses.h"
#include "HWaccess.h"
#include "Mutex.h"
#include "puckTypes.h"


class HAL_S {
public:
	virtual ~HAL_S();
	static HAL_S* getInstance();
	int getChid();
	int getCoid();
	int getHeightPuckType();
	int getHeight();
	void stopInterrupt();

private:
	HAL_S();
	void initInterrupt();
	int chid;
	int coid;
	int interruptId;
	struct sigevent event;
	static HAL_S* instance;
	static Mutex* halsInstanceMutex;
};

#endif /* HAL_S */
