/*
 * MyThread.h
 *
 *  Created on: 10.10.2012
 *      Author: Peter
 */

#ifndef MYTHREAD_H_
#define MYTHREAD_H_

#include "HAWThread.h"
#include "Color.h"

namespace thread {

class MyThread: public thread::HAWThread {
public:
    MyThread();
    virtual ~MyThread();

protected:
    virtual void execute(void* arg);
    virtual void shutdown();

public:
    void toggleLight(Color color);
};

}

#endif /* MYTHREAD_H_ */
