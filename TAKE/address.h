/**
 * SE2 WiSe 2012
 * I/O addresses and some defines
 *
 * Contains all defines for hardware access, interrupts and pulse codes
 * 
 * @file address.h
 * @author Chris Addo
 *         Jens Eberwein
 *         Tristan Rudat
 *         Martin Slowikowski
 * @date 2012-10-18
 * @version 0.8
 * 
 */

#ifndef ADDRESS_H_
#define ADDRESS_H_

// General defines

#define DIO_BASE		0x300	// Base Adresse
#define DIO_OFFS_A		0x00	// Port A Offset
#define DIO_OFFS_B		0x01	// Port B Offset
#define DIO_OFFS_C		0x02	// Port C Offset
#define DIO_OFFS_CTRL	0x03	// Control Register Offset

#define PORT_A		(DIO_BASE + DIO_OFFS_A)	
#define PORT_B		(DIO_BASE + DIO_OFFS_B)
#define PORT_C		(DIO_BASE + DIO_OFFS_C)
#define PORT_CTRL	(DIO_BASE + DIO_OFFS_CTRL)

#define DIO_INIT 0x8A

// Individual bits
#define BIT0	0x01
#define BIT1	0x02
#define BIT2	0x04
#define BIT3	0x08
#define BIT4	0x10
#define BIT5	0x20
#define BIT6	0x40
#define BIT7	0x80

// Port A
#define ENGINE_RIGHT	0x01
#define ENGINE_LEFT		0x02
#define ENGINE_SLOW		0x04
#define ENGINE_STOP		0x08
#define GATE			0x10
#define LIGHT_GREEN		0x20
#define LIGHT_YELLOW	0x40
#define LIGHT_RED		0x80

// Port B
#define SENS_BARRIER_START	0x01
#define SENS_BARRIER_HEIGHT	0x02
#define SENS_HEIGHT_CONTROL	0x04
#define SENS_BARRIER_GATE	0x08
#define SENS_METAL			0x10
#define SENS_GATE_OPEN		0x20
#define SENS_SLIDE_FULL		0x40
#define SENS_BARRIER_END	0x80

#define ENGINE_SLOW_LEFT	(ENGINE_SLOW + ENGINE_LEFT)
#define ENGINE_SLOW_RIGHT	(ENGINE_SLOW + ENGINE_RIGHT)

// Port C
#define LED_START			0x01
#define LED_RESET			0x02
#define LED_Q1				0x04
#define LED_Q2				0x08
#define SENS_BUTON_START	0x10
#define SENS_BUTTON_STOP	0x20
#define SENS_BUTTON_RESET	0x40
#define SENS_BUTTON_ESTOP	0x80

// Interrupt
#define DIO_INTERRUPT_ENABLE_REG	(DIO_BASE + 0x0B)	//DIO Page 18
#define DIO_INTERRUPT_READ_CLEAR 	(DIO_BASE + 0x18)	//DIO Page 18
#define DIO_INTERRUPT_CLEAR_REG		(DIO_BASE + 0x0F)	//DIO Page 18
#define DIO_INTERRUPT_ENABLE_BC		(0xF9) // ~(0000.0110) -> 1111.1001, DIO Page 18
#define PORTB_INTERRUPT  			2	//DIO Page 18
#define PORTC_INTERRUPT  			8	//DIO Page 18
#define DEFAULT_ISR_VAL				0xACB
#define DIO_IRQ						11

// Pulse
#define PULSE_FROM_ISR			0
#define PULSE_FROM_ISRHANDLER	1
#define PULSE_FROM_RS232		2
#define PULSE_FROM_ERR_FSM		3
#define PULSE_FROM_PUCK			4
#define PULSE_FROM_DISPATCHER 	5
#define PULSE_FROM_TIMER		6

// AIO Card
#define AIO_BASE 	0x320
#define AIO_OFFS_A 	0x02
#define AIO_GET_VAL	0x10
#define AIO_PORT_A	(AIO_BASE + AIO_OFFS_A)

#endif /* ADDRESS_H_ */
