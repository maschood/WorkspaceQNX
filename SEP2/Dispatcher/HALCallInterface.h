/*
 * HALCallInterface.h
 */

#ifndef HALCALLINTERFACE_H_
#define HALCALLINTERFACE_H_

#define N_SIGNALE 20

class HALCallInterface {
public:
    //Port B
    virtual void PART_IN_0(void) = 0;
    virtual void PART_IN_1(void) = 0;

    virtual void PART_HEIGHT_0(void) = 0;
    virtual void PART_HEIGHT_1(void) = 0;

    virtual void PART_IN_GATE_0(void) = 0;
    virtual void PART_IN_GATE_1(void) = 0;

    virtual void PART_METALL(void) = 0;

    virtual void GATE_STATUS_0(void) = 0;
    virtual void GATE_STATUS_1(void) = 0;

    virtual void SLIDE_FULL_0(void) = 0;
    virtual void SLIDE_FULL_1(void) = 0;

    virtual void PART_OUT_0(void) = 0;
    virtual void PART_OUT_1(void) = 0;

    //Port C
    virtual void START_BTN_PRESSED(void) = 0;
    virtual void START_BTN_RELEASED(void) = 0;

    virtual void STOP_BTN_PRESSED(void) = 0;
    virtual void STOP_BTN_RELEASED(void) = 0;

    virtual void RESET_BTN_PRESSED(void) = 0;
    virtual void RESET_BTN_RELEASED(void) = 0;

    virtual void ESTOP_BTN_PRESSED(void) = 0;
    virtual void ESTOP_BTN_RELEASED(void) = 0;

};

#endif /* HALCALLINTERFACE_H_ */
