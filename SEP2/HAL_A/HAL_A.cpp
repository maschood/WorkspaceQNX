/*
 * HAL_law.cpp
 *
 *  Created on: 12.04.2013
 *      Author: Erik Matthiessen
 */

#include "HAL_A.h"

HAL_A* HAL_A::instance = NULL;
Mutex* HAL_A::halMutex = new Mutex();

HAL_A::HAL_A() {

	// Initialisierung der Digitalen IO Karte
	out8(DIO_BASE + DIO_OFFS_CTRL, 0x8A);
	out8(DIO_BASE + DIO_OFFS_A, 0x00);
	out8(DIO_BASE + DIO_OFFS_C, 0x00);
}

HAL_A::~HAL_A() {
	delete instance;
	instance = NULL;
	out8(DIO_BASE + DIO_OFFS_CTRL, 0x8A);
	out8(DIO_BASE + DIO_OFFS_A, 0x00);
	out8(DIO_BASE + DIO_OFFS_C, 0x00);
}

HAL_A* HAL_A::get_instance() {
	// Requesting acces to HW
	if (-1 == ThreadCtl(_NTO_TCTL_IO, 0)) {
		perror("ThreadCtl access failed\n");
		return NULL;
	}

	if (instance == NULL) {
		instance = new HAL_A();
	}

	return instance;
}

/*
 * Switches of all actoric functions
 */
int HAL_A::general_switch_off(){
	int resu = -1;
	halMutex->lock();
	uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
	val = 0;
	out8(DIO_BASE + DIO_OFFS_A, val);
	val = in8(DIO_BASE + DIO_OFFS_C);
	val = val & ~BIT_0;
	val = val & ~BIT_1;
	val = val & ~BIT_2;
	val = val & ~BIT_3;
	out8(DIO_BASE + DIO_OFFS_C, val);
	resu = 0;
	halMutex->unlock();
	return resu;
}
