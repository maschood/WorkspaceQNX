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
	void TestAktorik();
	void TestSensorik();
	void TestLauf();
private:

	//Aktorik
	bool test_lamp_yellow_on();
	bool test_lamp_green_on();
	bool test_lamp_red_off();
	bool test_lamp_yellow_off();
	bool test_lamp_green_off();

	bool test_bar_open();
	bool test_bar_close();

	bool test_conveyor_move_right();
	bool test_conveyor_move_left();
	bool test_conveyor_stop();

	bool test_led_start_button_on();
	bool test_led_reset_button_on();
	bool test_led_start_button_off();
	bool test_led_reset_button_off();
	bool test_general_switch_off();
};

#endif /* REGRESSIONSTEST_H_ */
