/*
 * HAL_conveyor.cpp
 *
 *  Created on: 22.04.2013
 *      Author: ich
 */

#include "HAL_A.h"

// Fließband -----------------------------------------------

/*
 *  Drive conveyor right
 */
int HAL_A::conveyor_move_right() {
	int resu = -1;
	uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
	halMutex->lock();
	val = val | BIT_0;
	resu = 0;
	out8(DIO_BASE + DIO_OFFS_A, val);
	halMutex->unlock();
	return resu;
}

/*
 *  Drive conveyor left
 */
int HAL_A::conveyor_move_left() {
	int resu = -1;
	uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
	halMutex->lock();
	val = val | BIT_1;
	resu = 0;
	out8(DIO_BASE + DIO_OFFS_A, val);
	halMutex->unlock();
	return resu;
}

/*
 * Stop conveyor
 */
int HAL_A::conveyor_stop() {
	int resu = -1;
	uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
	halMutex->lock();
	val = val & ~BIT_0;
	val = val & ~BIT_1;
	resu = 0;
	out8(DIO_BASE + DIO_OFFS_A, val);
	halMutex->unlock();
	return resu;
}
