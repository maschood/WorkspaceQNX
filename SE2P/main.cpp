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
#include "HAL.h"
#include "HWaccess.h"
#include "HAWThread.h"


int main(int argc, char *argv[]) {
#ifdef SIMULATION
    cout << "Simulation aktiv" << endl;
    cout << "Zum Aufbau der Verbindung muss Die Festo Simulation schon laufen." << endl;
    IOaccess_open(); // Baue die Verbindung zur Simulation auf
#endif

	HAL* hal = HAL::get_instance();

    while(1) {
        hal->lamp_red_on();
        sleep(1);
        hal->lamp_red_off();
        sleep(1);
        hal->lamp_green_on();
        sleep(1);
        hal->lamp_green_off();
        sleep(1);
        hal->lamp_yellow_on();
        sleep(1);
        hal->lamp_yellow_off();
        sleep(1);
        hal->conveyor_move_left();
        sleep(1);
        hal->conveyor_stop();
        sleep(1);
        hal->conveyor_move_right();
        sleep(1);
        hal->bar_open();
        sleep(1);
        hal->bar_close();
        sleep(1);
    }
#ifdef SIMULATION
    IOaccess_close(); // Schlieﬂe die Verbindung zur Simulation
#endif
	return EXIT_SUCCESS;
}
