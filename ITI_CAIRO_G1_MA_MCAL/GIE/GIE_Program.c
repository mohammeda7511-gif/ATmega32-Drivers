/*
 * GIE_Program.c
 *
 *  Created on: Aug 30, 2026
 *      Author: Mohammed Abdelrahman
 */

/* Include bit manipulation macros (SET_BIT, CLR_BIT, GET_BIT, TOG_BIT) */
#include "../../ITI_CAIRO_G1_MA_LIB/BIT_MATH.h"
/* Include standard type definitions (u8, etc.) */
#include "../../ITI_CAIRO_G1_MA_LIB/STD_TYPES.h"
/* Include GIE interface header for function prototypes */
#include "GIE_Interface.h"
/* Include GIE private header for register addresses and macros */
#include "GIE_Private.h"
/* Include GIE configuration header */
#include "GIE_Config.h"

/* Function: enable global interrupts */
void GIE_Enable()
{
	/* Set the I bit in SREG to enable global interrupts */
	SET_BIT(SREG, I);
}

/* Function: disable global interrupts */
void GIE_Disable()
{
	/* Clear the I bit in SREG to disable global interrupts */
	CLR_BIT(SREG, I);
}
