/*
 * HAL_ISR.h
 *
 *  Created on: 29.04.2013
 *      Author: maschood
 */

#ifndef HAL_ISR_H_
#define HAL_ISR_H_

#include "HAWThread.h"

class HAL_ISR : public thread::HAWThread{

public:

	HAL_ISR();
	virtual ~HAL_ISR();
	int getChid();
	int getCoid();
	int hallo();

private:
	void initInterrupt();
	int chid;
	int coid;
};

#endif /* HAL_ISR_H_ */
