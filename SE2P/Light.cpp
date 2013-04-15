/*
 * Ampel.cpp
 *
 *  Created on: 12.04.2013
 *      Author: abc676
 */

// LAMPEN ------------------------------------------------
/*
 * Diese Methoden schalten die entsprechenden Lampen ein.
 * Wenn die Lampe bereits an ist bleibt die an.
 */

#include "HAL.h"
#include "Addresses.h"
#include "HWaccess.h"
#include <stdint.h>

int HAL::lamp_red_on() {
	int resu = -1;
	uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
	val = val | BIT_7;
	resu = 0;
	out8(DIO_BASE + DIO_OFFS_A, val);
	return resu;
}
int HAL::lamp_yellow_on() {
	int resu = -1;
	uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
	val = val || BIT_6;
	resu = 0;
	out8(DIO_BASE + DIO_OFFS_A, val);
	return resu;
}
int HAL::lamp_green_on() {
	int resu = -1;
	uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
	val = val & ~BIT_7;
	resu = 0;
	out8(DIO_BASE + DIO_OFFS_A, val);
	return resu;
}

/*
 * Diese Methoden schalten die entsprechenden Lampen aus.
 * Wenn die Lampe bereits an ist bleibt die an.
 */
int HAL::lamp_red_off() {
	int resu = -1;
	uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
	val = val && (!BIT_7);
	resu = 0;
	out8(DIO_BASE + DIO_OFFS_A, val);
	return resu;
}
int HAL::lamp_yellow_off() {
	int resu = -1;
	uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
	val = val && (!BIT_6);
	resu = 0;
	out8(DIO_BASE + DIO_OFFS_A, val);
	return resu;
}
int HAL::lamp_green_off() {
	int resu = -1;
	uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
	val = val && (!BIT_5);
	resu = 0;
	out8(DIO_BASE + DIO_OFFS_A, val);
	return resu;
}
