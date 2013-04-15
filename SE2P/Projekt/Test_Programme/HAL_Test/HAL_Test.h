/*
 * HAL_Test.h
 *
 *  Created on: 15.04.2013
 *      Author: ich
 */

class HAL_Test{
public:
	int HAL_Test_run(HAL hal);

private :

	HAL hal;

	HAL_Test();
	~HAL_Test();

	int Test_Lamp_Red();
	int Test_Lamp_Yellow();
	int Test_Lamp_Green();

	int Test_Conveyor_Right();
	int Test_Conveyor_Left();
	int Test_Conveyor_Stop();

	int Test_Bar_Open();
	int Test_Bar_Close();

};
