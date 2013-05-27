/*
 * MyController.h
 */

#ifndef MYCONTROLLER_H_
#define MYCONTROLLER_H_

#include "Dispatcher/HALCallInterface.h"
#include "FSM/MyState.h"

class MyController: public HALCallInterface {
private:
    MyState* state;
public:
    MyController(void);
    virtual ~MyController(void);

    // transitions
    void WERKS_EINLAUF_0(void) { state->WERKS_EINLAUF_0(); }
    void WERKS_EINLAUF_1(void) { state->WERKS_EINLAUF_1(); }
    void WERKS_IN_HOEHENMESSUNG_0(void) { state->WERKS_IN_HOEHENMESSUNG_0(); }
    void WERKS_IN_HOEHENMESSUNG_1(void) { state->WERKS_IN_HOEHENMESSUNG_1(); }
    void WERKS_IN_WEICHE_0(void) { state->WERKS_IN_WEICHE_0(); }
    void WERKS_IN_WEICHE_1(void) { state->WERKS_IN_WEICHE_1(); }
    void RUTSCHE_VOLL_0(void) { state->RUTSCHE_VOLL_0(); }
    void RUTSCHE_VOLL_1(void) { state->RUTSCHE_VOLL_1(); }
    void WERKS_AUSLAUF_0(void) { state->WERKS_AUSLAUF_0(); }
    void WERKS_AUSLAUF_1(void) { state->WERKS_AUSLAUF_1(); }
};

/**
 * State "MyState_1" of controller "MyController"
 */
class MyState_1 : public MyState {
public:
    MyState_1(void);

    // transitions
    void WERKS_EINLAUF_0(void);
};

/**
 * State "MyState_2" of controller "MyController"
 */
class MyState_2 : public MyState {
public:
    MyState_2(void);

    // transitions
    void WERKS_EINLAUF_1(void);
};

#endif /* MYCONTROLLER_H_ */
