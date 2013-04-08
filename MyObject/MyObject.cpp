/*
 * MyObject.cpp
 *
 *  Created on: 11.10.2012
 *      Author: Peter
 */

#include "MyObject.h"
#include <iostream> // für cout
using namespace std;

MyObject::~MyObject() {
    cout << "Destruktor-Aufruf" << endl;
}

MyObject::MyObject() {
    // TODO Auto-generated constructor stub

}

void MyObject::myMethod()
{
    cout << "Hallo!" << endl;
}
