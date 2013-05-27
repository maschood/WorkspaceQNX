/*
 * HALCallInterface.h
 */

#ifndef HALCALLINTERFACE_H_
#define HALCALLINTERFACE_H_

#define N_SIGNALE 10

class HALCallInterface {
public:
    virtual ~HALCallInterface() {}

    virtual void WERKS_EINLAUF_0(void) = 0;
    virtual void WERKS_EINLAUF_1(void) = 0;
    virtual void WERKS_IN_HOEHENMESSUNG_0(void) = 0;
    virtual void WERKS_IN_HOEHENMESSUNG_1(void) = 0;
    virtual void WERKS_IN_WEICHE_0(void) = 0;
    virtual void WERKS_IN_WEICHE_1(void) = 0;
    virtual void RUTSCHE_VOLL_0(void) = 0;
    virtual void RUTSCHE_VOLL_1(void) = 0;
    virtual void WERKS_AUSLAUF_0(void) = 0;
    virtual void WERKS_AUSLAUF_1(void) = 0;
};

#endif /* HALCALLINTERFACE_H_ */
