/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  UART_cfg.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>
 *
 *********************************************************************************************************************/
#ifndef UART_CFG_H
#define UART_CFG_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "UART_cfg.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum
{
    UART0 = 0, UART1, UART2, UART3, UART4, UART5, UART6, UART7
} UART_Num_t;

typedef enum
{
    BAUDRATE_1200 = 0,
    BAUDRATE_4800,
    BAUDRATE_9600,
    BAUDRATE_19200,
    BAUDRATE_115200
} UART_BaudRate_t;

typedef enum
{
    _ODD_PARITY_CHECK = 0, _EVEN_PARITY_CHECK, _NO_PARITY,_DISABLE_PARITY
} Parity_check_t;

typedef enum
{
    WORDLENGTH_5_BITS = 0,
    WORDLENGTH_6_BITS,
    WORDLENGTH_7_BITS,
    WORDLENGTH_8_BITS
} Word_Length_t;

typedef enum
{
    ONE_STOP_BIT = 0, TWO_STOP_BITS
} Stop_Bits_t;

typedef enum{
    INTERRUPT_DISABLE=0,
    INTERRUPT_ENABLE
}UART_INT_State;

typedef struct
{
    UART_Num_t UART_Num;
    UART_BaudRate_t BaudRate;
    Parity_check_t Parity_Bit;
    Stop_Bits_t stopBits;
    Word_Length_t data;
    UART_INT_State INT_state;
    void (*UARTNotification)(void);
} UART_Cfg_t;


#endif  /* UART_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: UART_cfg.h
 *********************************************************************************************************************/
