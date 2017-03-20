/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : CZ12.c
**     Project     : mpl_v4
**     Processor   : MK40DN512VLK10
**     Component   : BitIO
**     Version     : Component 02.086, Driver 01.00, CPU db: 3.00.000
**     Compiler    : CodeWarrior ARM C Compiler
**     Date/Time   : 2016-11-03, 20:41, # CodeGen: 0
**     Abstract    :
**         This component "BitIO" implements an one-bit input/output.
**         It uses one bit/pin of a port.
**         Note: This component is set to work in Output direction only.
**         Methods of this component are mostly implemented as a macros
**         (if supported by target language and compiler).
**     Settings    :
**         Used pin                    :
**             ----------------------------------------------------
**                Number (on package)  |    Name
**             ----------------------------------------------------
**                       5             |  PTE4/LLWU_P2/SPI1_PCS0/UART3_TX/SDHC0_D3
**             ----------------------------------------------------
**
**         Port name                   : PTE
**
**         Bit number (in port)        : 4
**         Bit mask of the port        : 0x0010
**
**         Initial direction           : Output (direction cannot be changed)
**         Initial output value        : 0
**         Initial pull option         : off
**
**         Port data register          : GPIOE_PDOR [0x400FF100]
**         Port control register       : GPIOE_PDDR [0x400FF114]
**
**         Optimization for            : speed
**     Contents    :
**         SetInput  - void CZ12_SetInput(void);
**         SetOutput - void CZ12_SetOutput(void);
**         GetVal    - bool CZ12_GetVal(void);
**         PutVal    - void CZ12_PutVal(bool Val);
**         NegVal    - void CZ12_NegVal(void);
**
**     Copyright : 1997 - 2014 Freescale Semiconductor, Inc. 
**     All Rights Reserved.
**     
**     Redistribution and use in source and binary forms, with or without modification,
**     are permitted provided that the following conditions are met:
**     
**     o Redistributions of source code must retain the above copyright notice, this list
**       of conditions and the following disclaimer.
**     
**     o Redistributions in binary form must reproduce the above copyright notice, this
**       list of conditions and the following disclaimer in the documentation and/or
**       other materials provided with the distribution.
**     
**     o Neither the name of Freescale Semiconductor, Inc. nor the names of its
**       contributors may be used to endorse or promote products derived from this
**       software without specific prior written permission.
**     
**     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**     
**     http: www.freescale.com
**     mail: support@freescale.com
** ###################################################################*/
/*!
** @file CZ12.c
** @version 01.00
** @brief
**         This component "BitIO" implements an one-bit input/output.
**         It uses one bit/pin of a port.
**         Note: This component is set to work in Output direction only.
**         Methods of this component are mostly implemented as a macros
**         (if supported by target language and compiler).
*/         
/*!
**  @addtogroup CZ12_module CZ12 module documentation
**  @{
*/         

/* MODULE CZ12. */

#include "CZ12.h"

#ifdef __cplusplus
extern "C" {
#endif 

/*
** ===================================================================
**     Method      :  CZ12_SetInput (component BitIO)
**     Description :
**         This method sets direction of the component to input.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void CZ12_SetInput(void)

**  This method is implemented as a macro. See CZ12.h file.  **
*/

/*
** ===================================================================
**     Method      :  CZ12_SetOutput (component BitIO)
**     Description :
**         This method sets direction of the component to output.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void CZ12_SetOutput(void)

**  This method is implemented as a macro. See CZ12.h file.  **
*/

/*
** ===================================================================
**     Method      :  CZ12_GetVal (component BitIO)
**     Description :
**         This method returns an input value.
**           a) direction = Input  : reads the input value from the
**                                   pin and returns it
**           b) direction = Output : returns the last written value
**         Note: This component is set to work in Output direction only.
**     Parameters  : None
**     Returns     :
**         ---             - Input value. Possible values:
**                           FALSE - logical "0" (Low level)
**                           TRUE - logical "1" (High level)

** ===================================================================
*/
/*
bool CZ12_GetVal(void)

**  This method is implemented as a macro. See CZ12.h file.  **
*/

/*
** ===================================================================
**     Method      :  CZ12_PutVal (component BitIO)
**     Description :
**         This method writes the new output value.
**     Parameters  :
**         NAME       - DESCRIPTION
**         Val             - Output value. Possible values:
**                           FALSE - logical "0" (Low level)
**                           TRUE - logical "1" (High level)
**     Returns     : Nothing
** ===================================================================
*/
/*
void CZ12_PutVal(bool Val)

**  This method is implemented as a macro. See CZ12.h file.  **
*/

/*
** ===================================================================
**     Method      :  CZ12_NegVal (component BitIO)
**     Description :
**         This method negates (inverts) the output value.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void CZ12_NegVal(void)

**  This method is implemented as a macro. See CZ12.h file.  **
*/

/* END CZ12. */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

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
