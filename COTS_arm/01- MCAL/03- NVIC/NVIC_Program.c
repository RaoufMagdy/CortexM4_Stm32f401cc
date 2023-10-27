/********************************
 *  Author: Raouf Magdy         *
 *                              *
 *  Date: 03-03-2023            *
 *                              *
 *  Version: V_01               *
 *                              *
 ********************************/
 
 

 #include "STD_Types.h"
 #include "BIT_MATHs.h"
 #include "NVIC_Private.h"
 #include "NVIC_Interface.h"
 
 
 //========================================================================================================//
 //======================================== NVIC ENABLE REGISTER ==========================================//
 //========================================================================================================//
 
 NVIC_enuErrorStatus NVIC_EnableIRQ(NVIC_Config_t *Add_strNvicCfgPtr)
 {
	 NVIC_enuErrorStatus Loc_enuNvicErrorStatus = NVIC_enuNotOK;
	 
	 NVIC_ISER_t *Add_strNvicIserPtr = Add_strNvicCfgPtr -> NVIC_Reg;
	 NVIC_ICER_t *Add_strNvicIcerPtr = Add_strNvicCfgPtr -> NVIC_Reg;

	 u8  Loc_u8BitsIterator = 0;
	 
	if(Add_strNvicCfgPtr == NULL){
		Loc_enuNvicErrorStatus = NVIC_enuNullPointer;
	}
	
	else
	{
		for(Loc_u8BitsIterator = 0; Loc_u8BitsIterator < MAX_NVIC_BIT; Loc_u8BitsIterator++)
		{
			if( (Add_strNvicCfgPtr -> NVIC_Bit)&(SINGLE_BIT << Loc_u8BitsIterator) )
			{
				switch(Add_strNvicCfgPtr -> NVIC_RegNum)
				{
					case ISER0:			
					     Add_strNvicIcerPtr -> NVIC_ICER0 &= ~(NVIC_REG_CLR << Loc_u8BitsIterator); //Clear the corresponding bit in ICER0 register
					     Add_strNvicIserPtr -> NVIC_ISER0 |=  (NVIC_REG_SET << Loc_u8BitsIterator); //Set the corresponding bit in ISER0 register
					break;
					
					case ISER1:			
					     Add_strNvicIcerPtr -> NVIC_ICER1 &= ~(NVIC_REG_CLR << Loc_u8BitsIterator); //Clear the corresponding bit in ICER0 register
					     Add_strNvicIserPtr -> NVIC_ISER1 |=  (NVIC_REG_SET << Loc_u8BitsIterator); //Set the corresponding bit in ISER0 register
					break;
					
					case ISER2:			
					     Add_strNvicIcerPtr -> NVIC_ICER2 &= ~(NVIC_REG_CLR << Loc_u8BitsIterator); //Clear the corresponding bit in ICER0 register
					     Add_strNvicIserPtr -> NVIC_ISER2 |=  (NVIC_REG_SET << Loc_u8BitsIterator); //Set the corresponding bit in ISER0 register
					break;
					
					case ISER3:			
					     Add_strNvicIcerPtr -> NVIC_ICER3 &= ~(NVIC_REG_CLR << Loc_u8BitsIterator); //Clear the corresponding bit in ICER0 register
					     Add_strNvicIserPtr -> NVIC_ISER3 |=  (NVIC_REG_SET << Loc_u8BitsIterator); //Set the corresponding bit in ISER0 register
					break;
					
					case ISER4:			
					     Add_strNvicIcerPtr -> NVIC_ICER4 &= ~(NVIC_REG_CLR << Loc_u8BitsIterator); //Clear the corresponding bit in ICER0 register
					     Add_strNvicIserPtr -> NVIC_ISER4 |=  (NVIC_REG_SET << Loc_u8BitsIterator); //Set the corresponding bit in ISER0 register
					break;
					
					case ISER5:			
					     Add_strNvicIcerPtr -> NVIC_ICER5 &= ~(NVIC_REG_CLR << Loc_u8BitsIterator); //Clear the corresponding bit in ICER0 register
					     Add_strNvicIserPtr -> NVIC_ISER5 |=  (NVIC_REG_SET << Loc_u8BitsIterator); //Set the corresponding bit in ISER0 register
					break;
					
					case ISER6:			
					     Add_strNvicIcerPtr -> NVIC_ICER6 &= ~(NVIC_REG_CLR << Loc_u8BitsIterator); //Clear the corresponding bit in ICER0 register
					     Add_strNvicIserPtr -> NVIC_ISER6 |=  (NVIC_REG_SET << Loc_u8BitsIterator); //Set the corresponding bit in ISER0 register
					break;
					
					case ISER7:			
					     Add_strNvicIcerPtr -> NVIC_ICER7 &= ~(NVIC_REG_CLR << Loc_u8BitsIterator); //Clear the corresponding bit in ICER0 register
					     Add_strNvicIserPtr -> NVIC_ISER7 |=  (NVIC_REG_SET << Loc_u8BitsIterator); //Set the corresponding bit in ISER0 register
					break;
						
					default: Loc_enuNvicErrorStatus = NVIC_enuNotOK; break;
				}
			}
		}
		
		Loc_enuNvicErrorStatus = NVIC_enuOK;
	}
	
	return Loc_enuNvicErrorStatus;
 }
 
 
 //========================================================================================================//
 //======================================== NVIC DISABLE REGISTER =========================================//
 //========================================================================================================//
 
 NVIC_enuErrorStatus NVIC_DisableIRQ(NVIC_Config_t *Add_strNvicCfgPtr)
 {
	 NVIC_enuErrorStatus Loc_enuNvicErrorStatus = NVIC_enuNotOK;
	 
	 NVIC_ICER_t *Add_strNvicIcerPtr = Add_strNvicCfgPtr -> NVIC_Reg;
	 NVIC_ISER_t *Add_strNvicIserPtr = Add_strNvicCfgPtr -> NVIC_Reg;
	 
	 u8  Loc_u8BitsIterator = 0;
	 
	if(Add_strNvicCfgPtr == NULL){
		Loc_enuNvicErrorStatus = NVIC_enuNullPointer;
	}
	
	else
	{
		for(Loc_u8BitsIterator = 0; Loc_u8BitsIterator < MAX_NVIC_BIT; Loc_u8BitsIterator++)
		{
			if( (Add_strNvicCfgPtr -> NVIC_Bit)&(SINGLE_BIT << Loc_u8BitsIterator) )
			{
				switch(Add_strNvicCfgPtr -> NVIC_RegNum)
				{
					case ICER0:			
					     Add_strNvicIserPtr -> NVIC_ISER0 &= ~(NVIC_REG_CLR << Loc_u8BitsIterator); 
					     Add_strNvicIcerPtr -> NVIC_ICER0 |=  (NVIC_REG_SET << Loc_u8BitsIterator); 
					break;
					
					case ICER1:			
					     Add_strNvicIserPtr -> NVIC_ISER1 &= ~(NVIC_REG_CLR << Loc_u8BitsIterator); 
					     Add_strNvicIcerPtr -> NVIC_ICER1 |=  (NVIC_REG_SET << Loc_u8BitsIterator); 
					break;
					
					case ICER2:			
					     Add_strNvicIserPtr -> NVIC_ISER2 &= ~(NVIC_REG_CLR << Loc_u8BitsIterator); 
					     Add_strNvicIcerPtr -> NVIC_ICER2 |=  (NVIC_REG_SET << Loc_u8BitsIterator); 
					break;
					
					case ICER3:			
					     Add_strNvicIserPtr -> NVIC_ISER3 &= ~(NVIC_REG_CLR << Loc_u8BitsIterator); 
					     Add_strNvicIcerPtr -> NVIC_ICER3 |=  (NVIC_REG_SET << Loc_u8BitsIterator); 
					break;
					
					case ICER4:			
					     Add_strNvicIserPtr -> NVIC_ISER4 &= ~(NVIC_REG_CLR << Loc_u8BitsIterator); 
					     Add_strNvicIcerPtr -> NVIC_ICER4 |=  (NVIC_REG_SET << Loc_u8BitsIterator); 
					break;
					
					case ICER5:			
					     Add_strNvicIserPtr -> NVIC_ISER5 &= ~(NVIC_REG_CLR << Loc_u8BitsIterator); 
					     Add_strNvicIcerPtr -> NVIC_ICER5 |=  (NVIC_REG_SET << Loc_u8BitsIterator); 
					break;
					
					case ICER6:			
					     Add_strNvicIserPtr -> NVIC_ISER6 &= ~(NVIC_REG_CLR << Loc_u8BitsIterator); 
					     Add_strNvicIcerPtr -> NVIC_ICER6 |=  (NVIC_REG_SET << Loc_u8BitsIterator); 
					break;
					
					case ICER7:			
					     Add_strNvicIserPtr -> NVIC_ISER7 &= ~(NVIC_REG_CLR << Loc_u8BitsIterator); 
					     Add_strNvicIcerPtr -> NVIC_ICER7 |=  (NVIC_REG_SET << Loc_u8BitsIterator); 
					break;
						
					default: Loc_enuNvicErrorStatus = NVIC_enuNotOK; break;
				}
			}
		}
		
		Loc_enuNvicErrorStatus = NVIC_enuOK;
	}
	
	return Loc_enuNvicErrorStatus;
 }
 
 
 //========================================================================================================//
 //====================================== NVIC SET PENDING REGISTER =======================================//
 //========================================================================================================//
 
 NVIC_enuErrorStatus NVIC_SetPendingIRQ(NVIC_Config_t *Add_strNvicCfgPtr)
 {
	 NVIC_enuErrorStatus Loc_enuNvicErrorStatus = NVIC_enuNotOK;
	 
	 NVIC_ISPR_t *Add_strNvicIsprPtr = Add_strNvicCfgPtr -> NVIC_Reg;
	 NVIC_ICPR_t *Add_strNvicIcprPtr = Add_strNvicCfgPtr -> NVIC_Reg;
	 
	 u8  Loc_u8BitsIterator = 0;
	 
	if(Add_strNvicCfgPtr == NULL){
		Loc_enuNvicErrorStatus = NVIC_enuNullPointer;
	}
	
	else
	{
		for(Loc_u8BitsIterator = 0; Loc_u8BitsIterator < MAX_NVIC_BIT; Loc_u8BitsIterator++)
		{
			if( (Add_strNvicCfgPtr -> NVIC_Bit)&(SINGLE_BIT << Loc_u8BitsIterator) )
			{
				switch(Add_strNvicCfgPtr -> NVIC_RegNum)
				{
					case ISPR0:			
					     Add_strNvicIcprPtr -> NVIC_ICPR0 &= ~(NVIC_REG_CLR << Loc_u8BitsIterator); 
					     Add_strNvicIsprPtr -> NVIC_ISPR0 |=  (NVIC_REG_SET << Loc_u8BitsIterator); 
					break;
					
					case ISPR1:			
					     Add_strNvicIcprPtr -> NVIC_ICPR1 &= ~(NVIC_REG_CLR << Loc_u8BitsIterator); 
					     Add_strNvicIsprPtr -> NVIC_ISPR1 |=  (NVIC_REG_SET << Loc_u8BitsIterator); 
					break;
					
					case ISPR2:			
					     Add_strNvicIcprPtr -> NVIC_ICPR2 &= ~(NVIC_REG_CLR << Loc_u8BitsIterator); 
					     Add_strNvicIsprPtr -> NVIC_ISPR2 |=  (NVIC_REG_SET << Loc_u8BitsIterator); 
					break;
					
					case ISPR3:			
					     Add_strNvicIcprPtr -> NVIC_ICPR3 &= ~(NVIC_REG_CLR << Loc_u8BitsIterator); 
					     Add_strNvicIsprPtr -> NVIC_ISPR3 |=  (NVIC_REG_SET << Loc_u8BitsIterator); 
					break;
					
					case ISPR4:			
					     Add_strNvicIcprPtr -> NVIC_ICPR4 &= ~(NVIC_REG_CLR << Loc_u8BitsIterator); 
					     Add_strNvicIsprPtr -> NVIC_ISPR4 |=  (NVIC_REG_SET << Loc_u8BitsIterator); 
					break;
					
					case ISPR5:			
					     Add_strNvicIcprPtr -> NVIC_ICPR5 &= ~(NVIC_REG_CLR << Loc_u8BitsIterator); 
					     Add_strNvicIsprPtr -> NVIC_ISPR5 |=  (NVIC_REG_SET << Loc_u8BitsIterator); 
					break;
					
					case ISPR6:			
					     Add_strNvicIcprPtr -> NVIC_ICPR6 &= ~(NVIC_REG_CLR << Loc_u8BitsIterator); 
					     Add_strNvicIsprPtr -> NVIC_ISPR6 |=  (NVIC_REG_SET << Loc_u8BitsIterator); 
					break;
					
					case ISPR7:			
					     Add_strNvicIcprPtr -> NVIC_ICPR7 &= ~(NVIC_REG_CLR << Loc_u8BitsIterator); 
					     Add_strNvicIsprPtr -> NVIC_ISPR7 |=  (NVIC_REG_SET << Loc_u8BitsIterator); 
					break;
						
					default: Loc_enuNvicErrorStatus = NVIC_enuNotOK; break;
				}
			}
		}
		
		Loc_enuNvicErrorStatus = NVIC_enuOK;
	}
	
	 return Loc_enuNvicErrorStatus;
 }
 
 
 //========================================================================================================//
 //===================================== NVIC CLEAR PENDING REGISTER ======================================//
 //========================================================================================================//
 
 NVIC_enuErrorStatus NVIC_ClearPendingIRQ(NVIC_Config_t *Add_strNvicCfgPtr)
 {
	 NVIC_enuErrorStatus Loc_enuNvicErrorStatus = NVIC_enuNotOK;
	 
	 NVIC_ICPR_t *Add_strNvicIcprPtr = Add_strNvicCfgPtr -> NVIC_Reg;
	 NVIC_ISPR_t *Add_strNvicIsprPtr = Add_strNvicCfgPtr -> NVIC_Reg;
	 
	 
	 u8  Loc_u8BitsIterator = 0;
	 
	if(Add_strNvicCfgPtr == NULL){
		Loc_enuNvicErrorStatus = NVIC_enuNullPointer;
	}
	
	else
	{
		for(Loc_u8BitsIterator = 0; Loc_u8BitsIterator < MAX_NVIC_BIT; Loc_u8BitsIterator++)
		{
			if( (Add_strNvicCfgPtr -> NVIC_Bit)&(SINGLE_BIT << Loc_u8BitsIterator) )
			{
				switch(Add_strNvicCfgPtr -> NVIC_RegNum)
				{
					case ICPR0:			
					     Add_strNvicIsprPtr -> NVIC_ISPR0 &= ~(NVIC_REG_CLR << Loc_u8BitsIterator); 
					     Add_strNvicIcprPtr -> NVIC_ICPR0 |=  (NVIC_REG_SET << Loc_u8BitsIterator); 
					break;
					
					case ICPR1:			
					     Add_strNvicIsprPtr -> NVIC_ISPR1 &= ~(NVIC_REG_CLR << Loc_u8BitsIterator); 
					     Add_strNvicIcprPtr -> NVIC_ICPR1 |=  (NVIC_REG_SET << Loc_u8BitsIterator); 
					break;
					
					case ICPR2:			
					     Add_strNvicIsprPtr -> NVIC_ISPR2 &= ~(NVIC_REG_CLR << Loc_u8BitsIterator); 
					     Add_strNvicIcprPtr -> NVIC_ICPR2 |=  (NVIC_REG_SET << Loc_u8BitsIterator); 
					break;
					
					case ICPR3:			
					     Add_strNvicIsprPtr -> NVIC_ISPR3 &= ~(NVIC_REG_CLR << Loc_u8BitsIterator); 
					     Add_strNvicIcprPtr -> NVIC_ICPR3 |=  (NVIC_REG_SET << Loc_u8BitsIterator); 
					break;
					
					case ICPR4:			
					     Add_strNvicIsprPtr -> NVIC_ISPR4 &= ~(NVIC_REG_CLR << Loc_u8BitsIterator); 
					     Add_strNvicIcprPtr -> NVIC_ICPR4 |=  (NVIC_REG_SET << Loc_u8BitsIterator); 
					break;
					
					case ICPR5:			
					     Add_strNvicIsprPtr -> NVIC_ISPR5 &= ~(NVIC_REG_CLR << Loc_u8BitsIterator); 
					     Add_strNvicIcprPtr -> NVIC_ICPR5 |=  (NVIC_REG_SET << Loc_u8BitsIterator); 
					break;
					
					case ICPR6:			
					     Add_strNvicIsprPtr -> NVIC_ISPR6 &= ~(NVIC_REG_CLR << Loc_u8BitsIterator); 
					     Add_strNvicIcprPtr -> NVIC_ICPR6 |=  (NVIC_REG_SET << Loc_u8BitsIterator); 
					break;
					
					case ICPR7:			
					     Add_strNvicIsprPtr -> NVIC_ISPR7 &= ~(NVIC_REG_CLR << Loc_u8BitsIterator); 
					     Add_strNvicIcprPtr -> NVIC_ICPR7 |=  (NVIC_REG_SET << Loc_u8BitsIterator); 
					break;
						
					default: Loc_enuNvicErrorStatus = NVIC_enuNotOK; break;
				}
			}
		}
		
		Loc_enuNvicErrorStatus = NVIC_enuOK;
	}
	
	 return Loc_enuNvicErrorStatus;
 }
 

 //========================================================================================================//
 //====================================== NVIC GET PENDING REGISTER =======================================//
 //========================================================================================================//

 u32 NVIC_GetPendingIRQ(NVIC_Config_t *Add_strNvicCfgPtr, u8 Copy_u8BitNum)
 {
	 u32 Loc_u32PendingStatus = 0;
	 
	 NVIC_ISPR_t *Add_strNvicIsprPtr = Add_strNvicCfgPtr -> NVIC_Reg;
	
	
	if(Add_strNvicCfgPtr == NULL)
	{
		Loc_u32PendingStatus = 0;
	}	
	else
	{
		if( (Add_strNvicCfgPtr -> NVIC_Bit)&(SINGLE_BIT << Copy_u8BitNum) )
		{
			switch(Add_strNvicCfgPtr -> NVIC_RegNum)
			{
				case ISPR0:			
                     if( (Add_strNvicIsprPtr -> NVIC_ISPR0)&(SINGLE_BIT << Copy_u8BitNum) )	
					 {
						 Loc_u32PendingStatus = 1;
					 }	
					 else
					 {
						 Loc_u32PendingStatus = 0;
					 }
				break;
				
				case ISPR1:			
				     if( (Add_strNvicIsprPtr -> NVIC_ISPR1)&(SINGLE_BIT << Copy_u8BitNum) )	
					 {
						 Loc_u32PendingStatus = 1;
					 }	
					 else
					 {
						 Loc_u32PendingStatus = 0;
					 }
				break;
				
				case ISPR2:			
				     if( (Add_strNvicIsprPtr -> NVIC_ISPR2)&(SINGLE_BIT << Copy_u8BitNum) )	
					 {
						 Loc_u32PendingStatus = 1;
					 }	
					 else
					 {
						 Loc_u32PendingStatus = 0;
					 }
				break;
				
				case ISPR3:			
				     if( (Add_strNvicIsprPtr -> NVIC_ISPR3)&(SINGLE_BIT << Copy_u8BitNum) )	
					 {
						 Loc_u32PendingStatus = 1;
					 }	
					 else
					 {
						 Loc_u32PendingStatus = 0;
					 }
				break;
				
				case ISPR4:			
				     if( (Add_strNvicIsprPtr -> NVIC_ISPR4)&(SINGLE_BIT << Copy_u8BitNum) )	
					 {
						 Loc_u32PendingStatus = 1;
					 }	
					 else
					 {
						 Loc_u32PendingStatus = 0;
					 }
				break;
				
				case ISPR5:			
				     if( (Add_strNvicIsprPtr -> NVIC_ISPR5)&(SINGLE_BIT << Copy_u8BitNum) )	
					 {
						 Loc_u32PendingStatus = 1;
					 }	
					 else
					 {
						 Loc_u32PendingStatus = 0;
					 }
				break;
				
				case ISPR6:			
				     if( (Add_strNvicIsprPtr -> NVIC_ISPR6)&(SINGLE_BIT << Copy_u8BitNum) )	
					 {
						 Loc_u32PendingStatus = 1;
					 }	
					 else
					 {
						 Loc_u32PendingStatus = 0;
					 }
				break;
				
				case ISPR7:			
				     if( (Add_strNvicIsprPtr -> NVIC_ISPR7)&(SINGLE_BIT << Copy_u8BitNum) )	
					 {
						 Loc_u32PendingStatus = 1;
					 }	
					 else
					 {
						 Loc_u32PendingStatus = 0;
					 }
				break;
					
				default: Loc_u32PendingStatus = 0; break;
			}
		}
	}
	
	return Loc_u32PendingStatus;
 }
 
 
 //========================================================================================================//
 //====================================== NVIC GET PENDING REGISTER =======================================//
 //========================================================================================================//

 NVIC_enuErrorStatus NVIC_SetPriority(u8 Copy_u8InterruptID, u8 Copy_u8Priority)
 {
	NVIC_enuErrorStatus Loc_enuNvicErrorStatus = NVIC_enuNotOK;

	u8 Loc_u8Register;

	u8 Loc_u8Bit;


	if(Copy_u8InterruptID > 239){
		Loc_enuNvicErrorStatus = NVIC_enuNotOK;
	}

	else
	{
		Loc_u8Register = Copy_u8InterruptID / 4;

		Loc_u8Bit = Copy_u8InterruptID % 4;

		NVIC_IPR_BASE_ADDRESS[Loc_u8Register] |= (Copy_u8Priority << Loc_u8Bit);

		Loc_enuNvicErrorStatus = NVIC_enuOK;
	}

	return Loc_enuNvicErrorStatus;
}
 
 
 
 
 





 //========================================================================================================//
 //========================================================================================================//
 //========================================================================================================//
 
