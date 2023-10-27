/***************************
 * Author: Raouf Magdy     *
 * Date: 04/04/2023        *
 * Version: V01            *
 ***************************/
 
 
 #include "LCD_Interface.h"
 #include "GPIO_Interface.h"


 LCD_Cfg_t LCD_CtrlConfigs[CtrlPinsCount] = {

        [RS] = {.GPIO_Port = GPIO_PORTB, .GPIO_Pin = GPIO_PIN0, .GPIO_Mode_Speed = GPIO_OUTPUT_PP_VHS},
        [RW] = {.GPIO_Port = GPIO_PORTB, .GPIO_Pin = GPIO_PIN1, .GPIO_Mode_Speed = GPIO_OUTPUT_PP_VHS},
        [E]  = {.GPIO_Port = GPIO_PORTB, .GPIO_Pin = GPIO_PIN2, .GPIO_Mode_Speed = GPIO_OUTPUT_PP_VHS}
};
 /* 
    Make sure you configure the Data pins according to the selected number of "Data Pins" 
    ==> "DATA_PINS_NUM"
 */

 LCD_Cfg_t LCD_DataConfigs[DataPinsCount] = {
                        /*Uncomment the Upper Section if you are using 4-Pin Mode*/
        [DataPin0] = {.GPIO_Port = GPIO_PORTB, .GPIO_Pin = GPIO_PIN3, .GPIO_Mode_Speed = GPIO_OUTPUT_PP_VHS},
        [DataPin1] = {.GPIO_Port = GPIO_PORTB, .GPIO_Pin = GPIO_PIN4, .GPIO_Mode_Speed = GPIO_OUTPUT_PP_VHS},
        [DataPin2] = {.GPIO_Port = GPIO_PORTB, .GPIO_Pin = GPIO_PIN5, .GPIO_Mode_Speed = GPIO_OUTPUT_PP_VHS},
        [DataPin3] = {.GPIO_Port = GPIO_PORTB, .GPIO_Pin = GPIO_PIN6, .GPIO_Mode_Speed = GPIO_OUTPUT_PP_VHS},

        [DataPin4] = {.GPIO_Port = GPIO_PORTB, .GPIO_Pin = GPIO_PIN7, .GPIO_Mode_Speed = GPIO_OUTPUT_PP_VHS},
        [DataPin5] = {.GPIO_Port = GPIO_PORTB, .GPIO_Pin = GPIO_PIN8, .GPIO_Mode_Speed = GPIO_OUTPUT_PP_VHS},
        [DataPin6] = {.GPIO_Port = GPIO_PORTB, .GPIO_Pin = GPIO_PIN9, .GPIO_Mode_Speed = GPIO_OUTPUT_PP_VHS},
        [DataPin7] = {.GPIO_Port = GPIO_PORTB, .GPIO_Pin = GPIO_PIN10, .GPIO_Mode_Speed = GPIO_OUTPUT_PP_VHS}
};
 
 
 
