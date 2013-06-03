/*
 * Puk.h
 *
 *  Created on: 21.05.2013
 *      Author: ich
 */

#include "Addresses.h"
#include "Definitions.h"

class Puk{
private:
	char id; // the ID of the Puk each one get its own.
	char hight_one; // the anbalog hight from the first mesurment
	char hight_two; // the anbalog hight from the second mesurment
	char status; // status bits that shoews information of the puk.
	int time_current; // the current time of the puk
	int time_last; // time of the last station of the puk
	static char wayne; // variable to determine the next ID.
	void (*zustand)(Puk*);
public:


	Puk();
	~Puk();

	char get_id();
	void set_hight_one(char);
	char get_hight_one();
	void set_hight_two(char);
	char get_hight_two();

	void set_metal(char);
	char get_metal();
	void set_direction(char);
	char get_direction();
	void set_remove(char);
	char get_remove();

	int check_time(int);

	void make_action();
};
