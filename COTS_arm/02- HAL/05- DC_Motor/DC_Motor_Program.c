/***************************
 * Author: Raouf Magdy     *
 * Date: 16/6/2023         *
 * Version: V01            *
 ***************************/
 
 
 #include "STD_Types.h"
 #include "GPIO_Interface.h"
 #include "DC_Motor_Interface.h"
 
 
 MotorErrorStatus Motor_vidInit(void)
 {
	 GPIO_Config_t MotorEnableCFG;
	 GPIO_Config_t MotorPin1CFG;
	 GPIO_Config_t MotorPin2CFG; //object from GPIO_Config_t
	 u8 Motor_Index = 0;
	 MotorErrorStatus motorErrorStatus = Motor_OK;
	 
	 for(Motor_Index = 0; Motor_Index < Motor_Count; Motor_Index++)
	 {
		 MotorEnableCFG.GPIO_Port       = Motors_EnablePin_Config[Motor_Index].GPIO_Port;
		 MotorEnableCFG.GPIO_Pin        = Motors_EnablePin_Config[Motor_Index].GPIO_Pin;
		 MotorEnableCFG.GPIO_Mode_Speed = Motors_EnablePin_Config[Motor_Index].GPIO_Mode_Speed;

	     GPIO_enuInit(&MotorEnableCFG);
	 }

	 for(Motor_Index = 0; Motor_Index < Motor_Count; Motor_Index++)
	 {
		 MotorPin1CFG.GPIO_Port       = Motors_Pin1_Config[Motor_Index].GPIO_Port;
		 MotorPin1CFG.GPIO_Pin        = Motors_Pin1_Config[Motor_Index].GPIO_Pin;
		 MotorPin1CFG.GPIO_Mode_Speed = Motors_Pin1_Config[Motor_Index].GPIO_Mode_Speed;

	     GPIO_enuInit(&MotorPin1CFG);
	 }

	 for(Motor_Index = 0; Motor_Index < Motor_Count; Motor_Index++)
	 {
		 MotorPin2CFG.GPIO_Port       = Motors_Pin2_Config[Motor_Index].GPIO_Port;
		 MotorPin2CFG.GPIO_Pin        = Motors_Pin2_Config[Motor_Index].GPIO_Pin;
		 MotorPin2CFG.GPIO_Mode_Speed = Motors_Pin2_Config[Motor_Index].GPIO_Mode_Speed;

	     GPIO_enuInit(&MotorPin2CFG);
	 }
	  
	 return motorErrorStatus;
 }
 
 
 MotorErrorStatus Motor_vidSetDirection(u8 Motor, u8 Direction)
 {
	 MotorErrorStatus motorErrorStatus = Motor_OK;
	 GPIO_Config_t MotorEnableCFG;
	 GPIO_Config_t MotorPin1CFG;
	 GPIO_Config_t MotorPin2CFG;

	 MotorEnableCFG.GPIO_Value = PIN_SET ^ Motors_EnablePin_Config[Motor].GPIO_Value; //Enabling the "Enable" pin anyway

	 if(Direction == CW) {
		MotorPin1CFG.GPIO_Port  = Motors_Pin1_Config[Motor].GPIO_Port;
		MotorPin1CFG.GPIO_Pin   = Motors_Pin1_Config[Motor].GPIO_Pin;
	 	MotorPin1CFG.GPIO_Value = PIN_HIGH ^ Motors_Pin1_Config[Motor].GPIO_Value;

	 	MotorPin2CFG.GPIO_Port  = Motors_Pin2_Config[Motor].GPIO_Port;
	 	MotorPin2CFG.GPIO_Pin   = Motors_Pin2_Config[Motor].GPIO_Pin;
		MotorPin2CFG.GPIO_Value = PIN_LOW ^ Motors_Pin2_Config[Motor].GPIO_Value;
	 } else if(Direction == CCW) {
		 MotorPin1CFG.GPIO_Port  = Motors_Pin1_Config[Motor].GPIO_Port;
		 MotorPin1CFG.GPIO_Pin   = Motors_Pin1_Config[Motor].GPIO_Pin;
		 MotorPin1CFG.GPIO_Value = PIN_LOW ^ Motors_Pin1_Config[Motor].GPIO_Value;

		 MotorPin2CFG.GPIO_Port  = Motors_Pin2_Config[Motor].GPIO_Port;
		 MotorPin2CFG.GPIO_Pin   = Motors_Pin2_Config[Motor].GPIO_Pin;
		 MotorPin2CFG.GPIO_Value = PIN_HIGH ^ Motors_Pin2_Config[Motor].GPIO_Value;
	 } else {
		motorErrorStatus = Motor_WrongDirection;
	 }

	 GPIO_enuSetPinValue(&MotorEnableCFG);
	 GPIO_enuSetPinValue(&MotorPin1CFG);
	 GPIO_enuSetPinValue(&MotorPin2CFG);

	 return motorErrorStatus;
 }
 
 


 MotorErrorStatus Motor_vidDisable(u8 Motor)
 {
	 MotorErrorStatus motorErrorStatus = Motor_OK;

	 GPIO_Config_t MotorDisableCFG;
	 GPIO_Config_t MotorPin1CFG;
	 GPIO_Config_t MotorPin2CFG;

	 MotorDisableCFG.GPIO_Value = (PIN_LOW ^ Motors_EnablePin_Config[Motor].GPIO_Value);
	 MotorPin1CFG.GPIO_Value = 	  (PIN_LOW ^ Motors_EnablePin_Config[Motor].GPIO_Value);
	 MotorPin2CFG.GPIO_Value = 	  (PIN_LOW ^ Motors_EnablePin_Config[Motor].GPIO_Value);

	 GPIO_enuSetPinValue(&MotorDisableCFG);
	 GPIO_enuSetPinValue(&MotorPin1CFG);
	 GPIO_enuSetPinValue(&MotorPin2CFG);

	 return motorErrorStatus;
 }
 
 
 
 
 MotorErrorStatus Motor_enuPwmInit(u8 Motor){

	 MotorErrorStatus MotorErrorStatus = Motor_OK;

	 Motor_PWM_cfg_t MotorPwmCFG;

	 if(Motor < Zero || Motor > Motor_Count ){
		 MotorErrorStatus = Motor_WrongID;
	 }
	 else {
		 	 MotorPwmCFG.TIM_PWM_ID       = Motors_PWM_Config[Motor].TIM_PWM_ID;
		 	 MotorPwmCFG.TIM_PWM_SET_ARR  = Motors_PWM_Config[Motor].TIM_PWM_SET_ARR;
		 	 MotorPwmCFG.TIM_PWM_CCR1_VAL = Motors_PWM_Config[Motor].TIM_PWM_CCR1_VAL;
		 	 MotorPwmCFG.TIM_PWM_CCR2_VAL = Motors_PWM_Config[Motor].TIM_PWM_CCR2_VAL;
		 	 MotorPwmCFG.TIM_ARPE 		  = Motors_PWM_Config[Motor].TIM_ARPE;
		 	 MotorPwmCFG.TIM_CC1P 		  = Motors_PWM_Config[Motor].TIM_CC1P;
		 	 MotorPwmCFG.TIM_CC2P 		  = Motors_PWM_Config[Motor].TIM_CC2P;
		 	 MotorPwmCFG.TIM_CC1E  	      = Motors_PWM_Config[Motor].TIM_CC1E;
		 	 MotorPwmCFG.TIM_CC2E 		  = Motors_PWM_Config[Motor].TIM_CC2E;

		 	TIM_enuPwmMode(&MotorPwmCFG);
	 }

	 return MotorErrorStatus;
 }




 MotorErrorStatus Motor_enuSpeedControl(u8 Motor, u16 Speed){

	 MotorErrorStatus MotorErrorStatus = Motor_OK;

	 Motor_PWM_cfg_t MotorSpeedCFG;

	 if(Motor < Zero || Motor > Motor_Count ){
		 MotorErrorStatus = Motor_WrongID;
	 }
	 else {
		 	 MotorSpeedCFG.TIM_PWM_ID       = Motors_PWM_Config[Motor].TIM_PWM_ID;
		 	 MotorSpeedCFG.TIM_PWM_CCR1_VAL = Speed;
		 	 MotorSpeedCFG.TIM_PWM_CCR2_VAL = Speed;

		 	 TIM_enuPwmMode(&MotorSpeedCFG);
	 }

	 return MotorErrorStatus;
 }
 
 
 
 
 
 
 
 
 
 
 


