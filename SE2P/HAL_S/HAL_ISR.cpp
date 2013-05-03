/*
 * HAL_ISR.cpp
 *
 *  Created on: 30.04.2013
 *      Author: maschood
 */

#include "HAL_ISR.h"

static int coid;

const struct sigevent * intHandler(void *arg, int id) {
	int iir;
	uint8_t val;
	struct sigevent *event = (struct sigevent *) arg;
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
HAL_ISR::HAL_ISR() {
	// TODO Auto-generated constructor stub

}

HAL_ISR::~HAL_ISR() {
	// TODO Auto-generated destructor stub
}


void HAL_ISR::initInterrupt(){
		// create channel to receive pulse messages from the ISR
	    chid = ChannelCreate(0);
	    if (chid == -1) {
	        perror("SensorikIntro: ChannelCreate isrChid failed");
	        exit(EXIT_FAILURE);
	    }

	    //Connect to Channel
	    coid = ConnectAttach(0, 0, chid, _NTO_SIDE_CHANNEL, 0);
	    if (coid == -1) {
	        perror("SensorikIntro: ConnectAttach isr_coid failed");
	        exit(EXIT_FAILURE);
	    }

	    //Iinit Sigevent for Pulse
	    SIGEV_PULSE_INIT(&event, coid, SIGEV_PULSE_PRIO_INHERIT, 0, 0);

		//Reset IRQs status Register
		out8(DIO_BASE + OFFS_INT_STATUS, 0);

	    // disable interrupts for all ports (Bit 0-5)
	    uint8_t int_ctrl = in8(DIO_BASE + OFFS_INT_CTRL);
	    out8(DIO_BASE + OFFS_INT_CTRL, int_ctrl | 0b00111111);

	    // enable interrupt for portB und portC (Bit 1 und 2) (S. 18)
	    int_ctrl = in8(DIO_BASE + OFFS_INT_CTRL);
	    out8(DIO_BASE + OFFS_INT_CTRL, int_ctrl & ~(PB_CTRL | PC_CTRL));

	    //ISR register
	    if (interruptId = InterruptAttach(HW_SERIAL_IRQ, intHandler, &event, sizeof(event), 0) == -1){
	    	perror( "Fehler beim ConnectAttach");
	    	exit(EXIT_FAILURE);
	    }
}
