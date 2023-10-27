/***************************
 * Author: Raouf Magdy     *
 * Date: 19/06/2023        *
 * Version: V01            *
 ***************************/
 
 
 #include "Encoder_Interface.h"
 #include "GPT_Interface.h"




ENCODER_Config_t      Encoders_Timers_Config[Encoder_Count] = {

     [Encoder_1] = { 
                     .TIM_ID       = TIM_2,
                     .TIM_CNT_DIR  = COUNT_UP,
                     .TIM_PRSC     = 0
                   }

};


ENCODER_ICM_Config_t  Encoders_InputCaptureModer_Config[Encoder_Count] = {

     [Encoder_1] = { 
                     .TIM_ICM_ID = TIM_2,
	                 .TIM_IC1PSC = 0,
	                 .TIM_IC2PSC = 0,
	                 .TIM_CC1P   = RISING_EDGE,
	                 .TIM_CC2P   = FALLING_EDGE,
	                 .TIM_CC1IE  = CAP_INT_ENABLE,
	                 .TIM_CC2IE  = CAP_INT_ENABLE,
	                 .TIM_TIE    = TRING_INT_DISABLE
                   }

};








 