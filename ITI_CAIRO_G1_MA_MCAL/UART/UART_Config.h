/*
 * UART_Config.h
 *
 *  Created on: Sep 6, 2026
 *      Author: Mohammed Abdelrahman
 */

/* Header guard to prevent multiple inclusion */
#ifndef ITI_CAIRO_G1_MA_MCAL_UART_UART_CONFIG_H_
#define ITI_CAIRO_G1_MA_MCAL_UART_UART_CONFIG_H_

/* Include UART private header for option definitions */
#include "UART_Private.h"

/*System Clock Frequency (Hz)*/
#ifndef F_CPU
/* Default CPU frequency if not defined elsewhere */
#define F_CPU                      8000000UL
#endif

/*Baud Rate
 *
 *Options: 2400, 4800, 9600, 19200, 38400, 57600, 115200, etc.
 */
/* Selected baud rate for USART communication */
#define USART_BAUDRATE              9600UL

/*USART Mode options
 *
 *USART_MODE_ASYNCHRONOUS, USART_MODE_SYNCHRONOUS
 */
/* Selected USART mode */
#define USART_MODE                  USART_MODE_ASYNCHRONOUS

/*Data Bits options
 *
 *USART_DATA_5_BIT, USART_DATA_6_BIT, USART_DATA_7_BIT,
 *USART_DATA_8_BIT, USART_DATA_9_BIT
 */
/* Selected number of data bits per frame */
#define USART_DATA_BITS             USART_DATA_8_BIT

/*Stop Bits options
 *
 *USART_STOP_1_BIT, USART_STOP_2_BIT
 */
/* Selected number of stop bits */
#define USART_STOP_BITS             USART_STOP_1_BIT

/*Parity Mode options
 *
 *USART_PARITY_DISABLED, USART_PARITY_EVEN, USART_PARITY_ODD
 */
/* Selected parity mode */
#define USART_PARITY                USART_PARITY_DISABLED

/*Double Speed options (Asynchronous mode only)
 *
 *USART_DOUBLE_SPEED_DISABLED, USART_DOUBLE_SPEED_ENABLED
 */
/* Selected double speed setting */
#define USART_DOUBLE_SPEED          USART_DOUBLE_SPEED_DISABLED

/*Clock Polarity options (Synchronous mode only)
 *
 *USART_CPOL_RISING, USART_CPOL_FALLING
 */
/* Selected clock polarity */
#define USART_CLOCK_POLARITY        USART_CPOL_RISING

#endif /* ITI_CAIRO_G1_MA_MCAL_UART_UART_CONFIG_H_ */
