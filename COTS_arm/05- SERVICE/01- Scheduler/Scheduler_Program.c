/********************************
 *  Author: Raouf Magdy         *
 *                              *
 *  Date: 21-03-2023            *
 *                              *
 *  Version: V_01               *
 *                              *
 ********************************/




#include "STD_Types.h"
#include "BIT_MATHs.h"
#include "SYSTICK_Interface.h"
#include "Scheduler_Interface.h"

#define TickTime SCHEDULER_TICK_MS //1ms tick
//Note that each 1ms an interrupt will occur which isn't the best case we can reduce
// the number of interrupts by increasing the tick time if we can in our system
// so that the software goes in a less number of interrupts.

static u8 flag = 0;


typedef struct
 {
 	TasksData_t *TasksData;
 	u32 RemainingTime;
 }Tasks_t;


static Tasks_t tasksList[NumOfTasks] ;


void SchedCBF(void)
{
	if (flag == 0)
	{
		flag = 1;
	}
}


void Sched_vidInit(void)
{
	u8 idx = 0;

	/* SysTick Initialization */
	SysTick_SetClockSource(Processor_Clock);
	SysTick_EnableSEQ();
	SysTick_SetPeriod_ms(HSI, Processor_Clock, TickTime); //Note: systick period must be less than or equal the least task period.
	SysTick_CallBackFunction(SchedCBF);

	for(idx=0; idx<NumOfTasks; idx++)
	{
		tasksList[idx].TasksData     = &TasksDataArr[idx];
		tasksList[idx].RemainingTime = TasksDataArr[idx].TaskPeriodms;
	}
}

void Sched_IncreaseTaskPeriod(u8 Copy_u8TaskIndex, u16 Copy_u16PausePeriodMs)
{
	TasksDataArr[Copy_u8TaskIndex].TaskPeriodms = tasksList[Copy_u8TaskIndex].RemainingTime;

	if(Copy_u8TaskIndex <= NumOfTasks)
	{
		TasksDataArr[Copy_u8TaskIndex].TaskPeriodms += Copy_u16PausePeriodMs;
	}

}


void Sched_ChangeTaskPeriod(u8 Copy_u8TaskIndex, u16 Copy_u16PausePeriodMs)
{
	if(Copy_u8TaskIndex <= NumOfTasks)
	{
		TasksDataArr[Copy_u8TaskIndex].TaskPeriodms = Copy_u16PausePeriodMs;
	}
}


void Sched_SetBackTaskPeriod(u8 Copy_u8TaskIndex)
{
	TasksDataArr[Copy_u8TaskIndex].TaskPeriodms = tasksList[Copy_u8TaskIndex].RemainingTime;
}


void Sched(void)
{
	u8 idx = 0;

	for(idx=0; idx<NumOfTasks; idx++)
	{
		if (tasksList[idx].TasksData->Runnable != NULL)
		{
			if (tasksList[idx].RemainingTime == 0)
			{
				tasksList[idx].TasksData -> Runnable();
				tasksList[idx].RemainingTime = tasksList[idx].TasksData -> TaskPeriodms;
			}
		}

		tasksList[idx].RemainingTime -= TickTime;
	}

}


void Sched_vidStart(void)
{
	SysTick_Start();

	while(1)
	{
		//polling until the new tick.
		if(flag == 1)
		{
			Sched();
			flag = 0;
		}
	}
}

/* ======================================================================================================= */
