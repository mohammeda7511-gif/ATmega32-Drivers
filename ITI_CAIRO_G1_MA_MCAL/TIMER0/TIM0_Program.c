/*
 * TIM0_Program.c
 *
 *  Created on: Sep 1, 2026
 *      Author: Mohammed Abdelrahman
 */


#include "../../ITI_CAIRO_G1_MA_LIB/BIT_MATH.h"
#include "../../ITI_CAIRO_G1_MA_LIB/STD_TYPES.h"
#include "TIM0_Private.h"
#include "TIM0_Interface.h"
#include "TIM0_Config.h"

static void (*CALL_BACK_FN)() = NULL;
static u8 g_prescaler = 0 ;

void TIM0_Init()
{
	/*Choosing the wave generation mode*/
#if TIM0_MODE == TIM0_WGM_NORMAL
	CLR_BIT(TCCR0,WGM00);
	CLR_BIT(TCCR0,WGM01);

#elif TIM0_MODE == TIM0_WGM_PHASE_PWM
	SET_BIT(TCCR0,WGM00);
	CLR_BIT(TCCR0,WGM01);

#elif TIM0_MODE == TIM0_WGM_CTC
	CLR_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);

#elif TIM0_MODE == TIM0_WGM_FAST_PWM
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);

#else
	#error "Wrong initialization for \"TIM0_MODE\"."
#endif


	/*Choosing the output compare mode*/
#if TIM0_MODE == TIM0_WGM_NORMAL || TIM0_MODE == TIM0_WGM_CTC
	/* Non-PWM mode */
	#if TIM0_NON_PWM == TIM0_N_NORMAL_PORT_OP
		CLR_BIT(TCCR0,COM00);
		CLR_BIT(TCCR0,COM01);
	#elif TIM0_NON_PWM == TIM0_N_TOGGLE_OC0
		SET_BIT(TCCR0,COM00);
		CLR_BIT(TCCR0,COM01);
	#elif TIM0_NON_PWM == TIM0_N_CLEAR_OC0
		CLR_BIT(TCCR0,COM00);
		SET_BIT(TCCR0,COM01);
	#elif TIM0_NON_PWM == TIM0_N_SET_OC0
		SET_BIT(TCCR0,COM00);
		SET_BIT(TCCR0,COM01);
	#else
		#error "Wrong initialization for \"TIM0_NON_PWM\"."
	#endif

#elif TIM0_MODE == TIM0_WGM_FAST_PWM
	/* Fast PWM mode */
	#if TIM0_FAST_PWM == TIM0_F_NORMAL_PORT_OP
		CLR_BIT(TCCR0,COM00);
		CLR_BIT(TCCR0,COM01);
	#elif TIM0_FAST_PWM == TIM0_F_CLEAR_OC0
		CLR_BIT(TCCR0,COM00);
		SET_BIT(TCCR0,COM01);
	#elif TIM0_FAST_PWM == TIM0_F_SET_OC0
		SET_BIT(TCCR0,COM00);
		SET_BIT(TCCR0,COM01);
	#else
		#error "Wrong initialization for \"TIM0_FAST_PWM\"."
	#endif

#elif TIM0_MODE == TIM0_WGM_PHASE_PWM
	/* Phase correct PWM mode */
	#if TIM0_phase_PWM == TIM0_P_NORMAL_PORT_OP
		CLR_BIT(TCCR0,COM00);
		CLR_BIT(TCCR0,COM01);
	#elif TIM0_phase_PWM == TIM0_P_CLEAR_OC0
		CLR_BIT(TCCR0,COM00);
		SET_BIT(TCCR0,COM01);
	#elif TIM0_phase_PWM == TIM0_P_SET_OC0
		SET_BIT(TCCR0,COM00);
		SET_BIT(TCCR0,COM01);
	#else
		#error "Wrong initialization for \"TIM0_phase_PWM\"."
	#endif

#else
	#error "Wrong initialization for \"TIM0_MODE\"."
