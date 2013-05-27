/*
 * HAL_S_return.cpp
 *
 *  Created on: 07.05.2013
 *      Author: ich
 */

#include "HAL_S/HAL_S.h"

int HAL_S::get_height_digital(uint8_t val_b_current) {
	int resu = -1;
	if ((val_b_current & BIT_1) == 0) { // check if puk is under the measure laser
		printf("Something in the entrance\n");
		if ((val_b_current & BIT_2) == BIT_2) {
			resu = 1; // hight of the object is ok
			cout << "Höhe ist ok" << endl;
		} else {
			resu = 0; // hight of the object is ok
			cout << "Höhe ist nicht ok" << endl;
		}
	}
	return resu;
}

int HAL_S::get_metal(uint8_t val_b_current) {
	int resu = -1;
	if ((val_b_current & BIT_3) == 0) { // check if puk is under the metal-scanner
		printf("Something in the entrance\n");
		if ((val_b_current & BIT_4) == BIT_4) {
			resu = 1; // metal detected
			cout << "Werstück Metall" << endl;
		} else {
			resu = 0; // no metal detected
			cout << "Werkstück kein Metall" << endl;
		}
	}
	return resu;
}

int HAL_S::get_height_analog(uint8_t val_b_current) {
	int resu = -1;
	int i;
	if ((val_b_current & BIT_1) == 0) { // check if puk is under the measure laser
		out8(AIO_PORT_A, AIO_GET_VAL);
		for (i = 0; i < 50; i++) {
			if ((in8(AIO_BASE) & BIT_7)) { // == (1<<7)
				resu = in16(AIO_PORT_A);
				break;
			}
		}
	}
	return resu;
}

int HAL_S::get_bar_open(uint8_t val_b_current) {
	int resu = -1;
	if ((val_b_current & BIT_5) == BIT_5) {
		resu = 1; // bar is open
		cout << "weiche ist offen" << endl;
	} else {
		resu = 0; // bar is closed
		cout << "weiche ist geschlossen" << endl;
	}
	return resu;
}
