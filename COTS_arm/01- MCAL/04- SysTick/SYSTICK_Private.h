/********************************
 *  Author: Raouf Magdy         *
 *                              *
 *  Date: 03-03-2023            *
 *                              *
 *  Version: V_01               *
 *                              *
 ********************************/
 
 
 #ifndef SYSTICK_PRIVATE_H
 #define SYSTICK_PRIVATE_H
 
 #define STK_CTRL   *((volatile u32 *) 0xE000E010)
 #define STK_LOAD   *((volatile u32 *) 0xE000E014)
 #define STK_VAL    *((volatile u32 *) 0xE000E018)
 #define STK_CALIB  *((volatile u32 *) 0xE000E01C)
 
 
 #endif
 