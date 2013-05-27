/*
 * HAL_S.h
 *
 *  Created on: 23.04.2013
 *      Author: ich
 */

/*
 * This class returns if a puk is at a defined place or not.
 */
#include <stdint.h>
#include <iostream>
#include <unistd.h>
#include <string.h>

#include "Addresses.h"
#include "HWaccess.h"
#include "Definitions.h"

#include "HAWThread/HAWThread.h"

using namespace thread;

class HAL_S: public thread::HAWThread {

public:

	int get_height_digital(uint8_t val_b_current);

	int get_height_analog(uint8_t val_b_current);

	int get_metal(uint8_t val_b_current);

	int get_bar_open(uint8_t val_b_current); // schecks if bar is open or not

	static HAL_S* get_instance(); // returns an pointer to the instance of the HAL_S.

	void start_process(); // Starts a process that permanently checks all sensors.

	~HAL_S();

private:
	int last_state;
	int current_state;

	uint8_t val_b_last;
	uint8_t val_c_last;
	uint8_t val_b_current;
	uint8_t val_c_current;

	HAL_S(); // Cunstuctor of the HAL_S.

	static HAL_S* instance; // singelton of the HAL_S.

	virtual void execute(void* arg);

	virtual void shutdown();

	void check_entrance(uint8_t val_b_current, uint8_t val_b_last); // checks if a puk is at the entrence.

	void check_hight_determinism(uint8_t val_b_current, uint8_t val_b_last); // checks if a puk is at the mesure laser.

	void check_bar(uint8_t val_b_current, uint8_t val_b_last); // checks if a puk is inside the bar.

	void check_slide_full(uint8_t val_b_current, uint8_t val_b_last); // checks if the slide is full or not.

	void check_exit(uint8_t val_b_current, uint8_t val_b_last); // checks if a puk is at the exit.

	void check_start_button(uint8_t val_c_current, uint8_t val_c_last); // checks if the start button is pressed or not.

	void check_stop_button(uint8_t val_c_current, uint8_t val_c_last); // checks if the stop button is pressed or not.

	void check_reset_button(uint8_t val_c_current, uint8_t val_c_last); // checks if the reset button is pressed or not.

	void check_quick_stop(uint8_t val_c_current, uint8_t val_c_last); // checks if the quick stop is pressed.
};
