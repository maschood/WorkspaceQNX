/**
 * SE2 WiSe 2012
 * Sensor HAL class for ISR and sensor management
 *
 * Offers functions for the different sensor the festo
 * system has, like light barriers, metal and height sensor,
 * buttons. All nterrupt driven, except the height control.
 * ISR tells kernel to send a pulse msg to a specific channel.
 *
 * @file SensorHAL.h
 * @author Chris Addo
 *         Jens Eberwein
 *         Tristan Rudat
 *         Martin Slowikowski
 * @date 2012-11-02
 * @version 0.2
 *
 */

#ifndef SENSOR_H_
#define SENSOR_H_

#include <stdlib.h>
#include <iostream>
#include "sys/siginfo.h"

#include "address.h"
#include "HWaccess.h"
#include "Mutex.h"
#include "puckTypes.h"

//#define DEBUG_SENSORHAL

class SensorHAL {
public:
	/**
	 * standard destructor
	 */
	virtual ~SensorHAL();

	/**
	 * Returns an instance for the sensor hal to work with.
	 * @return sensor hal instance
	 */
	static SensorHAL* getInstance();

	/**
	 * Channel ID for the ISR pulse messages
	 * @return channelid
	 */
	int getChid();

	/**
	 * Connection ID for the connection to the channel used
	 * for ISR pulse messages
	 * @return connectionid
	 */
	int getCoid();

	/**
	 * Returns the type of a puck that is currently lying in
	 * the height measurement on the band conveyor.
	 * Valid types are defined in puckTypes.h
	 *
	 * @return pucktype
	 */
	int getHeightPuckType();

	/**
	 * Returns an integer value representing measured height
	 * from the height sensor.
	 * @return height
	 */
	int getHeight();

	/**
	 * Called if ISR is no longer needed. Unbinds ISR from IRQ,
	 * disconnects from channel, closes channel.
	 * If used in a thread, thread's stop() method should be
	 * overwritten and if thread is called to stop, this function
	 * should be called afterwards for a clean shutdown.
	 */
	void stopInterrupt();

private:
	/**
	 * Standard constructor, initializes the IRQs and ISR
	 */
	SensorHAL();

	/**
	 * Initializes the IRQs and ISR, called by constructor
	 */
	void initInterrupt();


	/**
	 * Channel ID for channel used by kernel for pulse messages
	 * from the ISR
	 */
	int chid;

	/**
	 * Connection ID for connection to the channel used by kernel for
	 * pulse messages from the ISR.
	 */
	int coid;

	/**
	 * Interrupt ID for the ISR binded to IRQ 11
	 */
	int interruptId;

	/**
	 * Event structure for pulse messages to be send by kernel after
	 * ISR was called
	 */
	struct sigevent event;

	/**
	 * Instance for using Sensor HAL (Singleton)
	 */
	static SensorHAL* instance;

	/**
	 * Mutex for securing access to hal instance
	 */
	static Mutex* sensorInstanceMutex;

};

#endif /* SENSOR_H_ */
