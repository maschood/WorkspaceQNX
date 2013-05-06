/*
 * RS232_1.cpp
 *
 *  Created on: 16.04.2013
 *      Author: maschood
 */

#include "RS232_1.h"

RS232_1::RS232_1() {

	if((fd = open(DEV_SER1, O_RDWR)) < 0)
	{
		printf("opening devfile1 failed\n");
		exit(EXIT_FAILURE);
	} else {
		printf("opening devfile1 SUCCESSED\n");
	}
}

RS232_1::~RS232_1() {
	// TODO Auto-generated destructor stub
}

int RS232_1::sendMsg(char msg) {
	int rc = write(fd, &msg, sizeof(msg));

	if (rc < 0) {
		printf("writing on devfile1 failed\n");
		return -1;
	}
	return rc;
}

int RS232_1::readMsg(char* rbuf) {
	int rc = readcond(fd, rbuf, sizeof(rbuf), 1, 0, 10);

	if(rc <= 0) {
		if(errno == EAGAIN || rc == 0){
			printf("Debug RS232_1: Timeout \n");
			return 0;
		} else {
			printf("recieving from devfile1 failed\n");
			return -1;
		}
	}
	return rc;
}
