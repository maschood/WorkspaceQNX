/**
 * SE2 SS 2013
 * main class
 *
 * @file main.cpp
 * @author Erik Matthiessen
 *         Denis Rycka
 *         Nil�fer G�ng�r
 *         Maschhood Ahmad
 * 
 */


#include <cstdlib>
#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <sys/neutrino.h>


#include "LightController.h"
#include "HAL_S.h"
#include "HAL_ISR.h"
#include "PuckHandler.h"
#include "Controller.h"
#include "ErrorFSM.h"
#include "Timer.h"
#include "Receiver.h"

int main(int argc, char *argv[]) {

	HAL_A* hal_a = HAL_A::getInstance();
	HAL_S::getInstance();

	LightController* lc = LightController::getInstance();

	ErrorFSM* errfsm = ErrorFSM::getInstance();
	errfsm->start(0);

	Dispatcher* disp = Dispatcher::getInstance();
	disp->start(0);

	HAL_ISR* isrhandler = HAL_ISR::getInstance();
	isrhandler->start(0);

	PuckHandler::getInstance()->initializePucks();

	Receiver* recv = Receiver::getInstance();
	recv->start(0);

	/*START CLEANUP*/
	char breakWhile = 0;
	while(1){
		//tastatureiongabe lesen, dann thread stoppen, irqs stoppen, join, profit
		std::cin >> breakWhile;
		if(breakWhile == 'q'){
			break;
		}
	}
	printf("main was stopped, cleaning up ....\n");
	disp->stop();
	isrhandler->stop();
	hal_a->engine_stop();
	hal_a->gate(false);
	errfsm->stop();
	lc->lightsOff();
	lc->cont();
	lc->stop();
	recv->stop();


	disp->join();
	isrhandler->join();
	lc->join();
	errfsm->join();
	recv->join();
	/*END CLEANUP*/


	printf("EXIT_SUCCESS \n");

	return EXIT_SUCCESS;
}
