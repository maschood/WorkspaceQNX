/*
 * Kleines Beispielprogramm fuer den Zugriff auf die Festo Simulationsumgebung
 * der Transferstrecke und die Transferstrecke selbst.
 *
 * Voraussetzungen:
 *      - Die Bibliotheken und Header Files mussen in in der Entwicklungs-
 *        umgebung eingepfegt sein.
 *
 *       - Die Bibliothek ioaccess muss im Projekt eingebunden sein via
 *         Project->Properties : QNX C/C++ Project : Linker : Extra libraries
 */

#include <cstdlib>
#include <iostream>
#include<unistd.h>
#include <errno.h>

// Die Header Datei HWaccess.h steuert den Zugriff auf die HW bzw. Simulation
// Sie muss in jeder Datei stehen, die auf die HW zugreift
#include "HWaccess.h"

// Port der Digitalen IO Karte (s. Datenblatt)

#define D_IOBASE 0x300 								// Anfangsadresse Ports
#define DIGITAL_CARD_CONTROL (D_IOBASE + 0x03) 		// Adresse von Card Control
#define DIGITAL_CARD_CROUP0_PORTA (D_IOBASE + 0x00) // Adresse von Port A

using namespace std;

int main(int argc, char *argv[]) {
#ifdef SIMULATION
	cout << "Simulation aktiv" << endl;
	cout << "Zum Aufbau der Verbindung muss Die Festo Simulation schon laufen." << endl;
	IOaccess_open(); // Baue die Verbindung zur Simulation auf
#endif

	// Simpler Test des HW Zugriffs ohne Klassen, Pattern etc.
	// Reicht nicht fuer den ersten Meilenstein aus

	// Zugriffsrechte fuer den Zugriff auf die HW holen
	if (-1 == ThreadCtl(_NTO_TCTL_IO, 0)) {
		perror("ThreadCtl access failed\n");
		return -1;
	}
	// Initialisierung der Digitalen IO Karte
	out8(DIGITAL_CARD_CONTROL, 0x82);

	// Treibe die Ampel
	for (int count = 0; count < 20; count ++) {
		cout << "rot" << endl;
		out8(D_IOBASE, 0x80);//rot
		sleep(1);

		cout << "gelb" << endl;
		out8(D_IOBASE, 0x40);//gelb
		sleep(1);

		cout << "gruen" << endl;
		out8(D_IOBASE, 0x20);//gruen
		sleep(1);
	}

	cout << "Test beendet" << endl;
#ifdef SIMULATION
	IOaccess_close(); // Schließe die Verbindung zur Simulation
#endif
}
