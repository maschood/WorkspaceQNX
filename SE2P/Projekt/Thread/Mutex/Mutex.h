/*
 * Mutex.h
 *
 *  Created on: 12.04.2013
 *      Author: abc676
 */

#ifndef MUTEX_H_
#define MUTEX_H_

class Mutex {
public:
	Mutex();
	virtual ~Mutex();

	void lock();

	void unlock();

private:
	pthread_mutex_t myMutex;
};

#endif /* MUTEX_H_ */
