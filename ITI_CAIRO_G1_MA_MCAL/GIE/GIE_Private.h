/*
 * GIE_Private.h
 *
 *  Created on: Aug 30, 2026
 *      Author: Mohammed Abdelrahman
 */

/* Header guard to prevent multiple inclusion */
#ifndef ITI_CAIRO_G1_MA_MCAL_GIE_GIE_PRIVATE_H_
#define ITI_CAIRO_G1_MA_MCAL_GIE_GIE_PRIVATE_H_

/* Include standard type definitions (u8, etc.) */
#include "../../ITI_CAIRO_G1_MA_LIB/STD_TYPES.h"

/* Status Register (contains the global interrupt enable bit) */
#define SREG (*(volatile u8 *)0x5F)
/* Bit position of the global interrupt enable flag in SREG */
#define I    7

#endif /* ITI_CAIRO_G1_MA_MCAL_GIE_GIE_PRIVATE_H_ */
