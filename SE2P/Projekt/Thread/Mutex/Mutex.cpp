/*
 * Mutex.cpp
 *
 *  Created on: 12.04.2013
 *      Author: abc676
 */

#include "Mutex.h"

Mutex::Mutex() {
	pthread_mutex_init( &myMutex, null);

}

Mutex::~Mutex() {
	pthread_mutex_unlock(&myMutex);
	pthread_mutex_destroy( &myMutex);
}

void Mutex::lock() {
	pthread_mutex_lock(&myMutex);
}

void Mutex::unlock() {
	pthread_mutex_unlock(&myMutex);
}
