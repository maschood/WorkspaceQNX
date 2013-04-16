/*
 * HAL_law.cpp
 *
 *  Created on: 12.04.2013
 *      Author: Erik Matthiessen
 */

#include "HAL.h"

HAL* HAL::instance = NULL;
Mutex* HAL::halMutex = new Mutex();

HAL::HAL() {

	// Initialisierung der Digitalen IO Karte
	out8(DIO_BASE + DIO_OFFS_CTRL, 0x8A);
	out8(DIO_BASE + DIO_OFFS_A, 0x00);
	out8(DIO_BASE + DIO_OFFS_C, 0x00);
}

HAL::~HAL() {
	delete instance;
	instance = NULL;
	out8(DIO_BASE + DIO_OFFS_CTRL, 0x8A);
	out8(DIO_BASE + DIO_OFFS_A, 0x00);
	out8(DIO_BASE + DIO_OFFS_C, 0x00);
}

HAL* HAL::get_instance() {
	// Zugriffsrechte fuer den Zugriff auf die HW holen
	if (-1 == ThreadCtl(_NTO_TCTL_IO, 0)) {
		perror("ThreadCtl access failed\n");
		return NULL;
	}

	if (instance == NULL) {
		instance = new HAL();
	}

	return instance;
}

// LAMPEN ------------------------------------------------
/*
 * Diese Methoden schalten die entsprechenden Lampen ein.
 * Wenn die Lampe bereits an ist bleibt die an.
 */

int HAL::lamp_red_on() {
	int resu = -1;
	uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
	halMutex->lock();
	val = val | BIT_7;
	resu = 0;
	out8(DIO_BASE + DIO_OFFS_A, val);
	halMutex->unlock();
	return resu;
}
int HAL::lamp_yellow_on() {
	int resu = -1;
	uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
	halMutex->lock();
	val = val | BIT_6;
	resu = 0;
	out8(DIO_BASE + DIO_OFFS_A, val);
	halMutex->unlock();
	return resu;
}
int HAL::lamp_green_on() {
	int resu = -1;
	uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
	halMutex->lock();
	val = val | BIT_5;
	resu = 0;
	out8(DIO_BASE + DIO_OFFS_A, val);
	halMutex->unlock();
	return resu;
}

/*
 * Diese Methoden schalten die entsprechenden Lampen aus.
 * Wenn die Lampe bereits an ist bleibt die an.
 */
int HAL::lamp_red_off() {
	int resu = -1;
	uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
	halMutex->lock();
	val = val & ~BIT_7;
	resu = 0;
	out8(DIO_BASE + DIO_OFFS_A, val);
	halMutex->unlock();
	return resu;
}
int HAL::lamp_yellow_off() {
	int resu = -1;
	uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
	halMutex->lock();
	val = val & ~BIT_6;
	resu = 0;
	out8(DIO_BASE + DIO_OFFS_A, val);
	halMutex->unlock();
	return resu;
}
int HAL::lamp_green_off() {
	int resu = -1;
	uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
	halMutex->lock();
	val = val & ~BIT_5;
	resu = 0;
	out8(DIO_BASE + DIO_OFFS_A, val);
	halMutex->unlock();
	return resu;
}

// WEICHE -----------------------------------------
/*
 * Diese Methode öffnet die Weiche.
 * Wen sie bereits offen ist bleibt sie offen.
 */
int HAL::bar_open() {
	int resu = -1;
	uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
	resu = 0;
	halMutex->lock();
	out8(DIO_BASE + DIO_OFFS_A, val | BIT_4);
	halMutex->unlock();
	return resu;
}
/*
 * Diese Methode schließt die Weiche.
 * Wen sie bereits geschlossen ist bleibt sie geschlossen.
 */
int HAL::bar_close() {
	int resu = -1;
	uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
	resu = 0;
	halMutex->lock();
	out8(DIO_BASE + DIO_OFFS_A, val & ~BIT_4);
	halMutex->unlock();
	return resu;
}

// Fließband -----------------------------------------------
/*
 *  Diese Methode lässt das fließband nach rechts laufen
 */
int HAL::conveyor_move_right() {
	int resu = -1;
	uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
	halMutex->lock();
	val = val | BIT_0;
	resu = 0;
	out8(DIO_BASE + DIO_OFFS_A, val);
	halMutex->unlock();
	return resu;
}
/*
 *  Diese Methode lässt das fließband nach links laufen
 */
int HAL::conveyor_move_left() {
	int resu = -1;
	uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
	halMutex->lock();
	val = val | BIT_1;
	resu = 0;
	out8(DIO_BASE + DIO_OFFS_A, val);
	halMutex->unlock();
	return resu;
}
/*
 * Diese MEthode stopt das fließband
 */
int HAL::conveyor_stop() {
	int resu = -1;
	uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
	halMutex->lock();
	val = val & ~BIT_0;
	val = val & ~BIT_1;
	resu = 0;
	out8(DIO_BASE + DIO_OFFS_A, val);
	halMutex->unlock();
	return resu;
}
