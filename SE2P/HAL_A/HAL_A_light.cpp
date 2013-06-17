/*
 * HAL_A_light.cpp
 *
 * @author Erik Matthiessen
 *         Denis Rycka
 *         Nilüfer Güngör
 *         Maschhood Ahmad
 */

#include "HAL_A.h"


void HAL_A::lamp_red(bool isOn) {
	uint8_t val = in8(PORT_A);

	halMutex->lock();

	if (isOn) {
		out8(PORT_A, val | LIGHT_RED);
	} else {
		out8(PORT_A, val & ~(LIGHT_RED));
	}

	halMutex->unlock();
}

void HAL_A::lamp_yellow(bool isOn) {
	uint8_t val = in8(PORT_A);

	halMutex->lock();

	if (isOn) {
		out8(PORT_A, val | LIGHT_YELLOW);
	} else {
		out8(PORT_A, val & ~(LIGHT_YELLOW));
	}

	halMutex->unlock();
}

void HAL_A::lamp_green(bool isOn) {
	uint8_t val = in8(PORT_A);

	halMutex->lock();

	if (isOn) {
		out8(PORT_A, val | LIGHT_GREEN);
	} else {
		out8(PORT_A, val & ~(LIGHT_GREEN));
	}

	halMutex->unlock();
}

void HAL_A::lights_off() {
	uint8_t val = in8(PORT_A);

	halMutex->lock();

	out8(PORT_A, val & ~(LIGHT_GREEN + LIGHT_YELLOW + LIGHT_RED));

	halMutex->unlock();
}
