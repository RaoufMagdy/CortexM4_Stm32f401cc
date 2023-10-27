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
#include "RCC_Private.h"
#include "RCC_Interface.h"



//================================================================================================================//
//============================================ Select System Clock ===============================================//
//================================================================================================================//
RCC_enuErrorStatus RCC_enuSelectSystemClock(u8 Copy_u8ClockSelect)
{
	RCC_enuErrorStatus SystemClockStatus = RCC_enuNotOK;
	u16 TimeOut = 0;
	u32 Loc_u32ReisterMasker = 0;
	
	switch(Copy_u8ClockSelect)
	{
		case RCC_HSI:
			Loc_u32ReisterMasker = RCC_CR;         // Assign the value of RCC_CR to the masker.
			Loc_u32ReisterMasker &= RCC_HSION_CLR; // Clear the HSION bit from the masker value.
			Loc_u32ReisterMasker |= RCC_HSION_SET; // Setting the value of the HSION bit to the masker without changing other bits using OR operation.
			RCC_CR = Loc_u32ReisterMasker;         // Assigning the value of the masker to the RCC_CR register.
			
			//Check if HSI is ready
			while( (GET_BIT(RCC_CR,1) == 0) && (TimeOut < 5000) )
			{
				TimeOut++;
			}
			//Check timeout
			if(TimeOut < 4999)
			{
				//SW = HSI
				Loc_u32ReisterMasker = RCC_CFGR;         // Assign the value of RCC_CFGR to the masker.
				Loc_u32ReisterMasker &= RCC_SW_HSI_CLR;  // Clear the SW bits from the masker value.
				Loc_u32ReisterMasker |= RCC_SW_HSI_SET;  // Setting the values of SW0 and SW1 bits to the masker without changing other bits.
				RCC_CFGR = Loc_u32ReisterMasker;         // Assigning the value of the masker to the RCC_CR register.
				
				//CLR_BIT(RCC_CFGR, 0);
				//CLR_BIT(RCC_CFGR, 1);
				
				TimeOut = 0;
				while( (GET_BIT(RCC_CFGR,2) == 0)&&(GET_BIT(RCC_CFGR,3) == 0)&&(TimeOut < 5000) ) //Wait until SWS = HSI with Timeout
				{
					TimeOut++;
				}
				if(TimeOut < 4999)
				{
					SystemClockStatus = RCC_enuOK;
				}
				else
			    {
				    SystemClockStatus = RCC_enuNotOK;
			    }			
			}
			else
			{
				SystemClockStatus = RCC_enuNotOK;
			}	
		break;
		//=================================================================================
		case RCC_HSE:
			Loc_u32ReisterMasker = RCC_CR;         // Assign the value of RCC_CR to the masker.
			Loc_u32ReisterMasker &= RCC_HSEON_CLR; // Clear the HSION bit from the masker value.
			Loc_u32ReisterMasker |= RCC_HSEON_SET; // Setting the value of the HSEON bit to the masker without changing other bits using OR operation.
			RCC_CR = Loc_u32ReisterMasker;         // Assigning the value of the masker to the RCC_CR register.
			
			//Check if HSE is ready
			while( (GET_BIT(RCC_CR,16) == 0) && (TimeOut < 5000) )
			{
				TimeOut++;
			}
			//Check timeout
			if(TimeOut < 4999)
			{
				//SW = HSE
				Loc_u32ReisterMasker = RCC_CFGR;         // Assign the value of RCC_CFGR to the masker.
				Loc_u32ReisterMasker &= RCC_SW_HSE_CLR;  // Clear the SW bits from the masker value.
				Loc_u32ReisterMasker |= RCC_SW_HSE_SET;  // Setting the values of SW0 and SW1 bits to the masker without changing other bits.
				RCC_CFGR = Loc_u32ReisterMasker;         // Assigning the value of the masker to the RCC_CR register.				
				
				//SET_BIT(RCC_CFGR, 0);
				//CLR_BIT(RCC_CFGR, 1);
				
				TimeOut = 0;
				while( (GET_BIT(RCC_CFGR,2) == 1)&&(GET_BIT(RCC_CFGR,3) == 0)&&(TimeOut < 5000) ) //Wait until SWS = HSE with Timeout
				{
					TimeOut++;
				}
				if(TimeOut < 4999)
				{
					SystemClockStatus = RCC_enuOK;
				}
				else
			    {
				    SystemClockStatus = RCC_enuNotOK;
			    }			
			}
			else
			{
				SystemClockStatus = RCC_enuNotOK;
			}		
		break;
		//=================================================================================
		case RCC_PLL:
			Loc_u32ReisterMasker = RCC_CR;         // Assign the value of RCC_CR to the masker.
			Loc_u32ReisterMasker &= RCC_PLLON_CLR; // Clear the HSION bit from the masker value.
			Loc_u32ReisterMasker |= RCC_PLLON_SET; // Setting the value of the HSEON bit to the masker without changing other bits using OR operation.
			RCC_CR = Loc_u32ReisterMasker;         // Assigning the value of the masker to the RCC_CR register.
			
			//Check if PLL is ready
			while( (GET_BIT(RCC_CR,24) == 0) && (TimeOut < 5000) )
			{
				TimeOut++;
			}
			//Check timeout
			if(TimeOut < 4999)
			{
				//SW = PLL
				Loc_u32ReisterMasker = RCC_CFGR;         // Assign the value of RCC_CFGR to the masker.
				Loc_u32ReisterMasker &= RCC_SW_PLL_CLR;  // Clear the SW bits from the masker value.
				Loc_u32ReisterMasker |= RCC_SW_PLL_SET;  // Setting the values of SW0 and SW1 bits to the masker without changing other bits.
				RCC_CFGR = Loc_u32ReisterMasker;         // Assigning the value of the masker to the RCC_CR register.	
				
				//CLR_BIT(RCC_CFGR, 0);
				//SET_BIT(RCC_CFGR, 1);
				
				TimeOut = 0;
				while( (GET_BIT(RCC_CFGR,2) == 0)&&(GET_BIT(RCC_CFGR,3) == 1)&&(TimeOut < 5000) ) //Wait until SWS = PLL with Timeout
				{
					TimeOut++;
				}
				if(TimeOut < 4999)
				{
					SystemClockStatus = RCC_enuOK;
				}
				else
			    {
				    SystemClockStatus = RCC_enuNotOK;
			    }			
			}
			else
			{
				SystemClockStatus = RCC_enuNotOK;
			}		
		break;
		//=================================================================================
		default: SystemClockStatus = RCC_enuNotOK; break;
	}
	
	return SystemClockStatus;
}



