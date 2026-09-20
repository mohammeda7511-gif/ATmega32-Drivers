/*
 * LCD_Program.c
 *
 *  Created on: Aug 26, 2026
 *      Author: Mohammed Abdelrahman
 */
#include "LCD_Config.h"
#include "LCD_Interface.h"
#include "LCD_Private.h"
#include <util/delay.h>
#include "../../ITI_CAIRO_G1_MA_MCAL/DIO/DIO_Interface.h"

void LCD_SendData(u8 Copy_Data)
{
    DIO_SetPinValue(LCD_ControlPORT, LCD_RS, DIO_HIGH);
    DIO_SetPinValue(LCD_ControlPORT, LCD_RW, DIO_LOW);
    DIO_SetPortValue(LCD_DataPORT, Copy_Data);
    DIO_SetPinValue(LCD_ControlPORT, LCD_EN, DIO_HIGH);
    _delay_us(2);
    DIO_SetPinValue(LCD_ControlPORT, LCD_EN, DIO_LOW);
    _delay_us(50);
}

void LCD_SendCommand(u8 Copy_Command)
{
    DIO_SetPinValue(LCD_ControlPORT, LCD_RS, DIO_LOW);
    DIO_SetPinValue(LCD_ControlPORT, LCD_RW, DIO_LOW);
    DIO_SetPortValue(LCD_DataPORT, Copy_Command);
    DIO_SetPinValue(LCD_ControlPORT, LCD_EN, DIO_HIGH);
    _delay_us(2);
    DIO_SetPinValue(LCD_ControlPORT, LCD_EN, DIO_LOW);
    _delay_us(50);
}

void LCD_SendNumber(u8 number)
{
    u8 buffer[4];  /* Max 3 digits + null terminator for u8 (0-255) */
    u8 i = 0;
    u8 j;
    u8 temp;

    /* Handle zero case */
    if (number == 0)
    {
        LCD_SendData('0');
        return;
    }

    /* Extract digits in reverse order */
    while (number > 0)
    {
        buffer[i] = (number % 10) + '0';  /* Convert digit to ASCII */
        number /= 10;
        i++;
    }

    /* Reverse the buffer to get correct order */
    for (j = 0; j < i / 2; j++)
    {
        temp = buffer[j];
        buffer[j] = buffer[i - 1 - j];
        buffer[i - 1 - j] = temp;
    }

    /* Null terminate */
    buffer[i] = '\0';

    /* Send the string to LCD */
    LCD_SendString(buffer);
}

void LCD_Init(void)
{
    /* Set all pins as outputs */
    DIO_SetPortDirection(LCD_DataPORT, DIO_OUTPUT);
    DIO_SetPinDirection(LCD_ControlPORT, LCD_RS, DIO_OUTPUT);
    DIO_SetPinDirection(LCD_ControlPORT, LCD_RW, DIO_OUTPUT);
    DIO_SetPinDirection(LCD_ControlPORT, LCD_EN, DIO_OUTPUT);

    /* Initial state - all low */
    DIO_SetPinValue(LCD_ControlPORT, LCD_RS, DIO_LOW);
    DIO_SetPinValue(LCD_ControlPORT, LCD_RW, DIO_LOW);
    DIO_SetPinValue(LCD_ControlPORT, LCD_EN, DIO_LOW);

    /* Wait for LCD to power up */
    _delay_ms(100);

    /* ---- 8-bit Initialization Sequence (Corrected) ---- */

    // Step 1: Function Set (8-bit, 2-line, 5x8 dots)
    LCD_SendCommand(0x38);
    _delay_ms(10);

    // Step 2: Function Set again (wait longer)
    LCD_SendCommand(0x38);
    _delay_ms(10);

    // Step 3: Function Set third time
    LCD_SendCommand(0x38);
    _delay_ms(10);

    // Step 4: Display OFF
    LCD_SendCommand(0x08);
    _delay_ms(10);

    // Step 5: Display Clear
    LCD_SendCommand(0x01);
    _delay_ms(10);

    // Step 6: Entry Mode Set (Increment, no shift)
    LCD_SendCommand(0x06);
    _delay_ms(10);

    // Step 7: Display ON (Cursor ON, Blink OFF)
    LCD_SendCommand(0x0E);
    _delay_ms(10);
}

void LCD_SendString(u8 *P_CopyString)
{
    u8 LocalIterator = 0;
    while(P_CopyString[LocalIterator] != '\0')
    {
        LCD_SendData(P_CopyString[LocalIterator]);
        LocalIterator++;
    }
}

void LCD_SetCurserPosition(u8 CopyX, u8 CopyY)
{
    u8 LocalPosition = CopyX + CopyY * Line_Base;
    LCD_SendCommand(LocalPosition + DDRAM_MSB);
}

void LCD_ClearDisplay(void)
{
    LCD_SendCommand(Clear);
    _delay_ms(3);
}

void LCD_SendSpecialChar(u8 Copy_BlockNumber,u8 *P_PatternArray,u8 CopyX, u8 CopyY)
{
    u8 LocalPosition = Copy_BlockNumber * BlockOffset;
    LCD_SendCommand(CGRAM + LocalPosition);

    for(u8 Iterator = 0; Iterator < BlockOffset; Iterator++)
    {
        LCD_SendData(P_PatternArray[Iterator]);
    }

    LCD_SetCurserPosition(CopyX, CopyY);
    LCD_SendData(Copy_BlockNumber);
}


void LCD_SendStringCentered(u8 *P_String, u8 CopyRow)
{
    u8 length = 0;

    /* Calculate string length */
    while (P_String[length] != '\0')
    {
        length++;
    }

    /* Center: (LCD_COLS - length) / 2 */
    if (length < LCD_COLS)
    {
        LCD_SetCurserPosition((LCD_COLS - length) / 2, CopyRow);
    }
    else
    {
        /* String longer than display, start at column 0 */
        LCD_SetCurserPosition(0, CopyRow);
    }

    LCD_SendString(P_String);
}
