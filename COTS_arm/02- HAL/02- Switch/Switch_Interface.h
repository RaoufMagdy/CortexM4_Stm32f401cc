/***************************
 * Author: Raouf Magdy     *
 * Date: 21/3/2023         *
 * Version: V01            *
 ***************************/
 
 
 
 #ifndef SWITCH_INTERFACE_H
 #define SWITCH_INTERFACE_H
 
 #include "STD_Types.h"
 #include "Switch_Config.h"

 
 
 typedef enum{
	 
	 Switch_NotPressed = 0,
	 Switch_Pressed
	 
 }SwitchCurrentStatus;
 
 
 typedef struct
  {
 	 void* GPIO_Port;
 	 u16   GPIO_Pin;
 	 u32   GPIO_Mode_Speed;
 	 u8    GPIO_Value;
  }Switch_cfg_t;



 //#define Switch_PullUp	0x00000001
 //#define Switch_PullDown	0x00010000


 
 //Switch Initialization
 void Switch_Init(void);
 void Switch_Task(void); //Switch task that will be performed inside the application task when using scheduler.
 u8 Switch_GetState(u8 SwitchIdx);
 //void Switch_vidSetPinMode(u8 Switch, u32 Mode);

 
 extern Switch_cfg_t Switches_Config[Switch_Count];
 
 
 void Switch_Task(void);
 
 
 
 #endif
 