//================================================================================================================//
//========================================== Select Peripheral Enable ============================================//
//================================================================================================================//
RCC_enuErrorStatus RCC_enuPeripheralEnable(u8 Copy_u8BusSelect, u32 Copy_u32PeripheralSelect)
{
	RCC_enuErrorStatus SystemClockStatus = RCC_PeripheralNotOK;
	
	switch(Copy_u8BusSelect)
	{
		case AHB1:			
			if( (Copy_u32PeripheralSelect & AHB1_Reserved) > 0 ) //Selecting a reserved bit in AHB1 
			{
				SystemClockStatus = RCC_PeripheralNotOK;
			}
			
			else
			{	
				RCC_AHB1ENR |= Copy_u32PeripheralSelect;
				SystemClockStatus = RCC_PeripheralOK;
			}
		break;
		//=================================================================================
		case AHB2:
            if( (Copy_u32PeripheralSelect & AHB2_Reserved) > 0 ) //Selecting a reserved bit in AHB2 
			{
				SystemClockStatus = RCC_PeripheralNotOK;
			}
			
			else
			{	
				RCC_AHB2ENR |= Copy_u32PeripheralSelect;
				SystemClockStatus = RCC_PeripheralOK;
			}
		break;
		//=================================================================================
		case APB1:
			if( (Copy_u32PeripheralSelect & APB1_Reserved) > 0 ) //Selecting a reserved bit in APB1 
			{
				SystemClockStatus = RCC_PeripheralNotOK;
			}
			
			else
			{	
				RCC_APB1ENR |= Copy_u32PeripheralSelect;
				SystemClockStatus = RCC_PeripheralOK;
			}
		break;
		//=================================================================================
		case APB2:			
			if( (Copy_u32PeripheralSelect & APB2_Reserved) > 0 ) //Selecting a reserved bit in APB2 
			{
				SystemClockStatus = RCC_PeripheralNotOK;
			}
			
			else
			{	
				RCC_APB2ENR |= Copy_u32PeripheralSelect;
				SystemClockStatus = RCC_PeripheralOK;
			}
		break;
		//=================================================================================
		default: SystemClockStatus = RCC_PeripheralNotOK; break;
	}
		
	return SystemClockStatus;
}


