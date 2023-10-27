/***************************
 * Author: Raouf Magdy     *
 * Date: 04/04/2023        *
 * Version: V01            *
 ***************************/
 
 
 
 #ifndef LCD_CONFIG_H
 #define LCD_CONFIG_H
 

  /* Choose Data pins number to assure your configurations */
  #define FOUR  4
  #define EITHT 8
  #define DATA_PINS_NUM EITHT

 /* Systick Clock Source */
  #define HSI_AHB_8_MS           2000
  #define HSI_ProcessorClock_MS  16000
  #define HSE_AHB_8_MS           3125
  #define HSE_ProcessorClock_MS  25000
  #define LCD_DelayMs            HSI_ProcessorClock_MS
 /*
    NOTE THAT: When using LCD with Schedualer you need to make the "Tick" time of the sheduler > 2 ms
               so that we can perform the delays required for the LCD operations.
 */



 /* __________________________________________________________________________
    |===>   This configuration can either be for 8Pins or 4Pins modes    <===|
    |===> Just uncomment the desired configuration and comment the other <===| 
    |________________________________________________________________________|
 */

 typedef enum{
    DataPin0 = 0,
    DataPin1,
    DataPin2,
    DataPin3,
    DataPin4,
    DataPin5,
    DataPin6,
    DataPin7,
    DataPinsCount

 } LCD_enuDataPins;

/*
 typedef enum{
    DataPin4 = 0,
    DataPin5,
    DataPin6,
    DataPin7,
    DataPinsCount

 } LCD_enuDataPins;
*/

 
 
 
 #endif
 