/********************************
 *  Author:  Raouf Magdy        *
 *                              *
 *  Date:    18-06-2023         *
 *                              *
 *  Version: V_01               *
 ********************************/


 #ifndef GPT_INTERFACE_H
 #define GPT_INTERFACE_H
 
 #include "STD_Types.h"
 #include "GPT_Private.h"

 #define GPT_TIM2 0x11
 #define GPT_TIM3 0x22
 #define GPT_TIM4 0x33
 #define GPT_TIM5 0x44
 

 /* ==================== */
 #define TIM_2  ((void*) GPT2_BASE_ADDRESS)
 #define TIM_3  ((void*) GPT3_BASE_ADDRESS)
 #define TIM_4  ((void*) GPT4_BASE_ADDRESS)
 #define TIM_5  ((void*) GPT5_BASE_ADDRESS)
 /* ==================== */


 /* ===> GPT2 -> GPT5 Registers <=== */
 typedef struct{
    volatile u32 TIM_CR1;  //0x00 TIMx control register 1
    volatile u32 TIM_CR2;  //0x04 TIMx control register 2
    volatile u32 TIM_SMCR; //0x08 TIMx slave mode control register
    volatile u32 TIM_DIER; //0x0C TIMx DMA/Interrupt enable register
    volatile u32 TIM_SR;   //0x10 TIMx status register
    volatile u32 TIM_EGR;  //0x14 TIMx event generation register
    volatile u32 TIM_CCMR1;//0x18 TIMx capture/compare mode register 1
    volatile u32 TIM_CCMR2;//0x1C TIMx capture/compare mode register 2
    volatile u32 TIM_CCER; //0x20 TIMx capture/compare enable register
    volatile u32 TIM_CNT;  //0x24 TIMx counter
    volatile u32 TIM_PSC;  //0x28 TIMx prescaler
    volatile u32 TIM_ARR;  //0x2C TIMx auto-reload register
    volatile u32 RESERVED_REGISTER_1; //0x30
    volatile u32 TIM_CCR1; //0x34 TIMx capture/compare register 1
    volatile u32 TIM_CCR2; //0x38 TIMx capture/compare register 2
    volatile u32 TIM_CCR3; //0x3C TIMx capture/compare register 3
    volatile u32 TIM_CCR4; //0x40 TIMx capture/compare register 4
    volatile u32 RESERVED_REGISTER_2; //0x44
    volatile u32 TIM_DCR;  //0x48 TIMx DMA control register
    volatile u32 TIM_DMAR; //0x4C TIMx DMA address for full transfer
    volatile u32 TIM2_5_OR;//0x50 TIM2 & TIM5 option register
 }GPT_Regs_t;
 /* ==================== */

 //Timer config str:
 typedef struct{
    void* TIM_ID;      //Pointer to timers registers
    u16   TIM_CNT_DIR; //Timer count direction
    u16   TIM_PRSC;    //Timer prescaler
 }TIM_Config_t;


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
 }TIM_ICM_Config_t;


 //PWM config str:
 typedef struct{
	void* TIM_PWM_ID;
	u16   TIM_PWM_SET_ARR;
	u16   TIM_PWM_CCR1_VAL;
	u16   TIM_PWM_CCR2_VAL;


 }TIM_PWM_Config_t;



 /* ==================== */


 /* === Error Status === */
 typedef enum{

    TIM_enuOK = 0,
    TIM_enuNotOK,
    TIM_enuNullPointer,
    TIM_enuIdError

 }TIM_enuErrorStatus;
 /* ==================== */


 /* ===> TIMx MASKS <=== */

 #define SINGLE_BIT  0x01
 #define DOUBLE_BITS 0x02
 #define TRIBLE_BITS 0x03
 #define QUADRA_BITS 0x04
 #define PENTA_BITS  0x05
 #define HEXA_BITS   0x06
 #define SEVEN_BITS  0x07
 #define EIGHT_BITS  0x08
 #define NINE_BITS   0x09
 #define TEN_BITS    0x0A

 //Start Timer/Counter: TIM_CR1 register
 #define TIM_START 0x01
 #define TIM_STOP  0x00

 //Counting Direction: TIM_CR1 register
 #define TIM_CNT_DIR_CLR 0b1111101111
 #define COUNT_UP        0b0000000000
 #define COUNT_DOWN      0b0000010000

 //Prescaler: TIM_PSC register
 #define TIM_PSC_CLR     0x0000
 #define TIM_PSC_GET_VAL 0xFFFF


 //Input Capture Mode: TIM_CCMR1 register
 #define TIM_CCMR1_CLR               0xFFFF0000
 #define TIM_CCMR1_CC1S_TI1_CC2S_TI2 0x00000101 
    //Capture/Compare
 #define TIM_CCER_INPUT              0xFFFF0000
 #define RISING_EDGE  0x00
 #define FALLING_EDGE 0x01
    //Interrupt Enable/Disable
 #define TIM_DIER_CLR      0xFFFFA0A0
 #define CAP_INT_ENABLE    0x01
 #define CAP_INT_DISABLE   0x00
 #define TRIG_INT_ENABLE   0x01
 #define TRING_INT_DISABLE 0x00
 

 //PWM Masks:

 #define TIM_PWM_CLR    0b1000111110001111 //change to hexa
 #define TIM_PWM1_SET   0b1110111111101111
 #define TIM_ARR_CLR    0x00000000
 #define TIM_CCRx_CLR   0x00000000

 
 /* ==================== */


 /* ===> TIMx APIs <=== */
 TIM_enuErrorStatus TIM_enuInit(TIM_Config_t *Add_strTimCfgPtr);
 TIM_enuErrorStatus TIM_enuInputCaptureMode(TIM_ICM_Config_t *Add_strTimCfgPtr); // IC1 & IC2 are always mapped to TI1 & TI2 respectively.
 TIM_enuErrorStatus TIM_enuPwmMode(TIM_PWM_Config_t *Add_strTimCfgPtr);
 TIM_enuErrorStatus TIM_enuEnableInterrupt(u8 Copy_u8TimID); // will be implemented using switch case: ex: case TIM2: NVIC_EnableIRQ(TIM2_IRQn);
 TIM_enuErrorStatus TIM_enuStart(u8 Copy_u8TimID); // will be implemented using switch case statement.
 TIM_enuErrorStatus TIM_enuStop(u8 Copy_u8TimID); // will be implemented using switch case statement.
 /* ==================== */


 #endif

