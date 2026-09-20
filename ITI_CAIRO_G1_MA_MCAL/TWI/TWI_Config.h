/*
 * TWI_Config.h
 *
 *  Created on: Sep 12, 2026
 *      Author: Mohammed Abdelrahman
 */

#ifndef ITI_CAIRO_G1_MA_MCAL_TWI_TWI_CONFIG_H_
#define ITI_CAIRO_G1_MA_MCAL_TWI_TWI_CONFIG_H_


/* TWI Clock Frequency Options:
 * 1- TWI_CLOCK_FREQ_100MHZ
 * 2- TWI_CLOCK_FREQ_400MHZ
 * */
#define TWI_SCL_FREQ					TWI_SCL_FREQ_100MHZ

/* TWI Interrupt Options:
 * 1- TWI_INTERRUPT_DISABLE
 * 2- TWI_INTERRUPT_ENABLE
 */
#define TWI_INTERRUPT					TWI_INTERRUPT_DISABLE

/*TWI Prescaler Options:
 * 1- TWI_PRESCALER_1
 * 2- TWI_PRESCALER_4
 * 3- TWI_PRESCALER_16
 * 4- TWI_PRESCALER_64
 * */
#define TWI_PRESCALER					TWI_PRESCALER_1

/* TWI General Call Options:
 * 1- TWI_GENERAL_CALL_ENABLE
 * 2- TWI_GENERAL_CALL_DISABLE
 * */
#define TWI_GENERAL_CALL				TWI_GENERAL_CALL_ENABLE

/* Address of the device
 * this is the address used for the device to response
 * when a master call or during general call if enabled */
#define TWI_ADDRESS						0x0F

#endif /* ITI_CAIRO_G1_MA_MCAL_TWI_TWI_CONFIG_H_ */
