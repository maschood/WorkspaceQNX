/**
* SE2 WiSe 2012
* LightController for the traffic lights
*
* Offers functions for different states the festo
* system can have. Running in a Thread. Status of
* the traffic light is manipulated through public
* accessible functions.
*
* @file LightController.h
* @author Chris Addo
* Jens Eberwein
* Tristan Rudat
* Martin Slowikowski
* @date 2012-10-29
* @version 0.4
*
*/

#ifndef LIGHTCONTROLLER_H_
#define LIGHTCONTROLLER_H_

#define DEBUG_LIGHTCONTROLLER

#include "ActorHAL.h"
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
	ActorHAL* aHal;

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
