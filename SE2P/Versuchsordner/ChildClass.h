/*
 * ChildClass.h
 *
 *  Created on: 01.05.2013
 *      Author: ich
 */

//#ifndef CHILDCLASS_H_
//#define CHILDCLASS_H_

#include "HAWThread/HAWThread.h"

using namespace thread;

class ChildClass : public thread::HAWThread{
public:
	ChildClass();

	void InstanzialteChildClass(int id);
	 ~ChildClass();

protected:
	int id;
	int count;

	void ausgabe();

	virtual void execute(void* arg);
	virtual void shutdown();
};


//#endif /* CHILDCLASS_H_ */
