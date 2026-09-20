/*
 * UART_Program.c
 *
 *  Created on: Sep 6, 2026
 *      Author: Mohammed Abdelrahman
 */

/* Include standard type definitions (u8, etc.) */
#include "../../ITI_CAIRO_G1_MA_LIB/STD_TYPES.h"
/* Include bit manipulation macros (SET_BIT, CLR_BIT, GET_BIT, TOG_BIT) */
#include "../../ITI_CAIRO_G1_MA_LIB/BIT_MATH.h"
/* Include DIO interface header */
#include "../../ITI_CAIRO_G1_MA_MCAL/DIO/DIO_Interface.h"
/* Include UART private header for register addresses and macros */
#include "UART_Private.h"
/* Include UART configuration header */
#include "UART_Config.h"
/* Include UART interface header for function prototypes */
#include "UART_Interface.h"

/* Function: calculate UBRR value based on configured baud rate and mode */
static u16 USART_CalculateUBRR(void)
{
	/* Variable to hold the computed UBRR value */
	u16 ubrrValue;
	/* Local copy of CPU frequency */
	u32 fosc = F_CPU;
	/* Local copy of desired baud rate */
	u32 baud = USART_BAUDRATE;

	/* Check if asynchronous mode is selected */
	#if USART_MODE == USART_MODE_ASYNCHRONOUS
		/* Check if double speed mode is enabled */
		#if USART_DOUBLE_SPEED == USART_DOUBLE_SPEED_ENABLED
			/* BAUD = fOSC / (8 * (UBRR + 1)) */
			ubrrValue = (u16)((fosc / (8UL * baud)) - 1);
		#else
			/* BAUD = fOSC / (16 * (UBRR + 1)) */
			ubrrValue = (u16)((fosc / (16UL * baud)) - 1);
		#endif
	#else /* Synchronous */
		/* BAUD = fOSC / (2 * (UBRR + 1)) */
		ubrrValue = (u16)((fosc / (2UL * baud)) - 1);
	#endif

	/* Return the computed UBRR value */
	return ubrrValue;
}

/* Function: initialize USART with configured baud rate, frame format, and mode */
void USART_Init(void)
{
	/* Variable to hold the computed UBRR value */
	u16 ubrrValue;
	/* Local accumulator for UCSRC register value */
	u8 ucsrcValue = 0;
	/* Local accumulator for UCSRB register value */
	u8 ucsrbValue = 0;

	/* 1. Set baud rate */
	/* Compute the UBRR value from the configuration */
	ubrrValue = USART_CalculateUBRR();
	/* Write the high byte of UBRR */
	UBRRH = (u8)(ubrrValue >> 8);
	/* Write the low byte of UBRR */
	UBRRL = (u8)ubrrValue;

	/* 2. Set frame format */
	/* URSEL must be set to access UCSRC */
	SET_BIT(ucsrcValue, URSEL);

	/* Mode: Asynchronous or Synchronous */
	#if USART_MODE == USART_MODE_SYNCHRONOUS
		/* Set UMSEL bit to select synchronous mode */
		SET_BIT(ucsrcValue, UMSEL);
	#endif

	/* Parity */
	#if USART_PARITY == USART_PARITY_EVEN
		/* Enable even parity: UPM1 = 1, UPM0 = 0 */
		SET_BIT(ucsrcValue, UPM1);
	#elif USART_PARITY == USART_PARITY_ODD
		/* Enable odd parity: UPM1 = 1, UPM0 = 1 */
		SET_BIT(ucsrcValue, UPM0);
		/* Set UPM1 bit */
		SET_BIT(ucsrcValue, UPM1);
	#endif

	/* Stop Bits */
	#if USART_STOP_BITS == USART_STOP_2_BIT
		/* Set USBS bit to select two stop bits */
		SET_BIT(ucsrcValue, USBS);
	#endif

	/* Data Bits */
	#if USART_DATA_BITS == USART_DATA_5_BIT
		/* UCSZ1:0 = 00 */
	#elif USART_DATA_BITS == USART_DATA_6_BIT
		/* UCSZ1:0 = 01 */
		SET_BIT(ucsrcValue, UCSZ0);
	#elif USART_DATA_BITS == USART_DATA_7_BIT
		/* UCSZ1:0 = 10 */
		SET_BIT(ucsrcValue, UCSZ1);
	#elif USART_DATA_BITS == USART_DATA_8_BIT
		/* UCSZ1:0 = 11 */
		SET_BIT(ucsrcValue, UCSZ1);
		/* Set UCSZ0 bit */
		SET_BIT(ucsrcValue, UCSZ0);
	#elif USART_DATA_BITS == USART_DATA_9_BIT
		/* UCSZ1:0 = 11 */
		SET_BIT(ucsrcValue, UCSZ1);
		/* Set UCSZ0 bit */
		SET_BIT(ucsrcValue, UCSZ0);
		/* UCSZ2 is in UCSRB */
		SET_BIT(ucsrbValue, UCSZ2);
	#endif

	/* Clock Polarity (Synchronous only) */
	#if USART_MODE == USART_MODE_SYNCHRONOUS
		#if USART_CLOCK_POLARITY == USART_CPOL_FALLING
			/* Set UCPOL bit to select falling edge polarity */
			SET_BIT(ucsrcValue, UCPOL);
		#endif
	#endif

	/* Write the assembled value to UCSRC */
	UCSRC = ucsrcValue;

	/* 3. Enable receiver and transmitter */
	/* Enable the receiver */
	SET_BIT(ucsrbValue, RXEN);
	/* Enable the transmitter */
	SET_BIT(ucsrbValue, TXEN);
	/* Write the assembled value to UCSRB */
	UCSRB = ucsrbValue;

	/* 4. Double Speed mode (Asynchronous only) */
	#if USART_MODE == USART_MODE_ASYNCHRONOUS
		#if USART_DOUBLE_SPEED == USART_DOUBLE_SPEED_ENABLED
			/* Set U2X bit to enable double speed */
			SET_BIT(UCSRA, U2X);
		#endif
	#endif
}

/* Function: send a single character via USART (blocking/polling) */
void USART_SendChar(u8 Char)
{
	/* Wait for transmit buffer to be empty */
	while (!(GET_BIT(UCSRA, UDRE)));

	/* Put data into buffer and send */
	UDR = Char;
}

/* Function: receive a single character via USART (blocking/polling) */
u8 USART_ReceiveChar(void)
{
	/* Wait for data to be received */
	while (!(GET_BIT(UCSRA, RXC)));

	/* Return received data */
	return UDR;
}

/* Function: send a null-terminated string via USART (blocking/polling) */
void USART_SendString(u8 *String)
{
	/* Iterator for indexing into the string */
	u8 i = 0;

	/* Check for null pointer before dereferencing */
	if (String == NULL)
		/* Abort if the string pointer is invalid */
		return;

	/* Loop through each character until the null terminator is found */
	while (String[i] != '\0')
	{
		/* Send the current character */
		USART_SendChar(String[i]);
		/* Advance to the next character */
		i++;
	}
}
