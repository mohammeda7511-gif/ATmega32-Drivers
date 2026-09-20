/*
 * TWI_Interface.h
 *
 *  Created on: Sep 12, 2026
 *      Author: Mohammed Abdelrahman
 */

/* Header guard to prevent multiple inclusion */
#ifndef ITI_CAIRO_G1_MA_MCAL_TWI_TWI_INTERFACE_H_
#define ITI_CAIRO_G1_MA_MCAL_TWI_TWI_INTERFACE_H_

/* Include standard type definitions (u8, etc.) */
#include "../../ITI_CAIRO_G1_MA_LIB/STD_TYPES.h"


/* States */
/* Operation completed successfully */
#define TWI_SUCCESS					0
/* Operation failed */
#define TWI_FAIL					1

/* Read / Write */
/* Write operation */
#define TWI_WRITE					0
/* Read operation */
#define TWI_READ					1

/* Initiation */
/* Initialize the TWI peripheral */
void TWI_Init();

/* Master */
/* Send a start condition as master */
u8 TWI_MasterStartSending();
/* Send a repeated start condition as master */
u8 TWI_MasterRepeatStart();
/* Send a stop condition as master */
u8 TWI_MasterStopSending();
/* Send slave address with write bit as master */
u8 TWI_MasterSendAddressWrite(u8 address);
/* Send slave address with read bit as master */
u8 TWI_MasterSendAddressRead(u8 address);
/* Send a data byte as master */
u8 TWI_MasterSendData(u8 data);
/* Receive a data byte as master and respond with ACK */
u8 TWI_MasterReceiveDataACK(u8 *data);
/* Receive a data byte as master and respond with NACK */
u8 TWI_MasterReceiveDataNACK(u8 *data);

/* Slave */
/* Wait to be addressed by master with write bit */
u8 TWI_SlaveReceiveAddressWrite();
/* Wait to be addressed by master with read bit */
u8 TWI_SlaveReceiveAddressRead();
/* Send a data byte as slave and receive ACK */
u8 TWI_SlaveSendDataACK(u8 data);
/* Send a data byte as slave and receive NACK */
u8 TWI_SlaveSendDataNACK(u8 data);
/* Receive a data byte as slave and respond with ACK */
u8 TWI_SlaveReceiveDataACK(u8 *data);
/* Receive a data byte as slave and respond with NACK */
u8 TWI_SlaveReceiveDataNACK(u8 *data);

#endif /* ITI_CAIRO_G1_MA_MCAL_TWI_TWI_INTERFACE_H_ */
