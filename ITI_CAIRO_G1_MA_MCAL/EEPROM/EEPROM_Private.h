/*
 * EEPROM_Private.h
 *
 *  Created on: Sep 9, 2026
 *      Author: Mohammed Abdelrahman
 */

/* Header guard to prevent multiple inclusion */
#ifndef ITI_CAIRO_G1_MA_MCAL_EEPROM_EEPROM_PRIVATE_H_
#define ITI_CAIRO_G1_MA_MCAL_EEPROM_EEPROM_PRIVATE_H_

/* Include standard type definitions (u8, u16, etc.) */
#include "../../ITI_CAIRO_G1_MA_LIB/STD_TYPES.h"

/* Used Registers */
/* EEPROM High Address Register */
#define EEARH							 (*(volatile u8 *)0x3F)
/* EEPROM Low Address Register */
#define EEARL						 	 (*(volatile u8 *)0x3E)
/* EEPROM Data Register */
#define EEDR							 (*(volatile u8 *)0x3D)
/* EEPROM Control Register */
#define EECR							 (*(volatile u8 *)0x3C)
/* EEPROM Address Register (16-bit combined access) */
#define EEAR							 (*(volatile u16 *)0x3E)

/* Used Pins */
/* EEPROM Ready Interrupt Enable bit position in EECR */
#define EERIE 							 3
/* EEPROM Master Write Enable bit position in EECR */
#define EEMWE 							 2
/* EEPROM Write Enable bit position in EECR */
#define EEWE 							 1
/* EEPROM Read Enable bit position in EECR */
#define EERE 							 0

/* Interrupt Options */
/* Value to disable EEPROM ready interrupt */
#define EEPROM_READY_INTERRUPT_DISABLE   0
/* Value to enable EEPROM ready interrupt */
#define EEPROM_READY_INTERRUPT_ENABLE    1

/* NULL definition */
/* Generic null pointer constant */
#define NULL 							 ((void *)0)

#endif /* ITI_CAIRO_G1_MA_MCAL_EEPROM_EEPROM_PRIVATE_H_ */
