/***************************
 * Author: Raouf Magdy     *
 * Date: 21/3/2023         *
 * Version: V01            *
 ***************************/
 
 
 #include "Switch_Interface.h"
 #include "GPIO_Interface.h"
 
 //creating an array of struct "Led_cfg_t" for Led configurations:
 Switch_cfg_t Switches_Config[Switch_Count] =
 {
	 [Switch_Alarm] = {
			 	 	   .GPIO_Port = GPIO_PORTB,
			 	 	   .GPIO_Pin  = GPIO_PIN2,
					   .GPIO_Mode_Speed = GPIO_INPUT_PU,
					   .GPIO_Value = Switch_NotPressed
	                  }
	 
 };














