/**
 *
 * \file LightControllerTest.h
* @author Erik Matthiessen
 *         Denis Rycka
 *         Nilüfer Güngör
 *         Maschhood Ahmad
 */

#ifndef LIGHTCONTROLLERTEST_H_
#define LIGHTCONTROLLERTEST_H_

#include "LightController.h"

class LightControllerTest {
public:
	/**
	 * Empty standard constructor
	 */
	LightControllerTest();

	/**
	 * Empty standard destructor
	 */
	virtual ~LightControllerTest();

	/**
	 * Test all possible states the traffic light must
	 * offer.
	 */
	void testLightController();
};

#endif /* LIGHTCONTROLLERTEST_H_ */
