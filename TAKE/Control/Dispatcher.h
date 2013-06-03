/**
 * SE2 WiSe 2012
 * Festo Dispatcher
 *
 * Dispatcher forwards Pulse Messages received from the ISRHandler and RS232 to
 * all registered Controllers. Each Controller represents a puck on the band conveyor.
 * Controllers need the messages to do their transitions to get into another state.
 * The Dispatcher is part of the controller/reactor mechanism for the state pattern
 *
 * @file Dispatcher.h
 * @author Chris Addo
 *         Jens Eberwein
 *         Tristan Rudat
 *         Martin Slowikowski
 * @date 2012-11-28
 * @version 0.4
 *
 */

#ifndef DISPATCHER_H_
#define DISPATCHER_H_

#include <vector>
#include <stdint.h>
#include "HAWThread.h"
#include "HWaccess.h"
#include "messages.h"
#include "address.h"
#include "Mutex.h"
#include "CallInterface.h"
#include "LightController.h"
#include "RS232_1.h"

//#define DEBUG_DISPATCHER

typedef void (CallInterface::*callFuncs)();

class Dispatcher: public thread::HAWThread {
public:
	/**
	 * Class implemented as singleton. Method returns an instance of the
	 * Dispatcher to work with
	 *
	 * @return Dispatcher instance
	 */
	static Dispatcher* getInstance();

	/**
	 * Starts the dispatcher. If start is pressed at festo system,
	 * dispatching will start.
	 */
	virtual void execute(void* arg);

	/**
	 * Empty shutdown method
	 */
	virtual void shutdown();

	/**
	 * Stops thread execution. At first stop() method in superclass is called.
	 * Afterwards created dispatcher channel (for receiving pulse messages)
	 * is destroyed. After that thread will get out of blocked MsgReceivePulse()-call
	 * and execution ends.
	 */
	void stop();

	/**
	 * Standard destructor. If an instance of Dispatcher was created, it is destroyed,
	 * as well as its corresponding mutex.
	 */
	virtual ~Dispatcher();

	/**
	 * Controllers (Pucks) can register for all existing functions to get callback for.
	 *
	 * @param context referenced puck
	 */
	void registerContextForAllFuncs(CallInterface* context);

	/**
	 * Returns channel-id for ConnectAttach for sending pulse messages to the Dispatcher
	 *
	 * @return channelid of Dispatcher
	 */
	int getChid();

	/**
	 * Sets corresponding bool if button EStop is pressed at festo system. If set to
	 * true, dispatching stops until reset.
	 *
	 * @param eStop [true if button pressed, false if not]
	 */
	void setEstop(bool eStop);


	/**
	 * Sets corresponding bool if an error occured in the festo system. If set to
	 * true, dispatching stops until error was fixed.
	 *
	 * @param error [true if error occured, false if not]
	 */
	void setError(bool error);

	/**
	 * Returns if Dispatcher is working at the moment or stoppped dispatching.
	 *
	 * @return [true if Dispatcher is working, false if not]
	 */
	bool isRunning();

private:
	/**
	 * Setting up functionpointer array for all signals to dispatch to the registered controllers.
	 * Also the channel for pulse messages to the Dispatcher is created.
	 */
	Dispatcher();

	/**
	 * Instance for using Dispatcher (Singleton implementation)
	 */
	static Dispatcher* instance;

	/**
	 * Mutex for securing singleton implementation
	 */
	static Mutex* dispatcherInstanceMutex;

	/**
	 * Channel id for Dispatcher
	 */
	int chid;

	/**
	 * Represents status of EStop Button [true if button pressed, false if not]
	 */
	bool eStop;

	/**
	 * Indicates if an error occured [true if yes, false if not]
	 */
	bool error;

	/**
	 * Indicates if Dispatcher is working or stopped dispatching.
	 */
	bool running;

	/**
	 * Instance of the LightController
	 */
	LightController* lc;

	/**
	 *  Array for all known sensor signals (*fp), initialized in constructor
	 */
	callFuncs* sensorFuncArr;

	/**
	 *  Array for all known RS232 signals (*fp), initialized in constructor
	 */
	callFuncs* rs232FuncArr;

	/**
	 *  Array for all known RS232 signals (*fp), initialized in constructor
	 */
	callFuncs* timerFuncArr;

	/**
	 * Vector contains all Controllers (Pucks) registered for sensor messages
	 */
	vector<CallInterface*> controllersForSensorFunc[SENSOR_MESSAGES_SIZE];

	/**
	 * * Vector contains all Controllers (Pucks) registered for RS232 messages
	 */
	vector<CallInterface*> controllersForRS232Func[RS232_MESSAGES_SIZE];

	/**
	 * * Vector contains all Controllers (Pucks) registered for RS232 messages
	 */
	vector<CallInterface*> controllersForTimerFunc[TIMER_MESSAGES_SIZE];
};

#endif /* DISPATCHER_H_ */
