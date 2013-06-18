/*
 * FestoSelection.h
 *
 *  Created on: 12.06.2013
 */

#ifndef FESTOSELECT_H_
#define FESTOSELECT_H_

#ifndef FESTO_NUMBER
#define FESTO_NUMBER 5// hier die Nummer des Bandes aendern.
#endif

#if FESTO_NUMBER == 1

#define TURNAROUND ((height) >= 2400 && (height) <= 2700)  	// Gutes WS, aber falsch herum
#define OTHERSHEIGHT ((height) >= 2800 && (height) <= 2900)	// schlechtes WS (aber wohl kein Schluesselbund)

#elif FESTO_NUMBER == 2

#define TURNAROUND ((height) >= 2600 && (height) <= 2900)  	// Gutes WS, aber falsch herum
#define OTHERSHEIGHT ((height) >= 3000 && (height) <= 3100)	// schlechtes WS (aber wohl kein Schluesselbund)

#elif FESTO_NUMBER == 4

#define TURNAROUND ((height) >= 2450 && (height) <= 2600)  	// Gutes WS, aber falsch herum
#define OTHERSHEIGHT ((height) >= 2700 && (height) <= 2800)	// schlechtes WS (aber wohl kein Schluesselbund)

#elif FESTO_NUMBER == 5

#define TURNAROUND ((height) >= 2450 && (height) <= 2600)  	// Gutes WS, aber falsch herum
#define OTHERSHEIGHT ((height) >= 2750 && (height) <= 2850)	// schlechtes WS (aber wohl kein Schluesselbund)


#elif FESTO_NUMBER == 6

#define TURNAROUND ((height) >= 2450 && (height) <= 2600)  	// Gutes WS, aber falsch herum
#define OTHERSHEIGHT ((height) >= 2750 && (height) <= 2850)	// schlechtes WS (aber wohl kein Schluesselbund)

#elif FESTO_NUMBER == 7

#define TURNAROUND ((height) >= 2550 && (height) <= 2600)  	// Gutes WS, aber falsch herum
#define OTHERSHEIGHT ((height) >= 2750 && (height) <= 2850)	// schlechtes WS (aber wohl kein Schluesselbund)

#elif FESTO_NUMBER == 8

#define TURNAROUND ((height) >= 2500 && (height) <= 2600)  	// Gutes WS, aber falsch herum
#define OTHERSHEIGHT ((height) >= 2750 && (height) <= 2850)	// schlechtes WS (aber wohl kein Schluesselbund)

#elif FESTO_NUMBER == 9

#define TURNAROUND ((height) >= 2400 && (height) <= 2600)
#define OTHERSHEIGHT ((height) >= 3000 && (height) <= 3100)

#else // default-Werte, momentan die von Band 2

#define TURNAROUND ((height) >= 2600 && (height) <= 2800)
#define OTHERSHEIGHT ((height) >= 3000 && (height) <= 3100)


#endif

#endif /* FESTOSELECT_H_ */
