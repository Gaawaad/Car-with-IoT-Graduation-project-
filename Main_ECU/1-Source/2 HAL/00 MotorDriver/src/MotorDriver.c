/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  MotorDriver.c
 *        \brief
 *
 *      \details
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "MotorDriver.h"
/**********************************************************************************************************************
 *  LOCAL MACROS CONSTANT\FUNCTION
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
extern MotorDriver_Cfg_t MotorDriver_Cfg_Arr[];
MotorDirection_t MotorCurrentState = STOP;
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
void MotorDriver_Init(void)
{
    PWM_Init();
    PORT_Init();
    Dio_ConfigChannel(MotorDriver_Cfg_Arr[0].Port1, MotorDriver_Cfg_Arr[0].pin1,
                      OUTPUT);
    Dio_ConfigChannel(MotorDriver_Cfg_Arr[0].Port2, MotorDriver_Cfg_Arr[0].pin2,
                      OUTPUT);
    Dio_ConfigChannel(MotorDriver_Cfg_Arr[1].Port1, MotorDriver_Cfg_Arr[1].pin1,
                      OUTPUT);
    Dio_ConfigChannel(MotorDriver_Cfg_Arr[1].Port2, MotorDriver_Cfg_Arr[1].pin2,
                      OUTPUT);
    PWM_Set_Frequency(MotorDriver_Cfg_Arr[0].PWMChannel,
                      MotorDriver_Cfg_Arr[0].frequncy);
    PWM_Set_Frequency(MotorDriver_Cfg_Arr[1].PWMChannel,
                      MotorDriver_Cfg_Arr[0].frequncy);
}

void MotorDriver_Move(MotorDirection_t Direction)
{

    switch (Direction)
    {
    case STOP:
        Dio_WriteChannel(MotorDriver_Cfg_Arr[0].Port1,
                         MotorDriver_Cfg_Arr[0].pin1, LOW);
        Dio_WriteChannel(MotorDriver_Cfg_Arr[0].Port2,
                         MotorDriver_Cfg_Arr[0].pin2, LOW);
        Dio_WriteChannel(MotorDriver_Cfg_Arr[1].Port1,
                         MotorDriver_Cfg_Arr[1].pin1, LOW);
        Dio_WriteChannel(MotorDriver_Cfg_Arr[1].Port2,
                         MotorDriver_Cfg_Arr[1].pin2, LOW);
        break;

    case FOREWORD:
        Dio_WriteChannel(MotorDriver_Cfg_Arr[0].Port1,
                         MotorDriver_Cfg_Arr[0].pin1, HIGH);
        Dio_WriteChannel(MotorDriver_Cfg_Arr[0].Port2,
                         MotorDriver_Cfg_Arr[0].pin2, LOW);
        Dio_WriteChannel(MotorDriver_Cfg_Arr[1].Port1,
                         MotorDriver_Cfg_Arr[1].pin1, HIGH);
        Dio_WriteChannel(MotorDriver_Cfg_Arr[1].Port2,
                         MotorDriver_Cfg_Arr[1].pin2, LOW);
        break;

    case BACKWORD:
        Dio_WriteChannel(MotorDriver_Cfg_Arr[0].Port1,
                         MotorDriver_Cfg_Arr[0].pin1, LOW);
        Dio_WriteChannel(MotorDriver_Cfg_Arr[0].Port2,
                         MotorDriver_Cfg_Arr[0].pin2, HIGH);
        Dio_WriteChannel(MotorDriver_Cfg_Arr[1].Port1,
                         MotorDriver_Cfg_Arr[1].pin1, LOW);
        Dio_WriteChannel(MotorDriver_Cfg_Arr[1].Port2,
                         MotorDriver_Cfg_Arr[1].pin2, HIGH);
        break;

    case RIGHT:
        Dio_WriteChannel(MotorDriver_Cfg_Arr[0].Port1,
                         MotorDriver_Cfg_Arr[0].pin1, HIGH);
        Dio_WriteChannel(MotorDriver_Cfg_Arr[0].Port2,
                         MotorDriver_Cfg_Arr[0].pin2, LOW);
        Dio_WriteChannel(MotorDriver_Cfg_Arr[1].Port1,
                         MotorDriver_Cfg_Arr[1].pin1, LOW);
        Dio_WriteChannel(MotorDriver_Cfg_Arr[1].Port2,
                         MotorDriver_Cfg_Arr[1].pin2, HIGH);
        break;

    case LEFT:
        Dio_WriteChannel(MotorDriver_Cfg_Arr[0].Port1,
                         MotorDriver_Cfg_Arr[0].pin1, LOW);
        Dio_WriteChannel(MotorDriver_Cfg_Arr[0].Port2,
                         MotorDriver_Cfg_Arr[0].pin2, HIGH);
        Dio_WriteChannel(MotorDriver_Cfg_Arr[1].Port1,
                         MotorDriver_Cfg_Arr[1].pin1, HIGH);
        Dio_WriteChannel(MotorDriver_Cfg_Arr[1].Port2,
                         MotorDriver_Cfg_Arr[1].pin2, LOW);
        break;

    default:
        Dio_WriteChannel(MotorDriver_Cfg_Arr[0].Port1,
                         MotorDriver_Cfg_Arr[0].pin1, LOW);
        Dio_WriteChannel(MotorDriver_Cfg_Arr[0].Port2,
                         MotorDriver_Cfg_Arr[0].pin2, LOW);
        Dio_WriteChannel(MotorDriver_Cfg_Arr[1].Port1,
                         MotorDriver_Cfg_Arr[1].pin1, LOW);
        Dio_WriteChannel(MotorDriver_Cfg_Arr[1].Port2,
                         MotorDriver_Cfg_Arr[1].pin2, LOW);
        break;
    }
    MotorCurrentState = Direction;
}
void MotoDriver_Speed(u8 Speed)
{
    if (Speed < 100 && Speed > 0)
    {
        PWM_Set_Duty(MotorDriver_Cfg_Arr[0].PWMChannel, Speed);
        PWM_Set_Duty(MotorDriver_Cfg_Arr[1].PWMChannel, Speed);
    }
    else
    {
        PWM_Set_Duty(MotorDriver_Cfg_Arr[0].PWMChannel, 99);
        PWM_Set_Duty(MotorDriver_Cfg_Arr[1].PWMChannel, 99);
    }
}

void MotorDriver_LeftSpeed(u8 Speed)
{
    if (Speed < 100 && Speed > 0)
    {
        PWM_Set_Duty(MotorDriver_Cfg_Arr[0].PWMChannel, Speed);

    }
    else
    {
        PWM_Set_Duty(MotorDriver_Cfg_Arr[0].PWMChannel, 99);

    }
}

void MotorDriver_RightSpeed(u8 Speed)
{
    if (Speed < 100 && Speed > 0)
    {

        PWM_Set_Duty(MotorDriver_Cfg_Arr[1].PWMChannel, Speed);
    }
    else
    {

        PWM_Set_Duty(MotorDriver_Cfg_Arr[1].PWMChannel, 99);
    }
}

/**********************************************************************************************************************
 *  END OF FILE: MotorDriver.c
 *********************************************************************************************************************/
