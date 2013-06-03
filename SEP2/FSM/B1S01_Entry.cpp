/*
 * B1S01_Entry.cpp
 *
 *  Created on: 03.06.2013
 *      Author: maschood
 */

#include "B1S01_Entry.h"
#include "HAL_A.h"
#include "B1S02_Seq1.h"

B1S01_Entry::B1S01_Entry(Controller* controller):BasicState(controller){
}

B1S01_Entry::~B1S01_Entry() {

}

void B1S01_Entry::START_BTN_PRESSED(void){
#ifdef DEBUG_MESSAGES
	cout << "MyState_1: START_BTN_PRESSED / lampeGrünAn" << endl;
#endif
	HAL_A* hal_a = HAL_A::get_instance();
	hal_a->lamp_red_on();
}

void B1S01_Entry::START_BTN_RELEASED(){
#ifdef DEBUG_MESSAGES
	cout << "MyState_1: START_BTN_PRESSED / lampeGrünAn" << endl;
#endif
	HAL_A* hal_a = HAL_A::get_instance();
	hal_a->lamp_green_on();
}