//================================================================================================================//
//========================================= Select Peripheral Disable ============================================//
//================================================================================================================//
RCC_enuErrorStatus RCC_enuPeripheralDisable(u8 Copy_u8BusSelect, u32 Copy_u32PeripheralSelect)
{
	RCC_enuErrorStatus SystemClockStatus = RCC_PeripheralNotOK;
	
	switch(Copy_u8BusSelect)
	{
		case AHB1:			
			if( (Copy_u32PeripheralSelect & AHB1_Reserved) > 0 ) //Selecting a reserved bit in AHB1 
			{
				SystemClockStatus = RCC_PeripheralNotOK;
			}
			
			else
			{	
				RCC_AHB1ENR &= ~(Copy_u32PeripheralSelect);
				SystemClockStatus = RCC_PeripheralOK;
			}
		break;
		//=================================================================================
		case AHB2:
            if( (Copy_u32PeripheralSelect & AHB2_Reserved) > 0 ) //Selecting a reserved bit in AHB2 
			{
				SystemClockStatus = RCC_PeripheralNotOK;
			}
			
			else
			{	
				RCC_AHB2ENR &= ~(Copy_u32PeripheralSelect);
				SystemClockStatus = RCC_PeripheralOK;
			}
		break;
		//=================================================================================
		case APB1:
			if( (Copy_u32PeripheralSelect & APB1_Reserved) > 0 ) //Selecting a reserved bit in APB1 
			{
				SystemClockStatus = RCC_PeripheralNotOK;
			}
			
			else
			{	
				RCC_APB1ENR &= ~(Copy_u32PeripheralSelect);
				SystemClockStatus = RCC_PeripheralOK;
			}
		break;
		//=================================================================================
		case APB2:			
			if( (Copy_u32PeripheralSelect & APB2_Reserved) > 0 ) //Selecting a reserved bit in APB2 
			{
				SystemClockStatus = RCC_PeripheralNotOK;
			}
			
			else
			{	
				RCC_APB2ENR &= ~(Copy_u32PeripheralSelect);
				SystemClockStatus = RCC_PeripheralOK;
			}
		break;
		//=================================================================================
		default: SystemClockStatus = RCC_PeripheralNotOK; break;
	}
		
	return SystemClockStatus;
}



//================================================================================================================//
//========================================= Select AHB Bus Prescaler =============================================//
//================================================================================================================//
RCC_enuErrorStatus RCC_enuAHBPrescaler(u32 Copy_u32PrescalerSelect)
{
	RCC_enuErrorStatus SystemClockStatus = RCC_enuNotOK;
	u32 Loc_u32ReisterMasker = 0;
	
	//Check the division option:
	if(
		Copy_u32PrescalerSelect == AHB_DIV_2   ||
		Copy_u32PrescalerSelect == AHB_DIV_4   ||
		Copy_u32PrescalerSelect == AHB_DIV_8   ||
		Copy_u32PrescalerSelect == AHB_DIV_16  ||
		Copy_u32PrescalerSelect == AHB_DIV_64  ||
		Copy_u32PrescalerSelect == AHB_DIV_128 ||
		Copy_u32PrescalerSelect == AHB_DIV_256 ||
		Copy_u32PrescalerSelect == AHB_DIV_512 
	)
	
	{
		Loc_u32ReisterMasker = RCC_CFGR;
		Loc_u32ReisterMasker &= RCC_AHB_DIV_CLR;
		Loc_u32ReisterMasker |= Copy_u32PrescalerSelect;
		RCC_CFGR = Loc_u32ReisterMasker;

		SystemClockStatus = RCC_enuOK;
	}
	
	else
	{
		SystemClockStatus = RCC_enuNotOK;
	}
		
	return SystemClockStatus;
}



//================================================================================================================//
//========================================= Select APB1 Bus Prescaler ============================================//
//================================================================================================================//
RCC_enuErrorStatus RCC_enuAPB1Prescaler(u32 Copy_u32PrescalerSelect)
{
	RCC_enuErrorStatus SystemClockStatus = RCC_enuNotOK;
	u32 Loc_u32ReisterMasker = 0;
	
	//Check the division option:
	if(
		Copy_u32PrescalerSelect == APB1_DIV_2   ||
		Copy_u32PrescalerSelect == APB1_DIV_4   ||
		Copy_u32PrescalerSelect == APB1_DIV_8   ||
		Copy_u32PrescalerSelect == APB1_DIV_16
	)
	
	{
		Loc_u32ReisterMasker = RCC_CFGR;
		Loc_u32ReisterMasker &= RCC_APB1_DIV_CLR;
		Loc_u32ReisterMasker |= Copy_u32PrescalerSelect;
		RCC_CFGR = Loc_u32ReisterMasker;

		SystemClockStatus = RCC_enuOK;
	}
	
	else
	{
		SystemClockStatus = RCC_enuNotOK;
	}
		
	return SystemClockStatus;
}



