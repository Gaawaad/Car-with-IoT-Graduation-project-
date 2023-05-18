/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  PWM_Cfg.c
 *        \brief  The Tiva C microController does indeed have two Pulse Width Modulation (PWM) modules,
 *                each with four PWM generators and each generator having two PWM output channels. Therefore,
 *                in total, the Tiva C microController has eight PWM generators and sixteen PWM output channels.
 *                so we have 3 configuration arrays
 *
 *      \details  Contains:
 *                  PWM_Cfg_ARR[]
 *                  PWM_GEN_Cfg_Arr[]
 *                  PWM_Channel_Cfg_Arr[]
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "PWM.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/*
 * PWM_Cfg_ARR[]: This array is used to configure the PWM modules. Each element of the array contains information about the PWM module,
 *  such as the module number, the enable/disable status, and the clock source.
 * */
PWM_Cfg_t PWM_Cfg_ARR[] = {
    {PWM_M0, PWM_Enable, SYS_CLOCK},
    {PWM_M1, PWM_Enable, SYS_CLOCK},
};
/*
 * PWM_GEN_Cfg_Arr[]: This array is used to configure the PWM generators. Each element of the array contains information about the PWM module,
 *  the generator number, the waveform mode (up-count or down-count), the PWM frequency, the initial duty cycle, and the enable/disable status.
 * */
PWM_GEN_Cfg_t PWM_GEN_Cfg_Arr[] = {
    {PWM_M0, PWM_G0, DOWN_COUNT, 300, 90, PWM_Enable},
    {PWM_M0, PWM_G1, DOWN_COUNT, 300, 90, PWM_Enable},
    {PWM_M0, PWM_G2, DOWN_COUNT, 300, 90, PWM_Disable},
    {PWM_M0, PWM_G3, DOWN_COUNT, 300, 90, PWM_Disable},

    {PWM_M1, PWM_G0, DOWN_COUNT, 300, 90, PWM_Disable},
    {PWM_M1, PWM_G1, DOWN_COUNT, 300, 90, PWM_Disable},
    {PWM_M1, PWM_G2, DOWN_COUNT, 300, 90, PWM_Disable},
    {PWM_M1, PWM_G3, DOWN_COUNT, 300, 90, PWM_Disable},
};
/*
 * PWM_Channel_Cfg_Arr[]: This array is used to configure the PWM output channels.
 * Each element of the array contains information about the output channel,
 *  such as the pin number and the enable/disable status.
 * */
PWM_Channel_Cfg_t PWM_Channel_Cfg_Arr[] = {
    {M0PWM0, PWM_Enable},
    {M0PWM1, PWM_Enable},
    {M0PWM2, PWM_Enable},
    {M0PWM3, PWM_Disable},
    {M0PWM4, PWM_Disable},
    {M0PWM5, PWM_Disable},
    {M0PWM6, PWM_Disable},
    {M0PWM7, PWM_Disable},

    {M1PWM0, PWM_Disable},
    {M1PWM1, PWM_Disable},
    {M1PWM2, PWM_Disable},
    {M1PWM3, PWM_Disable},
    {M1PWM4, PWM_Disable},
    {M1PWM5, PWM_Disable},
    {M1PWM6, PWM_Disable},
    {M1PWM7, PWM_Disable},

};
/**********************************************************************************************************************
 *  END OF FILE: PWM_Cfg.c
 *********************************************************************************************************************/
