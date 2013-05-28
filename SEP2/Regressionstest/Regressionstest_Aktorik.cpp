/*
 * Regressionstest.cpp
 *
 *  Created on: 04.05.2013
 *      Author: NG
 */

#include "Regressionstest/Regressionstest.h"
#include "Addresses.h"
#include "HAL_A/HAL_A.h"
#include "HAL_S/HAL_S.h"
#include <stdlib.h>

using namespace std;
HAL_A* hal_a = HAL_A::get_instance();
bool erg = false;

bool Regressionstest::test_lamp_red_on() {
	hal_a->lamp_red_on();
	uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
	val = val & BIT_7;
	if (val == BIT_7) {
		erg = true;
	}
	return erg;
}

bool Regressionstest::test_lamp_yellow_on() {
	hal_a->lamp_yellow_on();
	uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
	val = val & BIT_6;
	if (val == BIT_6) {
		erg = true;
	}
	return erg;

}
bool Regressionstest::test_lamp_green_on() {
	hal_a->lamp_green_on();
	uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
	val = val & BIT_5;
	if (val == BIT_5) {
		erg = true;
	}
	return erg;
}
bool Regressionstest::test_lamp_red_off() {
	hal_a->lamp_red_off();
	uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
	val = val & BIT_7;
	if (val == BIT_7) {
		erg = true;
	}
	return erg;
}
bool Regressionstest::test_lamp_yellow_off() {
	hal_a->lamp_yellow_off();
	uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
	val = val & BIT_6;
	if (val == BIT_6) {
		erg = true;
	}
	return erg;
}
bool Regressionstest::test_lamp_green_off() {
	hal_a->lamp_green_off();
	uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
	val = val & BIT_5;
	if (val == BIT_5) {
		erg = true;
	}
	return erg;
}

bool Regressionstest::test_bar_open() {
	hal_a->bar_open();
	uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
	val = val & BIT_4;
	if (val == BIT_4) {
		erg = true;
	}
	return erg;

}
bool Regressionstest::test_bar_close() {
	hal_a->bar_close();
	uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
	val = val & BIT_4;
	if (val == BIT_4) {
		erg = true;
	}
	return erg;

}

bool Regressionstest::test_conveyor_move_right() {
	hal_a->conveyor_move_right();
	uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
	val = val & BIT_0;
	if (val == BIT_0) {
		erg = true;
	}
	return erg;
}
bool Regressionstest::test_conveyor_move_left() {
	hal_a->conveyor_move_left();
	uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
	val = val & BIT_1;
	if (val == BIT_1) {
		erg = true;
	}
	return erg;
}
bool Regressionstest::test_conveyor_stop() {
	hal_a->conveyor_stop();
	uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
	val = val && BIT_1 & BIT_0;
	if (val == (BIT_1 & BIT_0)) {
		erg = true;
	}
	return erg;
}

bool Regressionstest::test_led_start_button_on() {
	hal_a->led_start_button_on();
	uint8_t val = in8(DIO_BASE + DIO_OFFS_C);
	val = val & BIT_0;
	if (val == BIT_0) {
		erg = true;
	}
	return erg;
}
bool Regressionstest::test_led_reset_button_on() {
	hal_a->led_reset_button_on();
	uint8_t val = in8(DIO_BASE + DIO_OFFS_C);
	val = val & BIT_1;
	if (val == BIT_1) {
		erg = true;
	}
	return erg;
}
bool Regressionstest::test_led_start_button_off() {
	hal_a->led_start_button_off();
	uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
	val = val & BIT_0;
	if (val == BIT_0) {
		erg = true;
	}
	return erg;
}
bool Regressionstest::test_led_reset_button_off() {
	hal_a-> led_reset_button_off();
	uint8_t val = in8(DIO_BASE + DIO_OFFS_C);
	val = val & BIT_1;
	if (val == BIT_1) {
		erg = true;
	}
	return erg;
}

bool Regressionstest::test_general_switch_off() {
	hal_a->general_switch_off();
	uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
	val = val & BIT_0 & BIT_1 & BIT_2 & BIT_3;
	if (val == (CHECK_GENERAL_SWITCH)) {
		erg = true;
	}
	return erg;
}

void Regressionstest::TestAktorik() {
	erg = test_lamp_red_on();
	//	printf("lamp red on? %s \n" , erg );
	cout << "lamp red on? " << (erg ? "True" : "False") << endl;
	//	cout << "lamp red on? " << erg << endl;


	sleep(2);

	erg = test_lamp_yellow_on();
	cout << "lamp yellow on? " << (erg ? "True" : "False") << endl;
	sleep(2);

	erg = test_lamp_green_on();
	cout << "lamp green on? " << (erg ? "True" : "False") << endl;
	sleep(2);

	erg = test_lamp_red_off();
	cout << "lamp red off? " << (erg ? "True" : "False") << endl;
	sleep(2);

	erg = test_lamp_yellow_off();
	cout << "lamp yellow off? " << (erg ? "True" : "False") << endl;
	sleep(2);

	erg = test_lamp_green_off();
	cout << "lamp green off? " << (erg ? "True" : "False") << endl;
	sleep(2);

	erg = test_bar_open();
	cout << "bar open? " << (erg ? "True" : "False") << endl;
	sleep(2);

	erg = test_bar_close();
	cout << "bar closed? " << (erg ? "True" : "False") << endl;
	sleep(2);

	erg = test_conveyor_move_right();
	cout << "conveyor move right? " << (erg ? "True" : "False") << endl;
	sleep(2);

	erg = test_conveyor_stop();
	cout << "conveyor stoped? " << (erg ? "True" : "False") << endl;
	sleep(2);

	erg = test_conveyor_move_left();
	cout << "conveyor move left? " << (erg ? "True" : "False") << endl;
	sleep(2);

	erg = test_conveyor_stop();
	cout << "conveyor stoped? " << (erg ? "True" : "False") << endl;
	sleep(2);

	erg = test_led_start_button_on();
	cout << "start button on? " << (erg ? "True" : "False") << endl;
	sleep(2);

	erg = test_led_reset_button_on();
	cout << "reset button on? " << (erg ? "True" : "False") << endl;
	sleep(2);

	erg = test_led_start_button_off();
	cout << "start button off? " << (erg ? "True" : "False") << endl;
	sleep(2);

	erg = test_led_reset_button_off();
	cout << "reset button off? " << (erg ? "True" : "False") << endl;
	sleep(2);

}
