/*
 * ADC_Interface.h
 *
 *  Created on: Sep 1, 2026
 *      Author: Mohammed Abdelrahman
 */

#ifndef ITI_CAIRO_G1_MA_MCAL_ADC_ADC_INTERFACE_H_
#define ITI_CAIRO_G1_MA_MCAL_ADC_ADC_INTERFACE_H_

#include "../../ITI_CAIRO_G1_MA_LIB/STD_TYPES.h"
#include "ADC_Private.h"

/*Initialization*/
void ADC_Init();

/* Start Conversion */
void ADC_OnlyStartConversion(u8 channel);

u8 ADC_OnlyRead();

u16 ADC_Read10Bits(u8 channel);

u8 ADC_Read8Bits(u8 channel);

void ADC_Enable();

void ADC_Disable();

void ADC_AutoTriggerEnable();

void ADC_AutoTriggerDisable();

void ADC_InterruptEnable();

void ADC_InterruptDisable();

#endif /* ITI_CAIRO_G1_MA_MCAL_ADC_ADC_INTERFACE_H_ */
