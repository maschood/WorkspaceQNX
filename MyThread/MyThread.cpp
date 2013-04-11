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
        usleep(500000);
    }
}

void MyThread::toggleLight(Color color)
{
    uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
    int x = rand() % 6;
    	switch(x){
    	case 0: val ^= BIT_7; break;
    	case 1: val ^= BIT_6; break;
    	case 2: val ^= BIT_5; break;
    	case 3: val ^= BIT_4; break;
    	case 4: if(val & 2){val ^= BIT_1; val ^= BIT_0;} else {val ^= BIT_0;} break;
    	case 5: if(val & 1){val ^= BIT_0; val ^= BIT_1;} else {val ^= BIT_1;} break;

    	}
    out8(DIO_BASE + DIO_OFFS_A, val);
}

}
