/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  MotorDriver.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>
 *
 *********************************************************************************************************************/
#ifndef MOTOR_DRIVER_H
#define MOTOR_DRIVER_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "MotorDriver_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum
{
    STOPPED = 0,
    STARTED
} PWMState_t;

typedef enum
{
    STOP = 0,
    FOREWORD,
    BACKWORD,
    RIGHT,
    LEFT
} MotorDirection_t;
/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#endif /* MOTOR_DRIVER_H */

/**********************************************************************************************************************
 *  END OF FILE: MotorDriver.h
 *********************************************************************************************************************/
