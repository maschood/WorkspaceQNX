/**
 * @file HAL_ISR.h
  Created on: 30.04.2013
 * @author Erik Matthiessen
 *         Denis Rycka
 *         Nilüfer Güngör
 *         Maschhood Ahmad
 */


#ifndef HAL_ISR_H_
#define HAL_ISR_H_

#include "HAWThread.h"
#include "Addresses.h"
#include "HAL_S.h"
#include "messages.h"
#include "Mutex.h"
#include "Dispatcher.h"
#include "ErrorFSM.h"


class HAL_ISR: public thread::HAWThread {
public:
	virtual ~HAL_ISR();
	static HAL_ISR* getInstance();
	virtual void execute(void* arg);
	virtual void shutdown();
	void stop();

private:
	HAL_ISR();
	static HAL_ISR* instance;
	static Mutex* hal_isrInstanceMutex;
	HAL_S* hal_s;
	Dispatcher* disp;
	ErrorFSM* errfsm;
	LightController* lc;
	int dispatcherChid;
	int errfsmChid;
	int dispatcherCoid;
	int errfsmCoid;
};

#endif /* HAL_ISR_H_ */
