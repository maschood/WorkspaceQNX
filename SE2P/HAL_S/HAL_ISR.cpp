/*
 * HAL_ISR.cpp
 *
 *  Created on: 30.04.2013
 *      Author: maschood
 */

#include "HAL_ISR.h"

static int coid;

const struct sigevent * intHandler(void *arg, int id) {
	struct sigevent *event = (struct sigevent *) arg;
	int iir;
	uint8_t val;

	/*
	 * determine the source of the interrupt
	 * by reading the Interrupt Identification Register
	 */
	iir = in8(DIO_BASE + OFFS_INT_STATUS) & (BIT_1 | BIT_3);
	out8(DIO_BASE + OFFS_INT_STATUS, 0);

	switch (iir) {
	case (BIT_1 | BIT_3):
		val = (in8(DIO_BASE + DIO_OFFS_B) << 8) | (in8(DIO_BASE + DIO_OFFS_C));
		SIGEV_PULSE_INIT(event, coid, SIGEV_PULSE_PRIO_INHERIT,
				PB_STATUS | PC_STATUS, val);
		break;
	case BIT_1:
		val = in8(DIO_BASE + DIO_OFFS_B);
		SIGEV_PULSE_INIT(event, coid, SIGEV_PULSE_PRIO_INHERIT,
				PB_STATUS, val);
		break;
	case BIT_3:
		val = in8(DIO_BASE + DIO_OFFS_C);
		SIGEV_PULSE_INIT(event, coid, SIGEV_PULSE_PRIO_INHERIT,
				PC_STATUS, val);
		break;
	default:
		break;
		event = NULL;
	}
	return event;
}

HAL_ISR* HAL_ISR::instance = NULL;

HAL_ISR::HAL_ISR() {
	initInterrupt();
}

HAL_ISR::~HAL_ISR() {
	// TODO Auto-generated destructor stub
}

HAL_ISR* HAL_ISR::getInstance() {
	HAL_A* hal = HAL_A::get_instance();
	if (instance == NULL) {
		instance = new HAL_ISR();
	}
	return instance;
}

void HAL_ISR::initInterrupt() {
	// create channel to receive pulse messages from the ISR
	chid = ChannelCreate(0);
	if (chid == -1) {
		perror("SensorikIntro: ChannelCreate Chid failed");
		exit(EXIT_FAILURE);
	}

	//Connect to Channel
	coid = ConnectAttach(0, 0, chid, _NTO_SIDE_CHANNEL, 0);
	if (coid == -1) {
		perror("SensorikIntro: ConnectAttach coid failed");
		exit(EXIT_FAILURE);
	}

	//Iinit Sigevent for Pulse
	SIGEV_PULSE_INIT(&event, coid, SIGEV_PULSE_PRIO_INHERIT, 0, 0);

	//ISR register
	interruptId = InterruptAttach(HW_SERIAL_IRQ, intHandler, &event,
			sizeof(event), 0);
	if (interruptId == -1) {
		perror("Fehler beim InterruptAttach");
		exit(EXIT_FAILURE);
	}
	//Reset IRQs status Register
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

void HAL_ISR::stop() {
	HAWThread::stop(); // super.stop();

	if (-1 == ConnectDetach(coid)) {
		perror("SensorCtrl: ConnectDetach coid failed");
	}
	if (-1 == ChannelDestroy(chid)) {
		perror("SensorCtrl: ChannelDestroy chid failed");
	}
}

void HAL_ISR::shutdown() {
}

int HAL_ISR::getHeight() {
	/*
	 Bohrung oben	3506,3524,3528
	 Bohrung unten	2470,2478,2480
	 zu flach	2731,2737
	 Bohrung oben oM	3492
	 */
	int hoehe = -1;
	int i;

	out8(AIO_PORT_A, AIO_GET_VAL);

	for (i = 0; i < 50; i++) {
		//Bit 7 goes HIGH when an A/D conversion completes
		if ((in8(AIO_BASE) & (1 << 7))) { // == (1<<7)
			hoehe = in16(AIO_PORT_A);
			break;
		}
	}
	return hoehe;
}

void HAL_ISR::execute(void* arg) {
	struct _pulse pulse;
	while (!isStopped()) {
		if (-1 == MsgReceivePulse(chid, &pulse, sizeof(pulse), NULL)) {
			if (isStopped()) {
				break; // channel destroyed, Thread ending
			}
			perror("SensorCtrl: MsgReceivePulse");
			exit(EXIT_FAILURE);
		}

		cout << "Hier: "<< pulse.value.sival_int << endl;

		switch(pulse.value.sival_int)
		{	case BHANCHOD:
			cout << "Puck am Band Anfang!"<< endl;
			break;
//			case 201: std::cout << "falsch";
//			break;
//			case 207: std::cout << "wahr";
//			break;
//			case 195: std::cout << "falsch";
//			break;
//			case 219: std::cout << "wahr";
//			break;
//			case 235: std::cout << "falsch";
//			break;
//			case 139: std::cout << "wahr";
//			break;
//			case 75: std::cout << "falsch";
//			break;
	}
//		printf("|   %X   |   %2X   |", pulse.code, pulse.value.sival_int);
//		cout << endl;


	}
}

