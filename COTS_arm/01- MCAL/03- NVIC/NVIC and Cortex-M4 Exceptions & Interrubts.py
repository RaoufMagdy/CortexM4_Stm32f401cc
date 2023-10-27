print("""                                             
                                        /* Exceptions and Interrubts in Cortex-M4 */
											   
===========================================================================================================================================

Overview of exceptions and interrupts:
----------------------------------------


  Interrupts are events typically generated by hardware (e.g., peripherals or external input pins)
  that cause changes in program flow control outside a normal programmed sequence.
  When a peripheral or hardware needs service from the processor,
  typically the following sequence would occur:
  1-) The peripheral asserts an interrupt request to the processor.
  2-) The processor suspends the currently executing task.
  3-) The processor executes an Interrupt Service Routine (ISR) to service the peripheral,
      and optionally clear the interrupt request by software if needed.
  4-) The processor resumes the previously suspended task.


  The Cortex-M processors provide a feature-packed exception architecture that supports
  a number of system exceptions and external interrupts. Exceptions are
  numbered (1 to 15) for SYSTEM EXCEPTIONS and (16 and above) for INTERRUPT inputs (inputs
  to the processor, but not necessarily accessible on the I/O pins of the package). Most
  of the exceptions, including all interrupts, have PROGRAMMABLE PRIORITIES, and a few
  system exceptions have FIXED PRIORITY. 
  
  The table of Expetions : Table 7.1 => Ch7, Page 232.
  The table of Interrupts: Table 7.2 => Ch7, Page 233.


  Cortex-M3 & M4 microprocessors can have up to 240 interrupt input sources and different number of priority levels.
  Interrupts are numbered from 0 to 239(max).
  
  CMSIS: Common Microcontroller Software Interface Standard (CMSIS) is a vendor-independent abstraction layer for microcontrollers 
  that are based on Arm Cortex processors. CMSIS defines generic tool interfaces and enables consistent device support. 
  The CMSIS software interfaces simplify software reuse,reduce the learning curve for microcontroller developers, 
  and improve time to market for new devices.

===========================================================================================================================================

Overview of interrupt management:
-----------------------------------

  
  The CMSIS-Core also defines the names of the system exception handlers.
  The reason for using a different number system in CMSIS-Core access functions
  is to allow slightly better efficiency in some of these API functions (e.g.,
  when setting up priority levels). The interrupt number and enumeration definitions
  of interrupts are device-specific, and are defined in device-specific header files
  provided by microcontroller vendors, in a “typedef” section called “IRQn.”


  The NVIC and SCB are located inside the System Control Space (SCS) address
  range from 0xE000E000, with a size of 4KB. The SCS also contains registers for
  the SysTick timer, Memory Protection Unit (MPU), debug registers, etc. Almost
  all of the registers in this address range can only be accessed by code running in
  privileged access level. The only exception is a register called the Software Trigger
  Interrupt Register (STIR), which can be set up to be accessible in unprivileged
  mode.


  For general application programming, the best practice is to use the CMSIS-Core
  access functions. For example, the most commonly used interrupt control functions
  are shown in Table 7.4.
  You can also directly access registers in NVIC or SCB if needed. But such practice
  might limit the software portability when porting the code from one Cortex-M
  processor to another with a different processor type.


  After reset, all interrupts are disabled and given a priority-level value of "0". 
  Before using any interrupts, you need to:
  • Set up the priority level of the required interrupt (this step is optional).
  • Enable the interrupt generation control in the peripheral that triggers the interrupt.
  • Enable the interrupt in the NVIC.

===========================================================================================================================================

Overview of Priority:
-----------------------

  In most cases, applications only require a small number of programmable priority levels.
  Therefore silicon chip designers need to customize their processor design based on
  the number of priority levels in the targeted applications. This reduction in levels is
  implemented by cutting out the least significant bit (LSB) part of the priority configuration registers.


  The reason for removing the least significant bit (LSB) of the priority-level registers
  instead of the most significant bit (MSB) is to make it easier to port software
  from one Cortex-M device to another. In this way, a program written for devices with
  4-bit priority configuration registers is likely to be able to run on devices with 3-bit.
  If the MSB is removed instead of the LSB, you might get an inversion of the priority arrangement
  when porting an application from one Cortex-M chip to another.

=========================================================================================================================================== 

Input Interrupts and bending behaviour:
-----------------------------------------

  There are various status attributes applicable to each interrupt:
  • Each interrupt can either be disabled (default) or enabled.
  • Each interrupt can either be pending or not pending.
  • Each interrupt can either be in an active (being served) or inactive state.
  
  status. An interrupt request can be accepted by the processor if:
  • The pending status is set.
  • The interrupt is enabled.
  • The priority of the interrupt is higher than the current level.
  
  The NVIC is designed to support peripherals that generate pulsed interrupt
  requests as well as peripherals with high level interrupt request. There is no
  need to configure any NVIC register to select either interrupt type.
  
  • For pulsed interrupt requests, THE PULSE MUST BE AT LEAST ONE CLOCK CYCLE LONG.
  • For level triggered interrupts, the peripheral requesting service asserts the request signal
    until it is cleared by an operation inside the ISR.
  • The request signals received by the NVIC are active high, although the external interrupt request
    at the I/O pin level could be active low.
	

  The pending status of the interrupts are stored in programmable registers in the NVIC. 
  When an interrupt input of the NVIC is asserted, it causes the pending status of the interrupt to be asserted.
  The pending status remains high even if the interrupt request is de-asserted.
  In this way, the NVIC can work with pulsed interrupt requests.
  
  When the processor starts to process an interrupt request, the pending status of
  the interrupt is cleared automatically.
  When the interrupt is being served, it is in the active state. Please note that in the
  interrupt entry sequence, a number of registers are pushed onto the stack automatically.
  This is called stacking. Meanwhile, the starting address of the ISR is fetched from the vector table.
  
  Note: 
  In many microcontroller designs, the peripherals operate with level-triggered interrupts
  and therefore the ISR will have to clear the interrupt request manually; for example,
  by writing to a register in the peripheral.	
  
===========================================================================================================================================

Exception sequence overview:
------------------------------

  The processor accepts an exception if the following conditions are met:
  • The processor is running (not halted or in reset state).
  • The exception is enabled (with special cases for NMI and HardFault exceptions,
    which are always enabled).
  • The exception has higher priority than the current priority level.
  • The exception is not blocked by an exception masking register (e.g., PRIMASK).
  

Exception entrance sequence:
-----------------------------
An exception entrance sequence contains several operations:

  • Stacking of a number of registers, including "return address" to the currently selected stack. 
    This enables an exception handler to be written as a normal C function. 
    If the processor was in Thread mode and was using the Process Stack Pointer (PSP), 
    the stack area pointed to by the PSP will be used for this stacking.
    Otherwise the stack area pointed to by the Main Stack Pointer (MSP) will be used.
	
  • Fetching the exception vector (starting address of the exception handler/ISR).
    ==> THIS CAN HAPPEN IN PARALLEL TO THE STACKING OPERATION TO REDUCE LATENCY.
	
  • Fetching the instructions for the exception handler to be executed. After the starting
    address of the exception handler is determined, the instructions can be fetched.  

  • Update of various NVIC registers and core registers. This includes the pending
    status and active status of the exception, and registers in the processor core
    including the Program Status Register (PSR), Link Register (LR), Program
    Counter (PC), and Stack Pointer (SP).



Exception handler execution:
------------------------------






===========================================================================================================================================


""")



