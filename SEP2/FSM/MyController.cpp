/*
 * MyController.cpp
 */

#include "MyController.h"
#include "HAL_A/HAL_A.h"

#include <iostream>
#include <new>

using namespace std;

// -----------------------------------------------------------------------------
//  Class MyController
// -----------------------------------------------------------------------------
MyController::MyController(void)
: state(new MyState_1) {

}

MyController::~MyController(void) {
    delete state;
}

// -----------------------------------------------------------------------------
//  Class MyState_1
// -----------------------------------------------------------------------------
MyState_1::MyState_1(void) {
}

void MyState_1::WERKS_EINLAUF_0(void) {
#ifdef DEBUG_MESSAGES
    cout << "MyState_1: WERKS_EINLAUF_0 / lampeRotAn --> MyState_2" << endl;
#endif

    HAL_A::get_instance()->lamp_red_on();
    new(this) MyState_2;

}

// -----------------------------------------------------------------------------
//  Class MyState_2
// -----------------------------------------------------------------------------
MyState_2::MyState_2(void) {
}

void MyState_2::WERKS_EINLAUF_1(void) {
#ifdef DEBUG_MESSAGES
    cout << "MyState_2: WERKS_EINLAUF_1 / lampeRotAus --> MyState_1" << endl;
#endif

    HAL_A::get_instance()->lamp_red_off();
    new(this) MyState_1;

}
