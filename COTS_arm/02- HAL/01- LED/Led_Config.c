/***************************
 * Author: Raouf Magdy     *
 * Date: 27/1/2023         *
 * Version: V01            *
 ***************************/
 
 
 #include "Led_Interface.h"
 #include "GPIO_Interface.h"
 
 
 //creating an array of struct "Led_cfg_t" for Led configurations:
 Led_cfg_t Leds_Config[Led_Count] = 
 {
	 [Led_1]   = {.GPIO_Port = GPIO_PORTA, .GPIO_Pin = GPIO_PIN0, .GPIO_Mode_Speed = GPIO_OUTPUT_PP_VHS},
	 [Led_2]   = {.GPIO_Port = GPIO_PORTA, .GPIO_Pin = GPIO_PIN1, .GPIO_Mode_Speed = GPIO_OUTPUT_PP_VHS},
	 [Led_3]   = {.GPIO_Port = GPIO_PORTA, .GPIO_Pin = GPIO_PIN2, .GPIO_Mode_Speed = GPIO_OUTPUT_PP_VHS}
 };














