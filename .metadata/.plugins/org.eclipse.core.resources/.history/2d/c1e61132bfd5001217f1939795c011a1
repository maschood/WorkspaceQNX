/**
 * SE2 WiSe 2012
 * RS232 (serial connection)
 *
 * Some bla bla bla for this file
 *
 * @file RS232.h
 * @author Chris Addo
 *         Jens Eberwein
 *         Tristan Rudat
 *         Martin Slowikowski
 * @date 2012-10-18
 * @version 0.1
 *
 */

#ifndef RS232_2_H_
#define RS232_2_H_

#include <fcntl.h>
#include <termios.h>
#include <errno.h>

#include "HAWThread.h"
#include "Mutex.h"

#define DEBUG_RS232
#define DEV_SER2 "/dev/ser2"

#define MSG_TEST 	'a'
#define MSG_TIMEOUT	0

class RS232_2: public thread::HAWThread {
private:
	static RS232_2* instance;
	static Mutex* RS232InstanceMutex;
	int fd;
	char recvbuf;

	RS232_2();

public:

	static RS232_2* getInstance();

	virtual ~RS232_2();
	int sendMsg(char msg);
	int readMsg(char* rbuf);
	virtual void execute(void* arg);
	virtual void shutdown();
};
#endif /* RS232_2_H_ */
