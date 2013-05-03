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


class HAL_A
{
	    public:
        static HAL_A* get_instance();		// Gibt die Referenz auf die HAL zurück

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

        //LED
        int led_start_button_on();
        int led_reset_button_on();
        int led_start_button_off();
        int led_reset_button_off();

        int general_switch_off();

        ~HAL_A();     // Destruktor

	  private:
        HAL_A();      // Default Konstruktor
        /**
         * Instance for using Singleton
         */
        static HAL_A* instance;
        /**
         * Mutex for Threadsafe Hal use
         */
        static Mutex* halMutex;


};

#endif /* HAL_H_ */
