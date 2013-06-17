/**
 * SE2 WiSe 2012
 * PuckHandler
 *
 * PuckHandler handles pucks placed on Band1 or Band2.
 * There are queues for each segment on the band conveyor and for the whole
 * band conveyor, containing pucks placed on the band conveyor.
 *
 * @file PuckHandler.cpp
 * @author Chris Addo
 *         Jens Eberwein
 *         Tristan Rudat
 *         Martin Slowikowski
 * @date 2012-11-28
 * @version 0.6
 *
 */

#include "PuckHandler.h"

PuckHandler* PuckHandler::instance = NULL;
Mutex* PuckHandler::puckHandlerInstanceMutex = new Mutex();

PuckHandler::PuckHandler() {
	seg1Mutex = new Mutex;
	seg2Mutex = new Mutex;
	seg3Mutex = new Mutex;
	pucksBandMutex = new Mutex;
	sensorFuncCounterMutex = new Mutex;
	disp = Dispatcher::getInstance();
	dispChid = disp->getChid();
}

PuckHandler::~PuckHandler() {
	if (instance != NULL) {
		delete instance;
		instance = NULL;
		puckHandlerInstanceMutex->~Mutex();

		seg1Mutex->~Mutex();
		seg2Mutex->~Mutex();
		seg3Mutex->~Mutex();
		pucksBandMutex->~Mutex();
	}
}

PuckHandler* PuckHandler::getInstance() {
	if (!instance) {
		puckHandlerInstanceMutex->lock();
		if (!instance) {
			instance = new PuckHandler;
#ifdef DEBUG_PuckHandler
			printf("Debug PuckHandler: New PuckHandler instance created\n");
#endif
		}
		puckHandlerInstanceMutex->unlock();
	}

	return instance;
}


void PuckHandler::initializePucks() {
	for (int i = 0; i < MAX_PUCKS_BAND; i++) {
		pucks.push_back(new Controller(i + 1));
		disp->registerContextForAllFuncs(pucks.at(i));
#ifdef DEBUG_PuckHandler
		printf("Debug PuckHandler: created Puck%d \n", pucks.at(i)->getID());
#endif
	}
}

void PuckHandler::activatePuck() {
	if (!pucks.empty()) {
		for (int i = 0; i < MAX_PUCKS_BAND; i++) {
			if (!pucks.at(i)->isActive()) {
				pucks.at(i)->activate();
#ifdef DEBUG_PuckHandler
				printf("Debug PuckHandler: activated Puck%d \n", pucks.at(i)->getID());
#endif
				break;
			}
		}
	}
}

void PuckHandler::resetAllPucks() {
	if (!pucks.empty()) {
		for (int i = 0; i < MAX_PUCKS_BAND; i++) {
			pucks.at(i)->resetController();
#ifdef DEBUG_PuckHandler
			printf("Debug PuckHandler: resetted Puck%d \n", pucks.at(i)->getID());
#endif
		}
	}
}


void PuckHandler::addPuckToBand(Controller* contr) {
	pucksBandMutex->lock();
	if (pucksOnBand.size() < MAX_PUCKS_BAND) {
		pucksOnBand.push_back(contr);
		pucksBandMutex->unlock();
	} else {
		pucksBandMutex->unlock();
		printf("Error PuckHandler: No moar space on Band1!\n");
	}
}

void PuckHandler::addPuckToSeg1(Controller* contr) {
	seg1Mutex->lock();
	pucksInSeg1.push(contr);
	seg1Mutex->unlock();
}

void PuckHandler::addPuckToSeg2(Controller* contr) {
	seg2Mutex->lock();
	pucksInSeg2.push(contr);
	seg2Mutex->unlock();
}

void PuckHandler::addPuckToSeg3(Controller* contr) {
	seg3Mutex->lock();
	pucksInSeg3.push(contr);
	seg3Mutex->unlock();
}


void PuckHandler::removePuckFromBand(Controller* contr) {
	pucksBandMutex->lock();
	if (!pucksOnBand.empty()) {
		for (uint32_t i = 0; i < pucksOnBand.size(); i++) {
			if (pucksOnBand.at(i) == contr) {
				pucksOnBand.erase(pucksOnBand.begin() + i);
				break;
			}
		}
		pucksBandMutex->unlock();
	} else {
		pucksBandMutex->unlock();
		printf(
				"Error PuckHandler removePuckFromBand1(): Band1 already empty!\n");
	}
}

void PuckHandler::removePuckFromSeg1() {
	seg1Mutex->lock();
	if (!pucksInSeg1.empty()) {
		printf("puck%d pop from seg1\n",pucksInSeg1.front()->getID());
		pucksInSeg1.pop();
		seg1Mutex->unlock();
	} else {
		seg1Mutex->unlock();
		printf("Error PuckHandler: Seg1 already empty!\n");
	}
}

void PuckHandler::removePuckFromSeg2() {
	seg2Mutex->lock();
	if (!pucksInSeg2.empty()) {
		printf("puck%d pop from seg2\n",pucksInSeg2.front()->getID());
		pucksInSeg2.pop();
		seg2Mutex->unlock();
	} else {
		seg2Mutex->unlock();
		printf("Error PuckHandler: Seg2 already empty!\n");
	}
}

void PuckHandler::removePuckFromSeg3() {
	seg3Mutex->lock();
	if (!pucksInSeg3.empty()) {
		printf("puck%d pop from seg3\n",pucksInSeg3.front()->getID());
		pucksInSeg3.pop();
		seg3Mutex->unlock();
	} else {
		seg3Mutex->unlock();
		printf("Error PuckHandler: Seg3 already empty!\n");
	}
}

bool PuckHandler::isBandEmpty() {
	pucksBandMutex->lock();
	return pucksOnBand.empty();
	pucksBandMutex->unlock();
}

