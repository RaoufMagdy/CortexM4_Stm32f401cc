/********************************
 *  Author: Raouf Magdy         *
 *                              *
 *  Date: 01-02-2023            *
 *                              *
 *  Version: V_01               *
 *                              *
 ********************************/
 
 
 
 #ifndef RCC_INTERFACE_H
 #define RCC_INTERFACE_H

 #include "STD_Types.h"
 
 /* ================ */
 /* RCC Error Status */
 /* ================ */
 typedef enum
 {
	RCC_enuOK = 0,
	RCC_enuNotOK,
	RCC_PeripheralOK,
	RCC_PeripheralNotOK,
	RCC_enuPLLOK,
	RCC_enuPLLNotOK,
	RCC_enuHSI_RDY,
	RCC_enuHSE_RDY
 }RCC_enuErrorStatus;
 /* ============================== */
 /* ============================== */
 /* ============================== */
 
 
 
 /* ============================== */
 /* ===== Clocks and Buses ======= */
 /* ============================== */
 
 #define RCC_HSI  10
 #define RCC_HSE  11
 #define RCC_PLL  12
 
 #define HSI  10
 #define HSE  11
 #define PLL  12
 
 #define RCC_PLLSRC_HSI 0
 #define RCC_PLLSRC_HSE 1
 
 #define AHB1 0xA1
 #define AHB2 0xA2
 #define APB1 0xB1
 #define APB2 0xB2
 /* ============================== */
 /* ============================== */
 /* ============================== */




 // ====> Peripherals <==== //
 //AHB1:
 #define RCC_GPIOA     0x00000001
 #define RCC_GPIOB     0x00000002
 #define RCC_GPIOC     0x00000004 
 #define RCC_GPIOD     0x00000008
 #define RCC_GPIOE     0x00000010
 #define RCC_GPIOH     0x00000080
 #define RCC_CRC       0x00001000
 #define RCC_DMA1      0x00200000
 #define RCC_DMA2      0x00400000
 #define AHB1_Reserved 0xFF9FEF60
 
 //AHB2:
 #define RCC_OTGFSEN   0x00000080
 #define AHB2_Reserved 0xFFFFFF7F
 
 //APB1:
 #define RCC_TIM2      0x00000001
 #define RCC_TIM3      0x00000002
 #define RCC_TIM4      0x00000004
 #define RCC_TIM5      0x00000008
 #define RCC_WWDG      0x00000800
 #define RCC_SPI2      0x00004000
 #define RCC_SPI3      0x00008000
 #define RCC_USART2    0x00020000
 #define RCC_I2C1      0x00200000
 #define RCC_I2C2      0x00400000
 #define RCC_I2C3      0x00800000
 #define RCC_PWR       0x10000000
 #define APB1_Reserved 0xEF1D37F0
 
 //APB2:
 #define RCC_TIM1      0x00000001
 #define RCC_USART1    0x00000010
 #define RCC_USART6    0x00000020 
 #define RCC_ADC1      0x00000100
 #define RCC_SDIO      0x00000800
 #define RCC_SPI1      0x00001000
 #define RCC_SPI4      0x00002000
 #define RCC_SYSGFC    0x00004000
 #define RCC_TIM9      0x00010000
 #define RCC_TIM10     0x00020000
 #define RCC_TIM11     0x00040000
 #define APB2_Reserved 0xFFF886CE
 // ========================= //

 // ====> Buses Prescalers <==== //
 //AHB:
 #define AHB_DIV_2   0x00000080
 #define AHB_DIV_4   0x00000090
 #define AHB_DIV_8   0x000000A0
 #define AHB_DIV_16  0x000000B0
 #define AHB_DIV_64  0x000000C0
 #define AHB_DIV_128 0x000000D0
 #define AHB_DIV_256 0x000000E0
 #define AHB_DIV_512 0x000000F0
 //APB1:
 #define APB1_DIV_2   0x00001000
 #define APB1_DIV_4   0x00001400
 #define APB1_DIV_8   0x00001800
 #define APB1_DIV_16  0x00001C00
 //APB2:
 #define APB2_DIV_2   0x00008000
 #define APB2_DIV_4   0x0000A000
 #define APB2_DIV_8   0x0000C000
 #define APB2_DIV_16  0x0000E000
 
 // ============================ //
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 /* ===================== */
 /* Registers Bit Masking */
 /* ===================== */
 
 //====> Select Clock <====//
 //Set Select Clock: RCC_CR
 #define RCC_HSION_SET 0x00000001
 #define RCC_HSEON_SET 0x00010000
 #define RCC_PLLON_SET 0x01000000
 //Clear Select Clock: RCC_CR
 #define RCC_HSION_CLR 0xFFFFFFFE
 #define RCC_HSEON_CLR 0xFFFEFFFF
 #define RCC_PLLON_CLR 0xFEFFFFFF
 
 
 //Set SW: RCC_CFGR
 #define RCC_SW_HSI_SET 0x00000000
 #define RCC_SW_HSE_SET 0x00000001
 #define RCC_SW_PLL_SET 0x00000002
 //Clear SW: RCC_CFGR
 #define RCC_SW_HSI_CLR 0xFFFFFFFC
 #define RCC_SW_HSE_CLR 0xFFFFFFFC
 #define RCC_SW_PLL_CLR 0xFFFFFFFC
 //==============================//
 
 
 //====> Enable Peripheral <====//
 //Set Enable Peripheral (AHB1): RCC_AHB1ENR
 #define RCC_GPIOAEN_SET 0x00000001
 #define RCC_GPIOBEN_SET 0x00000002
 #define RCC_GPIOCEN_SET 0x00000004 
 #define RCC_GPIODEN_SET 0x00000008
 #define RCC_GPIOEEN_SET 0x00000010
 #define RCC_GPIOHEN_SET 0x00000080
 #define RCC_CRCEN_SET   0x00001000
 #define RCC_DMA1EN_SET  0x00200000
 #define RCC_DMA2EN_SET  0x00400000
 //Clear Enable (Disable) Peripheral (AHB1): RCC_AHB1ENR
 #define RCC_GPIOAEN_CLR 0xFFFFFFFE
 #define RCC_GPIOBEN_CLR 0xFFFFFFFD
 #define RCC_GPIOCEN_CLR 0xFFFFFFFB
 #define RCC_GPIODEN_CLR 0xFFFFFFF7
 #define RCC_GPIOEEN_CLR 0xFFFFFFEF
 #define RCC_GPIOHEN_CLR 0xFFFFFF7F
 #define RCC_CRCEN_CLR   0xFFFFEFFF
 #define RCC_DMA1EN_CLR  0xFFDFFFFF
 #define RCC_DMA2EN_CLR  0xFFBFFFFF
 
 
 //Set Enable Peripheral (AHB2): RCC_AHB2ENR
 #define RCC_OTGFSEN_SET 0x00000080
 //Clear Enable (Disable) Peripheral (AHB2): RCC_AHB2ENR
 #define RCC_OTGFSEN_CLR 0xFFFFFF7F
 
 
 //Set Enable Peripheral (APB1): RCC_APB1ENR
 #define RCC_TIM2_SET     0x00000001
 #define RCC_TIM3_SET     0x00000002
 #define RCC_TIM4_SET     0x00000004 
 #define RCC_TIM5_SET     0x00000008
 #define RCC_WWDGEN_SET   0x00000800
 #define RCC_SPI2_SET     0x00004000
 #define RCC_SPI3_SET     0x00008000
 #define RCC_USART2EN_SET 0x00020000
 #define RCC_I2C1_SET     0x00200000
 #define RCC_I2C2_SET     0x00400000
 #define RCC_I2C3_SET     0x00800000
 #define RCC_PWREN_SET    0x10000000
 //Clear Enable (Disable) Peripheral (APB1): RCC_APB1ENR
 #define RCC_TIM2_CLR     0xFFFFFFFE
 #define RCC_TIM3_CLR     0xFFFFFFFD
 #define RCC_TIM4_CLR     0xFFFFFFFB
 #define RCC_TIM5_CLR     0xFFFFFFF7
 #define RCC_WWDGEN_CLR   0xFFFFF7FF
 #define RCC_SPI2_CLR     0xFFFFBFFF
 #define RCC_SPI3_CLR     0xFFFF7FFF
 #define RCC_USART2EN_CLR 0xFFFDFFFF
 #define RCC_I2C1_CLR     0xFFDFFFFF
 #define RCC_I2C2_CLR     0xFFBFFFFF
 #define RCC_I2C3_CLR     0xFF7FFFFF
 #define RCC_PWREN_CLR    0xEFFFFFFF
 
 
 //Set Enable Peripheral (APB2): RCC_APB2ENR
 #define RCC_TIM1_SET     0x00000001
 #define RCC_USART1EN_SET 0x00000010
 #define RCC_USART6EN_SET 0x00000020 
 #define RCC_ADC1EN_SET   0x00000100
 #define RCC_SDIOEN_SET   0x00000800
 #define RCC_SPI1EN_SET   0x00001000
 #define RCC_SPI4EN_SET   0x00002000
 #define RCC_SYSGFCEN_SET 0x00004000
 #define RCC_TIM9_SET     0x00010000
 #define RCC_TIM10_SET    0x00020000
 #define RCC_TIM11_SET    0x00040000
 //Clear Enable (Disable) Peripheral (APB2): RCC_APB2ENR
 #define RCC_TIM1_CLR     0xFFFFFFFE
 #define RCC_USART1EN_CLR 0xFFFFFFEF
 #define RCC_USART6EN_CLR 0xFFFFFFDF
 #define RCC_ADC1EN_CLR   0xFFFFFEFF
 #define RCC_SDIOEN_CLR   0xFFFFF7FF
 #define RCC_SPI1EN_CLR   0xFFFFEFFF
 #define RCC_SPI4EN_CLR   0xFFFFDFFF
 #define RCC_SYSGFCEN_CLR 0xFFFFBFFF
 #define RCC_TIM9_CLR     0xFFFEFFFF
 #define RCC_TIM10_CLR    0xFFFDFFFF
 #define RCC_TIM11_CLR    0xFFFBFFFF
 //==============================//
 
 //====> PLL Configuration <====//
 //PLLM: RCC_CFGR
 #define RCC_PLLM_CLR   0xFFFFFFC0
					    
 //PLLN: RCC_CFGR             
 #define RCC_PLLN_CLR   0xFFFFC03F
					    
 //PLLP: RCC_CFGR             
 #define RCC_PLLP_CLR   0xFFFE7FFF
						
 //PLLSRC: RCC_CFGR             
 #define RCC_PLLSRC_CLR 0xFFDFFFFF
 
						   
 //Set PLLON & PLLI2SON: RCC_CFGR             
 #define RCC_CRPLLON_SET  0x05000000
 //Clear PLLON & PLLI2SON: RCC_CFGR
 #define RCC_CRPLLON_CLR  0xFAFFFFFF
 
 
 //==============================//
 
 
 //====> Buses Prescaler  <====//
 
 //AHB_DIV_SET:
 #define RCC_AHB_DIV_2_SET   0x00000080
 #define RCC_AHB_DIV_4_SET   0x00000090
 #define RCC_AHB_DIV_8_SET   0x000000A0
 #define RCC_AHB_DIV_16_SET  0x000000B0
 #define RCC_AHB_DIV_64_SET  0x000000C0
 #define RCC_AHB_DIV_128_SET 0x000000D0
 #define RCC_AHB_DIV_256_SET 0x000000E0
 #define RCC_AHB_DIV_512_SET 0x000000F0
 //AHB_DIV_CLR:
 #define RCC_AHB_DIV_CLR     0xFFFFFF0F
 
 
 //APB1_DIV_SET:
 #define RCC_APB1_DIV_2_SET   0x00001000
 #define RCC_APB1_DIV_4_SET   0x00001400
 #define RCC_APB1_DIV_8_SET   0x00001800
 #define RCC_APB1_DIV_16_SET  0x00001C00
 //APB1_DIV_CLR:
 #define RCC_APB1_DIV_CLR     0xFFFFE3FF
 
 
 //APB2_DIV_SET:
 #define RCC_APB2_DIV_2_SET   0x00008000
 #define RCC_APB2_DIV_4_SET   0x0000A000
 #define RCC_APB2_DIV_8_SET   0x0000C000
 #define RCC_APB2_DIV_16_SET  0x0000E000
 //APB1_DIV_CLR:
 #define RCC_APB2_DIV_CLR     0xFFFF1FFF
 
 //============================//
 
 //====> Check the working Clock  <====//
  
  #define RCC_isHSI_ON 0x00000001
  #define RCC_isHSE_ON 0x00010000
  
 //====================================//
 
 /* ============================== */
 /* ============================== */
 /* ============================== */
 
 


 
 /* ============================== */
 /* ========== RCC APIs ========== */
 /* ============================== */
 RCC_enuErrorStatus RCC_enuSelectSystemClock(u8 Copy_u8ClockSelect);
 RCC_enuErrorStatus RCC_enuPeripheralEnable(u8 Copy_u8BusSelect, u32 Copy_u32PeripheralSelect);
 RCC_enuErrorStatus RCC_enuPeripheralDisable(u8 Copy_u8BusSelect, u32 Copy_u32PeripheralSelect);
 RCC_enuErrorStatus RCC_enuAHBPrescaler(u32 Copy_u32PrescalerSelect);
 RCC_enuErrorStatus RCC_enuAPB1Prescaler(u32 Copy_u32PrescalerSelect);
 RCC_enuErrorStatus RCC_enuAPB2Prescaler(u32 Copy_u32PrescalerSelect);
 RCC_enuErrorStatus RCC_enuConfigurePLL(u8 Copy_u8PLLSource, u8 Copy_u8PLLM, u16 Copy_u16PLLN, u8 Copy_u8PLLP);
 RCC_enuErrorStatus RCC_enuGetReadyClock(void);
 
 /* ===================================================================== */

 
 
 #endif
 
