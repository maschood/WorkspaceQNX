/*
 * DispatcherIntro.h
 *
 *  Created on: 06.05.2013
 *      Author: Peter
 */

#ifndef DISPATCHERINTRO_H_
#define DISPATCHERINTRO_H_


#include "HAWThread.h"
using namespace thread;

#include "Dispatcher/HALCallInterface.h"
#include "SignalType.h"

#include <list>

class DispatcherIntro : public HAWThread {
private:
    list<HALCallInterface*> controllers[N_SIGNALE]; // registered controllers
    int signalChid;

    // typedef to use array of member methods
    typedef void (HALCallInterface::*FP)(void);
    FP funcArr[N_SIGNALE];

public:
    DispatcherIntro();
    virtual ~DispatcherIntro();

    /**
     * Register a controller for a specified signal.
     *
     * @param   controller  the controller to be registered
     * @param   sensor      the sensor to be observed
     * @param   val         the value of the sensor for notification
     */
    void registerController(HALCallInterface* controller, SignalType signalType, int val);

private:
    /**
     * Signal all controllers.
     */
    void signal(int signal);

protected:
    void execute(void* arg);
    void shutdown(void);
};

#endif /* DISPATCHERINTRO_H_ */
