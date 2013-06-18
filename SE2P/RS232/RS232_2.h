/**
 * @file RS232.h
* @author Erik Matthiessen
 *         Denis Rycka
 *         Nilüfer Güngör
 *         Maschhood Ahmad
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
