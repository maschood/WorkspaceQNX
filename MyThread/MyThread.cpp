/*
 * MyThread.cpp
 *
 *  Created on: 10.10.2012
 *      Author: Peter
 */

#include "MyThread.h"
#include "Addresses.h"

#include "HWaccess.h"

#include <stdint.h> // uint8_t etc.
#include <unistd.h> // sleep
#include <iostream> // cout, cerr

using namespace std;

namespace thread {

MyThread::MyThread() {
    // TODO Auto-generated constructor stub

}

MyThread::~MyThread() {
    // TODO Auto-generated destructor stub
}

void MyThread::shutdown() {
    cout << "Shutting down..." << endl;
}

void MyThread::execute(void *arg) {
    while(!isStopped()) {
        toggleLight(RED);
        usleep(500000);
        toggleLight(YELLOW);
        usleep(500000);
        toggleLight(GREEN);
        sleep(1);
    }
}

void MyThread::toggleLight(Color color)
{
    uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
    switch (color) {
        case RED:
            val ^= BIT_7;
            break;
        case YELLOW:
            val ^= BIT_6;
            break;
        case GREEN:
            val ^= BIT_5;
            break;
    }
    out8(DIO_BASE + DIO_OFFS_A, val);
}

}
