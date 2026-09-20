/*
 * TWI_Private.h
 *
 *  Created on: Sep 12, 2026
 *      Author: Mohammed Abdelrahman
 */

/* Header guard to prevent multiple inclusion */
#ifndef ITI_CAIRO_G1_MA_MCAL_TWI_TWI_PRIVATE_H_
#define ITI_CAIRO_G1_MA_MCAL_TWI_TWI_PRIVATE_H_


/* Registers */
/* TWI Bit Rate Register */
#define TWBR						(*(volatile u8 *)0x20)
/* TWI Control Register */
#define TWCR						(*(volatile u8 *)0x56)
/* TWI Status Register */
#define TWSR						(*(volatile u8 *)0x21)
/* TWI Data Register */
#define TWDR						(*(volatile u8 *)0x23)
/* TWI (Slave) Address Register */
#define TWAR						(*(volatile u8 *)0x22)
/* Status Register (contains global interrupt enable bit) */
#define SREG						(*(volatile u8 *)0x5F)


/* Pins */
// TWBR
/* Bit 7 of TWBR */
#define TWBR7						7
/* Bit 6 of TWBR */
#define TWBR6						6
/* Bit 5 of TWBR */
#define TWBR5						5
/* Bit 4 of TWBR */
#define TWBR4						4
/* Bit 3 of TWBR */
#define TWBR3						3
/* Bit 2 of TWBR */
#define TWBR2						2
/* Bit 1 of TWBR */
#define TWBR1						1
/* Bit 0 of TWBR */
#define TWBR0						0
// TWCR
/* TWI Interrupt Flag bit */
#define TWINT						7
/* TWI Enable Acknowledge bit */
#define TWEA						6
/* TWI Start Condition bit */
#define TWSTA						5
/* TWI Stop Condition bit */
#define TWSTO						4
/* TWI Write Collision Flag bit */
#define TWWWC						3
/* TWI Enable bit */
#define TWEN						2
/* Reserved bit 1 */
#define Reserved1					1
/* TWI Interrupt Enable bit */
#define TWIE						0
// TWSR
/* TWI Status bit 7 */
#define TWS7						7
/* TWI Status bit 6 */
#define TWS6						6
/* TWI Status bit 5 */
#define TWS5						5
/* TWI Status bit 4 */
#define TWS4						4
/* TWI Status bit 3 */
#define TWS3						3
/* Reserved bit 2 */
#define Reserved2					2
/* TWI Prescaler bit 1 */
#define TWPS1						1
/* TWI Prescaler bit 0 */
#define TWPS0						0
// TWDR
/* TWI Data bit 7 */
#define TWD7						7
/* TWI Data bit 6 */
#define TWD6						6
/* TWI Data bit 5 */
#define TWD5						5
/* TWI Data bit 4 */
#define TWD4						4
/* TWI Data bit 3 */
#define TWD3						3
/* TWI Data bit 2 */
#define TWD2						2
/* TWI Data bit 1 */
#define TWD1						1
/* TWI Data bit 0 */
#define TWD0						0
// TWAR
/* TWI Address bit 6 */
#define TWA6						7
/* TWI Address bit 5 */
#define TWA5						6
/* TWI Address bit 4 */
#define TWA4						5
/* TWI Address bit 3 */
#define TWA3						4
/* TWI Address bit 2 */
#define TWA2						3
/* TWI Address bit 1 */
#define TWA1						2
/* TWI Address bit 0 */
#define TWA0						1
/* TWI General Call Enable bit */
#define TWGCE						0
//SREG
/* Global Interrupt Enable bit */
#define I							7


/* Prescaler */
/* Prescaler value 1 */
#define TWI_PRESCALER_1				0
/* Prescaler value 4 */
#define TWI_PRESCALER_4				1
/* Prescaler value 16 */
#define TWI_PRESCALER_16			2
/* Prescaler value 64 */
#define TWI_PRESCALER_64			3


/* Clocks */
// TWI
/* SCL frequency 100 kHz */
#define TWI_SCL_FREQ_100MHZ			100000UL
/* SCL frequency 400 kHz */
#define TWI_SCL_FREQ_400MHZ			400000UL
// CPU
/* Default CPU frequency if not defined elsewhere */
#ifndef F_CPU
/* Assume 8 MHz if F_CPU is not defined */
#define F_CPU						8000000UL
/* Warn the user about the assumption */
#warning "F_CPU not defined, assumed 8MHz"
#endif


/* Interrupt */
/* Disable TWI interrupt */
#define TWI_INTERRUPT_DISABLE		0
/* Enable TWI interrupt */
#define TWI_INTERRUPT_ENABLE		1


/* General Call */
/* Disable general call recognition */
#define TWI_GENERAL_CALL_DISABLE	0
/* Enable general call recognition */
#define TWI_GENERAL_CALL_ENABLE		1


/* Status Codes */
// Status Mask to set only the status bits to zero
/* Mask to extract the TWI status bits */
#define TWI_STATUS_MASK             0xF8
// Start Conditions
/* Master start condition transmitted successfully */
#define TWI_MAS_START_SUCCESS		0x08
/* Master repeated start condition transmitted successfully */
#define TWI_MAS_REP_START_SUCCESS	0x10
// Master Transmitter
/* Send SLA+W, received ACK */
#define TWI_MAS_SEND_ADD_W_ACK		0x18
/* Send SLA+W, received NACK */
#define TWI_MAS_SEND_ADD_W_NACK		0x20
/* Send data, received ACK */
#define TWI_MAS_SEND_DATA_ACK		0x28
/* Send data, received NACK */
#define TWI_MAS_SEND_DATA_NACK		0x38
// Master Receiver
/* Send SLA+R, received ACK */
#define TWI_MAS_SEND_ADD_R_ACK		0x40
/* Send SLA+R, received NACK */
#define TWI_MAS_SEND_ADD_R_NACK		0x48
/* Received data, send ACK */
#define TWI_MAS_READ_DATA_ACK		0x50
/* Received data, send NACK */
#define TWI_MAS_READ_DATA_NACK		0x58
// Slave Receiver
/* Received SLA+W, send ACK */
#define TWI_SLA_ADD_W_MATCH_ACK		0x60
/* Received General Call, send ACK */
#define TWI_SLA_GENERAL_CALL_ACK	0X70
/* Received data, send ACK */
#define TWI_SLA_READ_DATA_ACK		0x80
/* Received data, send NACK */
#define TWI_SLA_READ_DATA_NACK		0x88
/* Stop or repeated start received */
#define TWI_SLA_STOP_OR_REP_START	0xA0
// Slave Transmitter
/* Received SLA+R, send ACK */
#define TWI_SLA_READ_ADD_MATCH_ACK	0xA8
/* Received SLA+R, send NACK */
#define TWI_SLA_SEND_DATA_ACK		0xB8
/* Send data, returned ACK */
#define TWI_SLA_SEND_DATA_NACK		0xC0
/* Send data, returned NACK */
#define TWI_SLA_READ_LAST_DATA_ACK	0xC8


/* NULL ptr */
/* Generic null pointer constant */
#define NULL						((void *)0)
#endif /* ITI_CAIRO_G1_MA_MCAL_TWI_TWI_PRIVATE_H_ */
