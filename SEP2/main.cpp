/*
 * main1.cpp
 *
 *  Created on: 15.04.2013
 *      Author: maschood
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <unistd.h>

#include "Addresses.h"
#include "Definitions.h"
#include "HAL_A/HAL_A.h"
#include "HWaccess.h"
#include "HAWThread/HAWThread.h"
#include "Mutex/Mutex.h"
#include "RS232/RS232_1.h"
#include "RS232/RS232_2.h"
#include "HAL_ISR/HAL_ISR.h"
#include "Regressionstest/Regressionstest.h"
#include "DISPATCHER/Dispatcher.h"
#include "Dispatcher/HALCallInterface.h"
#include "BasicState.h"
#include "Controller.h"
#include <Time.h>

int main(int argc, char *argv[]) {
#ifdef SIMULATION
	cout << "Simulation aktiv" << endl;
	cout << "Zum Aufbau der Verbindung muss Die Festo Simulation schon laufen."
	<< endl;
	IOaccess_open(); // Baue die Verbindung zur Simulation auf
#endif
	int mode = DISPATCHER;
	string quit;
	Regressionstest rt;
	HAL_ISR* isr = HAL_ISR::getInstance();
	Dispatcher dispatcher;
	Controller controller(1);

//	RS232_1* com1 = RS232_1::getInstance();
//	RS232_2* com2 = RS232_2::getInstance();

	switch (mode) {
	case NORMAL:
		isr->start(NULL);
		cout << "HAL Sensorik" << endl;
		cout << "========================================================="
				<< endl;
		cout << endl;

		do {
			cin >> quit;
		} while (quit != "q");
		cout << "Quitting...";
		isr->stop();
		isr->join();
		cout << " done." << endl;
		break;
	case TEST:
		break;
	case REGRESSION:
//		rt.TestLauf();
		break;
	case DISPATCHER:
		cout << "Dispatcher" << endl;
		cout << "========================================================="
				<< endl;
		cout << endl;

		isr->start(NULL);

		dispatcher.start(NULL);

		//Regestrieren


		dispatcher.registerController(&controller, start_btn, 0);
		dispatcher.registerController(&controller, start_btn, 1);
		dispatcher.registerController(&controller, stop_btn, 0);
		dispatcher.registerController(&controller, stop_btn, 1);

//		dispatcher.registerController(&controller, werks_einlauf, 1);
//		dispatcher.registerController(&controller, werks_in_hoehenmessung, 0);
//		dispatcher.registerController(&controller, werks_in_hoehenmessung, 1);
//		dispatcher.registerController(&controller, werks_in_weiche, 0);
//		dispatcher.registerController(&controller, werks_in_weiche, 1);
//		dispatcher.registerController(&controller, rutsche_voll, 0);
//		dispatcher.registerController(&controller, rutsche_voll, 1);
//		dispatcher.registerController(&controller, werks_auslauf, 0);
//		dispatcher.registerController(&controller, werks_auslauf, 1);

		do {
			cin >> quit;
		} while (quit != "q");

		cout << "Quitting..." << endl;

		isr->stop();
		dispatcher.stop();

		isr->join();
		dispatcher.join();

		cout << "quit." << endl;

		break;
	case RS232:
//
//		cout << "*********************Test RS232_1***************** \n" << endl;
////		//Test 1: read on ser1, write on ser2
//		com1->start(NULL);
//		com2->sendMsg('b');
//		sleep(3);
//		com2->sendMsg('a');
//		sleep(2);
//		com1->stop();
//		sleep(5);
//		com1->join();
//
//		cout << "*********************Test RS232_2***************** \n" << endl;
////		//Test 2: read on ser2, write on ser1
//		com2->start(NULL);
//		com1->sendMsg('a');
//		sleep(3);
//		com1->sendMsg('b');
//		sleep(2);
//		com2->stop();
//		sleep(5);
//		com2->join();
//
//		com1->~RS232_1();
//		com2->~RS232_2();

		do {
			cin >> quit;
		} while (quit != "q");

		cout << "Quitting..." << endl;

		cout << "quit." << endl;
		break;
	default:
		break;
	}

#ifdef SIMULATION
	IOaccess_close(); // Schliee die Verbindung zur Simulation
#endif
	return EXIT_SUCCESS;
}
