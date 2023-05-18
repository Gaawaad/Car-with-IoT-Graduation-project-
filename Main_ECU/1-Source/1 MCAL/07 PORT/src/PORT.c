/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  PORT.c
 *        \brief  Configure all pins of the MicroController
 *      \details  Contains:
 *                  1-LOCAL DATA
 *                       GPIODIR_Arr[]          Array
 *                       GPIODATA_Arr[]         Array
 *                       GPIOPDR_Arr[]          Array
 *                       GPIOPUR_Arr[]          Array
 *                       GPIOODR_Arr[]          Array
 *                       GPIODEN_Arr[]          Array
 *                       GPIOAFSEL_Arr[]        Array
 *                       GPIOPCTL_Arr[]         Array
 *                  2-GLOBAL DATA
 *                       PORT_Cfg_Arr[]         Array(extern)
 *                  3-GLOBAL FUNCTIONS
 *                       void PORT_Init(void)
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "PORT.h"

/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/
volatile u32 *GPIODIR_Arr[] = { &GPIODIR_A_Reg, &GPIODIR_B_Reg, &GPIODIR_C_Reg,
                                &GPIODIR_D_Reg, &GPIODIR_E_Reg, &GPIODIR_F_Reg };
volatile u32 *GPIODATA_Arr[] = { &GPIODATA_A_Reg, &GPIODATA_B_Reg,
                                 &GPIODATA_C_Reg, &GPIODATA_D_Reg,
                                 &GPIODATA_E_Reg, &GPIODATA_F_Reg };
volatile u32 *GPIOPDR_Arr[] = { &GPIOPDR_A_Reg, &GPIOPDR_B_Reg, &GPIOPDR_C_Reg,
                                &GPIOPDR_D_Reg, &GPIOPDR_E_Reg, &GPIOPDR_F_Reg };
volatile u32 *GPIOPUR_Arr[] = { &GPIOPUR_A_Reg, &GPIOPUR_B_Reg, &GPIOPUR_C_Reg,
                                &GPIOPUR_D_Reg, &GPIOPUR_E_Reg, &GPIOPUR_F_Reg };
volatile u32 *GPIOODR_Arr[] = { &GPIOODR_A_Reg, &GPIOODR_B_Reg, &GPIOODR_C_Reg,
                                &GPIOODR_D_Reg, &GPIOODR_E_Reg, &GPIOODR_F_Reg };
volatile u32 *GPIODEN_Arr[] = { &GPIODEN_A_Reg, &GPIODEN_B_Reg, &GPIODEN_C_Reg,
                                &GPIODEN_D_Reg, &GPIODEN_E_Reg, &GPIODEN_F_Reg };
volatile u32 *GPIOAFSEL_Arr[] = { &GPIOAFSEL_A_Reg, &GPIOAFSEL_B_Reg,
                                  &GPIOAFSEL_C_Reg, &GPIOAFSEL_D_Reg,
                                  &GPIOAFSEL_E_Reg, &GPIOAFSEL_F_Reg };
volatile u32 *GPIOPCTL_Arr[] = { &GPIOPCTL_A_Reg, &GPIOPCTL_B_Reg,
                                 &GPIOPCTL_C_Reg, &GPIOPCTL_D_Reg,
                                 &GPIOPCTL_E_Reg, &GPIOPCTL_F_Reg };
/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
extern PORT_Cfg_t PORT_Cfg_Arr[];

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/******************************************************************************
* \Syntax          : void PORT_Init(void);
* \Description     : The PORT_Init() function is defined, which iterates
*                    through all the elements of "PORT_Cfg_Arr" and performs the configuration
*                    for each pin based on the parameters in the array. The function sets the
*                    digital enable bit for the pin and sets up the pin for alternate function
*                    if required. It sets the direction of the pin as output or input and sets
*                    the level of the pin as high or low. Additionally, the function configures
*                    the pin for pull-up, pull-down, or open-drain connection.
*
* \Sync\Async      : Asynchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : None
* \Parameters (out): None
* \Return value:   : None
*/

void PORT_Init(void)
{
    u8 count1;
    for (count1 = 0; count1 <= 44; count1++)
    {

        if (PORT_Cfg_Arr[count1].DigEn == DIGITAL_ENABLE)
        {
            *GPIODEN_Arr[PORT_Cfg_Arr[count1].Port] |= (1
                    << PORT_Cfg_Arr[count1].Pin);

            if ((PORT_Cfg_Arr[count1].Altrnate_pin)
                    == ALTERNATE_ENABLE)
            {
                *GPIOAFSEL_Arr[PORT_Cfg_Arr[count1].Port] |= (1
                        << PORT_Cfg_Arr[count1].Pin);
                *GPIOPCTL_Arr[PORT_Cfg_Arr[count1].Port] |=
                        ((PORT_Cfg_Arr[count1].Altrnate_fun)
                                << ((PORT_Cfg_Arr[count1].Pin) * 4));
            }
            else
            {
                *GPIOAFSEL_Arr[PORT_Cfg_Arr[count1].Port] &= ~(1
                        << PORT_Cfg_Arr[count1].Pin);
            }

            if (PORT_Cfg_Arr[count1].Direction == OUTPUT)
            {
                *GPIODIR_Arr[PORT_Cfg_Arr[count1].Port] |= (1
                        << PORT_Cfg_Arr[count1].Pin);

                if (PORT_Cfg_Arr[count1].level == HIGH)
                {
                    *GPIODATA_Arr[PORT_Cfg_Arr[count1].Port] |= (1
                            << PORT_Cfg_Arr[count1].Pin);

                }
                else
                {
                    *GPIODATA_Arr[PORT_Cfg_Arr[count1].Port] &= ~(1
                            << PORT_Cfg_Arr[count1].Pin);
                }

            }
            else
            {
                *GPIODIR_Arr[PORT_Cfg_Arr[count1].Port] &= ~(1
                        << PORT_Cfg_Arr[count1].Pin);
            }

            if (PORT_Cfg_Arr[count1].Connection == POLLUP)
            {
                *GPIOPUR_Arr[PORT_Cfg_Arr[count1].Port] |= (1
                        << PORT_Cfg_Arr[count1].Pin);
            }
            else if (PORT_Cfg_Arr[count1].Connection == POLLDOWN)
            {
                *GPIOPDR_Arr[PORT_Cfg_Arr[count1].Port] |= (1
                        << PORT_Cfg_Arr[count1].Pin);
            }
            else if (PORT_Cfg_Arr[count1].Connection == OPEN_DRAIN)
            {
                *GPIOODR_Arr[PORT_Cfg_Arr[count1].Port] |= (1
                        << PORT_Cfg_Arr[count1].Pin);
            }
            else
            {
                *GPIOPUR_Arr[PORT_Cfg_Arr[count1].Port] &= ~(1
                        << PORT_Cfg_Arr[count1].Pin);
                *GPIOPDR_Arr[PORT_Cfg_Arr[count1].Port] &= ~(1
                        << PORT_Cfg_Arr[count1].Pin);
                *GPIOODR_Arr[PORT_Cfg_Arr[count1].Port] &= ~(1
                        << PORT_Cfg_Arr[count1].Pin);
            }
        }
        else
        {
            *GPIODEN_Arr[PORT_Cfg_Arr[count1].Port] &= ~(1
                    << PORT_Cfg_Arr[count1].Pin);
        }
    }
}
/**********************************************************************************************************************
 *  END OF FILE: PORT.c
 *********************************************************************************************************************/
