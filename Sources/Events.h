/* ###################################################################
**     Filename    : Events.h
**     Project     : mpl
**     Processor   : MK40DN512VLK10
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : CodeWarrior ARM C Compiler
**     Date/Time   : 2016-04-07, 18:28, # CodeGen: 0
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Settings    :
**     Contents    :
**         Cpu_OnNMIINT - void Cpu_OnNMIINT(void);
**
** ###################################################################*/
/*!
** @file Events.h
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup Events_module Events module documentation
**  @{
*/         

#ifndef __Events_H
#define __Events_H
/* MODULE Events */

#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
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
#include "WAIT1.h"
#include "KSDK1.h"
#include "WAIT2.h"

#ifdef __cplusplus
extern "C" {
#endif 

/*
** ===================================================================
**     Event       :  Cpu_OnNMIINT (module Events)
**
**     Component   :  Cpu [MK40DN512LQ10]
*/
/*!
**     @brief
**         This event is called when the Non maskable interrupt had
**         occurred. This event is automatically enabled when the [NMI
**         interrupt] property is set to 'Enabled'.
*/
/* ===================================================================*/
void Cpu_OnNMIINT(void);


/*
** ===================================================================
**     Event       :  MyClock_OnInterrupt (module Events)
**
**     Component   :  MyClock [TimerInt]
**     Description :
**         When a timer interrupt occurs this event is called (only
**         when the component is enabled - <Enable> and the events are
**         enabled - <EnableEvent>). This event is enabled only if a
**         <interrupt service/event> is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void MyClock_OnInterrupt(void);

/*
** ===================================================================
**     Event       :  MyUART_OnError (module Events)
**
**     Component   :  MyUART [AsynchroSerial]
**     Description :
**         This event is called when a channel error (not the error
**         returned by a given method) occurs. The errors can be read
**         using <GetError> method.
**         The event is available only when the <Interrupt
**         service/event> property is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void MyUART_OnError(void);

/*
** ===================================================================
**     Event       :  MyUART_OnTxChar (module Events)
**
**     Component   :  MyUART [AsynchroSerial]
**     Description :
**         This event is called after a character is transmitted.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void MyUART_OnTxChar(void);

/*
** ===================================================================
**     Event       :  MyUART_OnFreeTxBuf (module Events)
**
**     Component   :  MyUART [AsynchroSerial]
**     Description :
**         This event is called after the last character in output
**         buffer is transmitted.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void MyUART_OnFreeTxBuf(void);

/*
** ===================================================================
**     Event       :  MyUART_OnRxChar (module Events)
**
**     Component   :  MyUART [AsynchroSerial]
**     Description :
**         This event is called after a correct character is received.
**         The event is available only when the <Interrupt
**         service/event> property is enabled and either the <Receiver>
**         property is enabled or the <SCI output mode> property (if
**         supported) is set to Single-wire mode.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void MyUART_OnRxChar(void);

/*
** ===================================================================
**     Event       :  MyUART_OnFullRxBuf (module Events)
**
**     Component   :  MyUART [AsynchroSerial]
**     Description :
**         This event is called when the input buffer is full;
**         i.e. after reception of the last character 
**         that was successfully placed into input buffer.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void MyUART_OnFullRxBuf(void);

/* END Events */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

#endif 
/* ifndef __Events_H*/
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
