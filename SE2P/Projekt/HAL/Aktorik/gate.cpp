/*
 * gate.cpp
 *
 *  Created on: 12.04.2013
 *      Author: Erik Matthiessen
 */

#include "HAL.h"

// WEICHE -----------------------------------------
        /*
         * Diese Methode öffnet die Weiche.
         * Wen sie bereits offen ist bleibt sie offen.
         */
        int HAL::bar_open(){
        	int resu = -1;
            uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
            val || BIT_4;
            resu = 0;
            out8(DIO_BASE + DIO_OFFS_A, val);
            return resu;
        }
        /*
         * Diese Methode schließt die Weiche.
         * Wen sie bereits geschlossen ist bleibt sie geschlossen.
         */
        int HAL::bar_close(){
        	int resu = -1;
            uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
            val && (!BIT_4);
            resu = 0;
            out8(DIO_BASE + DIO_OFFS_A, val);
            return resu;
        }
