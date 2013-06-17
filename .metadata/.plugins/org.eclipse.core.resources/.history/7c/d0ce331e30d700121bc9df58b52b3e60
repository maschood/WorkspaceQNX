/**
 * SE2 WiSe 2012
 * pThread Mutex
 *
 * Mutual exclusion refers to the problem of ensuring that no two processes
 * or threads can be in their critical section at the same time.
 * 
 * @file Mutex.cpp
 * @author Chris Addo
 *         Jens Eberwein
 *         Tristan Rudat
 *         Martin Slowikowski
 * @date 2012-10-18
 * @version 0.1
 * 
 */

#include "Mutex.h"
 
Mutex::Mutex() 
{
	if(pthread_mutex_init(&mutex, NULL) != 0)
	{
		perror("mutex failed to init\n");
		exit(EXIT_FAILURE);
	}
}

Mutex::~Mutex() 
{
	if(pthread_mutex_destroy(&mutex) == -1)
	{
		perror("mutex failed to destroy\n");
		exit(EXIT_FAILURE);
	}
}

void Mutex::lock()
{
    if(pthread_mutex_lock(&mutex) == -1)
    {
		perror("mutex failed to lock\n");
		exit(EXIT_FAILURE);
    }
}

void Mutex::unlock()
{
	if(pthread_mutex_unlock(&mutex) == -1)
	{
		perror("mutex failed to unlock\n");
		exit(EXIT_FAILURE);
	}
}
