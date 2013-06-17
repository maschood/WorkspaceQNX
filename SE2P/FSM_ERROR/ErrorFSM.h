/**
 * @file ErrorFSM.h
 * @author Erik Matthiessen
 *         Denis Rycka
 *         Nilüfer Güngör
 *         Maschhood Ahmad
 */


#ifndef ERRORFSM_H_
#define ERRORFSM_H_

#include <sys/neutrino.h>
#include "Addresses.h"
#include "HAWThread.h"
#include "messages.h"
#include "errorStates.h"
#include "HAL_A.h"
#include "LightController.h"
#include "Mutex.h"
#include "Dispatcher.h"
#include "PuckHandler.h"
#include "TimerHandler.h"

#define DEBUG_ErrorFSM

class ErrorFSM: public thread::HAWThread {
public:
	/**
	 * Standard destructor. ErrorFSM is implemented as singleton.
	 * Instance and corresponding mutex is deleted here.
	 */
	virtual ~ErrorFSM();

	/**
	 * Returns an instance of the ErrorFSM to work with
	 *
	 * @return ErrorFSM instance
	 */
	static ErrorFSM* getInstance();

	/**
	 * Starts the ErrorFSM, blocks in MsgReceivePulse in initial state
	 * IDLE. Reacts on pulses from pucks, ISRHandler and RS232.
	 */
	virtual void execute(void* arg);

	/**
	 * Empty shutdown method
	 */
	virtual void shutdown();

	/**
	 * Stops thread execution. If called, at first stop() method in superclass
	 * is called. Then thread detaches from attached channels.
	 */
	void stop();

	/**
	 * Returns channel id for communicating with ErrorFSM
	 */
	int getErrorFSMChid();

	/**
	 * Returns channel id for communicating with pucks
	 */
	int getReplyChid();

	/**
	 * If EStop was pressed in an error state, a puck my block in a MsgReceivePulse
	 * in his state. It will be unblocked by calling this function, so Dispatcher can
	 * work properly.
	 */
	void unblockWaitingPucks();

private:
	/**
	 * Singleton constructor. Variables and states are initialized and
	 * creation of both needed channels and ConnectAttach.
	 */
	ErrorFSM();

	/**
	 * If an error was fixed the ErrorFSM sends a response pulse message
	 * to the calling puck. Response is send by calling this method
	 * using the reply channel.
	 */
	void sendPuckReply();

	/**
	 * Channel id of the ErrorFSM to receive pulse messages
	 */
	int ownChid;

	/**
	 * Channel id for the reply channel for ConnectAttach
	 */
	int replyChid;

	/**
	 * Connection id of the reply channel to send pulse messages to pucks
	 */
	int replyCoid;

	/**
	 * ErrorFSM instance
	 */
	static ErrorFSM* instance;

	/**
	 * Mutex to secure singleton pattern
	 */
	static Mutex* errfsmInstanceMutex;

	/**
	 * The state the ErrorFSm is actually working in
	 */
	int state;

	/**
	 * If old state needs to be backed up, it is saved here
	 */
	int oldState;

	HAL_A* hal_a;

	/**
	 * Dispatcher instance to work with
	 */
	Dispatcher* disp;

	/**
	 * LightController instance to work with
	 */
	LightController* lc;

	/**
	 * TimerHandler instance to work with
	 */
	TimerHandler* th;
};

#endif /* ERRORFSM_H_ */
