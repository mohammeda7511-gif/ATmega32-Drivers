/*
 * TIM0_Private.h
 *
 *  Created on: Sep 1, 2026
 *      Author: Mohammed Abdelrahman
 */

#ifndef ITI_CAIRO_G1_MA_MCAL_TIMER0_TIM0_PRIVATE_H_
#define ITI_CAIRO_G1_MA_MCAL_TIMER0_TIM0_PRIVATE_H_

#include "../../ITI_CAIRO_G1_MA_LIB/STD_TYPES.h"
#include "TIM0_Interface.h"
#include "TIM0_Config.h"

/*Required pins addresses*/
#define TCCR0                  (*(volatile u8 *)0x53)
#define TCNT0                  (*(volatile u8 *)0x52)
#define OCR0                   (*(volatile u8 *)0x5C)
#define TIMSK                  (*(volatile u8 *)0x59)
#define TIFR                   (*(volatile u8 *)0x58)
#define NULL 				   ((void*)0)

/*Wave generation modes*/
#define TIM0_WGM_NORMAL		   0
#define TIM0_WGM_PHASE_PWM     1
#define TIM0_WGM_CTC    	   2
#define TIM0_WGM_FAST_PWM	   3


/*Compare output mode, non-PWM*/
#define TIM0_N_NORMAL_PORT_OP  0    // -> OC0 disconnected
#define TIM0_N_TOGGLE_OC0	   1
#define TIM0_N_CLEAR_OC0	   2
#define TIM0_N_SET_OC0	       3

/*Compare output mode, fast PWM*/
#define TIM0_F_NORMAL_PORT_OP  0    // -> OC0 disconnected
#define TIM0_F_CLEAR_OC0	   2	// -> 1 is reserved
#define TIM0_F_SET_OC0	       3

/*Compare output mode, phase correct PWM*/
#define TIM0_P_NORMAL_PORT_OP  0    // -> OC0 disconnected
#define TIM0_P_CLEAR_OC0	   2	// -> 1 is reserved
#define TIM0_P_SET_OC0	       3

/*TCCR0 pins*/
#define CS00                   0
#define CS01                   1
#define CS02                   2
#define WGM01                  3
#define COM00                  4
#define COM01                  5
#define WGM00                  6
#define FOC0				   7

/*TIMSK pins*/
#define TOIE0				   0
#define OCIE0				   1

/*TIFR pins*/
#define TOV0				   0
#define OCF0				   1

/*Overflow number*/
#define TIM0_OVERFLOW		   256

/*Interrupt*/
#define TIM0_INT_DISABLE       0
#define TIM0_INT_ENABLE        1

/*Prescaler mask*/
#define TIM0_PRESCALER_MSK   0xF8

/*Prescaler options*/
#define TIM0_PRE_NO_CLOCK      0
#define TIM0_PRE_1             1
#define TIM0_PRE_8             2
#define TIM0_PRE_64            3
#define TIM0_PRE_256           4
#define TIM0_PRE_1024          7
#define TIM0_PRE_EXT_FALLING   6
#define TIM0_PRE_EXT_RISING    7

#endif /* ITI_CAIRO_G1_MA_MCAL_TIMER0_TIM0_PRIVATE_H_ */
