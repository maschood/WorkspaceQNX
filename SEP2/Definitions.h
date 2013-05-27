/*
 * Definitions.h
 *
 *  Created on: 23.04.2013
 *      Author: ich
 */


#include <sys/neutrino.h>
#include <iostream>

#define CHECK_C (BIT_5+BIT_7)
#define MANOWAR 1
#define CHECK_B (BIT_0+BIT_1+BIT_3+BIT_6+BIT_7)
#define CHECK_GENERAL_SWITCH (BIT_0&BIT_1&BIT_2&BIT_3)

#define NORMAL 1
#define TEST 2
#define REGRESSION 3

extern int mode;
extern int station;
