/*
 * Puk.cpp
 *
 *  Created on: 21.05.2013
 *      Author: ich
 */
#include "Puk.h"
#include "Dispatcher.h"

	Puk::Puk(){
		static char wayne = 0;
		id = wayne;
		hight_one = 0;
		hight_two = 0;
		status = 0;
		time_current = 0;
		time_last = 0;
//		zustand = &Dispatcher::puk_init();
		wayne++;
	}
	Puk::~Puk(){

	}

	int Puk::check_time(int input){
		int resu = -1;
		time_last = time_current;
		time_current = input;

		resu = (time_current - time_last);

		return resu;
	}

	void Puk::make_action(){
		zustand(this);
	}
