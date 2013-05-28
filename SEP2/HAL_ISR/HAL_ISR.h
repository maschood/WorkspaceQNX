/*
 * HAL_ISR.h
 *
 *  Created on: 30.04.2013
 *      Author: maschood
 */

#include "Addresses.h"
#include "HWaccess.h"
#include "HAL_A/HAL_A.h"
#include "HAWThread/HAWThread.h"
#include "HAL_S/HAL_S.h"

using namespace thread;

#ifndef HAL_ISR_H_
#define HAL_ISR_H_

const struct sigevent * ISR (void *arg, int id);

class HAL_ISR : public thread::HAWThread {
public:
	virtual ~HAL_ISR();
	static HAL_ISR* getInstance();
	void stop();
	int getSignalChid(void);
private:
	HAL_ISR();
	void initInterrupt();
	int chid;
	struct sigevent event;
	int interruptId;

	int signalChid;
	int signalCoid;

	uint8_t portBstatus;
	uint8_t portCstatus;
	static HAL_ISR* instance;

	HAL_S* hal_s;

protected:
	virtual void execute(void* arg);
	virtual void shutdown();

};

#endif /* HAL_ISR_H_ */
