/*
 * BIT_MATHs.h
 *
 *  Created on: May 11, 2022
 *      Author: Raouf
 */

#ifndef BIT_MATHS_H_
#define BIT_MATHS_H_

#define SET_BIT(REG,BIT) REG |= (1<<BIT)
#define CLR_BIT(REG,BIT) REG &= ~(1<<BIT)
#define TGL_BIT(REG,BIT) REG ^= (1<<BIT)
#define GET_BIT(REG,BIT) ((REG >> BIT)&1)

#endif /* BIT_MATHS_H_ */
