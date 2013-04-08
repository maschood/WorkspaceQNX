/*
 * MyThread.h
 *
 *  Created on: 11.10.2012
 *      Author: Peter
 */

#ifndef MYTHREAD_H_
#define MYTHREAD_H_

#include "HAWThread.h"

namespace thread {

class MyThread: public HAWThread {
public:
    MyThread();
    virtual ~MyThread();

    virtual void execute(void*arg);
    virtual void shutdown();
};

}

#endif /* MYTHREAD_H_ */
