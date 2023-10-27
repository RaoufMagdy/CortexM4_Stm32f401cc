/***************************
 * Author: Raouf Magdy     *
 * Date: 16/6/2023         *
 * Version: V01            *
 ***************************/
 
 
 
 #ifndef DC_MOTOR_INTERFACE_H
 #define DC_MOTOR_INTERFACE_H
 
 
 #include "DC_Motor_Config.h"


 typedef struct
 {
	 void* GPIO_Port;
	 u16   GPIO_Pin;
	 u32   GPIO_Mode_Speed;
	 u8    GPIO_Value;
 }Motor_EnablePin_cfg_t;

 typedef struct
 {
	 void* GPIO_Port;
	 u16   GPIO_Pin;
	 u32   GPIO_Mode_Speed;
	 u8    GPIO_Value;
 }Motor_Pin1_cfg_t;

 typedef struct
 {
	 void* GPIO_Port;
	 u16   GPIO_Pin;
	 u32   GPIO_Mode_Speed;
	 u8    GPIO_Value;
 }Motor_Pin2_cfg_t;


 //Motor PWM config str:
  typedef struct{
 	void* TIM_PWM_ID;       //Pointer to timers PWM registers
 	u16   TIM_PWM_SET_ARR;  //Set Auto Reload Register (PWM period)
 	u16   TIM_PWM_CCR1_VAL; //CCR1 PWM value
 	u16   TIM_PWM_CCR2_VAL; //CCR2 PWM value
 	u8    TIM_ARPE : 1; 	//Auto-reload preload enable
 	u8    TIM_CC1P : 1; 	//Capture/Compare 1 output Polarity
 	u8    TIM_CC2P : 1; 	//Capture/Compare 2 output Polarity
 	u8    TIM_CC1E : 1;     //Capture/Compare 1 output enable
 	u8    TIM_CC2E : 1;     //Capture/Compare 2 output enable
  }Motor_PWM_cfg_t;


 extern Motor_EnablePin_cfg_t Motors_EnablePin_Config[Motor_Count];
 extern Motor_Pin1_cfg_t 	  Motors_Pin1_Config[Motor_Count];
 extern Motor_Pin2_cfg_t 	  Motors_Pin2_Config[Motor_Count];
 extern Motor_PWM_cfg_t       Motors_PWM_Config[Motor_Count];
 
 
 typedef enum{
	 
	 Motor_OK = 0,
	 Motor_NotOK,
	 Motor_WrongID,
	 Motor_WrongDirection
	 
 }MotorErrorStatus;
 
 
 #define PIN_SET	0x00000001
 #define PIN_RESET	0x00010000
 #define PIN_HIGH	0x00000001
 #define PIN_LOW	0x00010000
 #define HIGH	    0x00000001
 #define LOW	    0x00010000
 #define CW         0xAA
 #define CCW        0x55
 
 #define Zero       0x00

 //Motors Initialization
 MotorErrorStatus Motor_vidInit(void);
 
 //Motors Set State:
 MotorErrorStatus Motor_vidSetDirection(u8 Motor, u8 Direction);

 //Motors Disable
 MotorErrorStatus Motor_vidDisable(u8 Motor);
 
 //Motors PWM Configuration Initialization:
 MotorErrorStatus Motor_enuPwmInit(u8 Motor);

 //Motors Speed Control:
 MotorErrorStatus Motor_enuSpeedControl(u8 Motor, u16 Speed);


 
 
 
 
 
 #endif
 
