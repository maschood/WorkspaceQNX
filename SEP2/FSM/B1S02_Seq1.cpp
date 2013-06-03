/*
 * B1S02_Seq1.cpp
 *
 *  Created on: 03.06.2013
 *      Author: maschood
 */

#include "B1S02_Seq1.h"
#include "HAL_A.h"

B1S02_Seq1::B1S02_Seq1() {


}

B1S02_Seq1::~B1S02_Seq1() {

}

void B1S02_Seq1::STOP_BTN_PRESSED(){
#ifdef DEBUG_MESSAGES
	cout << "MyState_1: START_BTN_PRESSED / lampeGrünAn" << endl;
#endif
	HAL_A* hal_a = HAL_A::get_instance();
	hal_a->general_switch_off();
}

void B1S02_Seq1::STOP_BTN_RELEASED(){
#ifdef DEBUG_MESSAGES
	cout << "MyState_1: START_BTN_PRESSED / lampeGrünAn" << endl;
#endif
	HAL_A* hal_a = HAL_A::get_instance();
	hal_a->lamp_yellow_on();
}
