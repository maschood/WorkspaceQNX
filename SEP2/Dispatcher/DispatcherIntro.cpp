/*
 * DispatcherIntro.cpp
 */

#include "Dispatcher/DispatcherIntro.h"

#include "Dispatcher/HALCallInterface.h"
#include "HAL_ISR/HAL_ISR.h"


DispatcherIntro::DispatcherIntro()
  : signalChid(HAL_ISR::getInstance()->getSignalChid()) {

    funcArr[0] = &HALCallInterface::WERKS_EINLAUF_0;
    funcArr[1] = &HALCallInterface::WERKS_EINLAUF_1;
    funcArr[2] = &HALCallInterface::WERKS_IN_HOEHENMESSUNG_0;
    funcArr[3] = &HALCallInterface::WERKS_IN_HOEHENMESSUNG_1;
    funcArr[4] = &HALCallInterface::WERKS_IN_WEICHE_0;
    funcArr[5] = &HALCallInterface::WERKS_IN_WEICHE_1;
    funcArr[6] = &HALCallInterface::RUTSCHE_VOLL_0;
    funcArr[7] = &HALCallInterface::RUTSCHE_VOLL_1;
    funcArr[8] = &HALCallInterface::WERKS_AUSLAUF_0;
    funcArr[9] = &HALCallInterface::WERKS_AUSLAUF_1;
}

DispatcherIntro::~DispatcherIntro() {
}

void DispatcherIntro::registerController(HALCallInterface *controller, SignalType signalType, int val) {
    controllers[2*signalType + val].push_back(controller);
}

void DispatcherIntro::signal(int signal) {
    list<HALCallInterface*>::iterator it;
    for (it = controllers[signal].begin(); it != controllers[signal].end(); it++) {
        ((*it)->*funcArr[signal])();
    }
}

void DispatcherIntro::execute(void *arg)
{
    struct _pulse pulse;
    while(!isStopped()) {
        if (-1 == MsgReceivePulse(signalChid, &pulse, sizeof(pulse), NULL)) {
            if (isStopped()) break; // ###### ChannelDestroyed, Thread endet
            perror("Dispatcher: MsgReceivePulse failed");
            exit(EXIT_FAILURE);
        }

        // code and value are -1 if not used
        if (pulse.code >= 0 && pulse.value.sival_int >= 0) {
        	cout<<"Message erhalten"<<endl;
            signal(2*pulse.code + pulse.value.sival_int);
        }
    }
}

void DispatcherIntro::shutdown(void)
{
#ifdef DEBUG_MESSAGES
    cout << "Dispatcher: shutting down..." << endl;
#endif
}
