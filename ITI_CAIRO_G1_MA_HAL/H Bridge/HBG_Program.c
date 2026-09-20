/*
 * HBG_Program.c
 *
 *  Created on: Sep 6, 2026
 *      Author: Mohammed Abdelrahman
 */


#include "../../ITI_CAIRO_G1_MA_LIB/STD_TYPES.h"
#include "../../ITI_CAIRO_G1_MA_MCAL/DIO/DIO_Interface.h"
#include "HBG_Config.h"
#include "HBG_Private.h"
#include "HBG_Interface.h"


void HBG_Init()
{
	/*Set pins direction*/
	DIO_SetPinDirection(MOTOR_RIGHT, MOTOR_1_PIN_1, DIO_OUTPUT);
	DIO_SetPinDirection(MOTOR_RIGHT, MOTOR_1_PIN_2, DIO_OUTPUT);
	DIO_SetPinDirection(MOTOR_LEFT, MOTOR_2_PIN_1, DIO_OUTPUT);
	DIO_SetPinDirection(MOTOR_LEFT, MOTOR_2_PIN_2, DIO_OUTPUT);
}


void HBG_MotorForward(u8 motor)
{
	/*Set one pin to high and the other to low*/
	switch (motor)
	{
	case MOTOR_RIGHT:
		DIO_SetPinValue(MOTOR_1_PORT, MOTOR_1_PIN_1, DIO_HIGH);
		DIO_SetPinValue(MOTOR_1_PORT, MOTOR_1_PIN_2, DIO_LOW);
		break;

	case MOTOR_LEFT:
		DIO_SetPinValue(MOTOR_2_PORT, MOTOR_2_PIN_1, DIO_HIGH);
		DIO_SetPinValue(MOTOR_2_PORT, MOTOR_2_PIN_2, DIO_LOW);
		break;

	default:
		break;
	}
}


void HBG_MotorBackward(u8 motor)
{
	/*Set pins exactly opposite of the forward function*/
	switch (motor)
	{
	case MOTOR_RIGHT:
		DIO_SetPinValue(MOTOR_1_PORT, MOTOR_1_PIN_1, DIO_LOW);
		DIO_SetPinValue(MOTOR_1_PORT, MOTOR_1_PIN_2, DIO_HIGH);
		break;

	case MOTOR_LEFT:
		DIO_SetPinValue(MOTOR_2_PORT, MOTOR_2_PIN_1, DIO_LOW);
		DIO_SetPinValue(MOTOR_2_PORT, MOTOR_2_PIN_2, DIO_HIGH);
		break;

	default:
		break;
	}
}


void HBG_MotorStop(u8 motor)
{
	/*Set both pins for each motor to low*/
	switch (motor)
	{
	case MOTOR_RIGHT:
		DIO_SetPinValue(MOTOR_1_PORT, MOTOR_1_PIN_1, DIO_LOW);
		DIO_SetPinValue(MOTOR_1_PORT, MOTOR_1_PIN_2, DIO_LOW);
		break;

	case MOTOR_LEFT:
		DIO_SetPinValue(MOTOR_2_PORT, MOTOR_2_PIN_1, DIO_LOW);
		DIO_SetPinValue(MOTOR_2_PORT, MOTOR_2_PIN_2, DIO_LOW);
		break;

	default:
		break;
	}
}


void HBG_BothForward(u8 motor1, u8 motor2)
{
	/*Set both motors to forward*/
	HBG_MotorForward(motor1);
	HBG_MotorForward(motor2);
}


void HBG_BothBackward(u8 motor1, u8 motor2)
{
	/*Set both motors to backward*/
	HBG_MotorBackward(motor1);
	HBG_MotorBackward(motor2);
}


void HBG_BothStop(u8 motor1, u8 motor2)
{
	/*Set both motors to stop*/
	HBG_MotorStop(motor1);
	HBG_MotorStop(motor2);
}


void HBG_TurnRight(u8 motor1, u8 motor2)
{
	/*Set the right motor (1) to high and the left one (2) to low or zero according to steering configuration*/
	HBG_MotorForward(motor1);
#if MOTOR_STEERING_MODE == HBG_STR_REVERSE
	HBG_MotorBackward(motor2);

#elif MOTOR_STEERING_MODE == HBG_STR_STOP
	HBG_MotorStop(motor2);

#else
	#error "Wrong initialization for \"MOTOR_STEERING_MODE\"."
#endif
}


void HBG_TurnLeft(u8 motor1, u8 motor2)
{
	/*Set the left motor (2) to high and the right one (1) to low or zero according to steering configuration*/
	HBG_MotorForward(motor2);
#if MOTOR_STEERING_MODE == HBG_STR_REVERSE
	HBG_MotorBackward(motor1);

#elif MOTOR_STEERING_MODE == HBG_STR_STOP
	HBG_MotorStop(motor1);

#else
	#error "Wrong initialization for \"MOTOR_STEERING_MODE\"."
#endif
}


void HBG_SetDirection(u8 motor1, u8 motor2, u8 direction)
{
	switch(direction)
		{
		case HBG_MOTOR_STOP:
			HBG_BothStop(motor1, motor2);
			break;

		case HBG_MOTOR_FORWARD:
			HBG_BothForward(motor1, motor2);
			break;

		case HBG_MOTOR_BACKWARD:
			HBG_BothBackward(motor1, motor2);
			break;

		case HBG_MOTOR_TURN_RIGHT:
			HBG_TurnRight(motor1, motor2);
			break;

		case HBG_MOTOR_TURN_LEFT:
			HBG_TurnLeft(motor1, motor2);
			break;
		}
}
