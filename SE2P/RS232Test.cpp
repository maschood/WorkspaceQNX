/*
 * RS232Test.cpp
 *
 *  Created on: 16.04.2013
 *      Author: maschood
 */

#include "RS232Test.h"

RS232Test::RS232Test() {
	RS232_1 ser1;
	RS232_2 ser2;

	char buff;
	char *bufferpointer = &buff;


	ser1.sendMsg(10);
	ser1.readMsg(bufferpointer);
	cout << "Empfangen: " << buff << endl;
}
RS232Test::~RS232Test() {
	// TODO Auto-generated destructor stub
}
