/***************************
 * Author: Raouf Magdy     *
 * Date: 21/3/2023         *
 * Version: V01            *
 ***************************/
 
 
 #include "STD_Types.h"
 #include "GPIO_Interface.h"
 #include "Switch_Interface.h"
 

 static u8 Switch_PrevState[Switch_Count];
 static u8 Switch_State[Switch_Count];
 static u8 Switch_Counter[Switch_Count];

 void Switch_Init(void)
 {
	 GPIO_Config_t SwitchCFG; //object from GPIO_Config_t
	 u8 Switch_Index = 0;
	 
	 for(Switch_Index = 0; Switch_Index < Switch_Count; Switch_Index++)
	 {
		 SwitchCFG.GPIO_Port       = Switches_Config[Switch_Index].GPIO_Port;
		 SwitchCFG.GPIO_Mode_Speed = Switches_Config[Switch_Index].GPIO_Mode_Speed;
		 SwitchCFG.GPIO_Pin        = Switches_Config[Switch_Index].GPIO_Pin;

		 GPIO_enuInit(&SwitchCFG);
	 }
 }
 
 
 
 void Switch_Task(void)
 {
	 u32 idx = 0;
	 u8 Loc_u8Iterator = 0;
	 GPIO_Config_t SwitchCFG;

	 for(idx = 0; idx<Switch_Count; idx++)
	 {
		 SwitchCFG.GPIO_Port  = Switches_Config[idx].GPIO_Port;
		 SwitchCFG.GPIO_Pin   = Switches_Config[idx].GPIO_Pin;

		 Switch_PrevState[idx] = GPIO_enuGetPinValue(&SwitchCFG, Switches_Config[idx].GPIO_Pin);


		 for(Loc_u8Iterator=0; Loc_u8Iterator<5; Loc_u8Iterator++)
		 {
			Switch_State[idx] = GPIO_enuGetPinValue(&SwitchCFG, Switches_Config[idx].GPIO_Pin);

			if(Switch_State[idx] == Switch_PrevState[idx])
			{
				Switch_Counter[idx]++;
			} else {
				Switch_Counter[idx] = 0;
			}

			if(Switch_Counter[idx] >= 5)
			{
				Switch_State[idx] = Switch_PrevState[idx];
				Switch_Counter[idx] = 0;
			}
		 }

		 Switches_Config[idx].GPIO_Value = Switch_State[idx];
	 }

 }
 

 u8 Switch_GetState(u8 SwitchIdx)
 {
	 u8 GetVal;
	 GetVal = Switches_Config[SwitchIdx].GPIO_Value;

	 return GetVal;
 }
 
 
 /*
  void Switch_vidSetPinMode(u8 Switch, u32 Mode)
   {
  	 GPIO_Config_t SwitchCFG;

  	 SwitchCFG.GPIO_Port  = Switches_Config[Switch].GPIO_Port;
  	 SwitchCFG.GPIO_Pin   = Switches_Config[Switch].GPIO_Pin;
  	 SwitchCFG.GPIO_Value = Mode ^ Switches_Config[Switch].GPIO_Value;

  	 GPIO_enuSetPinValue(&SwitchCFG);
   }
  */
 
 
 
