/********************************
 *  Author: Raouf Magdy         *
 *                              *
 *  Date: 01-02-2023            *
 *                              *
 *  Version: V_01               *
 *                              *
 ********************************/
 
 

#include "STD_Types.h"
#include "BIT_MATHs.h"
#include "GPIO_Private.h"
#include "GPIO_Interface.h"


//========================================================================================================//
//========================================= GPIO INITIALIZATION ==========================================//
//========================================================================================================//

GPIO_enuErrorStatus GPIO_enuInit(GPIO_Config_t *Add_strGpioCfgPtr)
{
	GPIO_enuErrorStatus Loc_GpioErrorStatus = GPIO_enuNotOK;
	
	GPIO_Regs_t *Add_strGpioRegsPtr = Add_strGpioCfgPtr -> GPIO_Port; 
	
	u8 Loc_u8GpioPinsIterator = 0;
	
	u32 Loc_u32_MODER_OTYPER_OSPEEDR_PUPDR_MASKER = 0;
	
	
	if(Add_strGpioCfgPtr == NULL){
		Loc_GpioErrorStatus = GPIO_enuErrorNullPointer;
	}
	else{
		for(Loc_u8GpioPinsIterator = 0; Loc_u8GpioPinsIterator < MAX_PINS_NUM; Loc_u8GpioPinsIterator++){
			if( (Add_strGpioCfgPtr -> GPIO_Pin)&(SINGLE_BIT << Loc_u8GpioPinsIterator) ) /* check if the pin is set to 1 */ 
			{
				//MODER_Config:
				Loc_u32_MODER_OTYPER_OSPEEDR_PUPDR_MASKER = ((Add_strGpioCfgPtr -> GPIO_Mode_Speed & GPIO_MODER_SEL) >> GPIO_MODER_SHIFT);      //Get the two bits of the MODER only from the passed value and right shift it with 0       
				Add_strGpioRegsPtr -> GPIO_MODER   &= ~(GPIO_MODER_CLR << (Loc_u8GpioPinsIterator * DOUBLE_BITS)); 
				Add_strGpioRegsPtr -> GPIO_MODER   |=  (Loc_u32_MODER_OTYPER_OSPEEDR_PUPDR_MASKER << (Loc_u8GpioPinsIterator * DOUBLE_BITS));
				
				//OTYPER_Config:
				Loc_u32_MODER_OTYPER_OSPEEDR_PUPDR_MASKER = ((Add_strGpioCfgPtr -> GPIO_Mode_Speed & GPIO_OTYPER_SEL) >> GPIO_OTYPER_SHIFT);    //Get the one bit of the OTYPER only from the passed value and right shift it with 2
				Add_strGpioRegsPtr -> GPIO_OTYPER  &= ~(GPIO_OTYPER_CLR << (Loc_u8GpioPinsIterator * SINGLE_BIT));
				Add_strGpioRegsPtr -> GPIO_OTYPER  |=  (Loc_u32_MODER_OTYPER_OSPEEDR_PUPDR_MASKER << (Loc_u8GpioPinsIterator * SINGLE_BIT));
				
				//OSPEEDR_Config:
				Loc_u32_MODER_OTYPER_OSPEEDR_PUPDR_MASKER = ((Add_strGpioCfgPtr -> GPIO_Mode_Speed & GPIO_OSPEEDR_SEL) >> GPIO_OSPEEDR_SHIFT);  //Get the two bits of the OSPEEDR only from the passed value and right shift it with 3
				Add_strGpioRegsPtr -> GPIO_OSPEEDR &= ~(GPIO_OSPEEDR_CLR << Loc_u8GpioPinsIterator * DOUBLE_BITS);
				Add_strGpioRegsPtr -> GPIO_OSPEEDR |=  (Loc_u32_MODER_OTYPER_OSPEEDR_PUPDR_MASKER << Loc_u8GpioPinsIterator * DOUBLE_BITS);
				
				//PUPDR_Config:
				Loc_u32_MODER_OTYPER_OSPEEDR_PUPDR_MASKER = ((Add_strGpioCfgPtr -> GPIO_Mode_Speed & GPIO_PUPDR_SEL) >> GPIO_PUPDR_SHIFT);      //Get the two bits of the PUPDR only from the passed value and right shift it with 5
				Add_strGpioRegsPtr -> GPIO_PUPDR   &= ~(GPIO_PUPDR_CLR << Loc_u8GpioPinsIterator * DOUBLE_BITS);
				Add_strGpioRegsPtr -> GPIO_PUPDR   |=  (Loc_u32_MODER_OTYPER_OSPEEDR_PUPDR_MASKER << Loc_u8GpioPinsIterator * DOUBLE_BITS);
			}
			else{
						/* Do Nothing */
				}
		}

			
		Loc_GpioErrorStatus = GPIO_enuOK;
	}	
	
	return Loc_GpioErrorStatus;
}


//========================================================================================================//
//========================================== GPIO SET PIN VALUE ==========================================//
//========================================================================================================//

