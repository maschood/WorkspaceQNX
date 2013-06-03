/*
 * Puk_get_set.cpp
 *
 *  Created on: 21.05.2013
 *      Author: ich
 */

#include "Puk.h"

	char Puk::get_id(){
		return id;
	}
	void Puk::set_hight_one(char hight){
		// check if the first masure wasnt made.
		if((status  & BIT_4)==0){
			// writeing that the mesurment was made
			status = status | BIT_4;
			hight_one = hight;
		}
	}
	char Puk::get_hight_one(){
		char resu = -1;
		// check if the first masure was made.
		if((status  & BIT_4)>0){
			resu = hight_one;
		}
		return resu;
	}
	void Puk::set_hight_two(char hight){
		// check if the second masure wasnt made.
		if((status  & BIT_5)==0){
			// writeing that the mesurment was made
			status = status | BIT_5;
			hight_two = hight;
		}
	}
	char Puk::get_hight_two(){
		char resu = -1;
		// check if the second masure was made.
		if((status  & BIT_5)>0){
			resu = hight_two;
		}
		return resu;
	}

	void Puk::set_metal(char metal){
		// check if metal wasnt allready mesured
		if((status & BIT_0)==0){
			// set the bits
			status = status | BIT_0;
			if(metal > 0){
				status = status | BIT_1;
			}
		}
	}
	char Puk::get_metal(){
		char resu = -1;
		// check if the metal masure was made.
		if((status  & BIT_0)>0){
			resu = (status & BIT_1);
		}
		return resu;
	}
	void Puk::set_direction(char direction){
		// set the bits 0 = hole down, 1 = hole up
		status = status | BIT_2;
		if(direction > 0){
			status = status | BIT_3;
		}
	}
	char Puk::get_direction(){
		char resu = -1;
		// check if the metal masure was made.
		if((status  & BIT_2)>0){
			resu = (status & BIT_3);
		}
		return resu;
	}
	void Puk::set_remove(char remove){
		if (remove > 0){
			status = status | BIT_6;
		}
	}
	char Puk::get_remove(){
		return (status & BIT_6);
	}
