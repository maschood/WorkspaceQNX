/*
 * RS232_2.h
 *
 *  Created on: 16.04.2013
 *      Author: maschood
 */

#ifndef RS232_2_H_
#define RS232_2_H_

#include <fcntl.h>
#include <termios.h>
#include <errno.h>

#include "HAWThread.h"
#include "Mutex.h"

//#define DEBUG_RS232
#define DEV_SER2 "/dev/ser2"

class RS232_2 {

private:
	int fd;
	char recivebuff;
public:
	RS232_2();
	virtual ~RS232_2();
	int sendMsg(char msg);
	int readMsg(char* rbuf);

};

#endif /* RS232_2_H_ */
