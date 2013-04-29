/*
 * Regressionstest.cpp
 *
 *  Created on: 24.04.2013
 *      Author: NG
 */

#include "Regressionstest.h"
#include "Addresses.h"
#include "HAL_A/HAL_A.h"
#include "HAL_S/HAL_S.h"
#include <stdlib.h>

using namespace std;
Regressionstest::Regressionstest() {
}

Regressionstest::~Regressionstest() {
}
HAL_A* hal_a = HAL_A::get_instance();
bool erg = false;

bool Regressionstest::test_lamp_red_on() {
	hal_a->lamp_red_on();
	int i = 1;
	uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
	val = BIT_7 && BIT_7;
	if (val == i) {
		erg = true;
	}
	return erg;
}

bool Regressionstest::test_lamp_yellow_on() {
	hal_a->lamp_yellow_on();
	int i = 1;
	uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
	val = BIT_6 && BIT_6;
	if (val == i) {
		erg = true;
	}
	return erg;

}
bool Regressionstest::test_lamp_green_on() {
	hal_a->lamp_green_on();
	int i = 1;
	uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
	val = BIT_5 && BIT_5;
	if (val == i) {
		erg = true;
	}
	return erg;
}
bool Regressionstest::test_lamp_red_off() {
	hal_a->lamp_red_off();
	int i = 0;
	uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
	val = BIT_7 && BIT_7;
	if (val == i) {
		erg = true;
	}
	return erg;
}
bool Regressionstest::test_lamp_yellow_off() {
	hal_a->lamp_yellow_off();
	int i = 0;
	uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
	val = BIT_6 && BIT_6;
	if (val == i) {
		erg = true;
	}
	return erg;
}
bool Regressionstest::test_lamp_green_off() {
	hal_a->lamp_green_off();
	int i = 0;
	uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
	val = BIT_5 && BIT_5;
	if (val == i) {
		erg = true;
	}
	return erg;
}

// Schrankensteuerung
bool Regressionstest::test_bar_open() {
	hal_a->bar_open();
	int i = 1;
	uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
	val = BIT_4 && BIT_4;
	if (val == i) {
		erg = true;
	}
	return erg;

}
bool Regressionstest::test_bar_close() {
	hal_a->bar_close();
	int i = 0;
	uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
	val = BIT_4 && BIT_4;
	if (val == i) {
		erg = true;
	}
	return erg;

}

// Fließbandsteuerung
bool Regressionstest::test_conveyor_move_right() {
	hal_a->conveyor_move_right();
	int i = 1;
	uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
	val = BIT_0 && BIT_0;
	if (val == i) {
		erg = true;
	}
	return erg;
}
bool Regressionstest::test_conveyor_move_left() {
	hal_a->conveyor_move_left();
	int i = 1;
	uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
	val = BIT_1 && BIT_1;
	if (val == i) {
		erg = true;
	}
	return erg;
}
bool Regressionstest::test_conveyor_stop() {
	hal_a->conveyor_stop();
	int i = 0;
	uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
	val = BIT_1 && BIT_0;
	if (val == i) {
		erg = true;
	}
	return erg;
}

//LED
bool Regressionstest::test_led_start_button_on() {
	hal_a->led_start_button_on();
	int i = 1;
	uint8_t val = in8(DIO_BASE + DIO_OFFS_C);
	val = BIT_0 && BIT_0;
	if (val == i) {
		erg = true;
	}
	return erg;
}
bool Regressionstest::test_led_reset_button_on() {
	hal_a->led_reset_button_on();
	int i = 1;
	uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
	val = BIT_1 && BIT_1;
	if (val == i) {
		erg = true;
	}
	return erg;
}
bool Regressionstest::test_led_start_button_off() {
	hal_a->led_start_button_off();
	int i = 0;
	uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
	val = BIT_0 && BIT_0;
	if (val == i) {
		erg = true;
	}
	return erg;
}
bool Regressionstest::test_led_reset_button_off() {
	hal_a-> led_reset_button_off();
	int i = 0;
	uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
	val = BIT_1 && BIT_1;
	if (val == i) {
		erg = true;
	}
	return erg;
}

bool Regressionstest::test_general_switch_off() {
	hal_a->general_switch_off();
	int i = 0;
	uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
	val = BIT_0 && BIT_1 && BIT_2 && BIT_3;
	if (val == i) {
		erg = true;
	}
	return erg;
}

void Regressionstest::startTest() {
	bool erg = false;

	erg = test_lamp_red_on();
	cout << "lamp red on? " << erg << endl;

	erg = test_lamp_yellow_on();
	cout << "lamp yellow on? " << erg << endl;

	erg = test_lamp_green_on();
	cout << "lamp green on? " << erg << endl;

	erg = test_lamp_red_off();
	cout << "lamp red off? " << erg << endl;

	erg = test_lamp_yellow_off();
	cout << "lamp yellow off? " << erg << endl;

	erg = test_lamp_green_off();
	cout << "lamp green off? " << erg << endl;

	// Schrankensteuerung
	erg = test_bar_open();
	cout << "bar open? " << erg << endl;

	erg = test_bar_close();
	cout << "bar closed? " << erg << endl;

	// Fließbandsteuerung
	erg = test_conveyor_move_right();
	cout << "conveyor move right? " << erg << endl;

	erg = test_conveyor_move_left();
	cout << "conveyor move left? " << erg << endl;

	erg = test_conveyor_stop();
	cout << "conveyor stoped? " << erg << endl;

	//LED
	erg = test_led_start_button_on();
	cout << "start button on? " << erg << endl;

	erg = test_led_reset_button_on();
	cout << "reset button on? " << erg << endl;

	erg = test_led_start_button_off();
	cout << "start button off? " << erg << endl;

	erg = test_led_reset_button_off();
	cout << "reset button off? " << erg << endl;

	erg = test_general_switch_off();
	cout << "OFF? " << erg << endl;
}
