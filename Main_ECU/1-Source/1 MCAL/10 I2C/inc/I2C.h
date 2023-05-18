/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  I2C.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>
 *
 *********************************************************************************************************************/
#ifndef I2C_H
#define I2C_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Mc_Hw_Reg.h"
#include "I2C_cfg.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void I2C_Init(void);
void I2C_Set_Slave_Address(I2C_Num_t I2C_Num, u32 address);
void I2C_transmit(I2C_Num_t I2C_Num, u8 byte);
u8 I2C_Receive(I2C_Num_t I2C_Num);

#endif  /* I2C_H */

/**********************************************************************************************************************
 *  END OF FILE: I2C.h
 *********************************************************************************************************************/