//================================================================================================================//
//========================================= Select APB1 Bus Prescaler ============================================//
//================================================================================================================//
RCC_enuErrorStatus RCC_enuAPB2Prescaler(u32 Copy_u32PrescalerSelect)
{
	RCC_enuErrorStatus SystemClockStatus = RCC_enuNotOK;
	u32 Loc_u32ReisterMasker = 0;
	
	//Check the division option:
	if(
		Copy_u32PrescalerSelect == APB2_DIV_2   ||
		Copy_u32PrescalerSelect == APB2_DIV_4   ||
		Copy_u32PrescalerSelect == APB2_DIV_8   ||
		Copy_u32PrescalerSelect == APB2_DIV_16
	)
	
	{
		Loc_u32ReisterMasker = RCC_CFGR;
		Loc_u32ReisterMasker &= RCC_APB2_DIV_CLR;
		Loc_u32ReisterMasker |= Copy_u32PrescalerSelect;
		RCC_CFGR = Loc_u32ReisterMasker;

		SystemClockStatus = RCC_enuOK;
	}
	
	else
	{
		SystemClockStatus = RCC_enuNotOK;
	}
		
	return SystemClockStatus;
}



//================================================================================================================//
//======================================== Set Clock PLL Configurations ==========================================//
//================================================================================================================//
 RCC_enuErrorStatus RCC_enuConfigurePLL(u8 Copy_u8PLLSource, u8 Copy_u8PLLM, u16 Copy_u16PLLN, u8 Copy_u8PLLP)
{
	RCC_enuErrorStatus SystemClockStatus = RCC_enuPLLNotOK;
	u32 Loc_u32ReisterMasker = 0;
	u32 Loc_u32RegisterMaskerPLL = 0;
	
	//Check the PLL Source, PLLM, PLLN and PLLP:
	if(	
	    (Copy_u8PLLSource == 0 || Copy_u8PLLSource == 1) &&
		(Copy_u8PLLM >= 2 && Copy_u8PLLM <= 63)          &&
		(Copy_u16PLLN >= 192 && Copy_u16PLLN <= 432)     &&
		(Copy_u8PLLP == 2 || Copy_u8PLLP == 4 || Copy_u8PLLP == 6 || Copy_u8PLLP == 8)
	)
	{
		//DISABLE PLL CLOCK CODE:::===>
		Loc_u32RegisterMaskerPLL = RCC_CR;
		Loc_u32RegisterMaskerPLL &= RCC_CRPLLON_CLR;
		RCC_CR = Loc_u32RegisterMaskerPLL; //Clear bits PLLON & PLLI2SON to start configuration of PLL
		//================================
		Loc_u32ReisterMasker = RCC_PLLCFGR;
		
		Loc_u32ReisterMasker &= RCC_PLLM_CLR;
		Loc_u32ReisterMasker |= (Copy_u8PLLM << 0);
		
		Loc_u32ReisterMasker &= RCC_PLLN_CLR;
		Loc_u32ReisterMasker |= (Copy_u16PLLN << 6);
		
		Loc_u32ReisterMasker &= RCC_PLLP_CLR;
		Loc_u32ReisterMasker |= (Copy_u8PLLP << 16);
		
		Loc_u32ReisterMasker &= RCC_PLLSRC_CLR;
		Loc_u32ReisterMasker |= (Copy_u8PLLSource << 22);
		
		RCC_PLLCFGR = Loc_u32ReisterMasker;
		//================================
		Loc_u32RegisterMaskerPLL = RCC_CR;
		Loc_u32RegisterMaskerPLL &= RCC_CRPLLON_CLR;
		Loc_u32RegisterMaskerPLL |= RCC_CRPLLON_SET;
		RCC_CR = Loc_u32RegisterMaskerPLL; //Set bits PLLON & PLLI2SON to finish configuration of PLL
		//================================
		
		SystemClockStatus = RCC_enuPLLOK;
	}
	
	else
	{
		SystemClockStatus = RCC_enuPLLNotOK;
	}

	return SystemClockStatus;
}



//================================================================================================================//
//=============================================== Get Ready Clock ================================================//
//================================================================================================================//
RCC_enuErrorStatus RCC_enuGetReadyClock(void)
{
	RCC_enuErrorStatus SystemClockStatus = RCC_enuHSI_RDY;
	
	if( GET_BIT(RCC_CR,0) == 1 )
	{
		SystemClockStatus = RCC_enuHSI_RDY;
	}
	
	if( GET_BIT(RCC_CR,16) == 1 )
	{
		SystemClockStatus = RCC_enuHSE_RDY;
	}
	
	else
	{
		SystemClockStatus = RCC_enuHSI_RDY;
	}
	
	return SystemClockStatus;
}

