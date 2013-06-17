/**
 * SE2 WiSe 2012
 * RS232 (serial connection) for /dev/ser1
 *
 * Reading on COM-port is implemented as a thread with qnx function readcond.
 * readcond generates cyclic timeouts, therefore after calling the thread's stop()
 * function the main-thread is not blocking within the thread's join() function.
 * Sending messages works without a thread.
 *
 * @file RS232_1.h
 * @author Chris Addo
 *         Jens Eberwein
 *         Tristan Rudat
 *         Martin Slowikowski
 * @date 2012-10-23
 * @version 0.9
 *
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

#define MSG_TEST 	'a'
#define MSG_TIMEOUT	0

class RS232_1: public thread::HAWThread {
private:
	/**
	 * instance for /dev/ser1 (singleton)
	 */
	static RS232_1* instance;

	/**
	 * mutex for securing access to RS232 instance
	 */
	static Mutex* RS232InstanceMutex;

	/**
	 * filedescriptor for /dev/ser1, returned by open() function
	 */
	int fd;

	/**
	 * recv-buffer for the readcond function
	 */
	char recvbuf;

	/**
	 * default private constructor for singleton pattern.
	 * opens and initializes the serial port via the termios
	 * struct.
	 */
	RS232_1();

public:

	/**
	 * Function returns an instance of the RS232_1-class. Class is
	 * using singleton pattern, so only one instance for access to
	 * the serial-port 1 exists.
	 * @return instance for serial1
	 */
	static RS232_1* getInstance();

	/**
	 * standard destructor, deletes instance and mutexes for serial1
	 * and closes the device.
	 */
	virtual ~RS232_1();

	/**
	 * send a message on serial1
	 * @param msg control message, will be defined later
	 * @return number of bytes send, or -1 if sending failed
	 */
	int sendMsg(char msg);

	/**
	 * read a message on serial1
	 * @param rbuf receive buffer, msg will be stored to this buf
	 * @return number of bytes read, or 0 if timeout occured, or -1 if error ocured
	 */
	int readMsg(char* rbuf);

	/**
	 * example implementation of a reading thread, this class is derived from HAWThread.
	 * this function reads from serial1 and also interprets the recved messages
	 * and executes the related commands.
	 */
	virtual void execute(void* arg);

	/**
	 * needs to be implemented, no functionality in here. closing of the
	 * device file is done in the destructor.
	 */
	virtual void shutdown();
};
#endif /* RS232_1_H_ */
