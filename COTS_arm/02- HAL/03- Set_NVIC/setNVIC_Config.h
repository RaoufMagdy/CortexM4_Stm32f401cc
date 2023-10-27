/***************************
 * Author: Raouf Magdy     *
 * Date: 27/1/2023         *
 * Version: V01            *
 ***************************/
 
 
 #ifndef setNVIC_CONFIG_H
 #define setNVIC_CONFIG_H
 
 
 
 
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
 
 /*
 typedef enum
 {
	 Led_Red = 0,
	 Led_Green,
	 Led_Blue,
	 Led_Count
 }Led_Counts;
 
 
 
 typedef struct
 {
	 void* GPIO_Port;
	 u16   GPIO_Pin;
	 u32   GPIO_Mode_Speed;
	 u8    GPIO_Value;
 }Led_cfg_t;
 
 
 extern Led_cfg_t Leds_Config[Led_Count];
 */
 
 
 
 
 typedef enum{
	 INT_1 = 0,
	 INT_2,
	 INT_3,
	 INT_Count
 }INT_Counts;
 
 typedef struct{
	 void *NVIC_Reg;
	 u32   NVIC_Bit;
	 u8    NVIC_RegNum;
 }INT_cfg_t;
 
 
 
 extern INT_cfg_t INTs_Config[INT_Count];
 
 
 
 #endif
 