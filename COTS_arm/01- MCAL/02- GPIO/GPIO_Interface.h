/********************************
 *  Author: Raouf Magdy         *
 *                              *
 *  Date: 01-02-2023            *
 *                              *
 *  Version: V_01               *
 *                              *
 ********************************/
 
 
 
 #ifndef GPIO_INTERFACE_H
 #define GPIO_INTERFACE_H
 
 #include "STD_Types.h"
 #include "GPIO_Private.h"
 
 /* =================== */
 /*  GPIO Error Status  */
 /* =================== */
 typedef enum{
	GPIO_enuOK = 0,
	GPIO_enuNotOK,
	GPIO_enuErrorPin,
	GPIO_enuErrorPort,
	GPIO_enuErrorMode,
	GPIO_enuErrorPull,
	GPIO_enuErrorSpeed,
	GPIO_enuErrorDirection,
	GPIO_enuErrorNullPointer,
	GPIO_enuErrorAlternateFunction,
	GPIO_enuErrorValue
	
 }GPIO_enuErrorStatus;
 
 typedef enum{
	 GPIO_enuGetBitLow = 0,
	 GPIO_enuGetBitHigh
 }GPIO_enuGetPinStatus;

 /* ============================== */
 /* ============================== */
 /* ============================== */
 
 typedef struct{
	void*  GPIO_Port;
	u16    GPIO_Pin;
	u32    GPIO_Mode_Speed;
	u32    GPIO_Value;
 }GPIO_Config_t;

 /* ============================== */
 /* ============================== */
 /* ============================== */
 
 typedef struct{
	void*  GPIO_PortAF;
	u16    GPIO_PinAF;
	u32    GPIO_AF_Selection;
 }GPIO_AF_Config_t;

 /* ============================== */
 /* ============================== */
 /* ============================== */

 typedef struct{
 	volatile u32 GPIO_MODER;   //0x00
 	volatile u32 GPIO_OTYPER;  //0x04
 	volatile u32 GPIO_OSPEEDR; //0x08
 	volatile u32 GPIO_PUPDR;   //0x0C
 	volatile u32 GPIO_IDR;     //0x10
 	volatile u32 GPIO_ODR;
 	volatile u32 GPIO_BSRR;
 	volatile u32 GPIO_LCKR;
 	volatile u32 GPIO_AFRL;
 	volatile u32 GPIO_AFRH;
 }GPIO_Regs_t;
 
 /* ============================== */
 /* ============================== */
 /* ============================== */

        /* === GPIO PORTS === */
 #define GPIO_PORTA      ((void*) GPIOA_BASE_ADDRESS)
 #define GPIO_PORTB      ((void*) GPIOB_BASE_ADDRESS)
 #define GPIO_PORTC      ((void*) GPIOC_BASE_ADDRESS)
 #define GPIO_PORTD      ((void*) GPIOD_BASE_ADDRESS)
 #define GPIO_PORTE      ((void*) GPIOE_BASE_ADDRESS)
 #define GPIO_PORTH      ((void*) GPIOH_BASE_ADDRESS)


 /* === GPIO PINS === */
 #define GPIO_PIN0  0x0001
 #define GPIO_PIN1  0x0002
 #define GPIO_PIN2  0x0004
 #define GPIO_PIN3  0x0008
 #define GPIO_PIN4  0x0010
 #define GPIO_PIN5  0x0020
 #define GPIO_PIN6  0x0040
 #define GPIO_PIN7  0x0080
 #define GPIO_PIN8  0x0100
 #define GPIO_PIN9  0x0200
 #define GPIO_PIN10 0x0400
 #define GPIO_PIN11 0x0800
 #define GPIO_PIN12 0x1000
 #define GPIO_PIN13 0x2000
 #define GPIO_PIN14 0x4000
 #define GPIO_PIN15 0x8000

