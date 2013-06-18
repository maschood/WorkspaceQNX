/**
 *
 * \file RS232Test.h
 * @author Erik Matthiessen
 *         Denis Rycka
 *         Nilüfer Güngör
 *         Maschhood Ahmad
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
