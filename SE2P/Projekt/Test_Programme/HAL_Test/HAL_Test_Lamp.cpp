/*
 * HAL_Test_Lamp.cpp
 *
 *  Created on: 15.04.2013
 *      Author: ich
 */

#include"HAL_Test.h"

	int HAL_Test::Test_Lamp_Red(){
		int resu = 0;
		hal.lamp_red_on();
		if(val != (1<<7)){ 				// Variable f�r Rotes Licht an nicht gesetzt
			resu = 7;
		}

		hal.lamp_red_off();
		if(val != 0){					// Variable f�r rotes Licht an nicht ausgeschaltet
			resu = 7;
		}
		return resu;
	}

	int HAL_Test::Test_Lamp_Yellow(){
		int resu = 0;
		hal.lamp_red_on();
		if(val != (1<<6)){ 				// Variable f�r Gelbes Licht an nicht gesetzt
			resu = 6;
		}

		hal.lamp_red_off();
		if(val != 0){					// Variable f�r gelbes Licht an nicht ausgeschaltet
			resu = 6;
		}
		return resu;
	}

	int HAL_Test::Test_Lamp_Green(){
		int resu = 0;
		hal.lamp_red_on();
		if(val != (1<<5)){ 				// Variable f�r gr�nes Licht an nicht gesetzt
			resu = 5;
		}

		hal.lamp_red_off();
		if(val != 0){					// Variable f�r gr�nes Licht an nicht ausgeschaltet
			resu = 5;
		}
		return resu;
	}
