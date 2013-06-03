/**
 * SE2 WiSe 2012
 * RS232 (serial connection) test class
 *
 * tests sending and receiving on local loop with nullmodem
 * between com1 and com2
 *
 * \file RS232Test.h
 * \author Chris Addo
 *         Jens Eberwein
 *         Tristan Rudat
 *         Martin Slowikowski
 * \date 2012-10-23
 * \version 0.9
 *
 */

#ifndef RS232TEST_H_
#define RS232TEST_H_

#include "RS232/RS232_1.h"
#include "RS232/RS232_2.h"

class RS232Test {
public:
	/**
	 * standard constructor, empty
	 */
	RS232Test();

	/**
	 * standard destructor, empty
	 */
	virtual ~RS232Test();

	/**
	 * test function for serial com, at first com1 is reading and
	 * com2 is sending, then reverse
	 */
	void testRS232();
};

#endif /* RS232TEST_H_ */
