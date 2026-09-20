/*
 * ADC_Config.h
 *
 *  Created on: Sep 1, 2026
 *      Author: Mohammed Abdelrahman
 */

#ifndef ITI_CAIRO_G1_MA_MCAL_ADC_ADC_CONFIG_H_
#define ITI_CAIRO_G1_MA_MCAL_ADC_ADC_CONFIG_H_

/*
 * ADC reference options:
 * 1 - ADC_EXTERNAL		   -> connect it to AREF
 * 2 - ADC_INTERNAL_VCC    -> you must add a capacitor at AREF pin
 * 3 - ADC_INTERNAL_2_56V  -> you must add a capacitor at AREF pin
 */
#define ADC_REF_MODE		    ADC_INTERNAL_VCC  // <- Change this to your mode

/*
 * ADC adjustment options:
 * 1- ADC_RIGHT            -> The most significant bit is at ADCH
 * 2- ADC_LEFT             -> The most significant bit is at ADCL
 */
#define ADC_ADJUST_RESULT		ADC_RIGHT

/*
 * ADC channel selection options: -> choose which channel you connect your source on
 * 1- ADC_PIN0
 * 2- ADC_PIN1
 * 3- ADC_PIN2
 * 4- ADC_PIN3
 * 5- ADC_PIN4
 * 6- ADC_PIN5
 * 7- ADC_PIN6
 * 8- ADC_PIN7
 *
 * Differential ADC: -> you can use the difference between two ADC channels
 * 9-  ADC_DIFF_10_0_0  -> (ADC0 - ADC0) * 10
 * 10- ADC_DIFF_10_1_0  -> (ADC1 - ADC0) * 10
 * 11- ADC_DIFF_10_2_2  -> (ADC2 - ADC2) * 10
 * 12- ADC_DIFF_10_3_2  -> (ADC3 - ADC2) * 10
 * 13- ADC_DIFF_200_0_0 -> (ADC0 - ADC0) * 200
 * 14- ADC_DIFF_200_1_0 -> (ADC1 - ADC0) * 200
 * 15- ADC_DIFF_200_2_2 -> (ADC2 - ADC2) * 200
 * 16- ADC_DIFF_200_3_2 -> (ADC3 - ADC2) * 200
 * 17- ADC_DIFF_1_0_1   -> (ADC0 - ADC1) * 1
 * 18- ADC_DIFF_1_1_1   -> (ADC1 - ADC1) * 1
 * 19- ADC_DIFF_1_2_1   -> (ADC2 - ADC1) * 1
 * 20- ADC_DIFF_1_3_1   -> (ADC3 - ADC1) * 1
 * 21- ADC_DIFF_1_4_1   -> (ADC4 - ADC1) * 1
 * 22- ADC_DIFF_1_5_1   -> (ADC5 - ADC1) * 1
 * 23- ADC_DIFF_1_6_1   -> (ADC6 - ADC1) * 1
 * 24- ADC_DIFF_1_7_1   -> (ADC7 - ADC1) * 1
 * 25- ADC_DIFF_1_0_2   -> (ADC0 - ADC2) * 1
 * 26- ADC_DIFF_1_1_2   -> (ADC1 - ADC2) * 1
 * 27- ADC_DIFF_1_2_2   -> (ADC2 - ADC2) * 1
 * 28- ADC_DIFF_1_3_2   -> (ADC3 - ADC2) * 1
 * 29- ADC_DIFF_1_4_2   -> (ADC4 - ADC2) * 1
 * 30- ADC_DIFF_1_5_2   -> (ADC5 - ADC2) * 1
 *
 * ADC check options:   -> set it and see the reading of ADC then check its accuracy
 * 31- ADC_1_22_CHECK   -> Internal 1.22V bandgap reference (use to calculate actual VCC)
 * 32- ADC_GND_CHECK    -> Internal GND (use to measure and subtract offset error)
 */
#define ADC_CHANNEL				ADC_PIN0

/*
 * ADC Modes:
 * 1- ADC_SINGLE_CONVERSION      -> Manually trigger each reading
 * 2- ADC_TRIGGER_MODE           -> Automatically trigger readings using flags
 */
#define ADC_MODE                ADC_SINGLE_CONVERSION

/*
 * ADC prescalar options:
 * 1- ADC_PRESCALAR_DEFAULT  -> 2
 * 2- ADC_PRESCALAR_2		  -> 2
 * 3- ADC_PRESCALAR_4		  -> 4
 * 4- ADC_PRESCALAR_8		  -> 8
 * 5- ADC_PRESCALAR_16		  -> 16
 * 6- ADC_PRESCALAR_32		  -> 32
 * 7- ADC_PRESCALAR_64		  -> 64
 * 8- ADC_PRESCALAR_128	  -> 128
 */
#define ADC_PRESCALAR			ADC_PRESCALAR_DEFAULT

/*
 * ADC trigger mode options
 * 1- ADC_TRIGGER_FREE_RUNNING     -> Free Running mode (continuous conversion)                                 ADTS = 000
 * 2- ADC_TRIGGER_ANALOG_COMP      -> Trigger on Analog Comparator output change                                 ADTS = 001
 * 3- ADC_TRIGGER_EXT_INT0         -> Trigger on External Interrupt 0 (INT0 pin)                                 ADTS = 010
 * 4- ADC_TRIGGER_TIMER0_COMP      -> Trigger on Timer0 Compare Match (OCR0)                                     ADTS = 011
 * 5- ADC_TRIGGER_TIMER0_OVF       -> Trigger on Timer0 Overflow                                                 ADTS = 100
 * 6- ADC_TRIGGER_TIMER1_COMPB     -> Trigger on Timer1 Compare Match B (OCR1B)                                  ADTS = 101
 * 7- ADC_TRIGGER_TIMER1_OVF       -> Trigger on Timer1 Overflow                                                 ADTS = 110
 * 8- ADC_TRIGGER_TIMER1_CAPT      -> Trigger on Timer1 Capture Event (ICP1 pin)                                 ADTS = 111
 */
#define ADC_TRIG_MODE           ADC_TRIGGER_FREE_RUNNING

/*
 * ADC interrupt:
 * 1- ADC_INTERRUPT_ENABLE
 * 2- ADC_INTERRUPT_DISABLE
 */
#define ADC_INTERRUPT_STATUS    ADC_INTERRUPT_ENABLE

#endif /* ITI_CAIRO_G1_MA_MCAL_ADC_ADC_CONFIG_H_ */
