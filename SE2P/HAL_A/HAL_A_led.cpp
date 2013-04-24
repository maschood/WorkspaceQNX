/*
 * HAL_led.cpp
 *
 *  Created on: 22.04.2013
 *      Author: ich
 */

#include "HAL_A.h"

// LED -----------------------------------------

/*
 * These methodes switch on the LEDs of the buttons start and reset.
 * If they are activated they stay on.
 */
int HAL_A::led_start_button_on(){
	int resu = -1;
	uint8_t val = in8(DIO_BASE + DIO_OFFS_C);
	halMutex->lock();
	val = val | BIT_0;
	resu = 0;
	out8(DIO_BASE + DIO_OFFS_C, val);
	halMutex->unlock();
	return resu;
}

int HAL_A::led_reset_button_on(){
	int resu = -1;
	uint8_t val = in8(DIO_BASE + DIO_OFFS_C);
	halMutex->lock();
	val = val | BIT_1;
	resu = 0;
	out8(DIO_BASE + DIO_OFFS_C, val);
	halMutex->unlock();
	return resu;
}

/*
 * These methodes switch off the LEDs of the buttons start and reset.
 * If they are deactivated they stay off.
 */
int HAL_A::led_start_button_off(){
	int resu = -1;
	uint8_t val = in8(DIO_BASE + DIO_OFFS_C);
	halMutex->lock();
	val = val & ~BIT_0;
	resu = 0;
	out8(DIO_BASE + DIO_OFFS_C, val);
	halMutex->unlock();
	return resu;
}

int HAL_A::led_reset_button_off(){
	int resu = -1;
	uint8_t val = in8(DIO_BASE + DIO_OFFS_C);
	halMutex->lock();
	val = val & ~BIT_1;
	resu = 0;
	out8(DIO_BASE + DIO_OFFS_C, val);
	halMutex->unlock();
	return resu;
}
