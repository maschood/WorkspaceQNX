/*
 * MyController.cpp
 */

#include "MyController.h"
#include "HAL_A/HAL_A.h"
#include "HAL_S/HAL_S.h"

#include <iostream>
#include <new>

using namespace std;

// -----------------------------------------------------------------------------
//  Class MyController
// -----------------------------------------------------------------------------
MyController::MyController(void) :
	state(new MyState_1) {

}

MyController::~MyController(void) {
	delete state;
}

// -----------------------------------------------------------------------------
//  Class MyState_1
// -----------------------------------------------------------------------------
MyState_1::MyState_1(void) {
}

void MyState_1::WERKS_EINLAUF_0(void) {
#ifdef DEBUG_MESSAGES
	cout << "MyState_1: WERKS_EINLAUF_0 / lampeRotAn --> MyState_2" << endl;
#endif
	HAL_A::get_instance()->conveyor_move_right();
	new (this) MyState_2;

}

// -----------------------------------------------------------------------------
//  Class MyState_2
// -----------------------------------------------------------------------------
MyState_2::MyState_2(void) {
}

void MyState_2::WERKS_EINLAUF_1(void) {
#ifdef DEBUG_MESSAGES
	cout << "MyState_2: WERKS_EINLAUF_1 / lampeRotAus --> MyState_3" << endl;
#endif
	HAL_A::get_instance()->lamp_green_on();
	new (this) MyState_3;

}

MyState_3::MyState_3(void) {
}
void MyState_3::WERKS_IN_HOEHENMESSUNG_0() {
	cout << "MyState_3: WERKS_IN_HOEHENMESSUNG_0 / --> MyState_4" << endl;

	hoehe = HAL_S::get_instance()->get_height_analog();

	if (hoehe < HOEHENWERT) { //keine Magic Numbers!!
		cout << "Werkst�ck hat: " << hoehe;
		//HAL_A::get_instance()->bar_open();
		HAL_A::get_instance()->conveyor_move_right();
		new (this) MyState_4;
	} else {
		cout << "Werkst�ck zu flach" << endl;
		HAL_A::get_instance()->conveyor_move_right();
		new (this) MyState_7;
	}

}

MyState_4::MyState_4(void) {
}
void MyState_4::WERKS_IN_HOEHENMESSUNG_1() {
	cout << "MyState_4: WERKS_IN_HOEHENMESSUNG_1 / --> MyState_5" << endl;
	HAL_A::get_instance()->conveyor_move_right();
	//HAL_A::get_instance()->bar_close();
	//HAL_A::get_instance()->conveyor_stop();

	new (this) MyState_5;
}

MyState_5::MyState_5(void) {
}
void MyState_5::WERKS_IN_WEICHE_0() {
	cout << "MyState_5: WERKS_IN_WEICHE_0 / --> MyState_6" << endl;
	HAL_A::get_instance()->conveyor_move_right();
	HAL_A::get_instance()->bar_open();
	//    HAL_A::get_instance()->lamp_green_off();

	new (this) MyState_6;
}

MyState_6::MyState_6(void) {
}
void MyState_6::WERKS_IN_WEICHE_1() {
	cout << "MyState_5: WERKS_IN_WEICHE_1 / --> MyState_1" << endl;
	HAL_A::get_instance()->conveyor_move_right();
	HAL_A::get_instance()->bar_open();
	//HAL_A::get_instance()->lamp_green_off();
	sleep(1);
	HAL_A::get_instance()->bar_close();
	HAL_A::get_instance()->conveyor_stop();


	new (this) MyState_9;
}
MyState_7::MyState_7(void) {
}
void MyState_7::RUTSCHE_VOLL_0() {
	cout << "MyState_7: RUTSCHE_VOLL_0 / --> MyState_8" << endl;
	HAL_A::get_instance()->conveyor_move_right();
	new(this) MyState_8;
}

MyState_8::MyState_8(void) {
}
void MyState_8::RUTSCHE_VOLL_1() {
	cout << "MyState_8: RUTSCHE_VOLL_1 / --> Ende" << endl;
	HAL_A::get_instance()->conveyor_move_right();
	new(this) MyState_1; //so richtig??
}

MyState_9::MyState_9(void) {
}
void MyState_9::WERKS_AUSLAUF_0() {
	cout << "MyState_9: WERKS_AUSLAUF_0 / --> WERKS_AUSLAUF_1" << endl;
	HAL_A::get_instance()->conveyor_move_right();
	new(this) MyState_10;
}

MyState_10::MyState_10(void) {
}
void MyState_10::WERKS_AUSLAUF_1() {
	cout << "MyState_10: WERKS_AUSLAUF_1 / --> Ende" << endl;
	HAL_A::get_instance()->conveyor_stop();
	new(this) MyState_1;
}
