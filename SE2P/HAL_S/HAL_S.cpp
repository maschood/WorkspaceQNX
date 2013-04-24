/*
 * HAL_S.cpp
 *
 *  Created on: 23.04.2013
 *      Author: ich
 */

#include "HAL_S/HAL_S.h"

HAL_S* HAL_S::instance = NULL;

HAL_S::HAL_S() {

	// Initialising the IO card
	out8(DIO_BASE + DIO_OFFS_CTRL, 0x8A);
	out8(DIO_BASE + DIO_OFFS_B, 0x00);
	out8(DIO_BASE + DIO_OFFS_C, 0x00);
}

HAL_S::~HAL_S() {
	delete instance;
	instance = NULL;
	out8(DIO_BASE + DIO_OFFS_CTRL, 0x8A);
	out8(DIO_BASE + DIO_OFFS_B, 0x00);
	out8(DIO_BASE + DIO_OFFS_C, 0x00);
}

HAL_S* HAL_S::get_instance() {
	// Requesting access to HW
	if (-1 == ThreadCtl(_NTO_TCTL_IO, 0)) {
		perror("ThreadCtl access failed\n");
		return NULL;
	}

	if (instance == NULL) {
		instance = new HAL_S();
	}

	return instance;
}

void HAL_S::start_process(){
	uint8_t val;
//	unit8_t val_c;

	val = in8(DIO_BASE + DIO_OFFS_B);
//	val_c = in8(DIO_BASE + DIO_OFFS_C);

	// Hier einen neuen Thread erzeugen
	while(MANOWAR){

		// check if at least one bit is set an a closer check is necessary
		val = in8(DIO_BASE + DIO_OFFS_B);
		if((val & CHECK_B) != CHECK_B){
			check_entrance(val);
			check_hight_determinism(val);
			check_bar(val);
			check_slide_full(val);
			check_exit(val);
		}

		val = in8(DIO_BASE + DIO_OFFS_C);
		int cHECK_C = BIT_5+BIT_7;
		if((val & 0xf0) != cHECK_C){
			check_start_button(val);
			check_stop_button(val);
			check_reset_button(val);
			check_quick_stop(val);
		}
	}
}