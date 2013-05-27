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
#include "HAL_ISR/HAL_ISR.h"
#include "Regressionstest/Regressionstest.h"
#include "Dispatcher/DispatcherIntro.h"
#include "Dispatcher/HALCallInterface.h"
#include "FSM/MyController.h"
#include "FSM/MyState.h"

int main(int argc, char *argv[]) {
#ifdef SIMULATION
	cout << "Simulation aktiv" << endl;
	cout << "Zum Aufbau der Verbindung muss Die Festo Simulation schon laufen."
			<< endl;
	IOaccess_open(); // Baue die Verbindung zur Simulation auf
#endif

<<<<<<< HEAD
	  cout << "Dispatcher Intro" << endl;
	    cout << "=========================================================" << endl;
	    cout << endl;

	    HAL_ISR* sens = HAL_ISR::getInstance();
	    sens->start(NULL);

	    DispatcherIntro dispatcher;
	    dispatcher.start(NULL);

	    MyController controller;
	    dispatcher.registerController(&controller, werks_einlauf, 0);
	    dispatcher.registerController(&controller, werks_einlauf, 1);


	    string quit;
	    do {
	        cin >> quit;
	    } while (quit != "q");

	    cout << "Quitting..." << endl;

	    sens->stop();
	    dispatcher.stop();

	    sens->join();
	    dispatcher.join();

	    cout << "quit." << endl;



//	int mode = NORMAL;
//	HAL_ISR* isr;
//	string quit;
//	Regressionstest rt;
//
//
//	switch (mode) {
//	case NORMAL:
//		isr = HAL_ISR::getInstance();
//		isr->start(NULL);
//		cout << "HAL Sensorik" << endl;
//		cout << "========================================================="
//				<< endl;
//		cout << endl;
//
//		do {
//			cin >> quit;
//		} while (quit != "q");
//		cout << "Quitting...";
//		isr->stop();
//		isr->join();
//		cout << " done." << endl;
//		break;
//	case TEST:
//		break;
//	case REGRESSION:
//		rt.TestLauf();
//		break;
//	default:
//		break;
//	}
=======
	mode = NORMAL;
	station = 1; // definition der Laufbandnummer
	HAL_ISR* isr;
	string quit;
	Regressionstest rt;


	switch (mode) {
	case NORMAL:
		isr = HAL_ISR::getInstance();
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
		rt.TestLauf();
		break;
	default:
		break;
	}
>>>>>>> 956a8e35f71e214d5be5ac5d7c3cfde00807c9f2

#ifdef SIMULATION
	IOaccess_close(); // Schliee die Verbindung zur Simulation
#endif
	return EXIT_SUCCESS;
}

