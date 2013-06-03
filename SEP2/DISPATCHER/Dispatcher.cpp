/*
 * DispatcherIntro.cpp
 */

#include "DISPATCHER/Dispatcher.h"

#include "DISPATCHER/HALCallInterface.h"
#include "HAL_ISR/HAL_ISR.h"


Dispatcher::Dispatcher()
  : signalChid(HAL_ISR::getInstance()->getSignalChid()) {
	int i = 0;

//    funcArr[i] = &HALCallInterface::PART_IN_0;
//    funcArr[i++] = &HALCallInterface::PART_IN_1;
//    funcArr[i++] = &HALCallInterface::PART_HEIGHT_0;
//    funcArr[i++] = &HALCallInterface::PART_HEIGHT_1;
//    funcArr[i++] = &HALCallInterface::PART_IN_GATE_0;
//    funcArr[i++] = &HALCallInterface::PART_IN_GATE_1;
//    funcArr[i++] = &HALCallInterface::PART_METALL;
//    funcArr[i++] = &HALCallInterface::GATE_STATUS_0;
//    funcArr[i++] = &HALCallInterface::GATE_STATUS_1;
//    funcArr[i++] = &HALCallInterface::SLIDE_FULL_0;
//    funcArr[i++] = &HALCallInterface::SLIDE_FULL_1;
//    funcArr[i++] = &HALCallInterface::PART_OUT_0;
//    funcArr[i++] = &HALCallInterface::PART_OUT_1;
    funcArr[15] = &HALCallInterface::START_BTN_PRESSED;
    funcArr[14] = &HALCallInterface::START_BTN_RELEASED;
    funcArr[18] = &HALCallInterface::STOP_BTN_PRESSED;
    funcArr[19] = &HALCallInterface::STOP_BTN_RELEASED;
//    funcArr[i++] = &HALCallInterface::RESET_BTN_PRESSED;
//    funcArr[i++] = &HALCallInterface::RESET_BTN_RELEASED;
//    funcArr[i++] = &HALCallInterface::ESTOP_BTN_PRESSED;
//    funcArr[i++] = &HALCallInterface::ESTOP_BTN_RELEASED;



}

Dispatcher::~Dispatcher() {
}

void Dispatcher::registerController(HALCallInterface *controller, SignalType signalType, int val) {
    controllers[2*signalType + val].push_back(controller);
}

void Dispatcher::signal(int signal) {
    list<HALCallInterface*>::iterator it;
    for (it = controllers[signal].begin(); it != controllers[signal].end(); it++) {
        ((*it)->*funcArr[signal])();
    }
}

void Dispatcher::execute(void *arg)
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
            signal(2*pulse.code + pulse.value.sival_int);
#ifdef DEBUG_MESSAGES
            cout << "Code: " << (2*pulse.code + pulse.value.sival_int) << endl;
#endif
        }
    }
}

void Dispatcher::shutdown(void)
{
#ifdef DEBUG_MESSAGES
    cout << "Dispatcher: shutting down..." << endl;
#endif
}
