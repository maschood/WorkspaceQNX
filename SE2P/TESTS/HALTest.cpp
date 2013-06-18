/**
 *
 *
 * \file HALTest.cpp
* @author Erik Matthiessen
 *         Denis Rycka
 *         Nilüfer Güngör
 *         Maschhood Ahmad
 */

#include "HALTest.h"

HALTest::HALTest() {

}

HALTest::~HALTest() {
}

void HALTest::testHal()
{
	ActorHAL* hal = ActorHAL::getInstance();
	// Lights
	hal->lightRed(true);
	sleep(1);
	hal->lightRed(false);
	sleep(1);

	hal->lightYellow(true);
	sleep(1);
	hal->lightYellow(false);
	sleep(1);

	hal->lightGreen(true);
	sleep(1);
	hal->lightGreen(false);
	sleep(1);

	hal->lightGreen(true);
	hal->lightYellow(true);
	hal->lightRed(true);
	sleep(2);
	hal->lightsOff();


	// Engine
	hal->engineRight(false);
	sleep(5);
	hal->engineRight(true);
	sleep(5);
	hal->engineStop();
	sleep(5);
	hal->engineUnstop();
	sleep(5);
	hal->engineStop();

	// Weiche
	hal->gate(true);
	sleep(1);
	hal->gate(false);
	sleep(1);

	// LEDs
	hal->ledStart(true);
	hal->ledReset(true);
	hal->ledQ1(true);
	hal->ledQ2(true);
	sleep(5);
	hal->ledStart(false);
	hal->ledReset(false);
	hal->ledQ1(false);
	hal->ledQ2(false);
	sleep(1);
}
