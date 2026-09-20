/*
 * EXTI_Interface.h
 *
 *  Created on: Aug 31, 2026
 *      Author: Mohammed Abdelrahman
 */

/* Header guard to prevent multiple inclusion */
#ifndef ITI_CAIRO_G1_MA_MCAL_EXTI_EXTI_INTERFACE_H_
#define ITI_CAIRO_G1_MA_MCAL_EXTI_EXTI_INTERFACE_H_

/* Include standard type definitions (u8, etc.) */
#include "../../ITI_CAIRO_G1_MA_LIB/STD_TYPES.h"

/* Enable the specified external interrupt */
void EXTI_Enable(u8 exti_id);
/* Disable the specified external interrupt */
void EXTI_Disable(u8 exti_id);
/* Configure the sense (trigger) control for the specified external interrupt */
void EXTI_SenseControl(u8 exti_id, u8 sense);

#endif /* ITI_CAIRO_G1_MA_MCAL_EXTI_EXTI_INTERFACE_H_ */
