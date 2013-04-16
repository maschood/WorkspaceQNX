/*
 * HAL.h
 *
 *  Created on: 10.04.2013
 *      Author: Erik Matthiessen
 */
#include <stdint.h>
#include <iostream>
#include <unistd.h>

#include "Addresses.h"
#include "HWaccess.h"
#include "Mutex.h"

#ifndef HAL_H_
#define HAL_H_


class HAL
{
	  private:
        HAL();      // Default Konstruktor
        /**
         * Instance for using Singleton
         */
        static HAL* instance;
        /**
         * Mutex for Threadsafe Hal use
         */
        static Mutex* halMutex;

    public:
        static HAL* get_instance();		// Gibt die Referenz auf die HAL zurück

        // bLampensteuerung
        int lamp_red_on();
        int lamp_yellow_on();
        int lamp_green_on();
        int lamp_red_off();
        int lamp_yellow_off();
        int lamp_green_off();

        // Schrankensteuerung
        int bar_open();
        int bar_close();

        // Fließbandsteuerung
        int conveyor_move_right();
        int conveyor_move_left();
        int conveyor_stop();
        ~HAL();     // Destruktor
};

#endif /* HAL_H_ */
