/********************************
 *  Author: Raouf Magdy         *
 *                              *
 *  Date: 20-04-2023            *
 *                              *
 *  Version: V_01               *
 *                              *
 ********************************/
 

 #include "STD_Types.h"
 #include "BIT_MATHs.h"
 #include "UART_Private.h"
 #include "UART_Interface.h"

 
 
 
 static UART_CFG_Buffer_t user_SendData[3];
 static UART_CFG_Buffer_t user_ReceData[3];
 static CallBackFunction cbfRX[3]={NULL};
 static CallBackFunction cbfTX[3]={NULL};
 static u32 UART_TXstate[3]={Uart_IDEL,Uart_IDEL,Uart_IDEL};
 static u32 UART_RXstate[3]={Uart_IDEL,Uart_IDEL,Uart_IDEL};



/* ================================================================================================== */
/* ======================================= UART INITIALIZATION ====================================== */
/* ================================================================================================== */

Uart_enuStatus_t UART_Init(const UART_CFG_t* copy_pCfg)
{
    Uart_enuStatus_t LOC_Status= Uart_Ok;
    u32 Loc_tmpVal;
    u16	Loc_tmpMantissa;
	u16 Loc_tmpFraction;
    void* LOC_tmpRegisters;

    if(copy_pCfg == NULL) {
		LOC_Status = Uart_NullPointer;
	} else {
        Loc_tmpVal = ((s64)F_CLK * 1000) / (copy_pCfg->BaudRate * (8 * (2 - copy_pCfg->Oversampling )));
        Loc_tmpFraction = (Loc_tmpVal % 1000) * (8 * (2 - copy_pCfg->Oversampling));
        Loc_tmpFraction = Loc_tmpFraction / 1000;

        if(Loc_tmpFraction > 0xF) {
            Loc_tmpMantissa += (Loc_tmpFraction & 0xF0); 
        }
        Loc_tmpMantissa = Loc_tmpVal / 1000;
		
        LOC_tmpRegisters = copy_pCfg->UART_Channal;
        /* Store the Baudrate */
        ((UART_Reg_t*)LOC_tmpRegisters)->BRR = (Loc_tmpMantissa << 4) | (Loc_tmpFraction & 0x0F);
        /* Clear Control register for UART */
        ((UART_Reg_t*)LOC_tmpRegisters)->CR[0] = 0;
        /* configure the UART */
        ((UART_Reg_t*)LOC_tmpRegisters)->CR[0] |= copy_pCfg->Oversampling << 15;
        ((UART_Reg_t*)LOC_tmpRegisters)->CR[0] |= copy_pCfg->WordLength <<12;
        ((UART_Reg_t*)LOC_tmpRegisters)->CR[0] |= copy_pCfg->ParityControl<<9;

        /* Enable UART */
        ((UART_Reg_t*)LOC_tmpRegisters)->CR[0] |= copy_pCfg->UartEnable<<13;

        /* Clear the sr register */
        ((UART_Reg_t*)LOC_tmpRegisters)->SR = 0;
	}
    return LOC_Status;
}














