/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  GPIO_Cfg.c
 *        \brief
 *
 *      \details
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "GPIO_Cfg.h"

/**********************************************************************************************************************
 *  LOCAL MACROS CONSTANT\FUNCTION
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

PORT_INT_Cfg_t InterruptCfg_Arr[] = {
    {PORTA, PORT_Pin0, INT_ENABLE, _ANY_EDGE},
    {PORTA, PORT_Pin1, INT_DISABLE, _ANY_EDGE},
    {PORTA, PORT_Pin2, INT_ENABLE, _FALLING_EDGE},
    {PORTA, PORT_Pin3, INT_DISABLE, _ANY_EDGE},
    {PORTA, PORT_Pin4, INT_DISABLE, _ANY_EDGE},
    {PORTA, PORT_Pin5, INT_DISABLE, _ANY_EDGE},
    {PORTA, PORT_Pin6, INT_DISABLE, _ANY_EDGE},
    {PORTA, PORT_Pin7, INT_DISABLE, _ANY_EDGE},

    {PORTB, PORT_Pin0, INT_DISABLE, _ANY_EDGE},
    {PORTB, PORT_Pin1, INT_DISABLE, _ANY_EDGE},
    {PORTB, PORT_Pin2, INT_DISABLE, _ANY_EDGE},
    {PORTB, PORT_Pin3, INT_DISABLE, _ANY_EDGE},
    {PORTB, PORT_Pin4, INT_DISABLE, _ANY_EDGE},
    {PORTB, PORT_Pin5, INT_DISABLE, _ANY_EDGE},
    {PORTB, PORT_Pin6, INT_DISABLE, _ANY_EDGE},
    {PORTB, PORT_Pin7, INT_DISABLE, _ANY_EDGE},

    {PORTC, PORT_Pin0, INT_DISABLE, _ANY_EDGE},
    {PORTC, PORT_Pin1, INT_DISABLE, _ANY_EDGE},
    {PORTC, PORT_Pin2, INT_DISABLE, _ANY_EDGE},
    {PORTC, PORT_Pin3, INT_DISABLE, _ANY_EDGE},
    {PORTC, PORT_Pin4, INT_DISABLE, _ANY_EDGE},
    {PORTC, PORT_Pin5, INT_DISABLE, _ANY_EDGE},
    {PORTC, PORT_Pin6, INT_DISABLE, _ANY_EDGE},
    {PORTC, PORT_Pin7, INT_DISABLE, _ANY_EDGE},

    {PORTD, PORT_Pin0, INT_DISABLE, _ANY_EDGE},
    {PORTD, PORT_Pin1, INT_DISABLE, _ANY_EDGE},
    {PORTD, PORT_Pin2, INT_DISABLE, _ANY_EDGE},
    {PORTD, PORT_Pin3, INT_DISABLE, _ANY_EDGE},
    {PORTD, PORT_Pin4, INT_DISABLE, _ANY_EDGE},
    {PORTD, PORT_Pin5, INT_DISABLE, _ANY_EDGE},
    {PORTD, PORT_Pin6, INT_DISABLE, _ANY_EDGE},
    {PORTD, PORT_Pin7, INT_DISABLE, _ANY_EDGE},

    {PORTE, PORT_Pin0, INT_DISABLE, _ANY_EDGE},
    {PORTE, PORT_Pin1, INT_DISABLE, _ANY_EDGE},
    {PORTE, PORT_Pin2, INT_DISABLE, _ANY_EDGE},
    {PORTE, PORT_Pin3, INT_DISABLE, _ANY_EDGE},
    {PORTE, PORT_Pin4, INT_DISABLE, _ANY_EDGE},
    {PORTE, PORT_Pin5, INT_DISABLE, _ANY_EDGE},
    {PORTE, PORT_Pin6, INT_DISABLE, _ANY_EDGE},
    {PORTE, PORT_Pin7, INT_DISABLE, _ANY_EDGE},

    {PORTF, PORT_Pin0, INT_DISABLE, _ANY_EDGE},
    {PORTF, PORT_Pin1, INT_DISABLE, _ANY_EDGE},
    {PORTF, PORT_Pin2, INT_DISABLE, _ANY_EDGE},
    {PORTF, PORT_Pin3, INT_DISABLE, _ANY_EDGE},
    {PORTF, PORT_Pin4, INT_DISABLE, _ANY_EDGE},

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

void GPIO_Unlock(void)
{

#if (_GPIO_PORT_A_UNLOCK == 1)
    GPIOLOCK_A_Reg = 0x0;
    GPIOCR_A_Reg = 0xFF;

#else
    GPIOCR_A_Reg = 0x00;
    GPIOLOCK_A_Reg = 0x1;
#endif

#if (_GPIO_PORT_B_UNLOCK == 1)
    GPIOLOCK_B_Reg = 0x0;
    GPIOCR_B_Reg = 0xFF;
#else
    GPIOCR_B_Reg = 0x00;
    GPIOLOCK_B_Reg = 0x1;
#endif

#if (_GPIO_PORT_C_UNLOCK == 1)
    GPIOLOCK_C_Reg = 0x0;
    GPIOCR_C_Reg = 0xFF;
#else
    GPIOCR_C_Reg = 0x00;
    GPIOLOCK_C_Reg = 0x1;
#endif

#if (_GPIO_PORT_D_UNLOCK == 1)
    GPIOLOCK_D_Reg = 0x0;
    GPIOCR_D_Reg = 0xFF;
#else
    GPIOCR_D_Reg = 0x00;
    GPIOLOCK_D_Reg = 0x1;
#endif

#if (_GPIO_PORT_E_UNLOCK == 1)
    GPIOLOCK_E_Reg = 0x0;
    GPIOCR_E_Reg = 0xFF;
#else
    GPIOCR_E_Reg = 0x00;
    GPIOLOCK_E_Reg = 0x1;
#endif

#if (_GPIO_PORT_F_UNLOCK == 1)
    GPIOLOCK_F_Reg = 0x0;
    GPIOCR_F_Reg = 0xFF;
#else
    GPIOCR_F_Reg = 0x00;
    GPIOLOCK_F_Reg = 0x1;
#endif
}

/**********************************************************************************************************************
 *  END OF FILE: GPIO_Cfg.c
 *********************************************************************************************************************/
