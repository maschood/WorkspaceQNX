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
    	int x = rand() % 6;
    	switch(x){
    	case 0: toggleLight(RED);
    	case 1: toggleLight(YELLOW);
    	case 2: toggleLight(GREEN);
    	case 3: val ^= BIT_0; val ^= BIT_1;
    	case 4: val ^= BIT_0; val ^= BIT_1;
    	case 5: cal ^= Bit_4;
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
