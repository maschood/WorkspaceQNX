/*
 * HAL_S_interrupt.cpp
 *
 *  Created on: 23.04.2013
 *      Author: ich
 */

#include "HAL_S/HAL_S.h"

void HAL_S::check_entrance(uint8_t val){ // checks if a puk is at the entrence.
	if((~val & BIT_0) == BIT_0){
		printf("Something in the entrance\n");
		printf("%x\n", val);
	}
}

void HAL_S::check_hight_determinism(uint8_t val){ // checks if a puk is at the mesure laser.
	if((~val & BIT_1) == BIT_1){
		printf("something in the mesure laser\n");
		printf("%x\n", val);
	}
}

void HAL_S::check_bar(uint8_t val){ // checks if a puk is inside the bar.
	if((~val & BIT_3) == BIT_3){
		printf("something inside the bar\n");
		printf("%x\n", val);
	}
}

void HAL_S::check_slide_full(uint8_t val){ // checks if the slide is full or not.
	if((~val & BIT_6) == BIT_6){
		printf("slide full\n");
		printf("%x\n", val);
	}
}

void HAL_S::check_exit(uint8_t val){ // checks if a puk is at the exit.
	if((~val & BIT_7) == BIT_7){
		printf("something leavin\n");
		printf("%x\n", val);
	}
}

void HAL_S::check_start_button(uint8_t val){ // checks if the start button is pressed or not.
	if((val & BIT_4) == BIT_4){
		printf("start button pressed\n");
		printf("%x\n", val);
	}
}

void HAL_S::check_stop_button(uint8_t val){ // checks if the stop button is pressed or not.
	if((~val & BIT_5) == BIT_5){
		printf("stop button pressed\n");
		printf("%x\n", val);
	}
}

void HAL_S::check_reset_button(uint8_t val){ // checks if the reset button is pressed or not.
	if((val & BIT_6) == BIT_6){
		printf("reset button pressed\n");
		printf("%x\n", val);
	}
}

void HAL_S::check_quick_stop(uint8_t val){ // checks if the quick stop is pressed.
	if((~val & BIT_7) == BIT_7){
		printf("shit is fucked up\n");
		printf("%x\n", val);
	}
}
