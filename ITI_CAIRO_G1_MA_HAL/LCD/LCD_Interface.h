/*
 * LCD_Interface.h
 *
 *  Created on: Aug 26, 2026
 *      Author: Mohammed Abdelrahman
 */

#ifndef ITI_CAIRO_G1_MA_HAL_LCD_LCD_INTERFACE_H_
#define ITI_CAIRO_G1_MA_HAL_LCD_LCD_INTERFACE_H_

#include "../../ITI_CAIRO_G1_MA_LIB/STD_TYPES.h"

void LCD_Init(void);
void LCD_SendString(u8 *P_CopyString);
void LCD_SetCurserPosition(u8 CopyX, u8 CopyY);
void LCD_ClearDisplay(void);
void LCD_SendSpecialChar(u8 Copy_BlockNumber,u8 *P_PatternArray,u8 CopyX, u8 CopyY);
void LCD_SendStringCentered(u8 *P_String, u8 CopyRow);
void LCD_SendNumber(u8 number);

void LCD_SendData(u8 Copy_Data);
void LCD_SendCommand(u8 Copy_Command);

#endif /* ITI_CAIRO_G1_MA_HAL_LCD_LCD_INTERFACE_H_ */
