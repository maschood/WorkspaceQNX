/*
 * Sensorika.cpp
 *
 *  Created on: 29.04.2013
 *      Author: Autorus Dominatus
 */

#include "Sensorika.h"
#include "Addresses.h"
#include "HWaccess.h"

static int isr_coid;

Mutex Sensorik:: mutex_Sensorik = Mutex();

const struct sigevent* ISR(void* arg, int id) {
	struct sigevent *event = (struct sigevent *) arg; //Event der geschickt werden soll
	uint8_t val;
	uint16_t state;
	state = in8(DIO_BASE + OFFS_INT_STATUS) & (BIT_1 | BIT_3); // lesen
	out8(DIO_BASE + OFFS_INT_STATUS, 0); // zuruecksetzen

	switch (state) {
	case (BIT_1 | BIT_3):
		val = (in8(DIO_BASE + DIO_OFFS_B) << 8) | (in8(DIO_BASE + DIO_OFFS_C));
		SIGEV_PULSE_INIT(event, isr_coid, SIGEV_PULSE_PRIO_INHERIT,
				PB_STATUS | PC_STATUS, val);
		break;
	case BIT_1:
		val = in8(DIO_BASE + DIO_OFFS_B);
		SIGEV_PULSE_INIT(event, isr_coid, SIGEV_PULSE_PRIO_INHERIT,
				PB_STATUS, val);
		break;
	case BIT_3:
		val = in8(DIO_BASE + DIO_OFFS_C);
		SIGEV_PULSE_INIT(event, isr_coid, SIGEV_PULSE_PRIO_INHERIT,
				PC_STATUS, val);
		break;
	default:
		event = NULL;
	}
	return event;
}
Sensorika* Sensorika::instance = NULL;

Sensorika::Sensorika() {
	// make sure the HAL object is created
	Sensorika::getInstance();
	initInterrupts();
}

Sensorika::~Sensorika() {
	if (instance != NULL) {
		delete instance;
		instance = NULL;
	}
}

Sensorika*::Sensorika::getInstance() {
	if (instance == NULL) {
		mutex_Sensorik.lock();
		if(instance == NULL) {
			instance = new Sensorik();
		}
		mutex_Sensorik.unlock();
	}
	return instance;
}

void Sensorika::initInterrupts() {
	// create channel to receive pulse messages from the ISR
	isrChid = ChannelCreate(0);
	if (isrChid == -1) {
		perror("SensorikIntro: ChannelCreate isrChid failed");
		exit(EXIT_FAILURE);
	}
	isr_coid = ConnectAttach(0, 0, isrChid, _NTO_SIDE_CHANNEL, 0);
	if (isr_coid == -1) {
		perror("SensorikIntro: ConnectAttach isr_coid failed");
		exit(EXIT_FAILURE);
	}

	// attach ISR
	SIGEV_PULSE_INIT(&event, isr_coid, SIGEV_PULSE_PRIO_INHERIT, 0, 0);
	interruptId = InterruptAttach(11, ISR, &event, sizeof(event), 0);
	if (interruptId == -1) {
		perror("SensorikIntro: InterruptAttach failed");
		exit(EXIT_FAILURE);
	}

	// configure interrupts

	// reset irq status register
	out8(DIO_BASE + OFFS_INT_STATUS, 0);
	// disable interrupts for all ports (Bit 0-5)
	uint8_t int_ctrl = in8(DIO_BASE + OFFS_INT_CTRL);
	out8(DIO_BASE + OFFS_INT_CTRL, int_ctrl | 0b00111111);
	// enable interrupt for portB und portC (Bit 1 und 2) (S. 18)
	int_ctrl = in8(DIO_BASE + OFFS_INT_CTRL);
	out8(DIO_BASE + OFFS_INT_CTRL, int_ctrl & ~(PB_CTRL | PC_CTRL));

	// read out port B and C valies
	portBstatus = in8(DIO_BASE + DIO_OFFS_B);
	portCstatus = in8(DIO_BASE + DIO_OFFS_B);
}

void Sensorika::stop() {
	HAWThread::stop(); // super.stop();

	if (-1 == ConnectDetach(isr_coid)) {
		perror("SensorCtrl: ConnectDetach isr_coid failed");
	}
	if (-1 == ChannelDestroy(isrChid)) {
		perror("SensorCtrl: ChannelDestroy isr_chid failed");
	}
	// in Simulation: bleibt hier haengen
	//    if (-1 == InterruptDetach(interruptId)) {
	//        perror("SensorCtrl: InterruptDetach failed");
	//    }
}

void Sensorika::shutdown() {
}
void Sensorika::execute(void *arg) {
	cout << "| code  |  " << "value |" << endl;
	cout << "|----------------|" << endl;

	struct _pulse pulse;
	while (!isStopped()) {
		if (-1 == MsgReceivePulse(isrChid, &pulse, sizeof(pulse), NULL)) {
			if (isStopped()) {
				break; // channel destroyed, Thread ending
			}
			perror("SensorCtrl: MsgReceivePulse");
			exit(EXIT_FAILURE);
		}

		printf("|   %X   |   %2X   |", pulse.code, pulse.value.sival_int);
		cout << endl;
	}
}