GPIO_enuErrorStatus GPIO_enuSetPinValue(GPIO_Config_t *Add_strGpioCfgPtr)
{
	GPIO_enuErrorStatus Loc_GpioErrorStatus = GPIO_enuErrorPin;
	
	GPIO_Regs_t *Add_strGpioRegsPtr = Add_strGpioCfgPtr -> GPIO_Port;
	
	u32 Loc_u32BSRR = 0;
	u8  Loc_u8GpioPinsIterator = 0;
	
	if(Add_strGpioCfgPtr == NULL)
	{
		Loc_GpioErrorStatus = GPIO_enuErrorNullPointer;
	}

	else{
		for(Loc_u8GpioPinsIterator = 0; Loc_u8GpioPinsIterator < MAX_PINS_NUM; Loc_u8GpioPinsIterator++)
		{
			if( (Add_strGpioCfgPtr -> GPIO_Pin)&(SINGLE_BIT << Loc_u8GpioPinsIterator) )
			{
				Loc_u32BSRR = Add_strGpioCfgPtr -> GPIO_Value;
				Add_strGpioRegsPtr -> GPIO_BSRR &= ~(GPIO_BSRR_CLR << Loc_u8GpioPinsIterator);
				Add_strGpioRegsPtr -> GPIO_BSRR |=  (Loc_u32BSRR   << Loc_u8GpioPinsIterator);
			}
			else{ /* Do Nothing */ }	
		}
		Loc_GpioErrorStatus = GPIO_enuOK;
	}
	return Loc_GpioErrorStatus;
}


//========================================================================================================//
//==================================== GPIO SET ALTERNATIVE FUNCTION =====================================//
//========================================================================================================//

GPIO_enuErrorStatus GPIO_enuSetPinAlternateFunction(GPIO_AF_Config_t *Add_strGpioCfgPtr)
{
	GPIO_enuErrorStatus Loc_GpioErrorStatus = GPIO_enuErrorAlternateFunction;
	
	GPIO_Regs_t *Add_strGpioRegsPtr = Add_strGpioCfgPtr -> GPIO_PortAF;
	
	u32 Loc_u32AFR = 0;
	u8  Loc_u8GpioPinsIterator = 0;
	
	if(Add_strGpioCfgPtr == NULL){
		Loc_GpioErrorStatus = GPIO_enuErrorNullPointer;
	}
	else{
		if( (Add_strGpioCfgPtr -> GPIO_PinAF) <= AF_LOW_MAX){ //AFLR:
			for(Loc_u8GpioPinsIterator = 0; Loc_u8GpioPinsIterator < 8; Loc_u8GpioPinsIterator++)
			{
				if( (Add_strGpioCfgPtr -> GPIO_PinAF)&(SINGLE_BIT << Loc_u8GpioPinsIterator) )
				{
				   Loc_u32AFR = Add_strGpioCfgPtr -> GPIO_AF_Selection;
				   Add_strGpioRegsPtr -> GPIO_AFRL &= ~(GPIO_AFR_CLR << (Loc_u8GpioPinsIterator * QUADRA_BITS) );
				   Add_strGpioRegsPtr -> GPIO_AFRL |=  (Loc_u32AFR << (Loc_u8GpioPinsIterator * QUADRA_BITS) );
				}
			}
			Loc_GpioErrorStatus = GPIO_enuOK;
		}
		else{ //AFHR:
			for(Loc_u8GpioPinsIterator = 8; Loc_u8GpioPinsIterator < 16; Loc_u8GpioPinsIterator++)
			{
				if( (Add_strGpioCfgPtr -> GPIO_PinAF)&(SINGLE_BIT << Loc_u8GpioPinsIterator) )
				{
				   Loc_u32AFR = Add_strGpioCfgPtr -> GPIO_AF_Selection;
				   Add_strGpioRegsPtr -> GPIO_AFRH &= ~(GPIO_AFR_CLR << (Loc_u8GpioPinsIterator * QUADRA_BITS) );
				   Add_strGpioRegsPtr -> GPIO_AFRH |=  (Loc_u32AFR << (Loc_u8GpioPinsIterator * QUADRA_BITS) );
				}
			}
			Loc_GpioErrorStatus = GPIO_enuOK;
		}
	}
	return Loc_GpioErrorStatus;
}


//========================================================================================================//
//========================================== GPIO GET PIN VALUE ==========================================//
//========================================================================================================//

GPIO_enuGetPinStatus GPIO_enuGetPinValue(GPIO_Config_t *Add_strGpioCfgPtr, u8 Copy_u8PinNum)
{
	GPIO_enuGetPinStatus Loc_GpioGetErrorStatus = GPIO_enuGetBitLow;

	GPIO_Regs_t *Add_strGpioRegsPtr = Add_strGpioCfgPtr -> GPIO_Port;

	u32 Loc_u32BitGetter = 0;

	if(Add_strGpioCfgPtr == NULL){
		Loc_GpioGetErrorStatus = GPIO_enuErrorNullPointer;
	}
	else
	{
		if( (Add_strGpioCfgPtr -> GPIO_Pin)&(Copy_u8PinNum) )
		{
			//Loc_u32BitGetter = SINGLE_BIT << Copy_u8PinNum;

			Loc_u32BitGetter = Copy_u8PinNum;

			if( (Add_strGpioRegsPtr -> GPIO_IDR) & Loc_u32BitGetter)
			{
			  	Loc_GpioGetErrorStatus = GPIO_enuGetBitHigh;
			} else { Loc_GpioGetErrorStatus = GPIO_enuGetBitLow; }
	     }

	  return Loc_GpioGetErrorStatus;
    }

}

//========================================================================================================//
//========================================================================================================//
//========================================================================================================//
