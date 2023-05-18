/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  FileName.c
 *        \brief
 *
 *      \details
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "IntCtr_Lcfg.h"

/**********************************************************************************************************************
 *  LOCAL MACROS CONSTANT\FUNCTION
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
ExceptionCtr_t FaultsCfg_Arr[] = {
    {Memory_Management_Fault, 0, 0},
    {Bus_Fault, 0, 0},
    {Usage_Fault, 0, 0},
    {SVCall, 0, 0},
    {Debug, 0, 0},
    {PendSV, 0, 0},
    {SysTick_Exception, 0, 0}

};

IntCtrCfg_t IntCfg_Arr[] = {
    {_INT0, 0, 0, _ENABLE},     //GPIO Port A
    {_INT1, 0, 0, _DISABLE},    //GPIO Port B
    {_INT2, 0, 0, _ENABLE},     //GPIO Port C
    {_INT3, 0, 0, _DISABLE},    //GPIO Port D
    {_INT4, 0, 0, _DISABLE},    //GPIO Port E
    {_INT5, 0, 0, _ENABLE},
    {_INT6, 0, 0, _ENABLE},
    {_INT7, 0, 0, _DISABLE},
    {_INT8, 0, 0, _DISABLE},
    {_INT9, 0, 0, _DISABLE},
    {_INT10, 0, 0, _DISABLE},
    {_INT11, 0, 0, _DISABLE},
    {_INT12, 0, 0, _DISABLE},
    {_INT13, 0, 0, _DISABLE},
    {_INT14, 0, 0, _DISABLE},
    {_INT15, 0, 0, _DISABLE},
    {_INT16, 0, 0, _DISABLE},
    {_INT17, 0, 0, _DISABLE},
    {_INT18, 0, 0, _DISABLE},
    {_INT19, 0, 0, _ENABLE},  //timer 0A
    {_INT20, 0, 0, _ENABLE},  //timer 0B
    {_INT21, 0, 0, _ENABLE},  //timer 1A
    {_INT22, 0, 0, _ENABLE},  //timer 1B
    {_INT23, 0, 0, _ENABLE},  //timer 2A
    {_INT24, 0, 0, _ENABLE},  //timer 2B
    {_INT25, 0, 0, _DISABLE},
    {_INT26, 0, 0, _DISABLE},
    {NONE, 0, 0, _RESERVED_INT},
    {_INT28, 0, 0, _DISABLE},
    {_INT29, 0, 0, _DISABLE},
    {_INT30, 0, 0, _ENABLE},    //GPIO Port F
    {NONE, 0, 0, _RESERVED_INT},
    {NONE, 0, 0, _RESERVED_INT},
    {_INT33, 0, 0, _DISABLE},
    {_INT34, 0, 0, _DISABLE},
    {_INT35, 0, 0, _ENABLE},  //timer 3A
    {_INT36, 0, 0, _ENABLE},  //timer 3B
    {_INT37, 0, 0, _DISABLE},
    {_INT38, 0, 0, _DISABLE},
    {_INT39, 0, 0, _DISABLE},
    {_INT40, 0, 0, _DISABLE},
    {NONE, 0, 0, _RESERVED_INT},
    {NONE, 0, 0, _RESERVED_INT},
    {_INT43, 0, 0, _DISABLE},
    {_INT44, 0, 0, _DISABLE},
    {_INT45, 0, 0, _DISABLE},
    {_INT46, 0, 0, _DISABLE},
    {_INT47, 0, 0, _DISABLE},
    {_INT48, 0, 0, _DISABLE},
    {_INT49, 0, 0, _DISABLE},
    {_INT50, 0, 0, _DISABLE},
    {_INT51, 0, 0, _DISABLE},
    {_INT57, 0, 0, _DISABLE},
    {NONE, 0, 0, _RESERVED_INT},
    {NONE, 0, 0, _RESERVED_INT},
    {NONE, 0, 0, _RESERVED_INT},
    {NONE, 0, 0, _RESERVED_INT},
    {NONE, 0, 0, _RESERVED_INT},
    {_INT58, 0, 0, _DISABLE},
    {_INT59, 0, 0, _DISABLE},
    {_INT60, 0, 0, _DISABLE},
    {_INT61, 0, 0, _DISABLE},
    {_INT62, 0, 0, _DISABLE},
    {_INT63, 0, 0, _DISABLE},
    {NONE, 0, 0, _RESERVED_INT},
    {NONE, 0, 0, _RESERVED_INT},
    {NONE, 0, 0, _RESERVED_INT},
    {NONE, 0, 0, _RESERVED_INT},
    {_INT68, 0, 0, _DISABLE},
    {_INT69, 0, 0, _DISABLE},
    {_INT70, 0, 0, _ENABLE},   //timer 4A
    {_INT71, 0, 0, _ENABLE},   //timer 4B
    {NONE, 0, 0, _RESERVED_INT},
    {NONE, 0, 0, _RESERVED_INT},
    {NONE, 0, 0, _RESERVED_INT},
    {NONE, 0, 0, _RESERVED_INT},
    {NONE, 0, 0, _RESERVED_INT},
    {NONE, 0, 0, _RESERVED_INT},
    {NONE, 0, 0, _RESERVED_INT},
    {NONE, 0, 0, _RESERVED_INT},
    {NONE, 0, 0, _RESERVED_INT},
    {NONE, 0, 0, _RESERVED_INT},
    {NONE, 0, 0, _RESERVED_INT},
    {NONE, 0, 0, _RESERVED_INT},
    {NONE, 0, 0, _RESERVED_INT},
    {NONE, 0, 0, _RESERVED_INT},
    {NONE, 0, 0, _RESERVED_INT},
    {NONE, 0, 0, _RESERVED_INT},
    {NONE, 0, 0, _RESERVED_INT},
    {NONE, 0, 0, _RESERVED_INT},
    {NONE, 0, 0, _RESERVED_INT},
    {NONE, 0, 0, _RESERVED_INT},
    {_INT92, 0, 0, _ENABLE},   //timer 5A
    {_INT93, 0, 0, _ENABLE},   //timer 5B
    {_INT94, 0, 0, _DISABLE},
    {_INT95, 0, 0, _DISABLE},
    {_INT96, 0, 0, _DISABLE},
    {_INT97, 0, 0, _DISABLE},
    {_INT98, 0, 0, _DISABLE},
    {_INT99, 0, 0, _DISABLE},
    {_INT100, 0, 0, _DISABLE},
    {_INT101, 0, 0, _DISABLE},
    {_INT102, 0, 0, _DISABLE},
    {_INT103, 0, 0, _DISABLE},
    {_INT104, 0, 0, _DISABLE},
    {_INT105, 0, 0, _DISABLE},
    {_INT106, 0, 0, _DISABLE},
    {NONE, 0, 0, _RESERVED_INT},
    {NONE, 0, 0, _RESERVED_INT},
    {NONE, 0, 0, _RESERVED_INT},
    {NONE, 0, 0, _RESERVED_INT},
    {NONE, 0, 0, _RESERVED_INT},
    {NONE, 0, 0, _RESERVED_INT},
    {NONE, 0, 0, _RESERVED_INT},
    {NONE, 0, 0, _RESERVED_INT},
    {NONE, 0, 0, _RESERVED_INT},
    {NONE, 0, 0, _RESERVED_INT},
    {NONE, 0, 0, _RESERVED_INT},
    {NONE, 0, 0, _RESERVED_INT},
    {NONE, 0, 0, _RESERVED_INT},
    {NONE, 0, 0, _RESERVED_INT},
    {NONE, 0, 0, _RESERVED_INT},
    {NONE, 0, 0, _RESERVED_INT},
    {NONE, 0, 0, _RESERVED_INT},
    {NONE, 0, 0, _RESERVED_INT},
    {NONE, 0, 0, _RESERVED_INT},
    {NONE, 0, 0, _RESERVED_INT},
    {NONE, 0, 0, _RESERVED_INT},
    {NONE, 0, 0, _RESERVED_INT},
    {NONE, 0, 0, _RESERVED_INT},
    {NONE, 0, 0, _RESERVED_INT},
    {NONE, 0, 0, _RESERVED_INT},
    {NONE, 0, 0, _RESERVED_INT},
    {NONE, 0, 0, _RESERVED_INT},
    {_INT134, 0, 0, _DISABLE},
    {_INT135, 0, 0, _DISABLE},
    {_INT136, 0, 0, _DISABLE},
    {_INT137, 0, 0, _DISABLE},
    {_INT138, 0, 0, _DISABLE},
};
/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/******************************************************************************
 * \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)
 * \Description     : Describe this service
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : parameterName   Parameter Describtion
 * \Parameters (out): None
 * \Return value:   : Std_ReturnType  E_OK
 *                                    E_NOT_OK
 *******************************************************************************/

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
