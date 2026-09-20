/*
 * ADC_Private.h
 *
 *  Created on: Sep 1, 2026
 *      Author: Mohammed Abdelrahman
 */

#ifndef ITI_CAIRO_G1_MA_MCAL_ADC_ADC_PRIVATE_H_
#define ITI_CAIRO_G1_MA_MCAL_ADC_ADC_PRIVATE_H_

#include "../../ITI_CAIRO_G1_MA_MCAL/DIO/DIO_Interface.h"
#include "../../ITI_CAIRO_G1_MA_MCAL/DIO/DIO_Private.h"

#define ADC_PORT				PORTA

// Channels
/*Input*/
#define ADC_PIN0  				0
#define ADC_PIN1  				1
#define ADC_PIN2  				2
#define ADC_PIN3  				3
#define ADC_PIN4  				4
#define ADC_PIN5  				5
#define ADC_PIN6 				6
#define ADC_PIN7  				7
/*Differential*/
#define ADC_DIFF_10_0_0         8
#define ADC_DIFF_10_1_0         9
#define ADC_DIFF_10_2_2         12
#define ADC_DIFF_10_3_2         13
#define ADC_DIFF_200_0_0        10
#define ADC_DIFF_200_1_0        11
#define ADC_DIFF_200_2_2        14
#define ADC_DIFF_200_3_2        15
#define ADC_DIFF_1_0_1          16
#define ADC_DIFF_1_1_1          17
#define ADC_DIFF_1_2_1          18
#define ADC_DIFF_1_3_1          19
#define ADC_DIFF_1_4_1          20
#define ADC_DIFF_1_5_1          21
#define ADC_DIFF_1_6_1          22
#define ADC_DIFF_1_7_1          23
#define ADC_DIFF_1_0_2          24
#define ADC_DIFF_1_1_2          25
#define ADC_DIFF_1_2_2          26
#define ADC_DIFF_1_3_2          27
#define ADC_DIFF_1_4_2          28
#define ADC_DIFF_1_5_2          29
/*Check*/
#define ADC_1_22_CHECK          30
#define ADC_GND_CHECK           31

#define ADC_CHANNEL_CLEAR		0x1F  // -> when ANDed with ADMUX will clear the mux pins

#define ADC_EXTERNAL            0
#define ADC_INTERNAL_VCC        1
#define ADC_INTERNAL_2_56V      2

#define ADC_RIGHT 				0
#define ADC_LEFT 				1

#define ADMUX   	    		(*(volatile u8 *)0x27)
#define ADCSRA    				(*(volatile u8 *)0x26)
#define ADC_DATA  				(*(volatile u16 *)0x24)
#define ADC_LOW   				(*(volatile u8 *)0x24)
#define ADC_HIGH  				(*(volatile u8 *)0x25)
#define SFIOR     				(*(volatile u8 *)0x50)
#define SREG					(*(volatile u8 *)0x5F)

#define MUX0	 		 		DIO_PIN0
#define MUX1 			 		DIO_PIN1
#define MUX2  			 		DIO_PIN2
#define MUX3  			 		DIO_PIN3
#define MUX4  	         		DIO_PIN4
#define ADLAR   		 		DIO_PIN5
#define REFS0     		 		DIO_PIN6
#define REFS1    		 		DIO_PIN7

#define ADPS0  	 		 		DIO_PIN0
#define ADPS1    		 		DIO_PIN1
#define ADPS2    		 		DIO_PIN2
#define ADIE     		 		DIO_PIN3
#define ADIF     		 		DIO_PIN4
#define ADATE  	 		 		DIO_PIN5
#define ADSC     		 		DIO_PIN6
#define ADEN     		 		DIO_PIN7

#define ADTS0					DIO_PIN5
#define ADTS1					DIO_PIN6
#define ADTS2					DIO_PIN7

#define ADC_PRESCALAR_CLEAR		0xF8 // 0b1111 1000 -> if ANDed with ADCSRA will reset prescalar pins
#define ADC_PRESCALAR_DEFAULT   0
#define ADC_PRESCALAR_2		    1
#define ADC_PRESCALAR_4		    2
#define ADC_PRESCALAR_8		    3
#define ADC_PRESCALAR_16	    4
#define ADC_PRESCALAR_32	    5
#define ADC_PRESCALAR_64	    6
#define ADC_PRESCALAR_128	    7

#define ADC_SINGLE_CONVERSION   0
#define ADC_TRIGGER_MODE        1

/*As ADTS bits are 7, 6 and 5, the value to be put in their register is shifted*/
#define ADC_TRIGGER_FREE_RUNNING    0x00      // ADTS = 000: Free Running (continuous)
#define ADC_TRIGGER_ANALOG_COMP     0x20      // ADTS = 001: Analog Comparator
#define ADC_TRIGGER_EXT_INT0        0x40      // ADTS = 010: External Interrupt 0
#define ADC_TRIGGER_TIMER0_COMP     0x60      // ADTS = 011: Timer0 Compare Match   (only one compare for timer 0)
#define ADC_TRIGGER_TIMER0_OVF      0x80      // ADTS = 100: Timer0 Overflow
#define ADC_TRIGGER_TIMER1_COMPB    0xA0      // ADTS = 101: Timer1 Compare Match B (not A)
#define ADC_TRIGGER_TIMER1_OVF      0xC0      // ADTS = 110: Timer1 Overflow
#define ADC_TRIGGER_TIMER1_CAPT     0xE0      // ADTS = 111: Timer1 Capture Event
#define ADC_TRIGGER_MODE_CLEAR      0x1F      // Will be ANDed with the register to set ADTS bits to zeros

#define ADC_INTERRUPT_ENABLE    0
#define ADC_INTERRUPT_DISABLE   1

#define I                       7      // From the datasheet, the bit that enables interrupt is called I

#endif /* ITI_CAIRO_G1_MA_MCAL_ADC_ADC_PRIVATE_H_ */
