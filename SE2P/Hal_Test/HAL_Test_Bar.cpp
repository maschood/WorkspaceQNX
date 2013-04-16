/*
 * HAL_Test_Bar.cpp
 *
 *  Created on: 15.04.2013
 *      Author: ich
 */

#include"HAL_Test.h"

int HAL_Test::Hal_Test_Bar(uint8_t val){
	int resu = 0;
	hal.bar_open();
	if((val & BIT_4) == 0){ 				// Variable für Schranke auf nicht gesetzt
		resu = 4;
	}

	hal.bar_close();
	if((val & BIT_4) != 0){					// Variable für Schranke auf nicht ausgeschaltet
		resu = 4;
	}
	return resu;
}
