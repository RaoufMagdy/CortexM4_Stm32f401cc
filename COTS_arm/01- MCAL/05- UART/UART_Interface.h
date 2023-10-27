/********************************
 *  Author: Raouf Magdy         *
 *                              *
 *  Date: 20-04-2023            *
 *                              *
 *  Version: V_01               *
 *                              *
 ********************************/
 
 
 
 #ifndef UART_INTERFACE_H
 #define UART_INTERFACE_H
 
 #include "UART_Private.h"
 #include "UART_Config.h"
 

 #define USART_1 ((void*) UART1)
 #define USART_2 ((void*) UART2)
 #define USART_6 ((void*) UART6)

 #define TransmitEnable   ((u32)1<<3) // 0x00000008
 #define ReceiveEnable 	  ((u32)1<<2) // 0x00000004
 #define TCIE             ((u32)1<<6) // 0x00000040
 #define RXNEIE           ((u32)1<<5) // 0x00000020

 #define UART_Enable  1
 #define UART_Disable 0
 
 #define	USART1	0
 #define	USART2	1
 #define	USART6	2


//Error Status:
typedef enum
{
	UART_enuOK ,
    UART_enuNotOK,
	UART_enuIdel,
	UART_enuBusy,
	UART_enuNullPointer
}UART_enuStatus;

//UART Configurations:
typedef struct
{
    void* UART_Channal;
    u8    Oversampling;
	u8    UartEnable;
	u8    WordLength;
	u8    ParityControl;
	u16   BaudRate;
}UART_CFG_t;

//UART Regesters:
typedef struct
{
	u32 SR;
	u32 DR;
	u32 BRR;
	u32 CR[3];
	u32 GTPR;
}UART_Regs_t;


//UART Data storage to send
typedef struct
{
	u8 Data;
	u32 Size;
	void* UART_Channal;
    u32 idx;
}UART_CFG_Buffer_t;


typedef void(*CallBackFunction)(void);

//UART APIs:
Uart_enuStatus_t UART_Init(const UART_CFG_t* copy_pCfg);
Uart_enuStatus_t UART_SendBufferAsynZeroCopy(Uart_Channel_t UartChannel,const pu8 buffer, u32 size);
Uart_enuStatus_t UART_ReceiveBuffer(Uart_Channel_t UartChannel, pu8 buffer, u32 size);
Uart_enuStatus_t UART_SetTXCallback(Uart_Channel_t uartChannal, CallBack tx_callback);
Uart_enuStatus_t UART_SetRXCallback(Uart_Channel_t uartChannal,CallBack rx_callback);



