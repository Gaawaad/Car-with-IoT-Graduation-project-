/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  PORT_Types.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>
 *
 *********************************************************************************************************************/
#ifndef PORT_TYPES_H
#define PORT_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Dio_types.h"
/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef enum
{
    PORT_Pin0,
    PORT_Pin1,
    PORT_Pin2,
    PORT_Pin3,
    PORT_Pin4,
    PORT_Pin5,
    PORT_Pin6,
    PORT_Pin7
} PORT_Channel_t;

typedef enum
{
    PORTA, PORTB, PORTC, PORTD, PORTE, PORTF
} Port_t;

typedef enum
{
    DIGITAL_DISABLE, DIGITAL_ENABLE
} DigitalEnable_t;

typedef enum
{
    ALTERNATE_DISABLE = 0, ALTERNATE_ENABLE
} AlternateEnable_t;

typedef enum
{
    NONE_FNC = 0, UART = 1, I2C = 3, M0PWM = 4, M1PWM = 5, TxCCPx = 7
} AlternateFunction_t;

typedef struct
{
    Port_t Port;
    PORT_Channel_t Pin;
    DigitalEnable_t DigEn;
    AlternateEnable_t Altrnate_pin;
    AlternateFunction_t Altrnate_fun;
    PIN_Dir Direction;
    Level_t level;
    PIN_Connection_t Connection;
} PORT_Cfg_t;

#endif /* PORT_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: PORT_Types.h
 *********************************************************************************************************************/
