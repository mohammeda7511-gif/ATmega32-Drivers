/*
 * EEPROM_Interface.h
 *
 *  Created on: Sep 9, 2026
 *      Author: Mohammed Abdelrahman
 */

/* Header guard to prevent multiple inclusion */
#ifndef ITI_CAIRO_G1_MA_MCAL_EEPROM_EEPROM_INTERFACE_H_
#define ITI_CAIRO_G1_MA_MCAL_EEPROM_EEPROM_INTERFACE_H_

/* Include standard type definitions (u8, u16, etc.) */
#include "../../ITI_CAIRO_G1_MA_LIB/STD_TYPES.h"

/* Char */
/* Write a single byte to the given EEPROM address */
void EEPROM_write(u16 uiAddress, u8 ucData);
/* Read a single byte from the given EEPROM address */
u8 EEPROM_read(u16 uiAddress);

/* String */
/* Write a null-terminated string starting at the given EEPROM address */
void EEPROM_WriteString(u8 address, u8 *data);
/* Read a null-terminated string from EEPROM into the given buffer */
void EEPROM_ReadString(u8 address, u8 *ptr);

/* Numbers */
/* Write a numeric byte value to the given EEPROM address */
void EEPROM_WriteNumber(u8 address, u8 data);
/* Read a numeric byte value from the given EEPROM address */
u8 EEPROM_ReadNumber(u8 address);

#endif /* ITI_CAIRO_G1_MA_MCAL_EEPROM_EEPROM_INTERFACE_H_ */