#endif


	/*Choosing the prescaler*/
	#if    TIM0_PRESCALER >= TIM0_PRE_NO_CLOCK \
		&& TIM0_PRESCALER <= TIM0_PRE_EXT_RISING

		TCCR0 &= TIM0_PRESCALER_MSK;
		TCCR0 |= TIM0_PRESCALER;

	#else
		#error "Wrong initialization for \"TIM0_PRESCALER\"."
	#endif

	/*Enabling Overflow Interrupt*/
	#if TIM0_OV_INTERRUPT == TIM0_INT_ENABLE
		SET_BIT(TIMSK,TOIE0);
	#elif TIM0_OV_INTERRUPT == TIM0_INT_DISABLE
		CLR_BIT(TIMSK,TOIE0);
	#else
		#error "Wrong initialization for \"TIM0_OV_INTERRUPT\"."
	#endif

	/*Enabling Output Compare Interrupt*/
	#if TIM0_OC_INTERRUPT == TIM0_INT_ENABLE
		SET_BIT(TIMSK,OCIE0);
	#elif TIM0_OC_INTERRUPT == TIM0_INT_DISABLE
		CLR_BIT(TIMSK,OCIE0);
	#else
		#error "Wrong initialization for \"TIM0_OC_INTERRUPT\"."
	#endif
}

void TIM0_PRESCALER_CHANGE(u8 prescaler)
{
	if(prescaler >= TIM0_PRE_NO_CLOCK && prescaler <= TIM0_PRE_EXT_RISING)  //checking for the input validation
	{
		TCCR0 &= TIM0_PRESCALER_MSK;
		TCCR0 |= prescaler;

		g_prescaler = prescaler;
	}
}

void TIM0_ENABLE()
{
	TCCR0 &= TIM0_PRESCALER_MSK;
	TCCR0 |= g_prescaler;
}
void TIM0_DISABLE()
{
	TCCR0 &= TIM0_PRESCALER_MSK;
}


void TIM0_TIMER_REG_WRITE(u8 timer_input)
{
	if(timer_input >= 0 || timer_input <= 255)
	{
		TCNT0 = timer_input;
	}
}
u8 TIM0_TIMER_REG_READ()
{
	return TCNT0;
}


void TIM0_OC_REG_WRITE(u8 OC_input)
{
	if(OC_input >= 0 || OC_input <= 255)
	{
		OCR0 = OC_input;
	}
}
u8 TIM0_OC_REG_READ()
{
	return OCR0;
}


void TIM0_OV_CLEAR_FLAG ()
{
	SET_BIT(TIFR,TOV0);
}
void TIM0_OC_CLEAR_FLAG()
{
	SET_BIT(TIFR,OCF0);
}


void TIMER0_CALC_TIME(f32 time, u16 * overflow, u8 * ticks)
{
	u16 prescaler;

	switch (TIM0_PRESCALER)
	{
		case TIM0_PRE_1:
			prescaler = 1;
			break;
		case TIM0_PRE_8:
			prescaler = 8;
			break;
		case TIM0_PRE_64:
			prescaler = 64;
			break;
		case TIM0_PRE_256:
			prescaler = 256;
			break;
		case TIM0_PRE_1024:
			prescaler = 1024;
			break;
		default:
			*overflow = 0;
			*ticks = 0;
			return;
	}

	f32 temp = (time * (F_CPU / (f32)prescaler)) / TIM0_OVERFLOW;
	if(temp > (int)temp)
	{
		*overflow = (u16)temp + 1;
		*ticks = (u8)((1 - (temp - (int)temp)) * TIM0_OVERFLOW);
	}
	else
	{
		*overflow = (u16)temp;
		*ticks = 0;
	}
}


void TIM0_CALL_BACK_LINKER (void(*ptr)())
{
	CALL_BACK_FN = ptr;
}

void __vector_11(void) __attribute__((signal,used));
void __vector_11(void)
{
	if(CALL_BACK_FN != NULL)
	{
		CALL_BACK_FN ();
	}
}
