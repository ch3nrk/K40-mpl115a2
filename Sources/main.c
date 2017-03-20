/* ###################################################################
**     Filename    : main.c
**     Project     : mpl
**     Processor   : MK40DN512VLK10
**     Version     : Driver 01.01
**     Compiler    : CodeWarrior ARM C Compiler
**     Date/Time   : 2016-04-07, 18:28, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file main.c
** @version 01.01
** @brief
**         Main module.
**         This module contains user's application code.
*/         
/*!
**  @addtogroup main_module main module documentation
**  @{
*/         
/* MODULE main */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "MyUART.h"
#include "ASerialLdd1.h"
#include "MPL115A2_0.h"
#include "IntI2cLdd1.h"
#include "CZ1.h"
#include "BitIoLdd4.h"
#include "CZ2.h"
#include "BitIoLdd5.h"
#include "CZ3.h"
#include "BitIoLdd1.h"
#include "CZ4.h"
#include "BitIoLdd2.h"
#include "CZ5.h"
#include "BitIoLdd3.h"
#include "CZ6.h"
#include "BitIoLdd6.h"
#include "CZ12.h"
#include "BitIoLdd7.h"
#include "CZ8.h"
#include "BitIoLdd8.h"
#include "CZ9.h"
#include "BitIoLdd9.h"
#include "CZ10.h"
#include "BitIoLdd10.h"
#include "CZ11.h"
#include "BitIoLdd11.h"
#include "CZ7.h"
#include "BitIoLdd12.h"
#include "MPL115A2_1.h"
#include "IntI2cLdd2.h"

/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "MPL115_A2.h"
#include "dodatki.h"

/* User includes (#include below this line is not maintained by Processor Expert) */
bool pusty_bufor;
/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */

	
  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */
  /* For example: for(;;) { } */

  petla();
  
  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END main */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.3 [05.09]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
