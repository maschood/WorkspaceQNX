/*
 * RS232_2.cpp
 *
 *  Created on: 16.04.2013
 *      Author: maschood
 */

#include "RS232_2.h"

RS232_2::RS232_2() {
	if((fd = open(DEV_SER2, O_RDWR)) < 0)
	{
		printf("opening devfile2 failed\n");
		exit(EXIT_FAILURE);
	} else {
		printf("opening devfile2 SUCCESSED\n");
	}
}


RS232_2::~RS232_2() {
	// TODO Auto-generated destructor stub
}

int RS232_2::sendMsg(char msg) {
	int rc = write(fd, &msg, sizeof(msg));

	if (rc < 0) {
		printf("writing on devfile1 failed\n");
		return -1;
	}
	return rc;
}

int RS232_2::readMsg(char* rbuf) {
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

