/*
 * TIM0_Config.h
 *
 *  Created on: Sep 1, 2026
 *      Author: Mohammed Abdelrahman
 */

#ifndef ITI_CAIRO_G1_MA_MCAL_TIMER0_TIM0_CONFIG_H_
#define ITI_CAIRO_G1_MA_MCAL_TIMER0_TIM0_CONFIG_H_

#include "TIM0_Private.h"
#include "TIM0_Interface.h"


/*
* Timer 0 mode options:
*1- TIM0_MODE_NORMAL
*2- TIM0_MODE_PHASE_PWM
*3- TIM0_MODE_CTC
*4- TIM0_MODE_FAST_PWM
 */
#define TIM0_MODE			TIM0_WGM_NORMAL

/*
 * Non-PWM mode options:
*1- TIM0_N_NORMAL_PORT_OP
*2- TIM0_N_TOGGLE_OC0
*3- TIM0_N_CLEAR_OC0
*4- TIM0_N_SET_OC0
*/
#define TIM0_NON_PWM        TIM0_N_NORMAL_PORT_OP

/*
 * Non-PWM mode options:
*1- TIM0_F_NORMAL_PORT_OP
*2- TIM0_F_TOGGLE_OC0
*3- TIM0_F_CLEAR_OC0
*4- TIM0_F_SET_OC0
*/
#define TIM0_FAST_PWM       TIM0_F_NORMAL_PORT_OP

/*
* Non-PWM mode options:
*1- TIM0_P_NORMAL_PORT_OP
*2- TIM0_P_TOGGLE_OC0
*3- TIM0_P_CLEAR_OC0
*4- TIM0_P_SET_OC0
*/
#define TIM0_phase_PWM      TIM0_P_NORMAL_PORT_OP

/*
 * Prescaler and clock options:
 * 1- TIM0_PRE_NO_CLOCK
 * 2- TIM0_PRE_1
 * 3- TIM0_PRE_8
 * 4- TIM0_PRE_64
 * 5- TIM0_PRE_256
 * 6- TIM0_PRE_1024
 * 7- TIM0_PRE_EXT_FALLING
 * 8- TIM0_PRE_EXT_RISING
 */
#define TIM0_PRESCALER      TIM0_PRE_NO_CLOCK

#define TIM0_OV_INTERRUPT   TIM0_INT_ENABLE
#define TIM0_OC_INTERRUPT   TIM0_INT_DISABLE

#endif /* ITI_CAIRO_G1_MA_MCAL_TIMER0_TIM0_CONFIG_H_ */
