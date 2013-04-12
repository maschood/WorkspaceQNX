/*
 * HAL_law.cpp
 *
 *  Created on: 12.04.2013
 *      Author: Erik Matthiessen
 */

HAL::HAL() {
    // Initialisierung der Digitalen IO Karte
    out8(DIO_BASE + DIO_OFFS_CTRL, 0x8A);
    out8(DIO_BASE + DIO_OFFS_A, 0x00);
    out8(DIO_BASE + DIO_OFFS_C, 0x00);
}

HAL::~HAL() {
    delete instance;
    instance = NULL;
}

HAL HAL::get_instance(){

    // Zugriffsrechte fuer den Zugriff auf die HW holen
    if (-1 == ThreadCtl(_NTO_TCTL_IO, 0)) {
        perror("ThreadCtl access failed\n");
        return NULL;
    }

    // nur zur sicherheit
//    if (instance == NULL) {
//        instance = new HALintro();
//    }

	return HAL;
}
