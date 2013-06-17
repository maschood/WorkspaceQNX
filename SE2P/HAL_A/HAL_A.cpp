/**
 * 
 * @file HAL.cpp
 * @author Erik Matthiessen
 *         Denis Rycka
 *         Nilüfer Güngör
 *         Maschhood Ahmad
 * 
 */

#include "HAL_A.h"

HAL_A* HAL_A::instance = NULL;
Mutex* HAL_A::halMutex = new Mutex();
Mutex* HAL_A::halInstanceMutex = new Mutex();

HAL_A::HAL_A() {
#ifdef SIMULATION
	std::cout << "Simulation aktiv" << std::endl;
	std::cout << "Zum Aufbau der Verbindung muss Die Festo Simulation schon laufen." << std::endl;
	IOaccess_open(); // Baue die Verbindung zur Simulation auf
#endif

	// Zugriffsrechte fuer den Zugriff auf die HW holen
	if (-1 == ThreadCtl(_NTO_TCTL_IO, 0)) {
		printf("ThreadCtl access failed\n");
		exit(EXIT_FAILURE);
	}

	// Initialisierung der Digitalen IO Karte
	//out8(DIO_BASE + DIO_CONTROL_BLA, 0x8A);
	out8(PORT_CTRL, DIO_INIT);

	//-->nicht nötig aber sicherer
	out8(PORT_A, 0x00);
	out8(PORT_C, 0x00);

	fullStop = false;
}

HAL_A::~HAL_A() {
	if (instance != NULL) {
		delete instance;
		instance = NULL;
		halMutex->~Mutex();
		halInstanceMutex->~Mutex();
	}
}

HAL_A* HAL_A::getInstance() {
	if (!instance) {
		halInstanceMutex->lock();
		if (!instance) {
			instance = new HAL_A;
		}
		halInstanceMutex->unlock();
	}

	return instance;
}


void HAL_A::led_start(bool isOn) {
	uint8_t val = in8(PORT_C);

	halMutex->lock();

	if (isOn) {
		out8(PORT_C, val | LED_START);
	} else {
		out8(PORT_C, val & ~(LED_START));
	}

	halMutex->unlock();
}


