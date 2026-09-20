/*
 * ADC_Program.c
 *
 *  Created on: Sep 1, 2026
 *      Author: Mohammed Abdelrahman
 */

#include "../../ITI_CAIRO_G1_MA_LIB/STD_TYPES.h"
#include "../../ITI_CAIRO_G1_MA_LIB/BIT_MATH.h"
#include "../../ITI_CAIRO_G1_MA_MCAL/DIO/DIO_Interface.h"
#include "ADC_Interface.h"
#include "ADC_Private.h"
#include "ADC_Config.h"

void ADC_Init()
{
	/* Check for reference*/
#if ADC_REF_MODE == ADC_EXTERNAL
	CLR_BIT(ADMUX, REFS0);
	CLR_BIT(ADMUX, REFS1);

#elif ADC_REF_MODE == ADC_INTERNAL_VCC
	SET_BIT(ADMUX, REFS0);
	CLR_BIT(ADMUX, REFS1);

#elif ADC_REF_MODE == ADC_INTERNAL_2_56V
	SET_BIT(ADMUX, REFS0);
	SET_BIT(ADMUX, REFS1);

#else
    #error "Wrong initialization for \"ADC_REF_MODE\"."
#endif

	/*Check for adjustment*/
#if ADC_ADJUST_RESULT == ADC_RIGHT
	CLR_BIT(ADMUX, ADLAR);

#elif ADC_ADJUST_RESULT == ADC_LEFT
	SET_BIT(ADMUX, ADLAR);

#else
 #error "Wrong initialization for \"ADC_ADJUST_RESULT\"."
#endif

	/*Prescalar*/

	/* Clear the prescaler bits */
	ADCSRA &= ADC_PRESCALAR_CLEAR;
	/* Set the prescaler value */
	ADCSRA |= ADC_PRESCALAR;

	/* Check for ADC mode */
#if ADC_MODE == ADC_SINGLE_CONVERSION
	CLR_BIT(ADCSRA, ADATE);

#elif ADC_MODE == ADC_TRIGGER_MODE
	/*Trigger mode will be enabled after choosing the mode*/
	CLR_BIT(ADCSRA, ADATE);
	SFIOR &= ADC_TRIGGER_MODE_CLEAR;
	SFIOR |= ADC_TRIG_MODE;
	SET_BIT(ADCSRA, ADATE);

#else
	#error "Wrong initialization for \"ADC_MODE\"."
#endif

	/*Enable ADC*/
	SET_BIT(ADCSRA, ADEN);

	/*Check for global interrupt*/
#if ADC_INTERRUPT_STATUS == ADC_INTERRUPT_DISABLE
	CLR_BIT(ADCSRA, ADIE);

#elif ADC_INTERRUPT_STATUS == ADC_INTERRUPT_ENABLE
	/*clear interrupt flag*/
	SET_BIT(ADCSRA, ADIF);

	SET_BIT(ADCSRA, ADEN);
	SET_BIT(SREG, I);
#else
 #error "Wrong initialization for \"ADC_INTERRUPT_STATUS\"."
#endif
}

void ADC_OnlyStartConversion(u8 channel)
{
	ADMUX &= ADC_CHANNEL_CLEAR;
	ADMUX |= channel;

	SET_BIT(ADCSRA, ADSC);
}

u8 ADC_OnlyRead()
{
#if ADC_COUNTOUT != ADC_WAIT_FOREVER
	volatile u16 ADC_Counter = 0;

	while (GET_BIT(ADCSRA, ADSC) && ADC_Counter < ADC_COUNTOUT)
	{
		ADC_Counter++;
	}

	if(ADC_Counter < ADC_COUNTOUT)
	{
#if ADC_ADJUST_RESULT == ADC_RIGHT
		return ADC;

#elif ADC_ADJUST_RESULT == ADC_LEFT
		return ADC_HIGH
#endif
	}
	else
	{
		return 0;
	}
#else
	/* Waiting until the conversion is complete */
	while (GET_BIT(ADCSRA, ADSC));

	/* Return the 10 bits in any adjust mode */
	#if   ADC_ADJUST_RESULT == ADC_RIGHT

		/* Return the 10 bits */
		return ADC_DATA;

	#elif ADC_ADJUST_RESULT == ADC_LEFT

		/* Return the 8 bits */
		return ADC_HIGH;

	#endif

#endif
}

u16 ADC_Read10Bits(u8 channel)
{
	ADC_OnlyStartConversion(channel);
#if ADC_ADJUST_RESULT == ADC_RIGHT
	return ADC_OnlyRead();

#elif ADC_ADJUST_RESULT == ADC_LEFT
	return (ADC_OnlyRead() << 2);
#endif
}

u8 ADC_Read8Bits(u8 channel)
{
	ADC_OnlyStartConversion(channel);
#if ADC_ADJUST_RESULT == ADC_RIGHT
	return (ADC_OnlyRead() >> 2);

#elif ADC_ADJUST_RESULT == ADC_LEFT
	return ADC_OnlyRead();

#endif
}

void ADC_Enable()
{
	SET_BIT(ADCSRA, ADEN);
}

void ADC_Disable()
{
	CLR_BIT(ADCSRA, ADEN);
}

void ADC_AutoTriggerEnable()
{
	SFIOR &= ADC_AUTO_TRIG_CLEAR;
	SFIOR |= ADC_TRIG_MODE;
	SET_BIT(ADCSRA, ADATE);
}

void ADC_AutoTriggerDisable()
{
	CLR_BIT(ADCSRA, ADATE);
}

void ADC_InterruptEnable()
{
	SET_BIT(ADCSRA, ADIE);
}

void ADC_InterruptDisable()
{
	CLR_BIT(ADCSRA, ADIE);
}
