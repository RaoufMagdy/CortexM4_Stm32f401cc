/********************************
 *  Author: Raouf Magdy         *
 *                              *
 *  Date: 03-03-2023            *
 *                              *
 *  Version: V_01               *
 *                              *
 ********************************/
 
 
 
 #ifndef NVIC_INTERFACE_H
 #define NVIC_INTERFACE_H
 
 #include "NVIC_Private.h"




 typedef enum{
	 NVIC_enuOK = 0,
	 NVIC_enuNotOK,
	 NVIC_enuNullPointer
 }NVIC_enuErrorStatus;


 typedef struct{
	 void *NVIC_Reg;
	 u32   NVIC_Bit;
	 u8    NVIC_RegNum;
 }NVIC_Config_t;
 
 
 
 typedef struct{
	 volatile u32 NVIC_ISER0; 
	 volatile u32 NVIC_ISER1;
	 volatile u32 NVIC_ISER2;
	 volatile u32 NVIC_ISER3;
	 volatile u32 NVIC_ISER4;
	 volatile u32 NVIC_ISER5;
	 volatile u32 NVIC_ISER6;
	 volatile u32 NVIC_ISER7;
 }NVIC_ISER_t;
 
 
 typedef struct{
	 volatile u32 NVIC_ICER0; 
	 volatile u32 NVIC_ICER1;
	 volatile u32 NVIC_ICER2;
	 volatile u32 NVIC_ICER3;
	 volatile u32 NVIC_ICER4;
	 volatile u32 NVIC_ICER5;
	 volatile u32 NVIC_ICER6;
	 volatile u32 NVIC_ICER7;
 }NVIC_ICER_t;
 
 
 typedef struct{
	 volatile u32 NVIC_ISPR0; 
	 volatile u32 NVIC_ISPR1;
	 volatile u32 NVIC_ISPR2;
	 volatile u32 NVIC_ISPR3;
	 volatile u32 NVIC_ISPR4;
	 volatile u32 NVIC_ISPR5;
	 volatile u32 NVIC_ISPR6;
	 volatile u32 NVIC_ISPR7;
 }NVIC_ISPR_t;
 
 
 typedef struct{
	 volatile u32 NVIC_ICPR0; 
	 volatile u32 NVIC_ICPR1;
	 volatile u32 NVIC_ICPR2;
	 volatile u32 NVIC_ICPR3;
	 volatile u32 NVIC_ICPR4;
	 volatile u32 NVIC_ICPR5;
	 volatile u32 NVIC_ICPR6;
	 volatile u32 NVIC_ICPR7;
 }NVIC_ICPR_t;
 
 
 typedef struct{
	 volatile u32 NVIC_IABR0; 
	 volatile u32 NVIC_IABR1;
	 volatile u32 NVIC_IABR2;
	 volatile u32 NVIC_IABR3;
	 volatile u32 NVIC_IABR4;
	 volatile u32 NVIC_IABR5;
	 volatile u32 NVIC_IABR6;
	 volatile u32 NVIC_IABR7;
 }NVIC_IABR_t;
 
 /*
 typedef struct{
	 volatile u32 NVIC_IPR[60]; 
 }NVIC_IPR_t;
 */
 
 /*
 typedef struct{
	 volatile u32 NVIC_STIR; 
 }NVIC_STIR_t;
 */
 
 
        /* === NVIC REGISTERS === */
 #define NVIC_ISER ((void*)NVIC_ISER_BASE_ADDRESS)
 #define NVIC_ICER ((void*)NVIC_ICER_BASE_ADDRESS)
 #define NVIC_ISPR ((void*)NVIC_ISPR_BASE_ADDRESS)
 #define NVIC_ICPR ((void*)NVIC_ICPR_BASE_ADDRESS)
 #define NVIC_IABR ((void*)NVIC_IABR_BASE_ADDRESS)
 #define NVIC_STIR ((void*)NVIC_STIR_BASE_ADDRESS)
 


  /* === NVIC BITS === */
 #define NVIC_BIT0  0x00000001
 #define NVIC_BIT1  0x00000002
 #define NVIC_BIT2  0x00000004
 #define NVIC_BIT3  0x00000008
 #define NVIC_BIT4  0x00000010
 #define NVIC_BIT5  0x00000020
 #define NVIC_BIT6  0x00000040
 #define NVIC_BIT7  0x00000080
 #define NVIC_BIT8  0x00000100
 #define NVIC_BIT9  0x00000200
 #define NVIC_BIT10 0x00000400
 #define NVIC_BIT11 0x00000800
 #define NVIC_BIT12 0x00001000
 #define NVIC_BIT13 0x00002000
 #define NVIC_BIT14 0x00004000
 #define NVIC_BIT15 0x00008000
 #define NVIC_BIT16 0x00010000
 #define NVIC_BIT17 0x00020000
 #define NVIC_BIT18 0x00040000
 #define NVIC_BIT19 0x00080000
 #define NVIC_BIT20 0x00100000
 #define NVIC_BIT21 0x00200000
 #define NVIC_BIT22 0x00400000
 #define NVIC_BIT23 0x00800000
 #define NVIC_BIT24 0x01000000
 #define NVIC_BIT25 0x02000000
 #define NVIC_BIT26 0x04000000
 #define NVIC_BIT27 0x08000000
 #define NVIC_BIT28 0x10000000
 #define NVIC_BIT29 0x20000000
 #define NVIC_BIT30 0x40000000
 #define NVIC_BIT31 0x80000000


 #define MAX_NVIC_BIT 30
 #define SINGLE_BIT   1


 #define ISER0 0xA0
 #define ISER1 0xA1
 #define ISER2 0xA2
 #define ISER3 0xA3
 #define ISER4 0xA4
 #define ISER5 0xA5
 #define ISER6 0xA6
 #define ISER7 0xA7

 #define ICER0 0xB0
 #define ICER1 0xB1
 #define ICER2 0xB2
 #define ICER3 0xB3
 #define ICER4 0xB4
 #define ICER5 0xB5
 #define ICER6 0xB6
 #define ICER7 0xB7

 #define ISPR0 0xC0
 #define ISPR1 0xC1
 #define ISPR2 0xC2
 #define ISPR3 0xC3
 #define ISPR4 0xC4
 #define ISPR5 0xC5
 #define ISPR6 0xC6
 #define ISPR7 0xC7
 
 #define ICPR0 0xD0
 #define ICPR1 0xD1
 #define ICPR2 0xD2
 #define ICPR3 0xD3
 #define ICPR4 0xD4
 #define ICPR5 0xD5
 #define ICPR6 0xD6
 #define ICPR7 0xD7

 #define IABR0 0xE0
 #define IABR1 0xE1
 #define IABR2 0xE2
 #define IABR3 0xE3
 #define IABR4 0xE4
 #define IABR5 0xE5
 #define IABR6 0xE6
 #define IABR7 0xE7
 
 #define STIR  0xFF
 
 
 
 #define PRIGRP_Prority_0 0b000
 #define PRIGRP_Prority_1 0b001
 #define PRIGRP_Prority_2 0b010
 #define PRIGRP_Prority_3 0b011
 #define PRIGRP_Prority_4 0b100
 #define PRIGRP_Prority_5 0b101
 #define PRIGRP_Prority_6 0b110
 #define PRIGRP_Prority_7 0b111
 
 
 
 #define IPR_INDEX_MIN 0
 #define IPR_INDEX_MAX 3
 
 
 
 
 
 
 
 /* === Registers Masking === */
 #define NVIC_REG_CLR 0x00000001 //as we only have 1 bit at a time
 #define NVIC_REG_SET 0x00000001
 
 
 
 
 
 
 NVIC_enuErrorStatus NVIC_EnableIRQ(NVIC_Config_t *Add_strNvicCfgPtr);
 NVIC_enuErrorStatus NVIC_DisableIRQ(NVIC_Config_t *Add_strNvicCfgPtr);
 NVIC_enuErrorStatus NVIC_SetPendingIRQ(NVIC_Config_t *Add_strNvicCfgPtr);
 NVIC_enuErrorStatus NVIC_ClearPendingIRQ(NVIC_Config_t *Add_strNvicCfgPtr);
 NVIC_enuErrorStatus NVIC_SetPriority(u8 Copy_u8RegNum, u8 Copy_u8Priority);
 NVIC_enuErrorStatus NVIC_setSubPriority(u8 Copy_u8Value); 
 
 u32                 NVIC_GetPendingIRQ(NVIC_Config_t *Add_strNvicCfgPtr, u8 Copy_u8BitNum);
 
 
 
 /* The input parameter IRQn is the IRQ number. Possible “n” values depend on product. Refer to reference
     manual/datasheet of relevant STM32 product for related information. */
 
 #endif
 