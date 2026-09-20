/*
 * DIO_Private.h
 *
 *  Created on: Aug 25, 2026
 *      Author: Mohammed Abdelrahman
 */

/* Header guard to prevent multiple inclusion */
#ifndef ITI_CAIRO_G1_MA_MCAL_DIO_DIO_PRIVATE_H_
#define ITI_CAIRO_G1_MA_MCAL_DIO_DIO_PRIVATE_H_

/* Port index definitions */
#define DIO_PORTA  		0
#define DIO_PORTB  		1
#define DIO_PORTC  		2
#define DIO_PORTD  		3

/* Pin index definitions */
#define DIO_PIN0   		0
#define DIO_PIN1   		1
#define DIO_PIN2   		2
#define DIO_PIN3  	 	3
#define DIO_PIN4   		4
#define DIO_PIN5   		5
#define DIO_PIN6   		6
#define DIO_PIN7   		7

/* Logic level definitions */
#define DIO_HIGH   		1
#define DIO_LOW    		0

/* Pin/Port direction definitions */
#define DIO_INPUT  		0
#define DIO_OUTPUT 		1
#define DIO_PULLUP 		2

/* Port-wide direction values (8-bit) */
#define DIO_INPUT_PORT  0x00
#define DIO_OUTPUT_PORT 0xff

/* Data Direction Register (DDR) addresses for each port */
#define DDRA  (*(volatile unsigned char *) 0x3A)
#define DDRB  (*(volatile unsigned char *) 0x37)
#define DDRC  (*(volatile unsigned char *) 0x34)
#define DDRD  (*(volatile unsigned char *) 0x31)

/* Output Port Register (PORT) addresses for each port */
#define PORTA (*(volatile unsigned char *) 0x3B)
#define PORTB (*(volatile unsigned char *) 0x38)
#define PORTC (*(volatile unsigned char *) 0x35)
#define PORTD (*(volatile unsigned char *) 0x32)

/* Input Pin Register (PIN) addresses for each port */
#define PINA  (*(volatile unsigned char *) 0x39)
#define PINB  (*(volatile unsigned char *) 0x36)
#define PINC  (*(volatile unsigned char *) 0x33)
#define PIND  (*(volatile unsigned char *) 0x30)

#endif /* ITI_CAIRO_G1_MA_MCAL_DIO_DIO_PRIVATE_H_ */
