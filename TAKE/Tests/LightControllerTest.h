/**
 * SE2 WiSe 2012
 * LightController test
 *
 * Offers functions for different states the festo
 * system can have. Running in a Thread. Status of
 * the traffic light is manipulated through public
 * accessible functions.
 *
 * \file LightControllerTest.h
 * \author Chris Addo
 *         Jens Eberwein
 *         Tristan Rudat
 *         Martin Slowikowski
 * \date 2012-10-29
 * \version 0.1
 *
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
