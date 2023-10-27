/********************************
 *  Author: Raouf Magdy         *
 *                              *
 *  Date: 03-03-2023            *
 *                              *
 *  Version: V_01               *
 *                              *
 ********************************/
 
 
 #ifndef NVIC_PRIVATE_H
 #define NVIC_PRIVATE_H
 
 #define NVIC_ISER_BASE_ADDRESS 0xE000E100
 #define NVIC_ICER_BASE_ADDRESS 0xE000E180
 #define NVIC_ISPR_BASE_ADDRESS 0xE000E200
 #define NVIC_ICPR_BASE_ADDRESS 0xE000E280
 #define NVIC_IABR_BASE_ADDRESS 0xE000E300
 #define NVIC_IPR_BASE_ADDRESS  ((volatile u32 *) 0xE000E400)
 #define NVIC_STIR_BASE_ADDRESS 0xE000EF00
 
 #define SCB_AIRCR_BASE_ADDRESS ((volatile u32 *) 0xE000ED0C)
 
 
 #endif
 