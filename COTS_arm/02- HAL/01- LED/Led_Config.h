/***************************
 * Author: Raouf Magdy     *
 * Date: 27/1/2023         *
 * Version: V01            *
 ***************************/
 
 
 #ifndef LED_CONFIG_H
 #define LED_CONFIG_H
 
 
 #include "STD_Types.h"
 
 /***************How to use*****************
 
 typedef enum
 { 
	 Led_1_Name = 0,
	 Led_2_Name,
	 Led_3_Name
	 .
	 .
	 .
	 //and so on
	 Led_Count
 }Led_Counts;
  
 ********************************************/
 
 
 typedef enum
 {
	 Led_1 = 0,
	 Led_2,
	 Led_3,
	 Led_Count
 }Led_Counts;
 
 
 
 
 
 #endif
 
