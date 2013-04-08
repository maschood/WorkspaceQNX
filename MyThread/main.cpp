#include <cstdlib>
#include <iostream>
#include <string>

#include "HWaccess.h"
#include "Addresses.h"
#include "MyThread.h"

using namespace std;

int main(int argc, char *argv[]) {
#ifdef SIMULATION
    cout << "Simulation aktiv" << endl;
    cout << "Zum Aufbau der Verbindung muss Die Festo Simulation schon laufen." << endl;
    IOaccess_open(); // Baue die Verbindung zur Simulation auf
#endif

    // Zugriffsrechte fuer den Zugriff auf die HW holen
    if (-1 == ThreadCtl(_NTO_TCTL_IO, 0)) {
        perror("ThreadCtl access failed\n");
        return -1;
    }

    // Initialisierung der Digitalen IO Karte
    out8(DIO_BASE + DIO_OFFS_CTRL, 0x8A);

    // Set all to zero on port A
    out8(DIO_BASE + DIO_OFFS_A, 0x00);

    thread::MyThread testThread;
    testThread.start(NULL);

    string str("");
    do {
        cout << "Enter 'q' to exit." << endl;
        cin >> str;
    } while (str != "q");

    testThread.stop();
    testThread.join();
#ifdef SIMULATION
    IOaccess_close(); // Schlieﬂe die Verbindung zur Simulation
#endif
}
