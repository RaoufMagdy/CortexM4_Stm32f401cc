/***************************
 * Author: Raouf Magdy     *
 * Date: 27/1/2023         *
 * Version: V01            *
 ***************************/
 
 
 #include "STD_Types.h"
 #include "GPIO_Interface.h"
 #include "Led_Interface.h"
 
 
 LedErrorStatus Led_vidInit(void)
 {
	 GPIO_Config_t LedCFG; //object from GPIO_Config_t
	 u8 Led_Index = 0;
	 LedErrorStatus ledErrorStatus = Led_OK;
	 
	 for(Led_Index = 0; Led_Index < Led_Count; Led_Index++)
	 {
		 LedCFG.GPIO_Port       = Leds_Config[Led_Index].GPIO_Port;
		 LedCFG.GPIO_Pin        = Leds_Config[Led_Index].GPIO_Pin;
	     LedCFG.GPIO_Mode_Speed = Leds_Config[Led_Index].GPIO_Mode_Speed;

	     GPIO_enuInit(&LedCFG);
	 }
	 
	 return ledErrorStatus;
 }
 
 
 void Led_vidSetState(u8 Led, u32 State)
 {
	 GPIO_Config_t LedCFG;

	 LedCFG.GPIO_Port  = Leds_Config[Led].GPIO_Port;
	 LedCFG.GPIO_Pin   = Leds_Config[Led].GPIO_Pin;
	 LedCFG.GPIO_Value = State ^ Leds_Config[Led].GPIO_Value;

	 GPIO_enuSetPinValue(&LedCFG);
 }
 
 
 u8 Led_vidGetState(u8 Led)
 {
	 GPIO_Config_t LedCFG;
	 u8 GetVal;

	 LedCFG.GPIO_Port  = Leds_Config[Led].GPIO_Port;
	 LedCFG.GPIO_Pin   = Leds_Config[Led].GPIO_Pin;

	 GetVal = GPIO_enuGetPinValue(&LedCFG, Led);

	 return GetVal;
 }


 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 


