#include "Scheduler_Interface.h"
#include "Led_Interface.h"
#include "Switch_Interface.h"
#include "Sched_App.h"


void App_Task1(void)
{
	static u8 count = 0;

	if(count == 0)
	{
		Led_vidSetState(Led_1, LED_LOW);
		count = 1;
	}
	else{
		Led_vidSetState(Led_1, LED_HIGH);
		count = 0;
	}

}

void App_Task2(void)
{
	static u8 count = 0;
	if(count == 0)
	{
		Led_vidSetState(Led_2, LED_LOW);
		count = 1;
	}
	else{
		Led_vidSetState(Led_2, LED_HIGH);
		count = 0;
	}
}

void App_Task3(void)
{
	static u8 count = 0;
	static u8 ValGetter = 0;

	Switch_Task();

	ValGetter = Switch_GetState(Switch_Alarm);

	if(ValGetter>0 && count==0)
	{
		Led_vidSetState(Led_3, LED_HIGH);
		count = 1;
	}
	else
	{
		Led_vidSetState(Led_3, LED_LOW);
		count = 0;
	}
}

