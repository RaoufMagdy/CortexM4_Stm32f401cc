/********************************
 *  Author: Raouf Magdy         *
 *                              *
 *  Date: 11-03-2023            *
 *                              *
 *  Version: V_01               *
 *                              *
 ********************************/
 
 
 
 #ifndef SYSTICK_INTERFACE_H
 #define SYSTICK_INTERFACE_H
 
 #include "SYSTICK_Private.h"
 
 
 typedef void(*SysTick_CBF_t)(void); //Pointer to Function type
 
 
 
 typedef enum{
	 STK_enuOK = 0,
	 STK_enuNotOK,
	 STK_enuNullPtr
 }STK_enuErrorStatus;
 
 
 /* === Clock Source === */
 #define Processor_Clock 1
 #define AHB_8_Clock     0
 
 
 #define MIN_LOAD     0x00000001
 #define MAX_LOAD     0x00FFFFFF
 #define CLR_LOAD_REG 0x00000000
 
 
 /* === Clock Selection === */
 #define HSI 0x55  //16MHz
 #define HSE 0xAA  //25MHz 
 //These values are for STM32f401c MC.
 
 /* === Delay Periods === */
 #define HSI_AHB_8_MS           2000
 #define HSI_ProcessorClock_MS  16000
 #define HSE_AHB_8_MS           3125
 #define HSE_ProcessorClock_MS  25000
 
 #define HSI_AHB_8_US           2
 #define HSI_ProcessorClock_US  16
 #define HSE_AHB_8_US           3   // ====> Note: this value isn't very accurate it should be 3.125
 #define HSE_ProcessorClock_US  25
 
 
 /* === Current Value Mask === */
 #define STK_VAL_MASK 0x00FFFFFF
 
 
 
 /* === SYSTICK APIs === */
 STK_enuErrorStatus SysTick_Start(void);
 STK_enuErrorStatus SysTick_Stop(void);
 STK_enuErrorStatus SysTick_EnableSEQ(void);
 STK_enuErrorStatus SysTick_DisableSEQ(void);
 STK_enuErrorStatus SysTick_SetClockSource(u8 Copy_u8ClkSource);
 STK_enuErrorStatus SysTick_SetCounts(u32 Copy_u32Counts);
 STK_enuErrorStatus SysTick_SetPeriod_us(u8 Copy_u8ClockSelection, u8 Copy_u8ClkSource, u16 Copy_u16Period);
 STK_enuErrorStatus SysTick_SetPeriod_ms(u8 Copy_u8ClockSelection, u8 Copy_u8ClkSource, u16 Copy_u16Period);
 STK_enuErrorStatus SysTick_ClearValue(void);
 u32                SysTick_GetCurrentValue(void);
 
 STK_enuErrorStatus SysTick_CallBackFunction(SysTick_CBF_t CallBackFunction);
 void               SysTick_Handler(void);
 
 
 
 #endif
 
 
