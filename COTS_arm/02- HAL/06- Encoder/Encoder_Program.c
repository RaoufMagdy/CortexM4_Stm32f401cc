/***************************
* Author: Raouf Magdy     *
* Date: 19/06/2023        *
* Version: V01            *
***************************/
 

 #include"Encoder_Interface.h"
 #include"GPT_Interface.h"



 EncoderErrorStatus Encoders_enuInit(void){

        ENCODER_Config_t      EncoderTimerCFG;
        ENCODER_ICM_Config_t  EncoderTimerIcmCFG;

        EncoderErrorStatus EncoderStatus = Encoder_NotOK;
        u8 EncoderIdx = 0;

        for(EncoderIdx = 0; EncoderIdx < Encoder_Count; EncoderIdx++){
            //Applying Timer Configurations:
            EncoderTimerCFG.TIM_ID       = Encoders_Timers_Config[EncoderIdx].TIM_ID     ;
            EncoderTimerCFG.TIM_CNT_DIR  = Encoders_Timers_Config[EncoderIdx].TIM_CNT_DIR;
            EncoderTimerCFG.TIM_PRSC     = Encoders_Timers_Config[EncoderIdx].TIM_PRSC   ;
            TIM_enuInit(&EncoderTimerCFG);

            //Applying Timer Input Capture Mode Configureations:
            EncoderTimerIcmCFG.TIM_ICM_ID = Encoders_InputCaptureModer_Config[EncoderIdx].TIM_ICM_ID;
            EncoderTimerIcmCFG.TIM_IC1PSC = Encoders_InputCaptureModer_Config[EncoderIdx].TIM_IC1PSC;
            EncoderTimerIcmCFG.TIM_IC2PSC = Encoders_InputCaptureModer_Config[EncoderIdx].TIM_IC2PSC;
            EncoderTimerIcmCFG.TIM_CC1P   = Encoders_InputCaptureModer_Config[EncoderIdx].TIM_CC1P  ;
            EncoderTimerIcmCFG.TIM_CC2P   = Encoders_InputCaptureModer_Config[EncoderIdx].TIM_CC2P  ;
            EncoderTimerIcmCFG.TIM_CC1IE  = Encoders_InputCaptureModer_Config[EncoderIdx].TIM_CC1IE ;
            EncoderTimerIcmCFG.TIM_CC2IE  = Encoders_InputCaptureModer_Config[EncoderIdx].TIM_CC2IE ;
            EncoderTimerIcmCFG.TIM_TIE    = Encoders_InputCaptureModer_Config[EncoderIdx].TIM_TIE   ;
            TIM_enuInputCaptureMode(&EncoderTimerIcmCFG);

            EncoderStatus = Encoder_OK;
        }

        return EncoderStatus;
 }




 EncoderErrorStatus Encoders_enuStart(void){

        EncoderErrorStatus EncoderStatus = Encoder_OK;
        u8 Loc_u8NumberOfEncoders = Encoder_Count;

        switch(Loc_u8NumberOfEncoders)
        {
            case ONE_ENCODER:
                    TIM_enuEnableInterrupt(GPT_TIM2);
	                TIM_enuStart(GPT_TIM2);
            break;

            case TWO_ENCODERS:
                    TIM_enuEnableInterrupt(GPT_TIM3);
	                TIM_enuStart(GPT_TIM3);
            break;

            case THREE_ENCODERS:
                    TIM_enuEnableInterrupt(GPT_TIM4);
	                TIM_enuStart(GPT_TIM4);
            break;

            case FOUR_ENCODERS:
                    TIM_enuEnableInterrupt(GPT_TIM5);
	                TIM_enuStart(GPT_TIM5);
            break;

            default: EncoderStatus = Encoder_OutOfRange; 
        }

        return EncoderStatus;
 }























