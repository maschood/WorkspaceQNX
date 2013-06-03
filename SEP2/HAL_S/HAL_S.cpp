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

	val_b_current = in8(DIO_BASE + DIO_OFFS_B);
	val_c_current = in8(DIO_BASE + DIO_OFFS_C);
}

HAL_S::~HAL_S() {
	delete instance;
	instance = NULL;
	out8(DIO_BASE + DIO_OFFS_CTRL, 0x8A);
	out8(DIO_BASE + DIO_OFFS_B, 0x00);
	out8(DIO_BASE + DIO_OFFS_C, 0x00);
}

HAL_S* HAL_S::get_instance() {
#ifdef HW
	if (-1 == ThreadCtl(_NTO_TCTL_IO, 0)) {
		perror("ThreadCtl access failed\n");
		return NULL;
	}
#endif

	if (instance == NULL) {
		instance = new HAL_S();
	}

	return instance;
}

void HAL_S::execute(void* arg) {
	while (!isStopped()) {
		start_process();
		// An dieser Stelle soll auf den Interrupt gewartet werden
	}
}

void HAL_S::start_process() {

	// check if at least one bit is set an a closer check is necessary
	val_b_last = val_b_current;
	val_c_last = val_c_current;

	val_b_current = in8(DIO_BASE + DIO_OFFS_B);
	val_c_current = in8(DIO_BASE + DIO_OFFS_C);

	last_state = current_state;
	current_state = (val_b_current + (val_c_current << 8));

	if (last_state - current_state != 0) {
		if (((val_b_current&CHECK_B)-(val_b_last&CHECK_B)) != 0) {
			check_entrance(val_b_current, val_b_last);
			check_hight_determinism(val_b_current, val_b_last);
			check_bar(val_b_current, val_b_last);
			check_slide_full(val_b_current, val_b_last);
			check_exit(val_b_current, val_b_last);
			get_height_digital(val_b_current);
			get_metal(val_b_current);


		}

		if ((val_c_current & 0xf0) - (val_c_last & 0xf0) != 0) {
			check_start_button(val_c_current, val_c_last);
			check_stop_button(val_c_current, val_c_last);
			check_reset_button(val_c_current, val_c_last);
			check_quick_stop(val_c_current, val_c_last);
		}

	}

}
void HAL_S::shutdown() {
}
