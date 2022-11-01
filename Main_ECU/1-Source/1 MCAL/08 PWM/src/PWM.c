/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  PWM.c
 *        \brief
 *
 *      \details
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "PWM.h"
#include "Mc_Hw_Reg.h"
#include "Std_types.h"
/**********************************************************************************************************************
 *  LOCAL MACROS CONSTANT\FUNCTION
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
extern PWM_Cfg_t PWM_Cfg_ARR[];
extern PWM_GEN_Cfg_t PWM_GEN_Cfg_Arr[];
extern PWM_Channel_Cfg_t PWM_Channel_Cfg_Arr[];
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
volatile u32 *PWMnCTL_Mn_Arr[] = { &PWM0CTL_M0_Reg, &PWM1CTL_M0_Reg,
                                   &PWM2CTL_M0_Reg, &PWM3CTL_M0_Reg,
                                   &PWM0CTL_M1_Reg, &PWM1CTL_M1_Reg,
                                   &PWM2CTL_M1_Reg, &PWM3CTL_M1_Reg };

volatile u32 *PWMnLOAD_Mn_Arr[] = { &PWM0LOAD_M0_Reg, &PWM1LOAD_M0_Reg,
                                    &PWM2LOAD_M0_Reg, &PWM3LOAD_M0_Reg,
                                    &PWM0LOAD_M1_Reg, &PWM1LOAD_M1_Reg,
                                    &PWM2LOAD_M1_Reg, &PWM3LOAD_M1_Reg };

volatile u32 *PWMnCMPA_Mn_Arr[] = { &PWM0CMPA_M0_Reg, &PWM1CMPA_M0_Reg,
                                    &PWM2CMPA_M0_Reg, &PWM3CMPA_M0_Reg,
                                    &PWM0CMPA_M1_Reg, &PWM1CMPA_M1_Reg,
                                    &PWM2CMPA_M1_Reg, &PWM3CMPA_M1_Reg };

volatile u32 *PWMnGENA_Mn_Arr[] = { &PWM0GENA_M0_Reg, &PWM1GENA_M0_Reg,
                                    &PWM2GENA_M0_Reg, &PWM3GENA_M0_Reg,
                                    &PWM0GENA_M1_Reg, &PWM1GENA_M1_Reg,
                                    &PWM2GENA_M1_Reg, &PWM3GENA_M1_Reg };

void PWM_Init(void)
{
    u8 counter;
    f64 Totaltime;
    u32 PreLoadValue;
    u32 DutyCycle;
    for (counter = 0; counter <= 1; counter++)
    {
        if (PWM_Cfg_ARR[counter].EN == PWM_Enable)
        {
            RCGCPWM_Reg |= (1 << counter);
        }
        else
        {
            RCGCPWM_Reg &= ~(1 << counter);
        }

        if (PWM_Cfg_ARR[counter].clockSurce == CLOCK_DIVIDER)
        {
            RCC_Reg |= (1 << 20);
        }
        else
        {
            RCC_Reg &= ~(1 << 20);
        }
    }

    for (counter = 0; counter <= 7; counter++)
    {
        *PWMnCTL_Mn_Arr[counter] &= ~(1 << 0); // disable the generator first

        if (PWM_GEN_Cfg_Arr[counter].countMode == UP_COUNT) // count mode
        {
            *PWMnCTL_Mn_Arr[counter] |= (1 << 1);
        }
        else
        {
            *PWMnCTL_Mn_Arr[counter] &= ~(1 << 1);
        }

        Totaltime = (1.0) / (PWM_GEN_Cfg_Arr[counter].Frequency);
        PreLoadValue = (f32) Totaltime / (0.0000000625);
        DutyCycle = PreLoadValue
                * (f32) ((100 - PWM_GEN_Cfg_Arr[counter].DutyCycle) / 100.0);
        *PWMnLOAD_Mn_Arr[counter] |= PreLoadValue;
        *PWMnCMPA_Mn_Arr[counter] |= DutyCycle;
        *PWMnGENA_Mn_Arr[counter] = (3 << 2) | (2 << 6);

        if (PWM_GEN_Cfg_Arr[counter].EN == PWM_Enable) // En / disEn
        {
            *PWMnCTL_Mn_Arr[counter] |= (1 << 0);
        }
        else
        {
            *PWMnCTL_Mn_Arr[counter] &= ~(1 << 0);
        }
    }

    for (counter = 0; counter <= 15; counter++)
    {
        if (counter < 8)
        {
            if (PWM_Channel_Cfg_Arr[counter].EN == PWM_Enable)
            {
                PWMENABLE_M0_Reg |= (1 << counter);
            }
            else
            {
                PWMENABLE_M0_Reg &= ~(1 << counter);
            }
        }
        else
        {
            if (PWM_Channel_Cfg_Arr[counter].EN == PWM_Enable)
            {
                PWMENABLE_M1_Reg |= (1 << (counter - 8));
            }
            else
            {
                PWMENABLE_M1_Reg &= ~(1 << (counter - 8));
            }
        }
    }
}

void PWM_Start(PWM_Channel_t Channel)
{
    *PWMnCTL_Mn_Arr[(u8) (Channel / 2)] |= (1 << 0);
    if (Channel < 8)
    {
        PWMENABLE_M0_Reg |= (1 << Channel);
    }
    else
    {
        PWMENABLE_M1_Reg |= (1 << Channel - 8);
    }
}

void PWM_Stop(PWM_Channel_t Channel)
{
    *PWMnCTL_Mn_Arr[(u8) (Channel / 2)] &= ~(1 << 0);
    if (Channel < 8)
    {
        PWMENABLE_M0_Reg &= ~(1 << Channel);
    }
    else
    {
        PWMENABLE_M1_Reg &= ~(1 << Channel - 8);
    }
}

void PWM_SET_Frequency_Duty(PWM_Channel_t Channel, u32 frequency, u8 DutyCycle)
{
    if (DutyCycle == 0)
    {
        PWM_Stop(Channel);
    }
    else
    {
        f64 Totaltime;
        u32 PreLoadValue;
        u32 Duty_Cycle;
        DutyCycle = 100 - DutyCycle;
        PWM_GEN_Cfg_Arr[(u8) (Channel / 2)].DutyCycle = DutyCycle;
        PWM_GEN_Cfg_Arr[(u8) (Channel / 2)].Frequency = frequency;
        Totaltime = (1.0) / (frequency);
        PreLoadValue = (f64) Totaltime / (0.0000000625);
        Duty_Cycle = PreLoadValue * (f32) (DutyCycle / 100.0);
        *PWMnLOAD_Mn_Arr[(u8) (Channel / 2)] = (*PWMnLOAD_Mn_Arr[(u8) (Channel
                / 2)] & ~0xFFFF) | PreLoadValue;
        *PWMnCMPA_Mn_Arr[(u8) (Channel / 2)] = (*PWMnCMPA_Mn_Arr[(u8) (Channel
                / 2)] & ~0xFFFF) | Duty_Cycle;
    }
}
void PWM_Set_Duty(PWM_Channel_t Channel, u8 DutyCycle)
{
    if (DutyCycle == 0)
    {
        PWM_Stop(Channel);
    }
    else
    {
        PWM_Stop(Channel);
        f64 Totaltime;
        u32 PreLoadValue;
        u32 Duty_Cycle;
        DutyCycle = 100 - DutyCycle;
        PWM_GEN_Cfg_Arr[(u8) (Channel / 2)].DutyCycle = DutyCycle;
        Totaltime = (1.0) / (PWM_GEN_Cfg_Arr[(u8) (Channel / 2)].Frequency);
        PreLoadValue = (f64) Totaltime / (0.0000000625);
        Duty_Cycle = PreLoadValue * (f32) (DutyCycle / 100.0);
        *PWMnCMPA_Mn_Arr[(u8) (Channel / 2)] = (*PWMnCMPA_Mn_Arr[(u8) (Channel
                / 2)] & ~0xFFFF) | Duty_Cycle;
        PWM_Start(Channel);
    }
}
void PWM_Set_Frequency(PWM_Channel_t Channel, u32 frequency)
{
    f64 Totaltime;
    u32 PreLoadValue;
    PWM_GEN_Cfg_Arr[(u8) (Channel / 2)].Frequency = frequency;
    Totaltime = (1.0) / (frequency);
    PreLoadValue = (f64) Totaltime / (0.0000000625);
    *PWMnLOAD_Mn_Arr[(u8) (Channel / 2)] = (*PWMnLOAD_Mn_Arr[(u8) (Channel / 2)]
            & ~0xFFFF) | PreLoadValue;
}
/**********************************************************************************************************************
 *  END OF FILE: PWM.c
 *********************************************************************************************************************/
