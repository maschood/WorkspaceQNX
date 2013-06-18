/**
 *
 * \file LightControllerTest.cpp
* @author Erik Matthiessen
 *         Denis Rycka
 *         Nilüfer Güngör
 *         Maschhood Ahmad
 */

#include "LightControllerTest.h"

LightControllerTest::LightControllerTest() {

}

LightControllerTest::~LightControllerTest() {
}

void LightControllerTest::testLightController() {

	LightController* lc = LightController::getInstance();

	sleep(4);
	lc->operatingNormal();
	sleep(4);
	lc->upcomingNotReceipted();
	sleep(4);
	lc->upcomingReceipted();
	sleep(4);
	lc->goneUnreceipted();
	sleep(4);
	lc->manualTurnover();
	sleep(4);
	lc->lightsOff();
	lc->stop();
	lc->cont();
	lc->join();
}
