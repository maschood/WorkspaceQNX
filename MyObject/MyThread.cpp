/*
 * MyThread.cpp
 *
 *  Created on: 11.10.2012
 *      Author: Peter
 */

#include "MyThread.h"
#include <iostream>
#include <unistd.h>
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
        cout << "Ich bin ein Thread." << endl;
        usleep(500000);
    }
}

}
