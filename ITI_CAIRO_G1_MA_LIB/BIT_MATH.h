/* Header guard to prevent multiple inclusion */
#ifndef BIT_MATH_H_
#define BIT_MATH_H_


/* Set a specific bit in a register to 1 */
#define SET_BIT(REG, BIT_NUM) (REG |= (1<<BIT_NUM))
/* Clear a specific bit in a register to 0 */
#define CLR_BIT(REG, BIT_NUM) (REG &= (~(1<<BIT_NUM)))
/* Toggle a specific bit in a register */
#define TOG_BIT(REG, BIT_NUM) (REG ^= (1<<BIT_NUM))
/* Read the value of a specific bit in a register */
#define GET_BIT(REG, BIT_NUM) ((REG >> BIT_NUM) & 1)

#endif
