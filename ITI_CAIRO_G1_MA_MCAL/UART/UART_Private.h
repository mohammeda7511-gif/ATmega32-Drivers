/*
 * UART_Private.h
 *
 *  Created on: Sep 6, 2026
 *      Author: Mohammed Abdelrahman
 */

/* Header guard to prevent multiple inclusion */
#ifndef ITI_CAIRO_G1_MA_MCAL_UART_UART_PRIVATE_H_
#define ITI_CAIRO_G1_MA_MCAL_UART_UART_PRIVATE_H_

/*Registers definitions*/
/* USART Control and Status Register A */
#define UCSRA                      (*(volatile u8 *)0x2B)
/* USART Control and Status Register B */
#define UCSRB                      (*(volatile u8 *)0x2A)
/* USART Control and Status Register C */
#define UCSRC                      (*(volatile u8 *)0x40)

/* USART Baud Rate Register Low byte */
#define UBRRL					   (*(volatile u8 *)0x29)
/* USART Baud Rate Register High byte */
#define UBRRH					   (*(volatile u8 *)0x40)

/* USART Data Register */
#define UDR					       (*(volatile u8 *)0x2C)

/*Pins definitions*/
/*1- UCSRA*/
/* USART Receive Complete flag bit */
#define RXC 					   7
/* USART Transmit Complete flag bit */
#define TXC 					   6
/* USART Data Register Empty flag bit */
#define UDRE 					   5
/* Frame Error flag bit */
#define FE  					   4
/* Data OverRun flag bit */
#define DOR 					   3
/* Parity Error flag bit */
#define PE 		    			   2
/* Double USART Transmission Speed bit */
#define U2X 					   1
/* Multi-Processor Communication Mode bit */
#define MPCM 					   0
/*2- UCSRB*/
/* RX Complete Interrupt Enable bit */
#define RXCIE 					   7
/* TX Complete Interrupt Enable bit */
#define TXCIE 					   6
/* USART Data Register Empty Interrupt Enable bit */
#define UDRIE 					   5
/* Receiver Enable bit */
#define RXEN  					   4
/* Transmitter Enable bit */
#define TXEN 					   3
/* Character Size bit 2 */
#define UCSZ2 		    		   2
/* Receive Data Bit 8 */
#define RXB8 					   1
/* Transmit Data Bit 8 */
#define TXB8 					   0
/*3- UCSRC*/
/* Register Select bit (must be set to access UCSRC) */
#define URSEL 					   7
/* USART Mode Select bit */
#define UMSEL 					   6
/* Parity Mode bit 1 */
#define UPM1 					   5
/* Parity Mode bit 0 */
#define UPM0  					   4
/* Stop Bit Select bit */
#define USBS 					   3
/* Character Size bit 1 */
#define UCSZ1 		    		   2
/* Character Size bit 0 */
#define UCSZ0 					   1
/* Clock Polarity bit */
#define UCPOL 					   0

/*USART Mode options
 *
 *USART_MODE_ASYNCHRONOUS, USART_MODE_SYNCHRONOUS
 */
/* Asynchronous USART mode */
#define USART_MODE_ASYNCHRONOUS    0
/* Synchronous USART mode */
#define USART_MODE_SYNCHRONOUS     1

/*Parity Mode options
 *
 *USART_PARITY_DISABLED, USART_PARITY_EVEN, USART_PARITY_ODD
 */
/* Parity disabled */
#define USART_PARITY_DISABLED      0
/* Even parity */
#define USART_PARITY_EVEN          1
/* Odd parity */
#define USART_PARITY_ODD           2

/*Stop Bits options
 *
 *USART_STOP_1_BIT, USART_STOP_2_BIT
 */
/* One stop bit */
#define USART_STOP_1_BIT           1
/* Two stop bits */
#define USART_STOP_2_BIT           2

/*Data Bits options
 *
 *USART_DATA_5_BIT, USART_DATA_6_BIT, USART_DATA_7_BIT,
 *USART_DATA_8_BIT, USART_DATA_9_BIT
 */
/* 5 data bits */
#define USART_DATA_5_BIT           5
/* 6 data bits */
#define USART_DATA_6_BIT           6
/* 7 data bits */
#define USART_DATA_7_BIT           7
/* 8 data bits */
#define USART_DATA_8_BIT           8
/* 9 data bits */
#define USART_DATA_9_BIT           9

/*Clock Polarity options (Synchronous mode only)
 *
 *USART_CPOL_RISING, USART_CPOL_FALLING
 */
/* Sample on rising edge */
#define USART_CPOL_RISING          0
/* Sample on falling edge */
#define USART_CPOL_FALLING         1

/*Double Speed options (Asynchronous mode only)
 *
 *USART_DOUBLE_SPEED_DISABLED, USART_DOUBLE_SPEED_ENABLED
 */
/* Double speed disabled */
#define USART_DOUBLE_SPEED_DISABLED   0
/* Double speed enabled */
#define USART_DOUBLE_SPEED_ENABLED    1

/*NULL definition*/
/* Generic null pointer constant */
#define NULL						((void*)0)

#endif /* ITI_CAIRO_G1_MA_MCAL_UART_UART_PRIVATE_H_ */
