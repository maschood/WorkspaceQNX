/*
 * HAL_S_interrupt.cpp
 *
 *  Created on: 23.04.2013
 *      Author: ich
 */

#include "HAL_S/HAL_S.h"

void HAL_S::check_entrance(uint8_t val_b_current, uint8_t val_b_last){ // checks if a puk is at the entrence.
	if((val_b_current & BIT_0)-(val_b_last & BIT_0) != 0){
		printf("Something in the entrance\n");
		if((val_b_last & BIT_0) == BIT_0){
			// BIT ist auf 1
		}else{
			// BIT ist auf 0
		}
	}
}

void HAL_S::check_hight_determinism(uint8_t val_b_current, uint8_t val_b_last){ // checks if a puk is at the mesure laser.
	if((val_b_current & BIT_1)-(val_b_last & BIT_1) != 0){
		printf("something in the mesure laser\n");
		if((val_b_last & BIT_1) == BIT_1){
			// BIT ist auf 1
		}else{
			// BIT ist auf 0
		}
	}
}

void HAL_S::check_bar(uint8_t val_b_current, uint8_t val_b_last){ // checks if a puk is inside the bar.
	if((val_b_current & BIT_3)-(val_b_last & BIT_3) != 0){
		printf("something inside the bar\n");
		if((val_b_last & BIT_3) == BIT_3){
			// BIT ist auf 1
		}else{
			// BIT ist auf 0
		}
	}
}

void HAL_S::check_slide_full(uint8_t val_b_current, uint8_t val_b_last){ // checks if the slide is full or not.
	if((val_b_current & BIT_6)-(val_b_last & BIT_6) != 0){
		printf("slide full\n");
		if((val_b_last & BIT_6) == BIT_6){
			// BIT ist auf 1
		}else{
			// BIT ist auf 0
		}
	}
}

void HAL_S::check_exit(uint8_t val_b_current, uint8_t val_b_last){ // checks if a puk is at the exit.
	if((val_b_current & BIT_7)-(val_b_last & BIT_7) != 0){
		printf("something leavin\n");
		if((val_b_last & BIT_7) == BIT_7){
			// BIT ist auf 1
		}else{
			// BIT ist auf 0
		}
	}
}

void HAL_S::check_start_button(uint8_t val_c_current, uint8_t val_c_last){ // checks if the start button is pressed or not.
	if((val_c_current & BIT_4)-(val_c_last & BIT_4) != 0){
		printf("start button pressed\n");
		if((val_c_last & BIT_4) == BIT_4){
			// BIT ist auf 1
		}else{
			// BIT ist auf 0
		}
	}
}

void HAL_S::check_stop_button(uint8_t val_c_current, uint8_t val_c_last){ // checks if the stop button is pressed or not.
	if((val_c_current & BIT_5)-(val_c_last & BIT_5) != 0){
		printf("stop button pressed\n");
		if((val_c_last & BIT_5) == BIT_5){
			// BIT ist auf 1
		}else{
			// BIT ist auf 0
		}
	}
}

void HAL_S::check_reset_button(uint8_t val_c_current, uint8_t val_c_last){ // checks if the reset button is pressed or not.
	if((val_c_current & BIT_6)-(val_c_last & BIT_6) != 0){
		printf("reset button pressed\n");
		if((val_c_last & BIT_6) == BIT_6){
			// BIT ist auf 1
		}else{
			// BIT ist auf 0
		}
	}
}

void HAL_S::check_quick_stop(uint8_t val_c_current, uint8_t val_c_last){ // checks if the quick stop is pressed.
	if((val_c_current & BIT_7)-(val_c_last & BIT_7) != 0){
		printf("shit is fucked up\n");
		if((val_c_last & BIT_7) == BIT_7){
			// BIT ist auf 1
		}else{
			// BIT ist auf 0
		}
	}
}
