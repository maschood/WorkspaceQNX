/*
 * Regressionstest.cpp
 *
 *  Created on: 04.05.2013
 *      Author: NG
 */

<<<<<<< HEAD
#include "Regressionstest.h"
=======
#include "Regressionstest/Regressionstest.h"
>>>>>>> Nilüfer
#include "Addresses.h"
#include "HAL_A/HAL_A.h"
#include "HAL_S/HAL_S.h"
#include <stdlib.h>

<<<<<<< HEAD
#define PRINTBOOL(x) x ? "true" : "false"
=======
Regressionstest::Regressionstest() {
<<<<<<< HEAD
>>>>>>> Nilüfer

using namespace std;
Regressionstest::Regressionstest() {
}

Regressionstest::~Regressionstest() {
<<<<<<< HEAD
}

HAL_A* hal_a = HAL_A::get_instance();
bool erg = false;

void Regressionstest::TestLauf() {

=======

=======
}

Regressionstest::~Regressionstest() {
>>>>>>> Nilüfer
}

bool test = true;

void Regressionstest::TestLauf() {

	HAL_A* hal_a = HAL_A::get_instance();

	uint8_t val = in8(DIO_BASE + DIO_OFFS_B);

	while (test) {

		val = in8(DIO_BASE + DIO_OFFS_B);

		if ((~val & BIT_0) == BIT_0) { //Lichtschranke unterbrochen
			hal_a->lamp_green_on();
			hal_a->conveyor_move_right();
			sleep(1);
			hal_a->lamp_green_off();

		}

		if ((~val & BIT_1) == BIT_1) { //H�henmessung
			//	sleep(1);
			hal_a->lamp_red_on();
			sleep(1);
			hal_a->lamp_red_off();
			//hal_a->conveyor_move_right();
		}
		if ((~val & BIT_3) == BIT_3) { //Puk an Weiche angekommen
			hal_a->bar_open();
			sleep(1);
			hal_a->bar_close();
		}
		if ((~val & BIT_7) == BIT_7) { //Puk am Ende von Band
			hal_a->conveyor_stop();
			hal_a->lamp_yellow_on();
			sleep(1);
			hal_a->lamp_yellow_off();
			hal_a->conveyor_move_left();
			hal_a->bar_open();
			sleep(2);
			hal_a->bar_close();
			hal_a->conveyor_stop();
			hal_a->conveyor_move_right();
			sleep(1);
			hal_a->conveyor_stop();
			//test = false;
		}

	}
<<<<<<< HEAD
>>>>>>> Nilüfer
=======

>>>>>>> Nilüfer
}
