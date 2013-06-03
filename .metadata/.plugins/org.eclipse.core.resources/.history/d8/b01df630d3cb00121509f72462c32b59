/*
 * MyController.h
 */

#ifndef MYCONTROLLER_H_
#define MYCONTROLLER_H_

#include "Dispatcher/HALCallInterface.h"
#include "FSM/MyState.h"


#define HOEHENWERT 2750

class MyController: public HALCallInterface {
private:
    MyState* state;
public:
    static int hoehe;
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


class MyState_3 : public MyState {
public:
	int hoehe;
    MyState_3(void);

    // transitions
    void WERKS_IN_HOEHENMESSUNG_0(void);
};

class MyState_4 : public MyState {
public:
	int hoehe;

	MyState_4(void);

    // transitions
    void WERKS_IN_HOEHENMESSUNG_1(void);

};

class MyState_5 : public MyState {
public:
	int hoehe;
    MyState_5(void);

    // transitions
    void WERKS_IN_WEICHE_0(void);
};

class MyState_6 : public MyState {
public:
	int hoehe;

	MyState_6(void);

    // transitions
    void WERKS_IN_WEICHE_1(void);

};

class MyState_7 : public MyState {
public:
	int hoehe;
    MyState_7(void);

    // transitions
    void RUTSCHE_VOLL_0(void);
};

class MyState_8 : public MyState {
public:
	int hoehe;
	MyState_8(void);

    // transitions
    void RUTSCHE_VOLL_1(void);

};

class MyState_9 : public MyState {
public:
	int hoehe;
	MyState_9(void);

    // transitions
    void WERKS_AUSLAUF_0(void);

};

class MyState_10 : public MyState {
public:
	int hoehe;
	MyState_10(void);

    // transitions
    void WERKS_AUSLAUF_1(void);

};


#endif /* MYCONTROLLER_H_ */



