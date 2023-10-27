/********************************
 *  Author:  Raouf Magdy        *
 *                              *
 *  Date:    18-06-2023         *
 *                              *
 *  Version: V_01               *
 ********************************/

#include "STD_Types.h"
#include "BIT_MATHs.h"
#include "GPT_Private.h"
#include "GPT_Interface.h"
#include "stm32f4xx.h"


//========================================================================================================//
//========================================== GPT INITIALIZATION ==========================================//
//========================================================================================================//

TIM_enuErrorStatus TIM_enuInit(TIM_Config_t *Add_strTimCfgPtr){

    TIM_enuErrorStatus TimErrorStatus = TIM_enuOK;

    GPT_Regs_t *Add_strGptRegsPtr = Add_strTimCfgPtr -> TIM_ID;

    if(Add_strGptRegsPtr == NULL){
        TimErrorStatus = TIM_enuNullPointer;
    }
    else if( Add_strGptRegsPtr != TIM_2 &&
             Add_strGptRegsPtr != TIM_3 &&
             Add_strGptRegsPtr != TIM_4 &&
             Add_strGptRegsPtr != TIM_5
           ) {   TimErrorStatus = TIM_enuIdError;    }

    else{
            Add_strGptRegsPtr -> TIM_CR1 &= TIM_CNT_DIR_CLR; //Clear the direction bit in TIM_CR1 register.
            Add_strGptRegsPtr -> TIM_CR1 |= Add_strTimCfgPtr -> TIM_CNT_DIR; //Set the DIR bit in TIM_CR1 register by the configured value.

            Add_strGptRegsPtr -> TIM_PSC &= TIM_PSC_CLR; //Clear the prescaler value in TIM_PSC register
            Add_strGptRegsPtr -> TIM_PSC |= Add_strTimCfgPtr -> TIM_PRSC & TIM_PSC_GET_VAL; //Set the PSC register value according to configurations.
    }

    return TimErrorStatus;
}


//========================================================================================================//
//======================================== GPT INPUT CAPTURE MODE ========================================//
//========================================================================================================//

TIM_enuErrorStatus TIM_enuInputCaptureMode(TIM_ICM_Config_t *Add_strTimCfgPtr){

    TIM_enuErrorStatus TimErrorStatus = TIM_enuOK;

    GPT_Regs_t *Add_strGptRegsPtr = Add_strTimCfgPtr -> TIM_ICM_ID;

    if(Add_strGptRegsPtr == NULL){
        TimErrorStatus = TIM_enuNullPointer;
    }
    else if( Add_strGptRegsPtr != TIM_2 &&
             Add_strGptRegsPtr != TIM_3 &&
             Add_strGptRegsPtr != TIM_4 &&
             Add_strGptRegsPtr != TIM_5
           ) {   TimErrorStatus = TIM_enuIdError;    }

    else{
             Add_strGptRegsPtr -> TIM_CCMR1 &= TIM_CCMR1_CLR; // Clear TIM_CCMR1 register.
             Add_strGptRegsPtr -> TIM_CCMR1 |= TIM_CCMR1_CC1S_TI1_CC2S_TI2; // Map CC1S to TI1 and CC2S to TI2 (PA0 & PA1).

             Add_strGptRegsPtr -> TIM_CCMR1 |= Add_strTimCfgPtr -> TIM_IC1PSC << DOUBLE_BITS; //Setting the value for IC1 Prescaler.
             Add_strGptRegsPtr -> TIM_CCMR1 |= Add_strTimCfgPtr -> TIM_IC2PSC << EIGHT_BITS; //Setting the value for IC1 Prescaler.

             Add_strGptRegsPtr -> TIM_CCER  &= TIM_CCER_INPUT; //Setting CCxE bits to be input.
             Add_strGptRegsPtr -> TIM_CCER  |= Add_strTimCfgPtr -> TIM_CC1P  << SINGLE_BIT;  //Select CC1P rising or falling.
             Add_strGptRegsPtr -> TIM_CCER  |= Add_strTimCfgPtr -> TIM_CC2P  << PENTA_BITS;  //Select CC2P rising or falling.

             Add_strGptRegsPtr -> TIM_DIER  &= TIM_DIER_CLR; //Clear the Interrupt Enable register.
             Add_strGptRegsPtr -> TIM_DIER  |= Add_strTimCfgPtr -> TIM_CC1IE << SINGLE_BIT;
             Add_strGptRegsPtr -> TIM_DIER  |= Add_strTimCfgPtr -> TIM_CC2IE << DOUBLE_BITS;
             Add_strGptRegsPtr -> TIM_DIER  |= Add_strTimCfgPtr -> TIM_TIE   << HEXA_BITS; //Trigger Interrupt.
    }

    return TimErrorStatus;
}


//========================================================================================================//
//========================================= GPT INTERRUPT ENABLE =========================================//
//========================================================================================================//

TIM_enuErrorStatus TIM_enuEnableInterrupt(u8 Copy_u8TimID){

    TIM_enuErrorStatus TimErrorStatus = TIM_enuOK;

    switch(Copy_u8TimID)
    {
        case GPT_TIM2: NVIC_EnableIRQ(TIM2_IRQn); break;
        case GPT_TIM3: NVIC_EnableIRQ(TIM3_IRQn); break;
        case GPT_TIM4: NVIC_EnableIRQ(TIM4_IRQn); break;
        case GPT_TIM5: NVIC_EnableIRQ(TIM5_IRQn); break;
        default: TimErrorStatus = TIM_enuIdError; break;
    }

    return TimErrorStatus;
}


