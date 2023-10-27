/********************************
 *  Author: Raouf Magdy         *
 *                              *
 *  Date: 21-03-2023            *
 *                              *
 *  Version: V_01               *
 *                              *
 ********************************/
 
 
 
 #ifndef SCHEDULER_INTERFACE_H
 #define SCHEDULER_INTERFACE_H

 #include "STD_Types.h"
 #include "Scheduler_Config.h"

 typedef void(*RunnableCBF_t)(void);


 typedef struct
 {
	char* name;
	RunnableCBF_t Runnable;
	u32 TaskPeriodms;
	u32 StartDelayms;
 }TasksData_t;


 void Sched_vidInit(void);
 void Sched_vidStart(void);
 void Sched_IncreaseTaskPeriod(u8 Copy_u8TaskIndex, u16 Copy_u16PausePeriodMs);
 void Sched_ChangeTaskPeriod(u8 Copy_u8TaskIndex, u16 Copy_u16PausePeriodMs);
 void Sched_SetBackTaskPeriod(u8 Copy_u8TaskIndex);
 
 void SchedCBF (void);
 void Sched (void);


 extern TasksData_t TasksDataArr[NumOfTasks];
 
 #endif
 
