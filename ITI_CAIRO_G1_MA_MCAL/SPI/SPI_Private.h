/*
 * SPI_Private.h
 *
 *  Created on: Sep 7, 2026
 *      Author: Mohammed Abdelrahman
 */

#ifndef ITI_CAIRO_G1_MA_MCAL_SPI_SPI_PRIVATE_H_
#define ITI_CAIRO_G1_MA_MCAL_SPI_SPI_PRIVATE_H_

#include "../../ITI_CAIRO_G1_MA_LIB/STD_TYPES.h"

/*Registers definitions*/
#define SPCR 							(*(volatile u8 *)0x2D)
#define SPSR 							(*(volatile u8 *)0x2E)
#define SPDR 							(*(volatile u8 *)0x2F)
#define DDRB 							(*(volatile u8 *)0x37)


/*Pins definitions*/
#define SPIE							7
#define SPE					   			6
#define DORD							5
#define MSTR							4
#define CPOL							3
#define CPHA							2
#define SPR1							1
#define SPR0							0

#define	SPIF							7
#define WCOL							6
#define SPI2X							0

#define SS_PIN					   		4
#define MOSI_PIN   						5
#define MISO_PIN   						6
#define SCK_PIN   						7

/* SPI mode options*/
#define SPI_MASTER						0
#define SPI_SLAVE						1

/**/
#define SPI_CLOCK_F_4					0
#define SPI_CLOCK_F_16					1
#define SPI_CLOCK_F_64					2
#define SPI_CLOCK_F_128					3
#define SPI_CLOCK_F_2					4
#define SPI_CLOCK_F_8					5
#define SPI_CLOCK_F_32					6

/*SPI clock phase options*/
#define SPI_IDLE_LOW					0
#define SPI_IDLE_HIGH					1

/*SPI clock parity options*/
#define SPI_SAMPLE_FIRST				0
#define SPI_SETUP_FIRST					1

/*SPI interrupt options*/
#define SPI_INTERRUPT_DISABLE			0
#define SPI_INTERRUPT_ENABLE			1

/*SPI data order options*/
#define SPI_MSB_BIT_FIRST				0
#define SPI_LSB_BIT_FIRST				1

#define SPI_CLOCK_MSK					0xFC
#define SPI_CLOCK_CHOICE_MSK			0x03

#endif /* ITI_CAIRO_G1_MA_MCAL_SPI_SPI_PRIVATE_H_ */
