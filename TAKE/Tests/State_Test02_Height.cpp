/*
 * B1S01_Entry.cpp
 *
 *  Created on: 24.11.2012
 *      Author: martin
 */

#include "State_Test02_Height.h"

State_Test02_Height::State_Test02_Height(Controller* controller) : BaseState(controller) {
	this->controller = controller;
	printf("Entering State 2: LS2\n");
}

State_Test02_Height::~State_Test02_Height() {
}

void State_Test02_Height::sbHeightcontrolClosed() {
	printf("Leaving State 2: LS2\n");
	new (this) State_Test03_Gate(controller);
}

