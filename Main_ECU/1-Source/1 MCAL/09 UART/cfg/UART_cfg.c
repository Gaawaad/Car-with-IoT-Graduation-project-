/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  UART_cfg.c
 *        \brief  configuring a UART (Universal Asynchronous Receiver/Transmitter) interface
 *
 *      \details  Contains:
 *                  UART_Cfg_Arr[]
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "UART_cfg.h"

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
/*
 *
    The global array of "UART_Cfg_t" structures is declared and initialized with configuration parameters for each UART interface.
    Each "UART_Cfg_t" structure contains the following parameters:
            UART number (e.g., UART0, UART1, etc.)
            Baud rate
            Parity check type (e.g., no parity, odd parity, even parity)
            Stop bit count (e.g., one stop bit, two stop bits)
            Word length (e.g., 8 bits, 9 bits)
            Interrupt enable/disable flag
            Call back function that called when an interrupt is occurred
 *
 * */
UART_Cfg_t UART_Cfg_Arr[]= { { UART0, BAUDRATE_9600,_ODD_PARITY_CHECK,ONE_STOP_BIT,WORDLENGTH_8_BITS,INTERRUPT_DISABLE,0},
                             { UART1, BAUDRATE_9600,_NO_PARITY,ONE_STOP_BIT,WORDLENGTH_8_BITS,INTERRUPT_ENABLE,0},
                             { UART2, BAUDRATE_9600,_ODD_PARITY_CHECK,ONE_STOP_BIT,WORDLENGTH_8_BITS,INTERRUPT_DISABLE,0},
                             { UART3, BAUDRATE_9600,_ODD_PARITY_CHECK,ONE_STOP_BIT,WORDLENGTH_8_BITS,INTERRUPT_DISABLE,0},
                             { UART4, BAUDRATE_9600,_ODD_PARITY_CHECK,ONE_STOP_BIT,WORDLENGTH_8_BITS,INTERRUPT_DISABLE,0},
                             { UART5, BAUDRATE_9600,_ODD_PARITY_CHECK,ONE_STOP_BIT,WORDLENGTH_8_BITS,INTERRUPT_DISABLE,0},
                             { UART6, BAUDRATE_9600,_ODD_PARITY_CHECK,ONE_STOP_BIT,WORDLENGTH_8_BITS,INTERRUPT_DISABLE,0},
                             { UART7, BAUDRATE_9600,_ODD_PARITY_CHECK,ONE_STOP_BIT,WORDLENGTH_8_BITS,INTERRUPT_DISABLE,0}
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
 *  END OF FILE: UART_cfg.c
 *********************************************************************************************************************/
