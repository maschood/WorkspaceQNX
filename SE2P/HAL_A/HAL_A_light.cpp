/*
 * HAL_light.cpp
 *
 *  Created on: 22.04.2013
 *      Author: ich
 */

#include "HAL_A.h"

// Light ------------------------------------------------

/*
 * Switch on the lamp.
 * If the lamp is on it stays on.
 */
int HAL_A::lamp_red_on() {
	int resu = -1;
	uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
	halMutex->lock();
	val = val | BIT_7;
	resu = 0;
	out8(DIO_BASE + DIO_OFFS_A, val);
	halMutex->unlock();
	return resu;
}

int HAL_A::lamp_yellow_on() {
	int resu = -1;
	uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
	halMutex->lock();
	val = val | BIT_6;
	resu = 0;
	out8(DIO_BASE + DIO_OFFS_A, val);
	halMutex->unlock();
	return resu;
}

int HAL_A::lamp_green_on() {
	int resu = -1;
	uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
	halMutex->lock();
	val = val | BIT_5;
	resu = 0;
	out8(DIO_BASE + DIO_OFFS_A, val);
	halMutex->unlock();
	return resu;
}

/*
 * Switch off the lamp.
 * If the lamp is off it stays off.
 */
int HAL_A::lamp_red_off() {
	int resu = -1;
	uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
	halMutex->lock();
	val = val & ~BIT_7;
	resu = 0;
	out8(DIO_BASE + DIO_OFFS_A, val);
	halMutex->unlock();
	return resu;
}

int HAL_A::lamp_yellow_off() {
	int resu = -1;
	uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
	halMutex->lock();
	val = val & ~BIT_6;
	resu = 0;
	out8(DIO_BASE + DIO_OFFS_A, val);
	halMutex->unlock();
	return resu;
}

int HAL_A::lamp_green_off() {
	int resu = -1;
	uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
	halMutex->lock();
	val = val & ~BIT_5;
	resu = 0;
	out8(DIO_BASE + DIO_OFFS_A, val);
	halMutex->unlock();
	return resu;
}
