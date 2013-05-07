/*
 * RS232.h
 *
 *  Created on: 30.04.2013
 *      Author: Autorus Dominatus
 */

#ifndef RS232_H_
#define RS232_H_


#include <fcntl.h>
#include <termios.h>
#include <errno.h>

#include "HAWThread.h"
#include "Mutex.h"

//#define DEBUG_RS232
#define DEV_SER1 "/dev/ser1"
#define DEV_SER2 "/dev/ser2"

class RS232 {

private:
	int fd;
	char recivebuff;
public:
	RS232(char* path);
	virtual ~RS232();
	int sendMsg(char msg);
	int readMsg(char* rbuf);

};

#endif /* RS232_H_ */

