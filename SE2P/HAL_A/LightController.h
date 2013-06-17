/**
 * @file LightController.h
  Created on: 09.06.2013
 * @author Erik Matthiessen
 *         Denis Rycka
 *         Nilüfer Güngör
 *         Maschhood Ahmad
 */


#ifndef LIGHTCONTROLLER_H_
#define LIGHTCONTROLLER_H_

#define DEBUG_LIGHTCONTROLLER

#include "HAL_A.h"
#include "HAWThread.h"

class LightController : public thread::HAWThread {
public:
	/**
	* Standard destructor
	*/
	virtual ~LightController();

	/**
	* Executes the chosen light function, initially starts with
	* all lighs off. function to start with configured in constructor
	*/
	virtual void execute(void* arg);

	/**
	* Empty shutdown() function
	*/
	virtual void shutdown();

	/**
	* Returns instance to work with LightController (Singleton)
	* @return LightController instance
	*/
	static LightController* getInstance();


	/**
	* Signals an upcoming error, not yet receipted.
	* Red light blinking fast with 1Hz
	*/
	void upcomingNotReceipted();

	/**
	 * Signals a timer MIN error (puck spawned)
	 */
	void upcomingNotReceiptedTimerMin();

	/**
	 * Signals a timer MAX error (puck despawned)
	 */
	void upcomingNotReceiptedTimerMax();

	/**
	* Signals an upcoming and receipted error.
	* Red light on
	*/
	void upcomingReceipted();

	/**
	* Signals an error gone but not receipted.
	* Red light blinking slow with 0,5Hz
	*/
	void goneUnreceipted();

	/**
	* Signals normal operating system
	* Green light on
	*/
	void operatingNormal();

	/**
	* Signals a workpiece with opening at top at the end
	* of conveyor 1.
	* Yellow light blinking
	*/
	void manualTurnover();

	/**
	 * If band conveyor was paused green light is flickering fast
	 */
	void bandHalted();

	/**
	 * eStop error occured
	 */
	void eStop();

	/**
	 * Switches the led on the reset button [on if true, else off]
	 *
	 * @param [true if on, false if off]
	 */
	void ledReset(bool isOn);

	/**
	 * Switches the led on the start button [on if true, else off]
	 *
	 * @param [true if on, false if off]
	 */
	void ledStart(bool isOn);

	/**
	* Switches all lights of and suspends the thread.
	*/
	void lightsOff();

	/**
	 * Pauses execution of the thread by calling hold() from superclass
	 */
	void off();
private:
	/**
	* Private constructor for singleton. Starts and then
	* suspends the thread. Initial function is lightsOff();
	*/
	LightController();

	/**
	* HAL instance to get access to actors.
	*/
	HAL_A* hal_a;

	/**
	* Mutex for creation of the LightController instance
	*/
	static Mutex* lightInstanceMutex;

	/**
	* Instance for using LightController (Singleton)
	*/
	static LightController* instance;

	/**
	* Function-pointer for the execute function. Can be set by
	* the public methods to be executed in the thread.
	*/
	void (LightController::*function)(void);

	/**
	* Blink yellow
	*/
	void blinkYellow();

	/**
	* Blink red fast
	*/
	void blinkRedFast();

	/**
	* Blink red slow
	*/
	void blinkRedSlow();

	/**
	 * Blink red slow, with double blink
	 */
	void blinkRedSlowDouble();

	/**
	 * Blink red slow, with double blink
	 */
	void blinkRedSlowTripple();

	/**
	 * Blink green fast
	 */
	void blinkGreenFast();

	/**
	 * Blink all fast
	 */
	void blinkAllFast();
};

#endif /* LIGHTCONTROLLER_H_ */
