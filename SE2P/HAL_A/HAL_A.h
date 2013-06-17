/**
 * @file HAL.h
 * @author Erik Matthiessen
 *         Denis Rycka
 *         Nil�fer G�ng�r
 *         Maschhood Ahmad
 * 
 */

#ifndef HAL_A_H_
#define HAL_A_H_

#include <stdint.h>
#include <iostream>
#include <unistd.h>

#include "Addresses.h"
#include "HWaccess.h"
#include "Mutex.h"

class HAL_A {
private:
	/**
	 * Instance for using the hal (Singleton)
	 */
	static HAL_A* instance;

	/**
	 * Mutex for securing access to hal instance
	 */
	static Mutex* halInstanceMutex;

	/**
	 * Mutex for threadsafe hal usage
	 */
	static Mutex* halMutex;

	/**
	 * Bool to control that no other puck can start convayor if not allowd
	 */
	bool fullStop;

	/**
	 * Private standard constructor for the singleton pattern
	 */
	HAL_A();
public:
	/**
	 * Standard destructor, deletes used mutexes and the HAL-instance
	 */
	~HAL_A();

	/**
	 * Function returns an instance of the Hal-class. Class is
	 * using singleton pattern, so only one instance for access to
	 * the HW exists.
	 * @return instance of the hal
	 */
	static HAL_A* getInstance();

	// Port A

	// bLampensteuerung
	void lamp_red(bool isOn);
	void lamp_yellow(bool isOn);
	void lamp_green(bool isOn);
	void lights_off();

	// Schrankensteuerung
	void gate(bool isOpen);

    // Flie�bandsteuerung
	void engine_right(bool isSlow);
	void revoke_engine_right();
	void revoke_engineLeft();
	void engine_left(bool isSlow);
	void engine_stop();
	void engine_unstop();
	void engine_full_stop();
	void engine_full_unstop();
	bool is_engine_stopped();

	// Port C
	void led_start(bool isOn);
	void led_reset(bool isOn);
};

#endif /* HAL_A_H_ */
