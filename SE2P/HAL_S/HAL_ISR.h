/*
 * HAL_ISR.h
 *
 *  Created on: 30.04.2013
 *      Author: maschood
 */

#include "Addresses.h"
#include "HWaccess.h"
#include "HAL_A.h"

#ifndef HAL_ISR_H_
#define HAL_ISR_H_

class HAL_ISR :   {
public:
	HAL_ISR();
	virtual ~HAL_ISR();
	void initInterrupt();


private:
	int chid;
	struct sigevent event;
	int interruptId;

	uint8_t portBstatus;
	uint8_t portCstatus;
};

#endif /* HAL_ISR_H_ */
