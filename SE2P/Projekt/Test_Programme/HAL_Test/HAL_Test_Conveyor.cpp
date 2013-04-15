/*
 * HAL_Test_Conveyor.cpp
 *
 *  Created on: 15.04.2013
 *      Author: ich
 */

#include"HAL_Test.h"

	int HAL_Test::Test_Conveyor_Right(){
		int resu = 0;
		hal.conveyor_move_right();
		if(val != (1<<0)){ 				// Variable für Fließband rechtslauf nicht gesetzt
			resu = 1;
		}

		hal.conveyor_stop();
		if(val != 0){					// Variable für Fließband rechtslauf nicht ausgeschaltet
			resu = 1;
		}
		return resu;
	}

	int HAL_Test::Test_Conveyor_Left(){
		int resu = 0;
		hal.bar_open();
		if(val != (1<<1)){ 				// Variable für Fließband linkslauf nicht gesetzt
			resu = 2;
		}

		hal.conveyor_stop();
		if(val != 0){					// Variable für Fließband linkslauf nicht ausgeschaltet
			resu = 2;
		}
		return resu;
	}

	int Test_Conveyor_Stop(){
		int resu = 0;
		hal.conveyor_move_right();
		hal.conveyor_stop();
		if(val != 0){ 				// Variable für Fließband rechtslauf nicht ausgeschaltet
			resu = 3;
		}

		hal.conveyor_move_left();
		hal.conveyor_stop();
		if(val != 0){ 				// Variable für Fließband rechtslauf nicht ausgeschaltet
			resu = 3;
		}
		return resu;
	}
