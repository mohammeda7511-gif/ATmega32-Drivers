/*
 * UART_Interface.h
 *
 *  Created on: Sep 6, 2026
 *      Author: Mohammed Abdelrahman
 */

/* Header guard to prevent multiple inclusion */
#ifndef ITI_CAIRO_G1_MA_MCAL_UART_UART_INTERFACE_H_
#define ITI_CAIRO_G1_MA_MCAL_UART_UART_INTERFACE_H_

/* Include standard type definitions (u8, etc.) */
#include "../../ITI_CAIRO_G1_MA_LIB/STD_TYPES.h"

/* Initialize USART with configured baud rate, frame format, and mode */
void USART_Init(void);

/* Send a single character via USART (blocking/polling) */
void USART_SendChar(u8 Char);

/* Receive a single character via USART (blocking/polling) */
u8 USART_ReceiveChar(void);

/* Send a null-terminated string via USART (blocking/polling) */
void USART_SendString(u8 *String);

#endif /* ITI_CAIRO_G1_MA_MCAL_UART_UART_INTERFACE_H_ */
