#include <cstdlib>
#include <iostream>
#include <unistd.h>

#include "HWaccess.h"
#include "HALintro.h"

using namespace std;


int main(int argc, char *argv[]) {
#ifdef SIMULATION
    cout << "Simulation aktiv" << endl;
    cout << "Zum Aufbau der Verbindung muss Die Festo Simulation schon laufen." << endl;
    IOaccess_open(); // Baue die Verbindung zur Simulation auf
#endif


    HALintro* hal = HALintro::getInstance();

    while(1) {
        hal->lampeRotAn();
        sleep(1);
        hal->lampeRotAus();
        sleep(1);
    }


#ifdef SIMULATION
    IOaccess_close(); // Schlieﬂe die Verbindung zur Simulation
#endif
    return EXIT_SUCCESS;
}
