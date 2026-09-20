/*
 * KPD_Interface.h
 *
 *  Created on: Aug 26, 2026
 *      Author: Mohammed Abdelrahman
 */

#ifndef ITI_CAIRO_G1_MA_HAL_KEYPAD_KPD_INTERFACE_H_
#define ITI_CAIRO_G1_MA_HAL_KEYPAD_KPD_INTERFACE_H_

/*
 * Keypad_program.c
 *
 *  Created on: Aug 25, 2026
 *      Author: Mohammed Abdelrahman
 */

#include "../../ITI_CAIRO_G1_MA_LIB/STD_TYPES.h"

#define KEYPAD_ROW_PORT   DIO_PORTB
#define KEYPAD_COL_PORT   DIO_PORTB

#define KEYPAD_ROWS_NUM 4
#define KEYPAD_COLS_NUM 4

#define KEYPAD_ROW_F_NUM 0
#define KEYPAD_COL_F_NUM 4

#define KEYPAD_NOTPRESSED 0

void Keypad_Init();
u8 Keypad_GetKey();


#endif /* ITI_CAIRO_G1_MA_HAL_KEYPAD_KPD_INTERFACE_H_ */
