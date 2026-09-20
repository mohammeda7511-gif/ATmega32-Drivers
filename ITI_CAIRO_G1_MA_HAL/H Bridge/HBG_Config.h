/*
 * HBG_Config.h
 *
 *  Created on: Sep 6, 2026
 *      Author: Mohammed Abdelrahman
 */

#ifndef ITI_CAIRO_G1_MA_HAL_H_BRIDGE_HBG_CONFIG_H_
#define ITI_CAIRO_G1_MA_HAL_H_BRIDGE_HBG_CONFIG_H_

#include "../../ITI_CAIRO_G1_MA_MCAL/DIO/DIO_Interface.h"

/*Motors definitions*/
#define MOTOR_RIGHT					0
#define MOTOR_LEFT					1

/*Ports definitions*/
#define MOTOR_1_PORT				DIO_PORTA  //-> Connected to the right
#define MOTOR_2_PORT				DIO_PORTA  //-> Connected to the left

/*Pins definitions*/
#define MOTOR_1_PIN_1				DIO_PIN0
#define MOTOR_1_PIN_2				DIO_PIN1
#define MOTOR_2_PIN_1				DIO_PIN2
#define MOTOR_2_PIN_2				DIO_PIN3

/*Steering mode options:            "assigns the function of the motors when turning"
 * 1- HBG_STR_REVERSE				-> The most used
 * 2- HBG_STR_STOP
 */
#define MOTOR_STEERING_MODE			HBG_STR_REVERSE

#endif /* ITI_CAIRO_G1_MA_HAL_H_BRIDGE_HBG_CONFIG_H_ */
