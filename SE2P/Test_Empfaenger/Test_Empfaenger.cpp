/*
 * Test_Empfaenger.cpp
 *
 *  Created on: 29.04.2013
 *      Author: ich
 */

#include <stdio.h>

#include "Test_Empfaenger/Test_Empfaenger.h"
#include <sys/neutrino.h>

void Test_Empfaenger::run_test(){

	char i = 0;
	char* ip = &i;

	char r = 3;
	char* rp = &r;

	coid_channel_Test = ConnectAttach(0,0,chid_channel_Test, _NTO_SIDE_CHANNEL,0);

	int rcvid = MsgReceive(chid_channel_Test, rp, 1, NULL);

	while(i == 0){

	}

	printf("Buffer i hat sich ge�ndert jajajajajajajaaj\n");

}
