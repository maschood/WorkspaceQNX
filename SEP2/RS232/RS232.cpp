/*
 * RS232.cpp
 *
 *  Created on: 30.04.2013
 *      Author: Autorus Dominatus
 */

#include "RS232.h"

RS232::RS232(int choice) {
	char* path = '';

	if (choice == 1) {
		path = DEV_SER1;
	} else if (choice == 2) {
		path = DEV_SER2;
	}

	if ((fd = open(path, O_RDWR)) < 0) {
		printf("opening devfile i  failed\n", choice);
		exit(EXIT_FAILURE);
	} else {
		printf("opening devfile i SUCCESSED\n", choice);
	}
}

RS232::~RS232() {
	// TODO Auto-generated destructor stub
}

int RS232::readMsg(char* rbuf) {
	int rc = readcond(fd, rbuf, sizeof(rbuf), 1, 0, 10);

	if (rc <= 0) {
		if (errno == EAGAIN || rc == 0) {
			printf("Debug RS232: Timeout \n");
			return 0;
		} else {
			printf("recieving from devfile i failed\n", choice);
			return -1;
		}
	}
	return rc;
}

int RS232::sendMsg(char msg) {
	int rc = write(fd, &msg, sizeof(msg));

	if (rc < 0) {
		printf("writing on devfile i failed\n", choice);
		return -1;
	}
	return rc;
}
