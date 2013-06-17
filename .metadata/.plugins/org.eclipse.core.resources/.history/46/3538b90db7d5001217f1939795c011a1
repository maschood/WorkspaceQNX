/**
 * SE2 WiSe 2012
 * RS232 (serial connection) test class
 *
 * tests sending and receiving on local loop with nullmodem
 * between com1 and com2
 *
 * \file RS232Test.cpp
 * \author Chris Addo
 *         Jens Eberwein
 *         Tristan Rudat
 *         Martin Slowikowski
 * \date 2012-10-23
 * \version 0.9
 *
 */

#include "RS232Test.h"

RS232Test::RS232Test() {

}

RS232Test::~RS232Test() {
}

void RS232Test::testRS232()
{
	RS232_1* com1 = RS232_1::getInstance();
	RS232_2* com2 = RS232_2::getInstance();

	//Test 1: read on ser1, write on ser2
	com1->start(NULL);
	com2->sendMsg('b');
	sleep(3);
	com2->sendMsg('a');
	sleep(2);
	com1->stop();
	sleep(5);
	com1->join();

	//Test 2: read on ser2, write on ser1
	com2->start(NULL);
	com1->sendMsg('b');
	sleep(3);
	com1->sendMsg('a');
	sleep(2);
	com2->stop();
	sleep(5);
	com2->join();

	com1->~RS232_1();
	com2->~RS232_2();
}
