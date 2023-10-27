/********************************
 *  Author: Raouf Magdy         *
 *                              *
 *  Date: 21-03-2023            *
 *                              *
 *  Version: V_01               *
 *                              *
 ********************************/
 
 
 
 #ifndef SCHEDULER_CONFIG_H
 #define SCHEDULER_CONFIG_H
 

 #include "Sched_App.h"
 
 #define SCHEDULER_TICK_MS         1 //tick time
 //#define SCHEDULER_RUNNABLE_COUNT  4 //number of runnable tasks
 
 //#define Tasks_Number	3 // You can use NumOfTasks directly.

 typedef enum
 {
	Task1 = 0,
	Task2,
	Task3,
	NumOfTasks
 }enuNumOfTasks;




 
 
 #endif
 
 
 
 
 
 
 
 
