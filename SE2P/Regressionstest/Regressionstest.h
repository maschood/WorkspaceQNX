/*
 * Regressionstest.h
 *
 *  Created on: 24.04.2013
 *      Author: NG
 */

#ifndef REGRESSIONSTEST_H_
#define REGRESSIONSTEST_H_

#define ISOFF	0
#define ISON	1

class Regressionstest {
public:
	Regressionstest();
	virtual ~Regressionstest();
	bool test_lamp_red_on();
	void startTest();
private:

	bool test_lamp_yellow_on();
	bool test_lamp_green_on();
	bool test_lamp_red_off();
	bool test_lamp_yellow_off();
	bool test_lamp_green_off();

	// Schrankensteuerung
	bool test_bar_open();
	bool test_bar_close();

	// Fließbandsteuerung
	bool test_conveyor_move_right();
	bool test_conveyor_move_left();
	bool test_conveyor_stop();

	//LED
	bool test_led_start_button_on();
	bool test_led_reset_button_on();
	bool test_led_start_button_off();
	bool test_led_reset_button_off();
	bool test_general_switch_off();

};

#endif /* REGRESSIONSTEST_H_ */
