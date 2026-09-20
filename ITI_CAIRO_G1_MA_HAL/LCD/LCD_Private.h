/*
 * LCD_Private.h
 *
 *  Created on: Aug 26, 2026
 *      Author: Mohammed Abdelrahman
 */

#ifndef ITI_CAIRO_G1_MA_HAL_LCD_LCD_PRIVATE_H_
#define ITI_CAIRO_G1_MA_HAL_LCD_LCD_PRIVATE_H_

#define Line_Base   0x40  // 64
#define DDRAM_MSB   0x80  // 128
#define CGRAM       0x40  // 64

#define Function_Set_8bit_1line  0x30
#define Function_Set_8bit_2line  0x38
#define Display_OFF              0x08
#define Display_ON_CURSOR_OFF    0x0C
#define Display_ON_CURSOR_ON     0x0E
#define Display_ON_CURSOR_BLINK  0x0F
#define Clear                    0x01
#define Entry_Mode               0x06

#define LCD_COLS   16

#define BlockOffset 8

#endif /* ITI_CAIRO_G1_MA_HAL_LCD_LCD_PRIVATE_H_ */
