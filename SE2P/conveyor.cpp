/*
 * conveyor.cpp
 *
 *  Created on: 12.04.2013
 *      Author: Erik Matthiessen
 */

#include "HAL.h"
#include "Addresses.h"
#include "HWaccess.h"
#include <stdint.h>

       // Flieﬂband -----------------------------------------------
        /*
         *  Diese Methode l‰sst das flieﬂband nach rechts laufen
         */
        int HAL::conveyor_move_right(){
        	int resu = -1;
            uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
            val = val | BIT_0;
            resu = 0;
            out8(DIO_BASE + DIO_OFFS_A, val);
            return resu;
        }
        /*
         *  Diese Methode l‰sst das flieﬂband nach links laufen
         */
        int HAL::conveyor_move_left(){
        	int resu = -1;
            uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
            val = val | BIT_1;
            resu = 0;
            out8(DIO_BASE + DIO_OFFS_A, val);
            return resu;
        }
        /*
         * Diese MEthode stopt das flieﬂband
         */
        int HAL::conveyor_stop(){
        	int resu = -1;
            uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
            val = val & ~BIT_0;
            val = val & ~BIT_1;
            resu = 0;
            out8(DIO_BASE + DIO_OFFS_A, val);
            return resu;
        }
