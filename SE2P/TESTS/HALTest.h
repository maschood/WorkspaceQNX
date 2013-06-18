/**
 * \file HALTest.h
 * @author Erik Matthiessen
 *         Denis Rycka
 *         Nilüfer Güngör
 *         Maschhood Ahmad
 */

#ifndef HALTEST_H_
#define HALTEST_H_

#include "ActorHAL.h"

class HALTest {
public:
	/**
	 * empty standard constructor
	 */
	HALTest();

	/**
	 * empty standard destructor
	 */
	virtual ~HALTest();

	/**
	 * function executes standard test plan for all actors of the
	 * festo system
	 */
	void testHal();
};

#endif /* HALTEST_H_ */
