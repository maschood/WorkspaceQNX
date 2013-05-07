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
#include "HAL_A/HAL_A.h"
#include "HWaccess.h"
#include "HAWThread/HAWThread.h"
#include "Mutex/Mutex.h"
#include "RS232/RS232_1.h"
#include "HAL_S/HAL_ISR.h"
#include "Regressionstest/Regressionstest.h"

	 int main(int argc, char *argv[]) {
	 #ifdef SIMULATION
	     cout << "Simulation aktiv" << endl;
	     cout << "Zum Aufbau der Verbindung muss Die Festo Simulation schon laufen." << endl;
	     IOaccess_open(); // Baue die Verbindung zur Simulation auf
	 #endif

//     HAL_S* hal_s  = HAL_S::get_instance();
//    hal_s->start(NULL);
//
//	     Regressionstest rt;
//	     rt.TestLauf();



//    HAL_A* hal_a = HAL_A::get_instance();
//
//
//    while(MANOWAR){
//        hal_a->lamp_green_on();
//        sleep(1);
//        hal_a->lamp_green_off();
//        sleep(1);
//    }

    cout << "HAL Sensorik" << endl;
        cout << "=========================================================" << endl;
        cout << endl;


        HAL_ISR* isr = HAL_ISR::getInstance();
        isr->start(NULL);
//
        string quit;
        do {
            cin >> quit;
        } while (quit != "q");

        cout << "Quitting...";

        isr->stop();
        isr->join();

        cout << " done." << endl;

//    HAL_S* hal_s  = HAL_S::get_instance();
//    hal_s->start(NULL);

//   ChildClass* one;
//   one = new ChildClass();
//    ChildClass* two;
//    two = new ChildClass();

//    one->InstanzialteChildClass(1);
//    two->InstanzialteChildClass(2);

//    one->start(NULL);
//    two->start(NULL);

//    while(MANOWAR){
//    	printf("bla in der Main\n");
//    }
//    ChildClass* eins = new ChildClass();
//    eins->InstanzialteChildClass(1);
//    ChildClass* zwei;
//    zwei->InstanzialteChildClass(2);
//
//    eins->ChildClass::start();
//    zwei->ChildClass::start();
//    hal_s->start_process();
//    rs2.readMsg();
//    rs1.sendMsg();



 #ifdef SIMULATION
    IOaccess_close(); // Schliee die Verbindung zur Simulation
 #endif
//   delete rs1;
 	return EXIT_SUCCESS;
 }



