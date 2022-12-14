/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  PWM_Cfg.c
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
/**********************************************************************************************************************
 *  LOCAL MACROS CONSTANT\FUNCTION
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

PWM_Cfg_t PWM_Cfg_ARR[] = {
    {PWM_M0, PWM_Enable, SYS_CLOCK},
    {PWM_M1, PWM_Enable, SYS_CLOCK},
};

PWM_GEN_Cfg_t PWM_GEN_Cfg_Arr[] = {
    {PWM_M0, PWM_G0, DOWN_COUNT, 300, 100, PWM_Enable},
    {PWM_M0, PWM_G1, DOWN_COUNT, 1000, 50, PWM_Disable},
    {PWM_M0, PWM_G2, DOWN_COUNT, 500, 50, PWM_Disable},
    {PWM_M0, PWM_G3, DOWN_COUNT, 2000, 50, PWM_Disable},

    {PWM_M1, PWM_G0, DOWN_COUNT, 5000, 50, PWM_Disable},
    {PWM_M1, PWM_G1, DOWN_COUNT, 5000, 50, PWM_Disable},
    {PWM_M1, PWM_G2, DOWN_COUNT, 1000, 50, PWM_Disable},
    {PWM_M1, PWM_G3, DOWN_COUNT, 400, 50, PWM_Disable},
};

PWM_Channel_Cfg_t PWM_Channel_Cfg_Arr[] = {
    {M0PWM0, PWM_Enable},
    {M0PWM1, PWM_Disable},
    {M0PWM2, PWM_Disable},
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
    {M1PWM7, PWM_Enable},

};
/**********************************************************************************************************************
 *  END OF FILE: PWM_Cfg.c
 *********************************************************************************************************************/
