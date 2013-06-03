/**
 * SE2 WiSe 2012
 * HAL (hardware abstraction layer)
 *
 * This class implements all basic actor functionalities of the
 * festo system. All functions are implemented threadsafe by using
 * mutexes.
 * 
 * @file HAL.h
 * @author Chris Addo
 *         Jens Eberwein
 *         Tristan Rudat
 *         Martin Slowikowski
 * @date 2012-10-18
 * @version 1.0
 * 
 */

#ifndef HALINTRO_H_
#define HALINTRO_H_

#include <stdint.h>
#include <iostream>
#include <unistd.h>

#include "address.h"
#include "HWaccess.h"
#include "Mutex.h"

//#define DEBUG_HAL

class ActorHAL {
private:
	/**
	 * Instance for using the hal (Singleton)
	 */
	static ActorHAL* instance;

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
	ActorHAL();
public:
	/**
	 * Standard destructor, deletes used mutexes and the HAL-instance
	 */
	~ActorHAL();

	/**
	 * Function returns an instance of the Hal-class. Class is
	 * using singleton pattern, so only one instance for access to
	 * the HW exists.
	 * @return instance of the hal
	 */
	static ActorHAL* getInstance();

	// Port A

	/**
	 * Belt conveyor engine moves right with normal speed,
	 * if parameter isSlow is set to true, engine moves slow
	 * @param isSlow [false is fast, true is slow]
	 */
	void engineRight(bool isSlow);

	/**
	 * Deletes the ENGINE_RIGHT and ENGINE_RIGHT_SLOW bit, band conveyor stops
	 */
	void revokeEngineRight();

	/**
	 * Belt conveyor engine moves left with normal speed,
	 * if parameter isSlow is set to true, engine moves slow
	 * @param isSlow [false is fast, true is slow]
	 */
	void engineLeft(bool isSlow);

	/**
	 * Stops belt conveyor engine. Old direction and speed bits
	 * are still set.
	 */
	void engineStop();

	/**
	 * Resets stop bit, belt conveyor engine moves with old direction
	 * and speed.
	 */
	void engineUnstop();

	/**
	 * Stops belt conveyor engine. Old direction and speed bits
	 * are still set. Sets bool fullStop
	 */
	void engineFullStop();

	/**
	 * Resets stop bit, belt conveyor engine moves with old direction
	 * and speed. Resets bool fullStop
	 */
	void engineFullUnstop();

	/**
	 *
	 */
	bool isEngineStopped();

	/**
	 * Opens or closes the gate.
	 * @param isopen [true for open, false for close]
	 */
	void gate(bool isOpen);

	/**
	 * Switches red light of the conveyor traffic light on or off
	 * @param isOn [true for on, false for off]
	 */
	void lightRed(bool isOn);

	/**
	 * Switches yellow light of the conveyor traffic light on or off
	 * @param isOn [true for on, false for off]
	 */
	void lightYellow(bool isOn);

	/**
	 * Switches green light of the conveyor traffic light on or off
	 * @param isOn [true for on, false for off]
	 */
	void lightGreen(bool isOn);

	/**
	 * Switches all lights off.
	 */
	void lightsOff();

	// Port C

	/**
	 * Switches led of the start-button on or off
	 * @param isOn [true for on, false for off]
	 */
	void ledStart(bool isOn);

	/**
	 * Switches led of the reset-button on or off
	 * @param isOn [true for on, false for off]
	 */
	void ledReset(bool isOn);

	/**
	 * Switches Q1-led on or off
	 * @param isOn [true for on, false for off]
	 */
	void ledQ1(bool isOn);

	/**
	 * Switches Q2-led on or off
	 * @param isOn [true for on, false for off]
	 */
	void ledQ2(bool isOn);
};

#endif /* HALINTRO_H_ */
