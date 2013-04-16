/*
 * HAL_Teast.cpp
 *
 *  Created on: 15.04.2013
 *      Author: ich
 */

#include "HAL_Test.h"

/*
 * Die Klasse teste die Funktionalitäten der HAL
 *
 * Wenn alle Test korrekt durchlaufen werden wird eine 0 Zurück gegeben.
 *
 * Ansonnsten kann am Fehlercode der Funktionsfehler erkannt werden.
 * Returncodes:
 * 1 = Fehler Fließband rechtslauf
 * 2 = Fehler Fließband linkslauf
 * 3 = Fehler Fließband stopen
 * 4 = Fehler Weiche auf/zu
 * 5 = Fehler grüne Lampe
 * 6 = Fehler gelbe Lampe
 * 7 = Fehler rote Lampe
 */

int HAL_Test::HAL_Test_run(HAL hal){
	hal = hal;
	int resu = 0;
	uint8_t val = in8(DIO_BASE + DIO_OFFS_A);

	resu = Test_Lamp_Red(val);
	if(resu != 0) return resu;
	resu = Test_Lamp_Yellow(val);
	if(resu != 0) return resu;
	resu = Test_Lamp_Green(val);
	if(resu != 0) return resu;

	resu = Test_Conveyor_Right(val);
	if(resu != 0) return resu;
	resu = Test_Conveyor_Left(val);
	if(resu != 0) return resu;
	resu = Test_Conveyor_Stop(val);
	if(resu != 0) return resu;

	resu = Test_Bar_Open(val);
	if(resu != 0) return resu;
	resu = Test_Bar_Close(val);
	if(resu != 0) return resu;


    out8(DIO_BASE + DIO_OFFS_A, val);
    return resu;
}

HAL_Test::HAL_Test() {
    // Initialisierung der Digitalen IO Karte
    out8(DIO_BASE + DIO_OFFS_CTRL, 0x8A);
    out8(DIO_BASE + DIO_OFFS_A, 0x00);
    out8(DIO_BASE + DIO_OFFS_C, 0x00);
}

HAL_Test::~HAL_Test() {
    delete instance;
    instance = NULL;
}

void HAL_Test::Test_Singleton(){
	HAL* hal = HAL::get_instance();

	cout << "Adresse des Pointers: " << &hal << endl;
	cout << "Inhalt des Pointers: " << hal << endl;

	HAL* hal2 = HAL::get_instance();

	cout << "Adresse des Pointers: " << &hal2 << endl;
	cout << "Inhalt des Pointers: " << hal2 << endl;

}
