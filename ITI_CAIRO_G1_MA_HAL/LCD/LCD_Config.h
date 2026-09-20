/*
 * LCD_Config.h
 *
 *  Created on: Aug 26, 2026
 *      Author: Mohammed Abdelrahman
 */

#ifndef ITI_CAIRO_G1_MA_HAL_LCD_LCD_CONFIG_H_
#define ITI_CAIRO_G1_MA_HAL_LCD_LCD_CONFIG_H_

#include "../../ITI_CAIRO_G1_MA_MCAL/DIO/DIO_Interface.h"

#define LCD_DataPORT    DIO_PORTA
#define LCD_ControlPORT DIO_PORTC
#define LCD_RS          DIO_PIN0
#define LCD_RW          DIO_PIN1
#define LCD_EN          DIO_PIN2

#endif /* ITI_CAIRO_G1_MA_HAL_LCD_LCD_CONFIG_H_ */
