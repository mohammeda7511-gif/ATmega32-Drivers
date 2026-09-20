/*
 * KPD_Program.c
 *
 *  Created on: Aug 26, 2026
 *      Author: Mohammed Abdelrahman
 */

#include "KPD_Interface.h"
#include <util/delay.h>
#include "../../ITI_CAIRO_G1_MA_MCAL/DIO/DIO_Interface.h"

const u8 KEYPAD_ARR[KEYPAD_ROWS_NUM][KEYPAD_COLS_NUM] = {\
{1,  2,  3,  4},\
{5,  6,  7,  8},\
{9,  10, 11, 12},\
{13, 14, 15, 16}\
};

void Keypad_Init()
{
	for (int rol = 0; rol < KEYPAD_ROWS_NUM; rol++)
	{
		DIO_SetPinDirection(KEYPAD_ROW_PORT, KEYPAD_ROW_F_NUM + rol, DIO_PULLUP);
	}

	for (int col=0; col<KEYPAD_COLS_NUM; col++)
	   {
			DIO_SetPinDirection(KEYPAD_COL_PORT, KEYPAD_COL_F_NUM + col, DIO_OUTPUT);
			DIO_SetPinValue(KEYPAD_COL_PORT, KEYPAD_COL_F_NUM + col, DIO_HIGH);
	   }

}

u8 Keypad_GetKey()
{
	while(!KEYPAD_NOTPRESSED)
	{
		for (int col = 0; col < KEYPAD_COLS_NUM; col++)
		{
			DIO_SetPinValue(KEYPAD_COL_PORT, KEYPAD_COL_F_NUM + col, DIO_LOW);

			for (int rol = 0; rol < KEYPAD_ROWS_NUM; rol++)
			{
				if(DIO_GetPinValue(KEYPAD_ROW_PORT, KEYPAD_ROW_F_NUM + rol) == 0)
				   {
						_delay_ms(200);
						DIO_SetPinValue(KEYPAD_COL_PORT, KEYPAD_COL_F_NUM + col, DIO_HIGH);
						return KEYPAD_ARR[rol][col];
				   }
			}
			DIO_SetPinValue(KEYPAD_COL_PORT, KEYPAD_COL_F_NUM + col, DIO_HIGH);
		}
	}

	return KEYPAD_NOTPRESSED;
}
