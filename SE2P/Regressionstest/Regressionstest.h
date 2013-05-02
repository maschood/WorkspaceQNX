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

	//Sensorik
	bool test_check_entrance(uint8_t val);
	bool test_check_hight_determinism(uint8_t val);
	bool test_hight_mesure();
	bool test_check_bar(uint8_t val);
	bool test_check_metal();
	bool test_check_bar_open();
	bool test_check_slide_full(uint8_t val);
	bool test_check_exit(uint8_t val);
	bool test_check_start_button(uint8_t val);
	bool test_check_stop_button(uint8_t val);
	bool test_check_reset_button(uint8_t val);
	bool test_check_quick_stop(uint8_t val);

};

#endif /* REGRESSIONSTEST_H_ */
