/*
 * B1S01_Entry.cpp
 *
 *  Created on: 24.11.2012
 *      Author: martin
 */

#include "State_Test01_Entry.h"

State_Test01_Entry::State_Test01_Entry(Controller* controller) : BaseState(controller) {
	this->controller = controller;
	printf("Entering State 1: LS1\n");
}

State_Test01_Entry::~State_Test01_Entry() {
}

void State_Test01_Entry::sbStartClosed() {
	printf("Leaving State 1: LS1\n");
	new (this) State_Test02_Height(controller);
}

