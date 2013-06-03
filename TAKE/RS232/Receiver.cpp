/**
 * SE2 WiSe 2012
 * RS232 (serial connection) receiver
 *
 * This receiver uses the RS232 class to receive messages
 * from another festo system via the serial interface.
 * It is running in a thread calling RS232's readMsg() function.
 * If a valid message is received, it is forwarded to responsible
 * unit (Dispatcher, ErrorFSM)
 *
 * @file Receiver.cpp
 * @author Chris Addo
 *         Jens Eberwein
 *         Tristan Rudat
 *         Martin Slowikowski
 * @date 2012-10-23
 * @version 0.1
 *
 */

#include "Receiver.h"

Receiver* Receiver::instance = NULL;
Mutex* Receiver::receiverInstanceMutex = new Mutex();

Receiver::Receiver() {
	rs232_1 = RS232_1::getInstance();
	
	dispatcherChid = Dispatcher::getInstance()->getChid();
	errfsmChid = ErrorFSM::getInstance()->getErrorFSMChid();

	//Connect to channel
	if ((dispatcherCoid = ConnectAttach(0, 0, dispatcherChid, _NTO_SIDE_CHANNEL, 0))
			== -1) {
		printf("Receiver: Error in ConnectAttach\n");
	}

	if ((errfsmCoid = ConnectAttach(0, 0, errfsmChid, _NTO_SIDE_CHANNEL, 0))
			== -1) {
		printf("Receiver: Error in ConnectAttach\n");
	}
}

Receiver::~Receiver() {
	if (instance != NULL) {
		delete instance;
		instance = NULL;
		receiverInstanceMutex->~Mutex();
	}
}

Receiver* Receiver::getInstance() {
	if (!instance) {
		receiverInstanceMutex->lock();
		if (!instance) {
			instance = new Receiver;
#ifdef DEBUG_Receiver
			printf("Debug Receiver: New Receiver instance created\n");
#endif
		}
		receiverInstanceMutex->unlock();
	}

	return instance;
}

void Receiver::execute(void*) {
	char buffer = -1;
	int readBytes; 
	int rc;
	int pulseval = -1;
	int coid = -1;
	
	while (!isStopped()) {
		readBytes = rs232_1->readMsg(&buffer);

		if (readBytes < 0) {
#ifdef DEBUG_Receiver
			printf("Error Receiver: Error or Timeout in readMsg\n");
#endif
		}

		if (readBytes > 0) {

			switch (buffer) {
			case RS232_BAND2_ACK:
				pulseval = RS232_BAND2_ACK;
				coid = dispatcherCoid;
#ifdef DEBUG_Receiver
				printf("DEBUG_Receiver: Received RS232_BAND2_ACK\n");
#endif
				break;
			case RS232_BAND2_READY:
				pulseval = RS232_BAND2_READY;
				coid = dispatcherCoid;
#ifdef DEBUG_Receiver
				printf("DEBUG_Receiver: Received RS232_BAND2_READY\n");
#endif
				break;
			case RS232_BAND1_WAITING:
				pulseval = RS232_BAND1_WAITING;
				coid = dispatcherCoid;
#ifdef DEBUG_Receiver
				printf("DEBUG_Receiver: Received RS232_BAND1_WAITING\n");
#endif
				break;
			case RS232_ESTOP:
				pulseval = RS232_ESTOP;
				coid = errfsmCoid;
#ifdef DEBUG_Receiver
				printf("DEBUG_Receiver: Received RS232_ESTOP\n");
#endif
				break;
			case RS232_PUCK_ARRIVED_ON_BAND2:
				pulseval = RS232_PUCK_ARRIVED_ON_BAND2;
				coid = dispatcherCoid;
#ifdef DEBUG_Receiver
				printf("DEBUG_Receiver: Received RS232_PUCK_ARRIVED_ON_BAND2\n");
#endif
				break;
			default:
#ifdef DEBUG_Receiver
				printf("Error Receiver: Received random shit not wanted...\n");
#endif
			}
			rc = MsgSendPulse(coid, SIGEV_PULSE_PRIO_INHERIT, PULSE_FROM_RS232, pulseval);
			if (rc < 0) {
				printf("Error Receiver: MsgSendPulse failed\n");
			}

		}
		
		fflush(stdout);
	};
}

void Receiver::shutdown() {
}

void Receiver::stop(){
	HAWThread::stop();

	if (ConnectDetach(dispatcherCoid) == -1) {
		printf("Receiver: Error in ConnectDetach\n");
	}

	if (ConnectDetach(errfsmCoid) == -1) {
		printf("Receiver: Error in ConnectDetach\n");
	}

	//TODO eigentlich m�sste das die main machen ...
	rs232_1->~RS232_1();
}
