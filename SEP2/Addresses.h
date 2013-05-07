/*
 * Adresses.h
 *
 *  Created on: 10.10.2012
 *      Author:
 */

#ifndef ADDRESSES_H_
#define ADDRESSES_H_

#define DIO_BASE 		0x300       // Base address
#define DIO_OFFS_A 		0x00        // Port A offset
#define DIO_OFFS_B 		0x01        // Port B offset
#define DIO_OFFS_C 		0x02        // Port C offset
#define DIO_OFFS_CTRL 	0x03      	// Control register offset

// BIT_X is set to one bzw BitMasken
#define BIT_0 0x01
#define BIT_1 0x02
#define BIT_2 0x04
#define BIT_3 0x08
#define BIT_4 0x10
#define BIT_5 0x20
#define BIT_6 0x40
#define BIT_7 0x80

//Interrupt
#define HW_SERIAL_IRQ 11

#define OFFS_INT_STATUS 0x0F
#define PB_STATUS       0x02
#define PC_STATUS       0x08

#define OFFS_INT_CTRL   0x0B
#define PB_CTRL         0x02
#define PC_CTRL         0x04

// AIO Card
#define AIO_BASE 	0x320
#define AIO_OFFS_A 	0x02
#define AIO_GET_VAL	0x10
#define AIO_PORT_A	(AIO_BASE + AIO_OFFS_A)

//HAL Sensorik PORT_B HIGH
#define PORT_B_0 0xCA
#define PORT_B_1 0xC9
#define PORT_B_2 0xCF
#define PORT_B_3 0xC3
#define PORT_B_4 0xDB
#define PORT_B_5 0xEB
#define PORT_B_6 0x8B
#define PORT_B_7 0x4B


#endif /* ADDRESSES_H_ */