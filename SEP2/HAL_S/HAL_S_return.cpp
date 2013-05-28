/*
 * HAL_S_return.cpp
 *
 *  Created on: 07.05.2013
 *      Author: ich
 */

#include "HAL_S/HAL_S.h"


int HAL_S::get_height_digital(uint8_t val_b_current){
	int resu = -1;
	if((val_b_current & BIT_1) == 0){
			printf("Something in the entrance\n");
			if((val_b_current & BIT_2) == BIT_2){
				resu = 1;
				cout << "Höhe ist ok" <<endl;// BIT ist auf 1
			}else{
				resu = 0;
				cout << "Höhe ist nicht ok" <<endl;
			}
	}
	return resu;
}


int HAL_S::get_metal(uint8_t val_b_current){
	int resu = -1;
		if((val_b_current & BIT_3) == 0){
				printf("Something in the entrance\n");
				if((val_b_current & BIT_4) == BIT_4){
					resu = 1;
					cout << "Werstück Metall" <<endl;// BIT ist auf 1
				}else{
					resu = 0;
					cout << "Werkstück kein Metall" <<endl;
				}
		}
	return resu;
}

int HAL_S::get_height_analog(){
		int hoehe = -1;
		int i;

		out8(AIO_PORT_A, AIO_GET_VAL);
		for (i = 0; i < 50; i++) {
			if ((in8(AIO_BASE) & BIT_7)) { // == (1<<7)
				hoehe = in16(AIO_PORT_A);
				break;
			}
		}
		return hoehe;
}
