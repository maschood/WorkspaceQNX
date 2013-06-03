/*
 * B1S01_Entry.cpp
 *
 *  Created on: 24.11.2012
 *      Author: martin
 */

#include "State_Test04_Slide.h"

State_Test04_Slide::State_Test04_Slide(Controller* controller) : BaseState(controller) {
	this->controller = controller;
	printf("Entering State 4: LS4\n");
}

State_Test04_Slide::~State_Test04_Slide() {
}

void State_Test04_Slide::sbSlideClosed() {
	printf("Leaving State 4: LS4\n");
	new (this) State_Test05_Slide(controller);
}

