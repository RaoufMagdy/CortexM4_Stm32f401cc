/***************************
 * Author: Raouf Magdy     *
 * Date: 19/06/2023        *
 * Version: V01            *
 ***************************/
 
 
 #ifndef ENCODER_CONFIG_H
 #define ENCODER_CONFIG_H
 
 
 #include "STD_Types.h"





typedef enum
 {
	 Encoder_1 = 0,
	 /* 
        Encoder_2,
	    Encoder_3, 
        Encoder_4 
     */
	 Encoder_Count     /* Note that the maximum number of encoders is 4, because this driver depends on TIM2,3,4,5 */
 }Encoders_Counts;     /* Note that Encoders are mapped to Timers respectively, Encoder_1 -> TIM2, Encoder_2 -> TIM3.. and so on */




#endif

