/***************************
 * Author: Raouf Magdy     *
 * Date: 16/6/2023         *
 * Version: V01            *
 ***************************/
 
 
 #include "DC_Motor_Interface.h"
 #include "GPIO_Interface.h"
 #include "GPT_Interface.h"
 
 
 //Creating arrays of structs "Motors_X_cfg_t" for Motors configurations:
 
 Motor_EnablePin_cfg_t Motors_EnablePin_Config[Motor_Count] = 
 {
	 [Motor_1]   = { .GPIO_Port 	  = GPIO_PORTA, 
					 .GPIO_Pin 	      = GPIO_PIN0, 
					 .GPIO_Mode_Speed = GPIO_OUTPUT_PP_VHS}
 };

 Motor_Pin1_cfg_t Motors_Pin1_Config[Motor_Count] = 
 {
	 [Motor_1]   = { .GPIO_Port 	  = GPIO_PORTA, 
					 .GPIO_Pin 	      = GPIO_PIN1, 
					 .GPIO_Mode_Speed = GPIO_OUTPUT_PP_VHS}
 };

 Motor_Pin2_cfg_t Motors_Pin2_Config[Motor_Count] = 
 {
	 [Motor_1]   = { .GPIO_Port 	  = GPIO_PORTA, 
					 .GPIO_Pin 	      = GPIO_PIN2, 
					 .GPIO_Mode_Speed = GPIO_OUTPUT_PP_VHS}
 };

 Motor_PWM_cfg_t       Motors_PWM_Config[Motor_Count] =
 {
	  [Motor_1] = {     /* Dummy Configurations */
			  	  	 .TIM_PWM_ID = TIM_5,
					 .TIM_PWM_SET_ARR = 59999,
					 .TIM_PWM_CCR1_VAL = 2000,
					 .TIM_PWM_CCR2_VAL = 2000,
					 .TIM_ARPE = 1,
					 .TIM_CC1P = 1,
					 .TIM_CC2P = 1,
					 .TIM_CC1E = 1,
					 .TIM_CC2E = 1
	              }

 };












