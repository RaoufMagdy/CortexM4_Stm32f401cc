/***************************
 * Author: Raouf Magdy     *
 * Date: 04/04/2023        *
 * Version: V01            *
 ***************************/
 
 
 
 #ifndef LCD_INTERFACE_H
 #define LCD_INTERFACE_H
 
 #include "STD_Types.h"
 #include "LCD_Config.h"

 #define SINGLE_BIT 0b00000001
 
 #define FIRST_LINE  0
 #define SECOND_LINE 1

 #define CMD  0
 #define DATA 1

 #define WRITE 0
 #define READ  1

 /* LCD Pins States */
 #define HIGH	    0x00000001
 #define LOW	    0x00010000
 #define PIN_HIGH   0x00000001
 #define PIN_LOW    0x00010000

 #define DDRAM_SECOND_LINE 0x80


typedef enum {
	LCD_ClrScreen 		= 0x01,		// clears the entire screen content
	LCD_ReturnHome  	= 0x02,		// Sets DDRAM to the entry point 00H and returns the cursor as well
	LCD_EntryMode		= 0x06,		// To enable the shift of the screen when cursor moves left or right
	LCD_DispOff  		= 0x08,		// Display off and cursor as well
	LCD_DispOn   		= 0x0C,		// Set the display and Cursor off
	LCD_CursorOn_DispOn = 0x0E,		// display on and cursor on
	LCD_ShiftLift   	= 0x18,		// Moves display to the left
	LCD_ShiftRight  	= 0x1C,		// Moves display to right
}LCD_enuCmd;



 typedef enum{
    RS = 0,
    RW,
    E,
    CtrlPinsCount
 }LCD_enuCtrlPins;


 typedef enum{
    LCD_enuOK = 0,
    LCD_enuBusy,
    LCD_enuIdle,
    LCD_enuPinError,
    LCD_enuNotInitialised
 }LCD_enuErrorStatus;


/* ===== LCD Configurations ===== */
 typedef struct{
    void* GPIO_Port;
	u16   GPIO_Pin;
	u32   GPIO_Mode_Speed;
	u8    GPIO_Value;
 }LCD_Cfg_t; 

 extern LCD_Cfg_t LCD_CtrlConfigs[CtrlPinsCount]; /* LCD Control Configurations */ 
 extern LCD_Cfg_t LCD_DataConfigs[DataPinsCount]; /* LCD Data Configurations */
 /* =========================== */


 /* ======== LCD Pins Set&Clear Functions ======== */
 void LCD_SetCtrlPinState(u8 CtrlPinIdx, u32 CtrlPinState);
 void LCD_SetDataPinState(u8 DataPinIdx, u32 DataPinState);
 void LCD_SetDelayMs(u8 Copy_u8DelayVal);

 /* ======== LCD APIs ======== */
 void LCD_Init(void);
 LCD_enuErrorStatus LCD_vidWriteCmd(u8 Copy_u8Cmd);
 LCD_enuErrorStatus LCD_vidWriteData(u8 Copy_u8Data);
 LCD_enuErrorStatus LCD_vidWriteString(char* Copy_String);
 LCD_enuErrorStatus LCD_vidGoToDDRAM(u8 Copy_u8Row, u8 Copy_u8Col);
 LCD_enuErrorStatus LCD_vidGoToCGRAM(u8 Copy_u8X_axis, u8 Copy_u8Y_axis);
 LCD_enuErrorStatus LCD_vidGoToCGROM(u8 Copy_u8X_axis, u8 Copy_u8Y_axis);
 

 
 
 
 
 #endif
 
