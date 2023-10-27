/***************************
 * Author: Raouf Magdy     *
 * Date: 27/1/2023         *
 * Version: V01            *
 ***************************/
 
 
 #include "STD_Types.h"
 #include "NVIC_Interface.h"
 #include "setNVIC_Interface.h"
 
 
 void INT_vidInitISER(void)
 {
	NVIC_Config_t INT_CFG; //Create object from NVIC_Config_t
	
	u8 INT_Index;
	
	
	for(INT_Index = 0; INT_Index < INT_Count; INT_Index++)
	{
		 INT_CFG.NVIC_Reg    = INTs_Config[INT_Index].NVIC_Reg;   
	     INT_CFG.NVIC_Bit    = INTs_Config[INT_Index].NVIC_Bit;   
		 INT_CFG.NVIC_RegNum = INTs_Config[INT_Index].NVIC_RegNum;
	}
	NVIC_EnableIRQ(&INT_CFG);
 }
 

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 