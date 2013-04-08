/*
 * MyObject.h
 *
 *  Created on: 11.10.2012
 *      Author: Peter
 */

#ifndef MYOBJECT_H_
#define MYOBJECT_H_

class MyObject {
public:
    MyObject();
    virtual ~MyObject();

    void myMethod();
private:
    int myInt;
};

#endif /* MYOBJECT_H_ */