bool PuckHandler::isOnlyOneElemeOnBand() {
	pucksBandMutex->lock();
	return pucksOnBand.size() == 1 ? true : false;
	pucksBandMutex->unlock();
}

bool PuckHandler::checkIfFirstElemInSeg1(Controller* contr) {
	seg1Mutex->lock();
	return (!pucksInSeg1.empty()) ? (pucksInSeg1.front() == contr) : false;
	seg1Mutex->unlock();
}

bool PuckHandler::checkIfFirstElemInSeg2(Controller* contr) {
	seg2Mutex->lock();
	return (!pucksInSeg2.empty()) ? (pucksInSeg2.front() == contr) : false;
	seg2Mutex->unlock();
}

bool PuckHandler::checkIfFirstElemInSeg3(Controller* contr) {
	seg3Mutex->lock();
	return (!pucksInSeg3.empty()) ? (pucksInSeg3.front() == contr) : false;
	seg3Mutex->unlock();
}

void PuckHandler::reInitFirstElemInSegBools() {
	if(!pucksInSeg1.empty()){
		pucksInSeg1.front()->setFirstElementInSegment(true);
	}
	if(!pucksInSeg2.empty()){
		pucksInSeg2.front()->setFirstElementInSegment(true);
	}
	if(!pucksInSeg3.empty()){
		pucksInSeg3.front()->setFirstElementInSegment(true);
	}
}

void PuckHandler::printQueueStatus() {
	printf("Queue Seg1 size(): %d -> PuckID: %d -> isFront: %c\n",
			pucksInSeg1.size(), (pucksInSeg1.empty() ? 99
					: pucksInSeg1.front()->getID()), (pucksInSeg1.empty() ? 'X'
					: pucksInSeg1.front()->isFirstElementInSegment() ? 't'
							: 'f'));
	printf("Queue Seg2 size(): %d -> PuckID: %d -> isFront: %c\n",
			pucksInSeg2.size(), (pucksInSeg2.empty() ? 99
					: pucksInSeg2.front()->getID()), (pucksInSeg2.empty() ? 'X'
					: pucksInSeg2.front()->isFirstElementInSegment() ? 't'
							: 'f'));
	printf("Queue Seg3 size(): %d -> PuckID: %d -> isFront: %c\n",
			pucksInSeg3.size(), (pucksInSeg3.empty() ? 99
					: pucksInSeg3.front()->getID()), (pucksInSeg3.empty() ? 'X'
					: pucksInSeg3.front()->isFirstElementInSegment() ? 't'
							: 'f'));
	printf("Queue Band size(): %d\n", pucksOnBand.size());
}

void PuckHandler::incrementSenseorFuncCounter(int funcIdx) {
	sensorFuncCounterMutex->lock();

	sensorFuncCounter[funcIdx]++;

	if(sensorFuncCounter[funcIdx] == MAX_PUCKS_BAND) {


		printf("-- > Debug PuckHandler: /me is THROWING big Error!!! for -> %d \n",funcIdx);

		int errorfsmChid = ErrorFSM::getInstance()->getErrorFSMChid();
		int errorfsmCoid;
		int rc;

		if ((errorfsmCoid = ConnectAttach(0, 0, errorfsmChid, _NTO_SIDE_CHANNEL, 0)) == -1) {
			printf("PuckHandler: Error in ConnectAttach\n");
		}

		//rc = MsgSendPulse(errorfsmCoid, SIGEV_PULSE_PRIO_INHERIT, PULSE_FROM_PUCK, ERR_STATE_CRITICAL_ERROR);
		rc = MsgSendPulse(errorfsmCoid, SIGEV_PULSE_PRIO_INHERIT, PULSE_FROM_PUCK, ERR_STATE_ERROR);
		if (rc < 0) {
			printf("PuckHandler: Error in MsgSendPulse");
		}

		if (ConnectDetach(errorfsmCoid) == -1) {
			printf("PuckHandler: Error in ConnectDetach\n");
		}
	}

	sensorFuncCounterMutex->unlock();
}
void PuckHandler::errorOccured() {
	//printf("PuckHandler::errorOccured()\n");
	if (!pucks.empty()) {
		for (int i = 0; i < MAX_PUCKS_BAND; i++) {
			pucks.at(i)->setError(true);
		}
	}
}

void PuckHandler::errorResolved() {
	//printf("PuckHandler::errorResolved()\n");
	if (!pucks.empty()) {
		for (int i = 0; i < MAX_PUCKS_BAND; i++) {
			pucks.at(i)->setError(false);
		}
	}
}

void PuckHandler::resetAllSenseorFuncCounters() {
	sensorFuncCounterMutex->lock();

	for(int i = 0; i < SENSOR_MESSAGES_SIZE; i++) {
		sensorFuncCounter[i] = 0;
	}

	sensorFuncCounterMutex->unlock();
}

int PuckHandler::getDispChid(){
	return dispChid;
}

void PuckHandler::reset(){

	seg1Mutex->~Mutex();
	seg2Mutex->~Mutex();
	seg3Mutex->~Mutex();
	pucksBandMutex->~Mutex();
	sensorFuncCounterMutex->~Mutex();

	seg1Mutex = new Mutex;
	seg2Mutex = new Mutex;
	seg3Mutex = new Mutex;
	pucksBandMutex = new Mutex;
	sensorFuncCounterMutex = new Mutex;

	pucksOnBand.clear();

	resetAllSenseorFuncCounters();

	while(!pucksInSeg1.empty()) {
		pucksInSeg1.pop();
	}

	while(!pucksInSeg2.empty()) {
		pucksInSeg2.pop();
	}

	while(!pucksInSeg3.empty()) {
		pucksInSeg3.pop();
	}

	resetAllPucks();
}
