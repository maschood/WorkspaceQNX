/*
 * MyState.h
 *
 *  Created on: 06.05.2013
 *      Author: Peter
 */

#ifndef MYSTATE_H_
#define MYSTATE_H_

class MyState {
public:
    MyState() {}
    virtual ~MyState() {}

    virtual void WERKS_EINLAUF_0(void) {}
    virtual void WERKS_EINLAUF_1(void) {}
    virtual void WERKS_IN_HOEHENMESSUNG_0(void) {}
    virtual void WERKS_IN_HOEHENMESSUNG_1(void) {}
    virtual void WERKS_IN_WEICHE_0(void) {}
    virtual void WERKS_IN_WEICHE_1(void) {}
    virtual void RUTSCHE_VOLL_0(void) {}
    virtual void RUTSCHE_VOLL_1(void) {}
    virtual void WERKS_AUSLAUF_0(void) {}
    virtual void WERKS_AUSLAUF_1(void) {}
};

#endif /* MYSTATE_H_ */
