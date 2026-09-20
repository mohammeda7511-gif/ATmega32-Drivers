/*
 * TIM0_Interface.h
 *
 *  Created on: Sep 1, 2026
 *      Author: Mohammed Abdelrahman
 */

#ifndef ITI_CAIRO_G1_MA_MCAL_TIMER0_TIM0_INTERFACE_H_
#define ITI_CAIRO_G1_MA_MCAL_TIMER0_TIM0_INTERFACE_H_

#include "TIM0_Private.h"
#include "TIM0_Config.h"


/*Initialization*/
void TIM0_Init();

/*Prescaler*/
void TIM0_PRESCALER_CHANGE(u8 prescaler);

/*Status*/
void TIM0_ENABLE();
void TIM0_DISABLE();

/*Timer writing and reading*/
void TIM0_TIMER_REG_WRITE(u8 timer_input);
u8 TIM0_TIMER_REG_READ();

/*OC writing and reading*/
void TIM0_OC_REG_WRITE(u8 OC_input);
u8 TIM0_OC_REG_READ();

/*Flags clear*/
void TIM0_OV_CLEAR_FLAG ();
void TIM0_OC_CLEAR_FLAG();

/*Time calculation*/
void TIM0_CALC_TIME(f32 time, u16 * overflow, u8 * ticks);

/*Call back for interrupt*/
void TIM0_CALL_BACK_LINKER (void(*ptr)());

#endif /* ITI_CAIRO_G1_MA_MCAL_TIMER0_TIM0_INTERFACE_H_ */
