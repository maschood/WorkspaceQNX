/*
 * HAL.cpp
 *
 *  Created on: 10.04.2013
 *      Author: Erik Matthiessen
 */

#include "HAL.h"

		/*
		 * Gibt die Referenz auf die statische HAL zur¸ck (singketon)
		 */
        HAL get_instance(){
        	return hal;
        }

        // LAMPEN ------------------------------------------------
        /*
         * Diese Methoden schalten die entsprechenden Lampen ein.
         * Wenn die Lampe bereits an ist bleibt die an.
         */
        int lamp_red_on(){
        	int resu = -1;
            uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
            val || BIT_7;
            resu = 0;
            out8(DIO_BASE + DIO_OFFS_A, val);
            return resu;
        }
        int lamp_yellow_on(){
        	int resu = -1;
            uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
            val || BIT_6;
            resu = 0;
            out8(DIO_BASE + DIO_OFFS_A, val);
            return resu;
        }
        int lamp_green_on(){
        	int resu = -1;
            uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
            val || BIT_5;
            resu = 0;
            out8(DIO_BASE + DIO_OFFS_A, val);
            return resu;
        }
        /*
         * Diese Methoden schalten die entsprechenden Lampen aus.
         * Wenn die Lampe bereits an ist bleibt die an.
         */
        int lamp_red_off(){
        	int resu = -1;
            uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
            val && (!BIT_7);
            resu = 0;
            out8(DIO_BASE + DIO_OFFS_A, val);
            return resu;
        }
        int lamp_yellow_off(){
        	int resu = -1;
            uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
            val && (!BIT_6);
            resu = 0;
            out8(DIO_BASE + DIO_OFFS_A, val);
            return resu;
        }
        int lamp_green_off(){
        	int resu = -1;
            uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
            val && (!BIT_5);
            resu = 0;
            out8(DIO_BASE + DIO_OFFS_A, val);
            return resu;
        }
        // WEICHE -----------------------------------------
        /*
         * Diese Methode ˆffnet die Weiche.
         * Wen sie bereits offen ist bleibt sie offen.
         */
        int bar_open(){
        	int resu = -1;
            uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
            val || BIT_4;
            resu = 0;
            out8(DIO_BASE + DIO_OFFS_A, val);
            return resu;
        }
        /*
         * Diese Methode schlieﬂt die Weiche.
         * Wen sie bereits geschlossen ist bleibt sie geschlossen.
         */
        int bar_close(){
        	int resu = -1;
            uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
            val && (!BIT_4);
            resu = 0;
            out8(DIO_BASE + DIO_OFFS_A, val);
            return resu;
        }

        // Flieﬂband -----------------------------------------------
        /*
         *  Diese Methode l‰sst das flieﬂband nach rechts laufen
         */
        int conveyor_move_right(){
        	int resu = -1;
            uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
            val || BIT_0;
            resu = 0;
            out8(DIO_BASE + DIO_OFFS_A, val);
            return resu;
        }
        /*
         *  Diese Methode l‰sst das flieﬂband nach links laufen
         */
        int conveyor_move_left(){
        	int resu = -1;
            uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
            val || BIT_1;
            resu = 0;
            out8(DIO_BASE + DIO_OFFS_A, val);
            return resu;
        }
        /*
         * Diese MEthode stopt das flieﬂband
         */
        int conveyor_stop(){
        	int resu = -1;
            uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
            val && (!BIT_0);
            val && (!BIT_1);
            resu = 0;
            out8(DIO_BASE + DIO_OFFS_A, val);
            return resu;
        }