//========================================================================================================//
//======================================= GPT START TIMER/COUNTER ========================================//
//========================================================================================================//

TIM_enuErrorStatus TIM_enuStart(u8 Copy_u8TimID){

    TIM_enuErrorStatus TimErrorStatus = TIM_enuOK;

    TIM_Config_t *Add_strTimCfgPtr;

    GPT_Regs_t *Add_strGptRegsPtr;

    switch(Copy_u8TimID)
    {
        case GPT_TIM2: 
            Add_strTimCfgPtr -> TIM_ID = TIM_2;
            Add_strGptRegsPtr = Add_strTimCfgPtr -> TIM_ID;
            Add_strGptRegsPtr ->TIM_CR1  |= TIM_START;    
        break;

        case GPT_TIM3: 
            Add_strTimCfgPtr -> TIM_ID = TIM_3;
            Add_strGptRegsPtr = Add_strTimCfgPtr -> TIM_ID;
            Add_strGptRegsPtr ->TIM_CR1  |= TIM_START;    
        break;

        case GPT_TIM4: 
            Add_strTimCfgPtr -> TIM_ID = TIM_4;
            Add_strGptRegsPtr = Add_strTimCfgPtr -> TIM_ID;
            Add_strGptRegsPtr ->TIM_CR1  |= TIM_START;    
        break;

        case GPT_TIM5: 
            Add_strTimCfgPtr -> TIM_ID = TIM_5;
            Add_strGptRegsPtr = Add_strTimCfgPtr -> TIM_ID;
            Add_strGptRegsPtr ->TIM_CR1  |= TIM_START;    
        break;

        default: TimErrorStatus = TIM_enuIdError; break;
    }

    return TimErrorStatus;
}


//========================================================================================================//
//======================================== GPT STOP TIMER/COUNTER ========================================//
//========================================================================================================//

TIM_enuErrorStatus TIM_enuStop(u8 Copy_u8TimID){

     TIM_enuErrorStatus TimErrorStatus = TIM_enuOK;

    TIM_Config_t *Add_strTimCfgPtr;

    GPT_Regs_t *Add_strGptRegsPtr;

    switch(Copy_u8TimID)
    {
        case GPT_TIM2: 
            Add_strTimCfgPtr -> TIM_ID = TIM_2;
            Add_strGptRegsPtr = Add_strTimCfgPtr -> TIM_ID;
            Add_strGptRegsPtr ->TIM_CR1  |= TIM_STOP;    
        break;

        case GPT_TIM3: 
            Add_strTimCfgPtr -> TIM_ID = TIM_3;
            Add_strGptRegsPtr = Add_strTimCfgPtr -> TIM_ID;
            Add_strGptRegsPtr ->TIM_CR1  |= TIM_STOP;    
        break;

        case GPT_TIM4: 
            Add_strTimCfgPtr -> TIM_ID = TIM_4;
            Add_strGptRegsPtr = Add_strTimCfgPtr -> TIM_ID;
            Add_strGptRegsPtr ->TIM_CR1  |= TIM_STOP;    
        break;

        case GPT_TIM5: 
            Add_strTimCfgPtr -> TIM_ID = TIM_5;
            Add_strGptRegsPtr = Add_strTimCfgPtr -> TIM_ID;
            Add_strGptRegsPtr ->TIM_CR1  |= TIM_STOP;    
        break;

        default: TimErrorStatus = TIM_enuIdError; break;
    }

    return TimErrorStatus;
}


//========================================================================================================//
//============================================= GPT PWM MODE =============================================//
//========================================================================================================//

TIM_enuErrorStatus TIM_enuPwmMode(TIM_PWM_Config_t *Add_strTimCfgPtr){

	TIM_enuErrorStatus TimErrorStatus = TIM_enuOK;

	    GPT_Regs_t *Add_strGptRegsPtr = Add_strTimCfgPtr -> TIM_PWM_ID;

	    if(Add_strGptRegsPtr == NULL){
	        TimErrorStatus = TIM_enuNullPointer;
	    }
	    else if( Add_strGptRegsPtr != TIM_2 &&
	             Add_strGptRegsPtr != TIM_3 &&
	             Add_strGptRegsPtr != TIM_4 &&
	             Add_strGptRegsPtr != TIM_5
	           ) {   TimErrorStatus = TIM_enuIdError;    }
	    else{

	    		 Add_strGptRegsPtr -> TIM_CCMR1 &= TIM_PWM_CLR;
	    		 Add_strGptRegsPtr -> TIM_CCMR1 |= TIM_PWM1_SET; //Set OC1M & OC2M to PWM 1 Mode

	    		 Add_strGptRegsPtr -> TIM_ARR   &= TIM_ARR_CLR;
	    		 Add_strGptRegsPtr -> TIM_ARR   |= Add_strTimCfgPtr -> TIM_PWM_SET_ARR;


	    		 Add_strGptRegsPtr -> TIM_CCR1  &= TIM_CCRx_CLR;  //Clear the CCR1 & CCR2 Registers
	    		 Add_strGptRegsPtr -> TIM_CCR2  &= TIM_CCRx_CLR;
	    		 Add_strGptRegsPtr -> TIM_CCR1  |= Add_strTimCfgPtr -> TIM_PWM_CCR1_VAL; //Set the configured value CCR1
	    		 Add_strGptRegsPtr -> TIM_CCR2  |= Add_strTimCfgPtr -> TIM_PWM_CCR2_VAL; //Set the configured value CCR2
	    }

	    return TimErrorStatus;
}



