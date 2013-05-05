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

Regressionstest::Regressionstest() {

}

Regressionstest::~Regressionstest() {

}

void Regressionstest::TestLauf() {
	HAL_A* hal_a = HAL_A::get_instance();

	uint8_t val = in8(DIO_BASE + DIO_OFFS_B);

	while (true) {

		val = in8(DIO_BASE + DIO_OFFS_B);

		if ((~val & BIT_0) == BIT_0) { //Lichtschranke unterbrochen
			hal_a->conveyor_move_right();
		}

		else if ((~val & BIT_1) == BIT_1) { //Höhenmessung
			sleep(1);
			hal_a->conveyor_move_right();
		}

		else if ((~val & BIT_3) == BIT_3) { //Puk an Weiche angekommen
			hal_a->bar_open();
			sleep(1);
			hal_a->conveyor_move_right();
			sleep(3);
			hal_a->bar_close();
			hal_a->conveyor_move_right();

		} else if ((~val & BIT_7) == BIT_7) { //Puk am Ende von Band
			hal_a->conveyor_stop();
		}

	}
}
