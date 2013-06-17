/*
 * HAL_A_conveyor.cpp
 *
 * @author Erik Matthiessen
 *         Denis Rycka
 *         Nilüfer Güngör
 *         Maschhood Ahmad
 */

#include "HAL_A.h"

void HAL_A::engine_right(bool isSlow) {
	uint8_t val = in8(PORT_A);

	halMutex->lock();

	if (isSlow) {
		out8(PORT_A, val | ENGINE_SLOW_RIGHT);
	} else {
		out8(PORT_A, (val | ENGINE_RIGHT) & ~(ENGINE_SLOW));;
	}

	halMutex->unlock();
}

void HAL_A::revoke_engine_right() {
	uint8_t val = in8(PORT_A);
	halMutex->lock();

	out8(PORT_A, val & ~(ENGINE_SLOW_RIGHT));

	halMutex->unlock();
}

void HAL_A::revoke_engineLeft() {
	uint8_t val = in8(PORT_A);
	halMutex->lock();
	out8(PORT_A, val & ~(ENGINE_SLOW_LEFT));
	halMutex->unlock();
}



void HAL_A::engine_left(bool isSlow) {
	uint8_t val = in8(PORT_A);

	halMutex->lock();

	if (isSlow) {
		out8(PORT_A, val | ENGINE_SLOW_LEFT);
	} else {
		out8(PORT_A, (val | ENGINE_LEFT) & ~(ENGINE_SLOW));

	}

	halMutex->unlock();
}

void HAL_A::engine_stop() {
	halMutex->lock();
	if (!fullStop) {
		uint8_t val = in8(PORT_A);

		out8(PORT_A, val | ENGINE_STOP);
	}
	halMutex->unlock();
}

bool HAL_A::is_engine_stopped() {
	halMutex->lock();
	uint8_t val = in8(PORT_A);
	halMutex->unlock();
	val = (val >> 3) & 1;
	return val;
}

void HAL_A::engine_unstop() {
	halMutex->lock();
	if (!fullStop) {
		uint8_t val = in8(PORT_A);
		out8(PORT_A, val & ~(ENGINE_STOP));
	}
	halMutex->unlock();
}

void HAL_A::engine_full_stop() {
	halMutex->lock();
	fullStop = true;
	uint8_t val = in8(PORT_A);

	out8(PORT_A, val | ENGINE_STOP);
	halMutex->unlock();
}

void HAL_A::engine_full_unstop() {
	halMutex->lock();
	fullStop = false;
	uint8_t val = in8(PORT_A);

	out8(PORT_A, val & ~(ENGINE_STOP));
	halMutex->unlock();
}

