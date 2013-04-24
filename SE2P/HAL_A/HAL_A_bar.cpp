/*
 * HAL_bar.cpp
 *
 *  Created on: 22.04.2013
 *      Author: ich
 */

#include "HAL_A.h"

// BAR -----------------------------------------

/*
 * This Method opens the Bar
 * If the Bar is already open it stays open
 */
int HAL_A::bar_open() {
	int resu = -1;
	uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
	halMutex->lock();
	resu = 0;
	val = val | BIT_4;
	out8(DIO_BASE + DIO_OFFS_A, val);
	halMutex->unlock();
	return resu;
}

/*
 * This Method closes the Bar
 * If the Bar is already closed it stays closed.
 */
int HAL_A::bar_close() {
	int resu = -1;
	uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
	halMutex->lock();
	resu = 0;
	val = val & ~BIT_4;
	out8(DIO_BASE + DIO_OFFS_A, val);
	halMutex->unlock();
	return resu;
}
