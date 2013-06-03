/*
 * Seriell.h
 *
 *  Created on: 17.04.2013
 *      Author: Carlos
 */

#ifndef SERIELL_H_
#define SERIELL_H_

#include <fcntl.h>
#include <termios.h>
#include <errno.h>
#include <iostream.h>

#define SCHNITTSTELLE1 "/dev/ser1"
#define SCHNITTSTELLE2 "/dev/ser2"

class Seriell {
public:
	Seriell();
	virtual ~Seriell();
	int fd;
	int sendMsg(char msg);
	int readMsg(char* buff);
};

#endif /* SERIELL_H_ */
