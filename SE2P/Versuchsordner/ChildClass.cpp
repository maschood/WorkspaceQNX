/*
 * ChildClass.cpp
 *
 *  Created on: 01.05.2013
 *      Author: ich
 */

#include <stdio.h>
#include"Versuchsordner/ChildClass.h"
using namespace thread;

ChildClass::ChildClass(){

}

ChildClass::~ChildClass(){

}

void ChildClass::InstanzialteChildClass(int i){
	id = i;
	count = 0;
}
void ChildClass::shutdown(){
	printf("shutting down");
}

void ChildClass::ausgabe(){
	printf("ID: %d | COUNT: %d\n",id,count);
	count++;
}

void ChildClass::execute(void* arg){
	while(!isStopped()){
		ausgabe();
	}
}

