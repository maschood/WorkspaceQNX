/*
 * Sensorika.h
 *
 *  Created on: 29.04.2013
 *      Author: Autorus Dominatus
 */

#ifndef SENSORIKA_H_
#define SENSORIKA_H_

#include <stdint.h>
#include <iostream>
#include <unistd.h>

#include "Addresses.h"
#include "HWaccess.h"
#include "HAWThread/HAWThread.h"
#include "Mutex/Mutex.h"

const struct sigevent * ISR(void *arg, int id);

namespace hal {

class Sensorika: public thread::HAWThread {
private:
	static Sensorika* instance;

	int isrChild;
	int interruptID;
	struct sigevent event;

	uinit8_t portBstatus;
	uinit8_t portCstatus;

	Sensorika();
public:
	virtual ~Sensorika();
	static Sensorika* getInstance();

	void stop(); //HAWThread: stop -> virtual
protected:
	virtual void execute(void* arg);
	virtual void shutdown();
private:
	void initInterupts();
};

}
#endif /* SENSORIKA_H_ */