/* =========================== */




        /* === GPIO MODES === */
 //SPEED: VERY_HIGH_SPEED		
 //GPIO_OUTPUT:
 #define GPIO_OUTPUT_PP_VHS     0b0011001
 #define GPIO_OUTPUT_PP_PU_VHS  0b0111001
 #define GPIO_OUTPUT_PP_PD_VHS  0b1011001						     
 #define GPIO_OUTPUT_OD_VHS     0b0011101
 #define GPIO_OUTPUT_OD_PU_VHS  0b0111101
 #define GPIO_OUTPUT_OD_PD_VHS  0b1011101
								
 //GPIO_Alternate_Function:        
 #define GPIO_AF_PP_VHS	        0b0011010		     
 #define GPIO_AF_PP_PU_VHS	    0b0111010				     
 #define GPIO_AF_PP_PD_VHS	    0b1011010					     
 #define GPIO_AF_OD_VHS         0b0011110		     
 #define GPIO_AF_OD_PU_VHS	    0b0111110				     
 #define GPIO_AF_OD_PD_VHS	    0b1011110						     
 
 //SPEED: HIGH_SPEED		
 //GPIO_OUTPUT:
 #define GPIO_OUTPUT_PP_HS      0b0010001
 #define GPIO_OUTPUT_PP_PU_HS   0b0110001
 #define GPIO_OUTPUT_PP_PD_HS   0b1010001						     
 #define GPIO_OUTPUT_OD_HS      0b0010101
 #define GPIO_OUTPUT_OD_PU_HS   0b0110101
 #define GPIO_OUTPUT_OD_PD_HS   0b1010101
								
 //GPIO_Alternate_Function:        
 #define GPIO_AF_PP_HS	        0b0010010		     
 #define GPIO_AF_PP_PU_HS	    0b0110010				     
 #define GPIO_AF_PP_PD_HS	    0b1010010					     
 #define GPIO_AF_OD_HS          0b0010110		     
 #define GPIO_AF_OD_PU_HS	    0b0110110				     
 #define GPIO_AF_OD_PD_HS	    0b1010110
 
 //SPEED: MEDIUM_SPEED		
 //GPIO_OUTPUT:
 #define GPIO_OUTPUT_PP_MS      0b0001001
 #define GPIO_OUTPUT_PP_PU_MS   0b0101001
 #define GPIO_OUTPUT_PP_PD_MS   0b1001001						     
 #define GPIO_OUTPUT_OD_MS      0b0001101
 #define GPIO_OUTPUT_OD_PU_MS   0b0101101
 #define GPIO_OUTPUT_OD_PD_MS   0b1001101
								
 //GPIO_Alternate_Function:        
 #define GPIO_AF_PP_MS	        0b0001010		     
 #define GPIO_AF_PP_PU_MS	    0b0101010				     
 #define GPIO_AF_PP_PD_MS	    0b1001010					     
 #define GPIO_AF_OD_MS          0b0001110		     
 #define GPIO_AF_OD_PU_MS	    0b0101110				     
 #define GPIO_AF_OD_PD_MS	    0b1001110
 
 //SPEED: LOW_SPEED		
 //GPIO_OUTPUT:
 #define GPIO_OUTPUT_PP_LS      0b0000001
 #define GPIO_OUTPUT_PP_PU_LS   0b0100001
 #define GPIO_OUTPUT_PP_PD_LS   0b1000001						     
 #define GPIO_OUTPUT_OD_LS      0b0000101
 #define GPIO_OUTPUT_OD_PU_LS   0b0100101
 #define GPIO_OUTPUT_OD_PD_LS   0b1000101
								
 //GPIO_Alternate_Function:        
 #define GPIO_AF_PP_LS	        0b0000010		     
 #define GPIO_AF_PP_PU_LS	    0b0100010				     
 #define GPIO_AF_PP_PD_LS	    0b1000010					     
 #define GPIO_AF_OD_LS          0b0000110		     
 #define GPIO_AF_OD_PU_LS	    0b0100110				     
 #define GPIO_AF_OD_PD_LS	    0b1000110
 
 
 
 
 
 //GPIO_INPUT:                     
 #define GPIO_INPUT_FLOAT   0b0000000
 #define GPIO_INPUT_PU      0b0100000
 #define GPIO_INPUT_PD      0b1000000
								
 //GPIO_INPUT_OUTPUT ANALOG:       
 #define GPIO_IN_OUT_ANALOG 0b0000011

 //GPIO_DIRECTION:
 #define GPIO_INPUT  0x55
 #define GPIO_OUTPUT 0xAA

 /* ================================ */
		
		
