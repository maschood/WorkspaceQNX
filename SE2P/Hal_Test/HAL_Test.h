/*
 * HAL_Test.h
 *
 *  Created on: 15.04.2013
 *      Author: ich
 */

#include "HAL.h"

class HAL_Test{
public:
	int HAL_Test_run(HAL hal);
	void Test_Singleton();

private :

	HAL hal;

	HAL_Test();
	~HAL_Test();

	int Test_Lamp_Red(uint8_t val);
	int Test_Lamp_Yellow(uint8_t val);
	int Test_Lamp_Green(uint8_t val);

	int Test_Conveyor_Right(uint8_t val);
	int Test_Conveyor_Left(uint8_t val);
	int Test_Conveyor_Stop(uint8_t val);

	int Test_Bar_Open(uint8_t val);
	int Test_Bar_Close(uint8_t val);

};
