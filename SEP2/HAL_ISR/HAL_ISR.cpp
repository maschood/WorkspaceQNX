/*
 *
 */

#include "HAL_ISR/HAL_ISR.h"
#include "SignalType.h"

static int coid;

const struct sigevent * intHandler(void *arg, int id) {
	struct sigevent *event = (struct sigevent *) arg;
	int iir;
	uint16_t val;

	/*
	 * determine the source of the interrupt
	 * by reading the Interrupt Identification Register
	 */

	iir = in8(DIO_BASE + OFFS_INT_STATUS) & (BIT_1 | BIT_3);
	out8(DIO_BASE + OFFS_INT_STATUS, 0);

	switch (iir) {
	case (BIT_1 | BIT_3):
		val = (in8(DIO_BASE + DIO_OFFS_B) << 8) | (in8(DIO_BASE + DIO_OFFS_C));
		SIGEV_PULSE_INIT(event, coid, SIGEV_PULSE_PRIO_INHERIT, PB_STATUS
				| PC_STATUS, val);
		break;
	case BIT_1:
		val = in8(DIO_BASE + DIO_OFFS_B);
		SIGEV_PULSE_INIT(event, coid, SIGEV_PULSE_PRIO_INHERIT, PB_STATUS, val);
		break;
	case BIT_3:
		val = in8(DIO_BASE + DIO_OFFS_C);
		SIGEV_PULSE_INIT(event, coid, SIGEV_PULSE_PRIO_INHERIT, PC_STATUS, val);
		break;
	default:
		break;
		event = NULL;
	}
	return event;
}

HAL_ISR* HAL_ISR::instance = NULL;

HAL_ISR::HAL_ISR() {
	HAL_A::get_instance();
	initInterrupt();

	// create channel for dispatcher
	signalChid = ChannelCreate(0);
	if (signalChid == -1) {
		perror("Dispatcher: ChannelCreate signalChid failed");
		exit(EXIT_FAILURE);
	}

	// attach to signal channel
	signalCoid = ConnectAttach(0, 0, signalChid, _NTO_SIDE_CHANNEL, 0);
	if (signalCoid == -1) {
		perror("SensorCtrl: ConnectAttach signalCoid failed");
		exit(EXIT_FAILURE);
	}

}

HAL_ISR::~HAL_ISR() {

}

HAL_ISR* HAL_ISR::getInstance() {

	if (instance == NULL) {
		instance = new HAL_ISR();
	}
	return instance;
}

int HAL_ISR::getSignalChid(void) {
	return signalChid;
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

	if (-1 == ConnectDetach(signalCoid)) {
		perror("SensorCtrl: ConnectDetach ConnectDetach failed");
	}
	if (-1 == ChannelDestroy(signalChid)) {
		perror("SensorCtrl: ChannelDestroy signalChid failed");
	}

}

void HAL_ISR::shutdown() {
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

		if (pulse.value.sival_int == PORT_B_1){
				cout << "H�he ist: " << hal_s->get_height_analog() << endl;
		}

		int sendCode = -1;
		int sendVal = -1;

		// only port b and WERKS_EINLAUF
		if (pulse.code & PB_STATUS) {
			if ((pulse.value.sival_int & WERKS_EINLAUF) != (portBstatus
					& WERKS_EINLAUF)) {
				cout <<"Bin drinnen" << endl;
				sendCode = werks_einlauf;
				sendVal = (pulse.value.sival_int & WERKS_EINLAUF);
			}
			portBstatus = pulse.value.sival_int;
		}

		MsgSendPulse(signalCoid, SIGEV_PULSE_PRIO_INHERIT, sendCode, sendVal);

		//		if (-1 == MsgReceivePulse(chid, &pulse, sizeof(pulse), NULL)) {
		//			if (isStopped()) {
		//				break; // channel destroyed, Thread ending
		//			}
		//			perror("SensorCtrl: MsgReceivePulse");
		//			exit( EXIT_FAILURE);
		//		}
		//
		//		if (pulse.value.sival_int == PORT_B_1){
		//			cout << "H�he ist: " << hal_s->get_height_analog() << endl;
		//		}
		//
		//		if ((pulse.code == 2) || (pulse.code == 8)) {
		//			hal_s->start_process();

		//		}
	}
}
