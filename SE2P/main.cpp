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
#include "RS232Test.h"

int main(int argc, char *argv[]) {
#ifdef SIMULATION
    cout << "Simulation aktiv" << endl;
    cout << "Zum Aufbau der Verbindung muss Die Festo Simulation schon laufen." << endl;
    IOaccess_open(); // Baue die Verbindung zur Simulation auf
#endif

    HAL_S* hal_s  = HAL_S::get_instance();
    hal_s->start_process();

#ifdef SIMULATION
   IOaccess_close(); // Schlie�e die Verbindung zur Simulation
#endif
	return EXIT_SUCCESS;
}

