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
#include "HAL_A.h"
#include "HAL_S/HAL_S.h"
#include "HWaccess.h"
#include "HAWThread.h"
#include "Mutex.h"
#include "RS232_1.h"
<<<<<<< HEAD

<<<<<<< HEAD
#include"Test/Vererbungstest.h"
=======
//#include "Versuchsordner/ChildClass.h"


>>>>>>> Erik
=======
#include "Regressionstest.h"
>>>>>>> Nilüfer

int main(int argc, char *argv[]) {
#ifdef SIMULATION
	cout << "Simulation aktiv" << endl;
	cout << "Zum Aufbau der Verbindung muss Die Festo Simulation schon laufen."
			<< endl;
	IOaccess_open(); // Baue die Verbindung zur Simulation auf
#endif

<<<<<<< HEAD
    HAL_S* hal_s  = HAL_S::get_instance();
    hal_s->start(NULL);

//   ChildClass* one;
//   one = new ChildClass();
//    ChildClass* two;
//    two = new ChildClass();

//    one->InstanzialteChildClass(1);
//    two->InstanzialteChildClass(2);

//    one->start(NULL);
//    two->start(NULL);

    while(MANOWAR){
    	printf("bla in der Main\n");
    }
//    ChildClass* eins = new ChildClass();
//    eins->InstanzialteChildClass(1);
//    ChildClass* zwei;
//    zwei->InstanzialteChildClass(2);
//
//    eins->ChildClass::start();
//    zwei->ChildClass::start();




=======
	//  HAL_S* hal_s  = HAL_S::get_instance();
	//  hal_s->start_process();
>>>>>>> Nilüfer


#ifdef SIMULATION
	IOaccess_close(); // Schlie�e die Verbindung zur Simulation
#endif
	return EXIT_SUCCESS;
}
