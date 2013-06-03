/**
 * SE2 WiSe 2012
 * Test class for ISR with pulse messages
 *
 *
 * \file ISRTest.h
 * \author Chris Addo
 *         Jens Eberwein
 *         Tristan Rudat
 *         Martin Slowikowski
 * \date 2012-11-02
 * \version 0.1
 *
 */

#ifndef ISRTEST_H_
#define ISRTEST_H_

#include "HAWThread.h"
#include "address.h"
#include "SensorHAL.h"
#include "ActorHAL.h"
#include "LightController.h"

class ISRTest: public thread::HAWThread {
public:
	/**
	 * Standard constructor, gets instances for sensor and actor HAL.
	 */
	ISRTest();

	/**
	 * Standard destructor
	 */
	virtual ~ISRTest();

	/**
	 * Thread's execute method, receives pulse messages from the kernel
	 * from the ISR until stopped.
	 */
	virtual void execute(void* arg);

	/**
	 * Empty shutdown method
	 */
	virtual void shutdown();

	/**
	 * Overwritten stop() method from superclass HAWThread,
	 * if called also stops interrupts.
	 */
	void stop();

private:
	/**
	 * Actor hal instance to work with
	 */
	ActorHAL* aHal;

	/**
	 * Sensor hal instance to work with
	 */
	SensorHAL* sHal;
	LightController* lc;
};

#endif /* ISRTEST_H_ */
