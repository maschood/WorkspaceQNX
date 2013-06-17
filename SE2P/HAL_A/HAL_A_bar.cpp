/*
 * HAL_A_bar.cpp
 *
 * @author Erik Matthiessen
 *         Denis Rycka
 *         Nilüfer Güngör
 *         Maschhood Ahmad
 */

#include "HAL_A.h"

void HAL_A::gate(bool isOpen) {
	uint8_t val = in8(PORT_A);

	halMutex->lock();

	if (isOpen) {
		out8(PORT_A, val | GATE);
	} else {
		out8(PORT_A, val & ~(GATE));
	}

	halMutex->unlock();
}

