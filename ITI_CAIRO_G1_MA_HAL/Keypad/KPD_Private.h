/*
 * KPD_Private.h
 *
 *  Created on: Aug 26, 2026
 *      Author: Mohammed Abdelrahman
 */

#ifndef ITI_CAIRO_G1_MA_HAL_KEYPAD_KPD_PRIVATE_H_
#define ITI_CAIRO_G1_MA_HAL_KEYPAD_KPD_PRIVATE_H_

#define Line1_Base 0x40 // 64
#define DDRAM_MSB  0x80 // 128
#define CGRAM      0x40 // 64

static void LCD_SendData(u8 Copy_Data);
static void LCD_SendCommand(u8 Copy_Command);

#endif /* ITI_CAIRO_G1_MA_HAL_KEYPAD_KPD_PRIVATE_H_ */
