/*
 * HAL_A_led.cpp
 *
 * @author Erik Matthiessen
 *         Denis Rycka
 *         Nil�fer G�ng�r
 *         Maschhood Ahmad
 */

#include "HAL_A.h"

void HAL_A::led_reset(bool isOn) {
	uint8_t val = in8(PORT_C);

	halMutex->lock();

	if (isOn) {
		out8(PORT_C, val | LED_RESET);
	} else {
		out8(PORT_C, val & ~(LED_RESET));
	}

	halMutex->unlock();
}
