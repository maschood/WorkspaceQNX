/*
 * gate.cpp
 *
 *  Created on: 12.04.2013
 *      Author: Erik Matthiessen
 */

#include "HAL.h"
#include "Addresses.h"
#include "HWaccess.h"
#include <stdint.h>

// WEICHE -----------------------------------------
        /*
         * Diese Methode �ffnet die Weiche.
         * Wen sie bereits offen ist bleibt sie offen.
         */
        int HAL::bar_open(){
        	int resu = -1;
            uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
            resu = 0;
            out8(DIO_BASE + DIO_OFFS_A, val | BIT_4);
            return resu;
        }
        /*
         * Diese Methode schlie�t die Weiche.
         * Wen sie bereits geschlossen ist bleibt sie geschlossen.
         */
        int HAL::bar_close(){
        	int resu = -1;
            uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
            resu = 0;
            out8(DIO_BASE + DIO_OFFS_A, val & ~BIT_4);
            return resu;
        }
