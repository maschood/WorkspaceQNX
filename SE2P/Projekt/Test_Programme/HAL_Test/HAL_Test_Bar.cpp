/*
 * HAL_Test_Bar.cpp
 *
 *  Created on: 15.04.2013
 *      Author: ich
 */

#include"HAL_Test.h"

int HAL_Test::Hal_Test_Bar(){
	int resu = 0;
	hal.bar_open();
	if(val != (1<<4)){ 				// Variable für Schranke auf nicht gesetzt
		resu = 4;
	}

	hal.lamp_red_off();
	if(val != 0){					// Variable für Schranke auf nicht ausgeschaltet
		resu = 4;
	}
	return resu;
}
