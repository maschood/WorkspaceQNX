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

#include "Addresses.h"
#include "HWaccess.h"
#include "Definitions.h"

class HAL_S{
public:

	static HAL_S* get_instance(); // returns an pointer to the instance of the HAL_S.

	void start_process(); // Starts a process that permanently checks all sensors.

	~HAL_S();

private:
	static HAL_S* instance; // singelton of the HAL_S.

	HAL_S(); // Cunstuctor of the HAL_S.

	void check_entrance(uint8_t val); // checks if a puk is at the entrence.

	void check_hight_determinism(uint8_t val); // checks if a puk is at the mesure laser.

	int hight_mesure(); // returns the hight of the puk.

	void check_bar(uint8_t val); // checks if a puk is inside the bar.

	int check_metal(); // checks if the puk is contains metal or not.

	int check_bar_open(); // checks if the bar is open or not.

	void check_slide_full(uint8_t val); // checks if the slide is full or not.

	void check_exit(uint8_t val); // checks if a puk is at the exit.

	void check_start_button(uint8_t val); // checks if the start button is pressed or not.

	void check_stop_button(uint8_t val); // checks if the stop button is pressed or not.

	void check_reset_button(uint8_t val); // checks if the reset button is pressed or not.

	void check_quick_stop(uint8_t val); // checks if the quick stop is pressed.
};
