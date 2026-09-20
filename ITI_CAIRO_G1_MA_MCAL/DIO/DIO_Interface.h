/*
 * DIO_Interface.h
 *
 *  Created on: Aug 25, 2026
 *      Author: Mohammed Abdelrahman
 */


/* Header guard to prevent multiple inclusion */
#ifndef ITI_CAIRO_G1_MA_MCAL_DIO_DIO_INTERFACE_H_
#define ITI_CAIRO_G1_MA_MCAL_DIO_DIO_INTERFACE_H_

/* Include standard type definitions (u8, etc.) */
#include "../../ITI_CAIRO_G1_MA_LIB/STD_TYPES.h"
#include "DIO_Private.h"

/* Set the direction of a single pin (input, output, or pull-up) */
void DIO_SetPinDirection(u8 u8_port,u8 pin,u8 dir);
/* Set the direction of an entire port (input, output, or pull-up) */
void DIO_SetPortDirection(u8 u8_port,u8 dir);

/* Read the current logic level of all pins on a port */
u8 DIO_GetPortValue(u8 u8_port);
/* Read the current logic level of a single pin */
u8 DIO_GetPinValue(u8 u8_port,u8 pin);

/* Write an 8-bit value to an entire port */
void DIO_SetPortValue(u8 u8_port,u8 value);
/* Write a logic level to a single pin */
void DIO_SetPinValue(u8 u8_port,u8 u8_pin,u8 value);

/* Toggle the logic level of a single pin */
void DIO_TogglePinValue(u8 u8_port,u8 pin);
/* Toggle the logic level of all pins on a port */
void DIO_TogglePortValue(u8 port);

#endif /* ITI_CAIRO_G1_MA_MCAL_DIO_DIO_INTERFACE_H_ */
