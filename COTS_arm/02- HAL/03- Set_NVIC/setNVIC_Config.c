/***************************
 * Author: Raouf Magdy     *
 * Date: 10/3/2023         *
 * Version: V01            *
 ***************************/
 
 
 #include "setNVIC_Config.h"

 
 
 //creating an array of struct "Led_cfg_t" for Led configurations:
 INT_cfg_t INTs_Config[INT_Count] = 
 {
	 
	 [INT_1]  = {.NVIC_Reg = NVIC_ISER, .NVIC_Bit = NVIC_BIT5, .NVIC_RegNum = ISER0},
	 [INT_2]  = {.NVIC_Reg = NVIC_ISER, .NVIC_Bit = NVIC_BIT6, .NVIC_RegNum = ISER0},
	 [INT_3]  = {.NVIC_Reg = NVIC_ISER, .NVIC_Bit = NVIC_BIT7, .NVIC_RegNum = ISER0}
	 
	 
 };














