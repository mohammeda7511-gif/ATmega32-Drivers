/*
 * GIE_Interface.h
 *
 *  Created on: Aug 30, 2026
 *      Author: Mohammed Abdelrahman
 */

/* Header guard to prevent multiple inclusion */
#ifndef ITI_CAIRO_G1_MA_MCAL_GIE_GIE_INTERFACE_H_
#define ITI_CAIRO_G1_MA_MCAL_GIE_GIE_INTERFACE_H_

/* Enable global interrupts (set the I bit in SREG) */
void GIE_Enable();
/* Disable global interrupts (clear the I bit in SREG) */
void GIE_Disable();

#endif /* ITI_CAIRO_G1_MA_MCAL_GIE_GIE_INTERFACE_H_ */
