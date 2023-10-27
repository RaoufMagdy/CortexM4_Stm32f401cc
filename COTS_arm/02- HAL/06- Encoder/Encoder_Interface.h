/***************************
 * Author: Raouf Magdy     *
 * Date: 19/06/2023        *
 * Version: V01            *
 ***************************/
 
 
 #ifndef ENCODER_INTERFACE_H
 #define ENCODER_INTERFACE_H


 #include "Encoder_Config.h"



 //Timer config str:
 typedef struct{
    void* TIM_ID;      //Pointer to timers registers
    u16   TIM_CNT_DIR; //Timer count direction
    u16   TIM_PRSC;    //Timer prescaler
 }ENCODER_Config_t;


 //Input Capture Mode config str:
 typedef struct{
    void* TIM_ICM_ID;     //Pointer to timers registers
    u8    TIM_IC1PSC : 2; //Input Capture 1 Prescaler 
    u8    TIM_IC2PSC : 2; //Input Capture 2 Prescaler
    u8    TIM_CC1P   : 1; //Capture/Compare 1 output Polarity
    u8    TIM_CC2P   : 1; //Capture/Compare 2 output Polarity
    u8    TIM_CC1IE  : 1; //Capture/Compare 1 Interrupt enable
    u8    TIM_CC2IE  : 1; //Capture/Compare 2 Interrupt enable
    u8    TIM_TIE    : 1; //Trigger Interrupt enable
 }ENCODER_ICM_Config_t;


 typedef enum{
	Encoder_OK = 0,
	Encoder_NotOK,
    Encoder_OutOfRange
 }EncoderErrorStatus;

 
 #define ONE_ENCODER    0x01
 #define TWO_ENCODERS   0x02
 #define THREE_ENCODERS 0x03
 #define FOUR_ENCODERS  0x04


 extern ENCODER_Config_t      Encoders_Timers_Config[Encoder_Count];
 extern ENCODER_ICM_Config_t  Encoders_InputCaptureModer_Config[Encoder_Count];


 EncoderErrorStatus Encoders_enuInit(void);
 EncoderErrorStatus Encoders_enuStart(void);
 //void               Encoder_vidGetSpeed(u8 Copy_u8EncoderID);






 #endif






