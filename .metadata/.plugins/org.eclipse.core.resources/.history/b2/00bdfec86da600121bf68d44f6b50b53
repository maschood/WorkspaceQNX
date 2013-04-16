/*
 * RS232_1.h
 *
 *  Created on: 16.04.2013
 *      Author: maschood
 */

#ifndef RS232_1_H_
#define RS232_1_H_


#include <fcntl.h>
#include <termios.h>
#include <errno.h>

#include "HAWThread.h"
#include "Mutex.h"

//#define DEBUG_RS232
#define DEV_SER1 "/dev/ser1"

class RS232_1 {

private:
	int fd;
	char recivebuff;
public:
	RS232_1();
	virtual ~RS232_1();
	int sendMsg(char msg);
	int readMsg(char* rbuf);

};

#endif /* RS232_1_H_ */