/* === GPIO ALTERNATE FUNCTIONS === */
 #define GPIO_ALTERNATE_FUNC_0   0
 #define GPIO_ALTERNATE_FUNC_1   1
 #define GPIO_ALTERNATE_FUNC_2   2
 #define GPIO_ALTERNATE_FUNC_3   3
 #define GPIO_ALTERNATE_FUNC_4   4
 #define GPIO_ALTERNATE_FUNC_5   5
 #define GPIO_ALTERNATE_FUNC_6   6
 #define GPIO_ALTERNATE_FUNC_7   7
 #define GPIO_ALTERNATE_FUNC_8   8
 #define GPIO_ALTERNATE_FUNC_9   9
 #define GPIO_ALTERNATE_FUNC_10  10
 #define GPIO_ALTERNATE_FUNC_11  11
 #define GPIO_ALTERNATE_FUNC_12  12
 #define GPIO_ALTERNATE_FUNC_13  13
 #define GPIO_ALTERNATE_FUNC_14  14
 #define GPIO_ALTERNATE_FUNC_15  15
 /* ================================ */

 /* === GPIO LOW-HIGH STATES === */
 #define GPIO_RESET	0x00010000
 #define GPIO_SET	0x00000001
 #define GPIO_LOW	0x00010000
 #define GPIO_HIGH	0x00000001
 #define LOW	    0x00010000
 #define HIGH	    0x00000001
 
 /* ===================== */
 /* Registers Bit Masking */
 /* ===================== */
 //Clear_Regs:
 #define GPIO_MODER_CLR   0x00000003
 #define GPIO_OTYPER_CLR  0x00000001
 #define GPIO_OSPEEDR_CLR 0x00000003
 #define GPIO_PUPDR_CLR   0x00000003 
 #define GPIO_BSRR_CLR    0x00010001
 #define GPIO_AFR_CLR     0x0000000F
 
 //Select Regs:
 #define GPIO_MODER_SEL   0b0000011
 #define GPIO_OTYPER_SEL  0b0000100
 #define GPIO_OSPEEDR_SEL 0b0011000
 #define GPIO_PUPDR_SEL   0b1100000
 
 //Shift_Regs:
 #define GPIO_MODER_SHIFT   0
 #define GPIO_OTYPER_SHIFT  2
 #define GPIO_OSPEEDR_SHIFT 3
 #define GPIO_PUPDR_SHIFT   5
 
 //Shifting_bits:
 #define SINGLE_BIT  1
 #define DOUBLE_BITS 2
 #define QUADRA_BITS 4
 
 
 
 /* ============================== */
 /* ============================== */
 /* ============================== */
 #define MAX_PINS_NUM 15 
 #define AF_LOW_MAX   0x0080 /* the pin number 7 */





 
 /* =============================== */
 /* ========== GPIO APIs ========== */
 /* =============================== */
 GPIO_enuErrorStatus  GPIO_enuInit(GPIO_Config_t *Add_strGpioCfgPtr);
 GPIO_enuErrorStatus  GPIO_enuSetPinValue(GPIO_Config_t *Add_strGpioCfgPtr);
 GPIO_enuErrorStatus  GPIO_enuSetPinAlternateFunction(GPIO_AF_Config_t *Add_strGpioCfgPtr);
 GPIO_enuGetPinStatus GPIO_enuGetPinValue(GPIO_Config_t *Add_strGpioCfgPtr, u8 Copy_u8Direction);
 
 
 /* ===================================================================== */

 
 
 #endif
 
