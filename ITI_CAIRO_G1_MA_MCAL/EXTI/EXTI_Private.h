/*
 * EXTI_Private.h
 *
 *  Created on: Aug 31, 2026
 *      Author: Mohammed Abdelrahman
 */

/* Header guard to prevent multiple inclusion */
#ifndef ITI_CAIRO_G1_MA_MCAL_EXTI_EXTI_PRIVATE_H_
#define ITI_CAIRO_G1_MA_MCAL_EXTI_EXTI_PRIVATE_H_

/* MCU Control Register (sense control for INT0 and INT1) */
#define MCUCR  (*(volatile u8 *)0x55)
/* MCU Control and Status Register (sense control for INT2) */
#define MCUCSR (*(volatile u8 *)0x54)
/* General Interrupt Control Register (enable bits for INT0, INT1, INT2) */
#define GICR   (*(volatile u8 *)0x5B)
/* General Interrupt Flag Register (flag bits for INT0, INT1, INT2) */
#define GIFR   (*(volatile u8 *)0x5A)

/* Bit position: sense control for INT2 */
#define ISC2  6
/* Bit position: high sense control bit for INT1 */
#define ISC11 3
/* Bit position: low sense control bit for INT1 */
#define ISC10 2
/* Bit position: high sense control bit for INT0 */
#define ISC01 1
/* Bit position: low sense control bit for INT0 */
#define ISC00 0

/* Bit position: interrupt flag for INT1 */
#define INTF1 7
/* Bit position: interrupt flag for INT0 */
#define INTF0 6
/* Bit position: interrupt flag for INT2 */
#define INTF2 5

/* Enable bit position for INT1 */
#define INT1  7
/* Enable bit position for INT0 */
#define INT0  6
/* Enable bit position for INT2 */
#define INT2  5

/* Sense mode: trigger on low logic level (INT0/INT1 only) */
#define EXTI_LOW_LOGIC 0
/* Sense mode: trigger on any logic change (INT0/INT1 only) */
#define EXTI_ANY_LOGIC 1
/* Sense mode: trigger on falling edge (INT0/INT1/INT2) */
#define EXTI_FALLING   2
/* Sense mode: trigger on rising edge (INT0/INT1/INT2) */
#define EXTI_RISING    3

#endif /* ITI_CAIRO_G1_MA_MCAL_EXTI_EXTI_PRIVATE_H_ */
