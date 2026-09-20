/*
 * HBG_Interface.h
 *
 *  Created on: Sep 6, 2026
 *      Author: Mohammed Abdelrahman
 */

#ifndef ITI_CAIRO_G1_MA_HAL_H_BRIDGE_HBG_INTERFACE_H_
#define ITI_CAIRO_G1_MA_HAL_H_BRIDGE_HBG_INTERFACE_H_

#include "../../ITI_CAIRO_G1_MA_LIB/STD_TYPES.h"

/*Initialization*/
void HBG_Init();

/*One motor*/
void HBG_MotorForward(u8 motor);
void HBG_MotorBackward(u8 motor);
void HBG_MotorStop(u8 motor);

/*Two motors*/
void HBG_BothForward(u8 motor1, u8 motor2);
void HBG_BothBackward(u8 motor1, u8 motor2);
void HBG_BothStop(u8 motor1, u8 motor2);

/*Direction change*/
void HBG_TurnRight(u8 motor1, u8 motor2);
void HBG_TurnLeft(u8 motor1, u8 motor2);

/*User function*/
void HBG_SetDirection(u8 motor1, u8 motor2, u8 direction);  //-> the most used by the user.

#endif /* ITI_CAIRO_G1_MA_HAL_H_BRIDGE_HBG_INTERFACE_H_ */
