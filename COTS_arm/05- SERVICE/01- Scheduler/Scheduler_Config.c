/********************************
 *  Author: Raouf Magdy         *
 *                              *
 *  Date: 21-03-2023            *
 *                              *
 *  Version: V_01               *
 *                              *
 ********************************/
 
 
 #include "STD_Types.h"
 #include "Scheduler_Interface.h"
 #include "Scheduler_Config.h"



  TasksData_t TasksDataArr[NumOfTasks] = {

		[Task1] = {
					.name = "Task One 0.3s",
					.Runnable = App_Task1,
					.TaskPeriodms = 300,
					.StartDelayms = 0,
			  },
			  
	    [Task2] = {
					.name = "Task Two 0.6s",
					.Runnable = App_Task2,
					.TaskPeriodms = 600,
					.StartDelayms = 0,
	          },

		[Task3] = {
			  		.name = "Task Two 0.1s",
			  		.Runnable = App_Task3,
			  		.TaskPeriodms = 100,
			  		.StartDelayms = 0,
			  	  }

 };

 
 
 
 
 
 
