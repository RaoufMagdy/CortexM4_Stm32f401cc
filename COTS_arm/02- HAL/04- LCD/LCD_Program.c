/***************************
 * Author: Raouf Magdy     *
 * Date: 04/04/2023        *
 * Version: V01            *
 ***************************/
 
 
 #include "STD_Types.h"
 #include "GPIO_Interface.h"
 #include "SYSTICK_Interface.h"
 #include "Scheduler_Config.h"
 #include "LCD_Interface.h"

#define  LCD_OK     			8
#define  Max_Screen_Length      15
#define  Init_1					0
#define  Init_2					1
#define  NoReq  				0
#define  Write  				1
#define  Clear  				2
#define  GoXY   				3

//LCD Commands:
#define ClearScreen 	0x01
#define Home        	0x02
#define EntryMode   	0x06
#define DisplayOFF  	0x08
#define DisplayON   	0x0C
#define CursorOnDispOn  0x0E
#define LeftShift       0x18
#define RightShift		0x1C
#define SetFunction     0x38
#define SetCGRAM 		0x40
#define SetDDRAM		0x80



 typedef struct
 {
	const u8 * str;
	u8 len;
	u8 currentPos;
 }user_req_t;


 u8 init_Done = 0;
 static u8 state = Init_1;
 u8 Req = NoReq;
 user_req_t requestData;


 static void LCD_WriteSeq();
 static void LCD_ClearSeq(void);


 //========================================================================================================//
 //===================================== LCD CONTROL PINS SET&CLEAR =======================================//
 //========================================================================================================//

 void LCD_SetCtrlPinState(u8 CtrlPinIdx, u32 CtrlPinState)
 {
	if(CtrlPinIdx < CtrlPinsCount) {
	 	GPIO_Config_t LcdCtrlCFG;
	 	LcdCtrlCFG.GPIO_Port  = LCD_CtrlConfigs[CtrlPinIdx].GPIO_Port;
	 	LcdCtrlCFG.GPIO_Pin   = LCD_CtrlConfigs[CtrlPinIdx].GPIO_Pin;
		LcdCtrlCFG.GPIO_Value = CtrlPinState ^ LCD_CtrlConfigs[CtrlPinIdx].GPIO_Value;
	 	GPIO_enuSetPinValue(&LcdCtrlCFG);
	} else {
		/* Do Nothing */
    }
 }

 //========================================================================================================//
 //======================================= LCD DATA PINS SET&CLEAR ========================================//
 //========================================================================================================//

 void LCD_SetDataPinState(u8 DataPinIdx, u32 DataPinState)
 {
	if(DataPinIdx < DataPinsCount) {
		 GPIO_Config_t LcdDataCFG;
		 LcdDataCFG.GPIO_Port  = LCD_DataConfigs[DataPinIdx].GPIO_Port;
		 LcdDataCFG.GPIO_Pin   = LCD_DataConfigs[DataPinIdx].GPIO_Pin;
		 LcdDataCFG.GPIO_Value = DataPinState ^ LCD_DataConfigs[DataPinIdx].GPIO_Value;
		 GPIO_enuSetPinValue(&LcdDataCFG);
	} else {
		/* Do Nothing */
	}
 }
 

 //========================================================================================================//
 //========================================== LCD INITIALIZATION ==========================================//
 //========================================================================================================//
 
 void LCD_Init(void)
 {
	 u16 DummyIteratorForDummyLcdMCU = 0;

	 //Pins initialisation:
	 GPIO_Config_t LcdInitCFG;
	 u8 Loc_InitIdx = 0;
	 //initialising control pins:
	 for(Loc_InitIdx = 0; Loc_InitIdx<CtrlPinsCount; Loc_InitIdx++)
	 {
		 LcdInitCFG.GPIO_Port 		= LCD_CtrlConfigs[Loc_InitIdx].GPIO_Port;
		 LcdInitCFG.GPIO_Pin        = LCD_CtrlConfigs[Loc_InitIdx].GPIO_Pin;
		 LcdInitCFG.GPIO_Mode_Speed = LCD_CtrlConfigs[Loc_InitIdx].GPIO_Mode_Speed;
		 GPIO_enuInit(&LcdInitCFG);
	 }
	 //initialising data pins:
	 Loc_InitIdx = 0;
	 for(Loc_InitIdx = 0; Loc_InitIdx<DataPinsCount; Loc_InitIdx++)
	 {
	 	 LcdInitCFG.GPIO_Port 		= LCD_DataConfigs[Loc_InitIdx].GPIO_Port;
	 	 LcdInitCFG.GPIO_Pin        = LCD_DataConfigs[Loc_InitIdx].GPIO_Pin;
	 	 LcdInitCFG.GPIO_Mode_Speed = LCD_DataConfigs[Loc_InitIdx].GPIO_Mode_Speed;
	 	 GPIO_enuInit(&LcdInitCFG);
	 }

	 // Display Clear: 0b00000001;
	 LCD_SetCtrlPinState(E, PIN_LOW);
	 // RS -> 0; command
	 LCD_SetCtrlPinState(RS, PIN_LOW);
	 // RW -> 0; write
	 LCD_SetCtrlPinState(RW, PIN_LOW);
	 LCD_SetDataPinState(DataPin7, PIN_LOW);
	 LCD_SetDataPinState(DataPin6, PIN_LOW);
	 LCD_SetDataPinState(DataPin5, PIN_LOW);
	 LCD_SetDataPinState(DataPin4, PIN_LOW);
	 LCD_SetDataPinState(DataPin3, PIN_LOW);
	 LCD_SetDataPinState(DataPin2, PIN_LOW);
	 LCD_SetDataPinState(DataPin1, PIN_LOW);
	 LCD_SetDataPinState(DataPin0, PIN_HIGH);
	 LCD_SetCtrlPinState(E, PIN_HIGH);

	 while(DummyIteratorForDummyLcdMCU < 32000) //delay 2ms
	 {
		 DummyIteratorForDummyLcdMCU++;
	 }
	 DummyIteratorForDummyLcdMCU = 0;

	 // Function Set: 0b00111000; Sets 8-bit operation and selects 2-line display and 5*8 dot char font
	 LCD_SetCtrlPinState(E, PIN_LOW);
	 // RS -> 0; command
	 LCD_SetCtrlPinState(RS, PIN_LOW);
	 // RW -> 0; write
	 LCD_SetCtrlPinState(RW, PIN_LOW);
	 LCD_SetDataPinState(DataPin7, PIN_LOW);
	 LCD_SetDataPinState(DataPin6, PIN_LOW);
	 LCD_SetDataPinState(DataPin5, PIN_HIGH);
	 LCD_SetDataPinState(DataPin4, PIN_HIGH);
	 LCD_SetDataPinState(DataPin3, PIN_HIGH);
	 LCD_SetDataPinState(DataPin2, PIN_LOW);
	 LCD_SetDataPinState(DataPin1, PIN_LOW);
	 LCD_SetDataPinState(DataPin0, PIN_LOW);
	 LCD_SetCtrlPinState(E, PIN_HIGH);
	 
	 while(DummyIteratorForDummyLcdMCU < 32000) //delay 2ms
	 {
		 DummyIteratorForDummyLcdMCU++;
	 }
	 DummyIteratorForDummyLcdMCU = 0;

	 //Display on,: 0b00001100;
	 // D = 1; // Display on
	 // C = 0; // Cursor off (no curser)
	 // B = 0; // Cursor Blinking off 
	 LCD_SetCtrlPinState(E, PIN_LOW);
	 // RS -> 0; command
	 LCD_SetCtrlPinState(RS, PIN_LOW);
	 // RW -> 0; write
	 LCD_SetCtrlPinState(RW, PIN_LOW);
	 LCD_SetDataPinState(DataPin7, PIN_LOW);
	 LCD_SetDataPinState(DataPin6, PIN_LOW);
	 LCD_SetDataPinState(DataPin5, PIN_LOW);
	 LCD_SetDataPinState(DataPin4, PIN_LOW);
	 LCD_SetDataPinState(DataPin3, PIN_HIGH);
	 LCD_SetDataPinState(DataPin2, PIN_HIGH);
	 LCD_SetDataPinState(DataPin1, PIN_LOW);
	 LCD_SetDataPinState(DataPin0, PIN_LOW);
	 LCD_SetCtrlPinState(E, PIN_HIGH);

	 while(DummyIteratorForDummyLcdMCU < 32000) //delay 2ms
	 {
	 	DummyIteratorForDummyLcdMCU++;
	 }
	 DummyIteratorForDummyLcdMCU = 0;

 }


 
 //========================================================================================================//
 //========================================== LCD WRITE COMMAND ===========================================//
 //========================================================================================================//
 
 LCD_enuErrorStatus LCD_vidWriteCmd(u8 Copy_u8Cmd)
 {
	 u8 Loc_u8Iterator = 0;
	 //clear enable
	 LCD_SetCtrlPinState(E, PIN_LOW);
	 // RS -> 0; command
	 LCD_SetCtrlPinState(RS, PIN_LOW);
	 // RW -> 0; write
	 LCD_SetCtrlPinState(RW, PIN_LOW);
	 // D0 - D7 => Command
	 for(Loc_u8Iterator = DataPin0; Loc_u8Iterator < DataPinsCount; Loc_u8Iterator++)
	 {
		if(Copy_u8Cmd & (SINGLE_BIT << Loc_u8Iterator) ) {
			LCD_SetDataPinState(Loc_u8Iterator, PIN_HIGH);
		} else {
			LCD_SetDataPinState(Loc_u8Iterator, PIN_LOW);
		}
	 }	 
	//set enable:
	 LCD_SetCtrlPinState(E, PIN_HIGH);
 }
 
 
 //========================================================================================================//
 //=========================================== LCD WRITE DATA =============================================//
 //========================================================================================================//
 
 LCD_enuErrorStatus LCD_vidWriteData(u8 Copy_u8Data)
 {
	 u8 Loc_u8Iterator = 0;

	 //clear enable
	 LCD_SetCtrlPinState(E, PIN_LOW);
	 // RS -> 1; data
	 LCD_SetCtrlPinState(RS, PIN_HIGH);
	 // RW -> 0; write
	 LCD_SetCtrlPinState(RW, PIN_LOW);
	 // D0 - D7 => Command
	 for(Loc_u8Iterator = DataPin0; Loc_u8Iterator<DataPinsCount; Loc_u8Iterator++)
	 {
		if(Copy_u8Data & (SINGLE_BIT << Loc_u8Iterator) ) {
			LCD_SetDataPinState(Loc_u8Iterator, PIN_HIGH);
		} else {
			LCD_SetDataPinState(Loc_u8Iterator, PIN_LOW);
		}
	 }	 
	//set enable:
	 LCD_SetCtrlPinState(E, PIN_HIGH);

 }


 //========================================================================================================//
 //========================================== LCD WRITE STRING ============================================//
 //========================================================================================================//

 LCD_enuErrorStatus LCD_vidWriteString(char* Copy_String)
 {
	 u8 Loc_u8Iterator= 0;
	 int Loc_u8Iterator_str = 0;
	 char GetChar;

	 while(Copy_String[Loc_u8Iterator_str] != NULL )
	 {
		//clear enable
	 	LCD_SetCtrlPinState(E, PIN_LOW);
	 	// RS -> 1; data
	 	LCD_SetCtrlPinState(RS, PIN_HIGH);
	 	// RW -> 0; write
	 	LCD_SetCtrlPinState(RW, PIN_LOW);
	 	// D0 - D7 => Command
		GetChar = Copy_String[Loc_u8Iterator_str];
		for(Loc_u8Iterator = DataPin0; Loc_u8Iterator<DataPinsCount; Loc_u8Iterator++)
	 	{
			if(GetChar & (SINGLE_BIT << Loc_u8Iterator) ) {
				LCD_SetDataPinState(Loc_u8Iterator, PIN_HIGH);
			} else {
				LCD_SetDataPinState(Loc_u8Iterator, PIN_LOW);
			}
	 	}
		//set enable:
	 	LCD_SetCtrlPinState(E, PIN_HIGH);
	 	Loc_u8Iterator_str++;
	 }

 }
 
 

 //========================================================================================================//
 //========================================= LCD WRITE GO TO XY ===========================================//
 //========================================================================================================//

 LCD_enuErrorStatus LCD_vidGoToDDRAM(u8 Copy_u8Row, u8 Copy_u8Col)
 {
	 u8 Loc_Address;
	 if(Copy_u8Row == FIRST_LINE){
		 Loc_Address = Copy_u8Col;
	 } else if(Copy_u8Row == SECOND_LINE){
		 Loc_Address = 0x40 + Copy_u8Col;
	 }else{
		 //Do_Nothing;
	 }
	 LCD_vidWriteCmd((Loc_Address + 128));
 }
 
 /*

 void LCD_vidGoToCGRAM(u8 Copy_u8X_axis, u8 Copy_u8Y_axis)
 {
	 
	 if(Copy_u8X_axis == FIRST_LINE){
		 //location = Copy_u8Y_axis;
	 } else if(Copy_u8X_axis == SECOND_LINE){
		 //location = JUMP_TO_2nd_LINE + Copy_u8Y_axis;
	 }else{
		 //Do_Nothing;
	 }
	 
	 WriteCmd(128 + location);
 }
 
 void LCD_vidGoToCGROM(u8 Copy_u8X_axis, u8 Copy_u8Y_axis)
 {
	 
	 if(Copy_u8X_axis == FIRST_LINE){
		 //location = Copy_u8Y_axis;
	 } else if(Copy_u8X_axis == SECOND_LINE){
		 //location = 0x40 + Copy_u8Y_axis;
	 }else{
		 //Do_Nothing;
	 }
	 
	 WriteCmd(128 + location);
 }
 
  
 void LCD_vidWriteSpecialChar(u8* Copy_u8Pattern, u8 Copy_u8BlockNum, u8 Copy_u8X_axis, u8 Copy_u8Y_axis)
 {
	//from CGRAM to DDRAM
	u8 Iterator = 0;
	//Address in CGRAM
	u8 Loc_u8Address = Copy_u8BlockNum * 8;
	LCD_vidWriteCmd(Loc_u8Address + 64);

	for(Iterator = 0; Iterator<7; Iterator++)
	{
		LCD_vidWriteData(Copy_u8Pattern[Iterator]);
	}


 }
 
*/
 
 
 //========================================================================================================//
  //==================================== LCD WRITE STRING ASYNCHRONOUS =====================================//
  //========================================================================================================//

  LCD_enuErrorStatus LCD_vidWriteStringAsync(const char* str, u8 size, u8 Col, u8 Row)
  {
	  LCD_enuErrorStatus status = LCD_enuBusy;
	  	if(state == LCD_enuIdle)
	  	{
	  		state = LCD_enuBusy;
	  		status = LCD_enuOK;
	  		Req =   Write;
	  		requestData.str 	   = str;
	  		requestData.len 	   = size;
	  		LCD_enuSetPosition(Col ,Row);
	  		requestData.currentPos = 0;
	  	}
	  	else if(state == LCD_enuNotInitialized)
	  	{
	  		status = LCD_enuNotInitialized;
	  	}
	  	return status;
  }


  LCD_enuErrorStatus LCD_FunctionInit(void)
 {
 	switch(state)
 	{
 	 case Init_1:
 	 	 LCD_vidWriteCmd(SetFunction);
 		 state = Init_2;
 	 break;

 	 case Init_2:
 		 LCD_vidWriteCmd(CursorOnDispOn);
 		 state = LCD_enuNotInitialized;
 	 break;

 	 case LCD_enuNotInitialized:
 		 LCD_vidWriteCmd(ClearScreen);
 		 state = LCD_enuOK;
 	 break;

 	 case LCD_OK:
 		 LCD_vidWriteCmd(EntryMode);
 		 init_Done = 1;
 		 state = LCD_enuIdle;
 	 break;
 	}
 	return state;
 }


 void LCD_Task(void)
 {
 	if(init_Done != 1)
 	{
 		LCD_FunctionInit();
 	}
 	else
 	{
 		switch(Req)
 		{
 		case Write:
 			LCD_WriteSeq();
 			break;
 		case Clear:
 			LCD_ClearSeq();
 		break;
 		}
 	}
 }

 void LCD_ClearReq()
 {
 	Req = Clear;
 }

 static void LCD_WriteSeq()
 {
 	if(requestData.currentPos==requestData.len)
 	{
 		state = LCD_enuIdle;
 		Req   = NoReq;
 	}
 	else if(requestData.currentPos==Max_Screen_Length)
 	{
 		LCD_vidGoToDDRAM(0,1);
 	}
 	else
 	{
 		LCD_voiWriteData(requestData.str[requestData.currentPos++]);
 	}
 }

 static void LCD_ClearSeq(void)
 {
 	LCD_vidSendCommand(ClearScreen);
 }
 