/**
 * SE2 WiSe 2012
 * Test class for ISR with pulse messages
 *
 *
 * \file ISRTest.cpp
 * \author Chris Addo
 *         Jens Eberwein
 *         Tristan Rudat
 *         Martin Slowikowski
 * \date 2012-11-02
 * \version 0.1
 *
 */

#include "ISRTest.h"

ISRTest::ISRTest() {
	sHal = SensorHAL::getInstance();
	aHal = ActorHAL::getInstance();
	lc = LightController::getInstance();
}

ISRTest::~ISRTest() {
}

void ISRTest::execute(void*) {

	struct _pulse pulse;
	int oldVal = DEFAULT_ISR_VAL;
	int newVal = 0;
	int rc;
	bool manualTurnover = false;
	bool hasMetal = false;
	bool wsOk = false;
	bool eStopBtn = false;
	bool running = true;

	while (!isStopped()) {
		rc = MsgReceivePulse(sHal->getChid(), &pulse, sizeof(pulse), NULL);
		if (rc < 0) {
			printf("Error in recv pulse\n");
			if (isStopped()) {
				break;
			}
		}

		//printf("ISR status: %x\n", pulse.value.sival_int);

		newVal = pulse.value.sival_int;
		int i;

		bool hasChanged;

		for (i = 0; i < 12; i++) {
			if (((newVal >> i) & 1) != ((oldVal >> i) & 1)) {
				hasChanged = (newVal >> i) & 1;
				switch (i) {
				case 0:
					if (hasChanged) {
						printf("Kein Werkstueck im Einlauf\n");
					} else {
						printf("Werkstueck im Einlauf\n");
						manualTurnover = false;
						hasMetal = false;
						wsOk = false;
						aHal->engineRight(false);
						aHal->engineUnstop();
					}
					break;
				case 1:
					if (hasChanged) {
						printf("Kein Werkstueck in Hoehenmessung\n");
					} else {
						printf("Werkstueck in Hoehenmessung\n");
						printf("Werkstueck Hoehe: %d\n", sHal->getHeight());
						aHal->engineStop();
						if ((sHal->getHeight() < 2900) && (sHal->getHeight()
								> 2600)) {
							aHal->engineUnstop();
						} else if ((sHal->getHeight() < 2600)) {
							manualTurnover = true;
							wsOk = true;
							aHal->engineUnstop();
						} else {
							aHal->engineUnstop();
							wsOk = true;
						}
					}
					break;
				case 2:
					if (hasChanged) {
						printf("Werkstueck im Toleranzbereich: %d\n",
								sHal->getHeight());
					} else {
						printf("Werkstueck zu klein/gross: %d\n",
								sHal->getHeight());
					}
					break;
				case 3:
					if (hasChanged) {
						printf("Kein Werkstueck in Weiche\n");
					} else {
						printf("Werkstueck in Weiche\n", i);
						if (!hasMetal && wsOk) {
							aHal->gate(true);
						}
					}
					break;
				case 4:
					if (hasChanged) {
						printf("Werkstueck Metall\n");
						hasMetal = true;
					} else {
						printf("Werkstueck kein Metall\n");
					}
					break;
				case 5:
					if (hasChanged) {
						printf("Weiche offen\n");
					} else {
						printf("Weiche geshlossen\n");
					}
					break;
				case 6:
					if (hasChanged) {
						printf("Rutsche nicht voll\n");
						aHal->engineStop();
					} else {
						printf("Rutsche voll\n");
					}
					break;
				case 7:
					if (hasChanged) {
						printf("kein Werkstueck im Auslauf\n");
						lc->lightsOff();
						manualTurnover = false;
						hasMetal = false;
						wsOk = false;
					} else {
						printf("Werkstueck im Auslauf\n");
						aHal->gate(false);
						aHal->engineStop();
						if (manualTurnover) {
							printf("manualTurnover: %i\n", manualTurnover);
							lc->manualTurnover();
						}
					}
					break;
				case 8:
					if (hasChanged) {
						printf("Starttste gedrueck\n");
						if(!eStopBtn){
							running = true;
							printf("System rennt weiter, EStop geloest udn start\n");
							aHal->lightRed(false);
							aHal->lightGreen(true);
						}
					} else {
						printf("Starttste losgelassen\n");
					}
					break;
				case 9:
					if (hasChanged) {
						printf("Stoptaste losgelassen\n");
					} else {
						printf("Stoptaste gedrueckt\n");
					}
					break;
				case 10:
					if (hasChanged) {
						printf("Resettaste gedrueckt\n");
					} else {
						printf("Resettaste losgelassen\n");
					}
					break;
				case 11:
					if (hasChanged) {
						printf("E-Stoptaste geloest\n");
						eStopBtn = false;
					} else {
						printf("E-Stoptaste gedrueckt\n");
						eStopBtn = true;
						running = false;
						printf("System angehalten mittels EStop\n");
						aHal->lightRed(true);
					}
					break;
				default:
					printf("ISRTest switch def value\n");
				}
			}
		}
		oldVal = newVal;
	}
}
void ISRTest::stop() {
	HAWThread::stop();
	sHal->stopInterrupt();
}

void ISRTest::shutdown() {
}
