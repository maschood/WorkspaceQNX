/*
 * B1S01_Entry.cpp
 *
 *  Created on: 24.11.2012
 *      Author: martin
 */

#include "State_Test03_Gate.h"

State_Test03_Gate::State_Test03_Gate(Controller* controller) : BaseState(controller) {
	this->controller = controller;
	printf("Entering State 3: LS3\n");
}

State_Test03_Gate::~State_Test03_Gate() {
}

void State_Test03_Gate::sbGateClosed() {
	printf("Leaving State 3: LS3\n");
	new (this) State_Test04_Slide(controller);
}

