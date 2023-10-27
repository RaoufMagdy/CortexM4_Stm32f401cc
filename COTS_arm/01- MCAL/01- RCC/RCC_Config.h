/********************************
 *  Author: Raouf Magdy         *
 *                              *
 *  Date: 01-02-2023            *
 *                              *
 *  Version: V_01               *
 *                              *
 ********************************/
 
 
 
 #ifndef RCC_CONFIG_H
 #define RCC_CONFIG_H
 
 
 
 /* 
    This file should contain comments descibing the APIs and 
    how to use them. 
 */
 
 /**********************************
  typedef struct{
	 //PLLM:
	 u8 PLLM : 5;  //2 ≤ PLLM ≤ 63 

	 //PLLN:
	 u16 PLLN : 9; //192 ≤ PLLN ≤ 432
	 
	 //PLLP:
	 u8 PLLP : 2;  //Options: 2,4,8,16
	 
	 //PLLQ:
	 u8 PLLQ : 4;  //2 ≤ PLLQ ≤ 15
	 
 }RCC_strPLLConfig;
 *************************************/
 
 /*****************************************************************
 
        ||===> Clock PLL Configuration Equations <===|| 
 
   Freq(VCO clock) = Freq(PLL clock input) × (PLLN / PLLM)
   Freq(PLL general clock output) = Freq(VCO clock) / PLLP
   Freq(USB OTG FS, SDIO, RNG clock output) = Freq(VCO clock) / PLLQ
 
 
 *****************************************************************/
 
 
 #endif
 