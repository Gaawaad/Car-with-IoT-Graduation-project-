/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  UART.c
          \brief  Configuring a UART (Universal Asynchronous Receiver/Transmitter) interface
        \details  Contains:
                    1-LOCAL DATA
                        UART_CTL_Reg_Arr[]
                        UART_IBRD_Reg_Arr[]
                        UART_FBRD_Reg_Arr[]
                        UART_FR_Reg_Arr[]
                        UART_DR_Reg_Arr[]
                        UART_LCRH_Reg_Arr[]
                        UART_CC_Reg_Arr[]
                        UART_IM_Reg_Arr[]
                        BaudRateInt_Arr[]
                        BaudRateFrc_Arr[]
                        UART_Noti_Arr[]
                        UART_InterruptNum_Arr[]
                        RxBuffer[]
                    2-GLOBAL DATA
                        UART_Cfg_Arr[]
                    3-GLOBAL FUNCTIONS
                        void UART_Init(void)
                        void UART_SendChr(UART_Num_t UART_Number, u8 data)
                        u8 UART_ReceiveChr(UART_Num_t UART_Number)
                        void UART_SendStr(UART_Num_t UART_Number, u8 *str)
                        void UART_SetNotification(UART_Num_t UART_Number, void (*UART_Notfi)(void))
                        u8 UART_readBuffer(UART_Num_t UART_Number)
                        void UART_readStr(UART_Num_t UART_Number, u8 *str)
                        void UART_SendNum(UART_Num_t UART_Number, u32 num)
                        void UART0_Handler(void)
                        void UART1_Handler(void)
                        void UART2_Handler(void)
                        void UART3_Handler(void)
                        void UART4_Handler(void)
                        void UART5_Handler(void)
                        void UART6_Handler(void)
                        void UART7_Handler(void)
                     4-STATIC FUNCTIONS
                        static void dummy_func(void)
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "UART.h"

/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/

volatile u32 *UART_CTL_Reg_Arr[] = { &UART_0_CTL_Reg, &UART_1_CTL_Reg,
                                     &UART_2_CTL_Reg, &UART_3_CTL_Reg,
                                     &UART_4_CTL_Reg, &UART_5_CTL_Reg,
                                     &UART_6_CTL_Reg, &UART_7_CTL_Reg };

volatile u32 *UART_IBRD_Reg_Arr[] = { &UART_0_IBRD_Reg, &UART_1_IBRD_Reg,
                                      &UART_2_IBRD_Reg, &UART_3_IBRD_Reg,
                                      &UART_4_IBRD_Reg, &UART_5_IBRD_Reg,
                                      &UART_6_IBRD_Reg, &UART_7_IBRD_Reg, };

volatile u32 *UART_FBRD_Reg_Arr[] = { &UART_0_FBRD_Reg, &UART_1_FBRD_Reg,
                                      &UART_2_FBRD_Reg, &UART_3_FBRD_Reg,
                                      &UART_4_FBRD_Reg, &UART_5_FBRD_Reg,
                                      &UART_6_FBRD_Reg, &UART_7_FBRD_Reg, };

volatile u32 *UART_FR_Reg_Arr[] = { &UART_0_FR_Reg, &UART_1_FR_Reg,
                                    &UART_2_FR_Reg, &UART_3_FR_Reg,
                                    &UART_4_FR_Reg, &UART_5_FR_Reg,
                                    &UART_6_FR_Reg, &UART_7_FR_Reg, };

volatile u32 *UART_DR_Reg_Arr[] = { &UART_0_DR_Reg, &UART_1_DR_Reg,
                                    &UART_2_DR_Reg, &UART_3_DR_Reg,
                                    &UART_4_DR_Reg, &UART_5_DR_Reg,
                                    &UART_6_DR_Reg, &UART_7_DR_Reg, };

volatile u32 *UART_LCRH_Reg_Arr[] = { &UART_0_LCRH_Reg, &UART_1_LCRH_Reg,
                                      &UART_2_LCRH_Reg, &UART_3_LCRH_Reg,
                                      &UART_4_LCRH_Reg, &UART_5_LCRH_Reg,
                                      &UART_6_LCRH_Reg, &UART_7_LCRH_Reg, };

volatile u32 *UART_CC_Reg_Arr[] = { &UART_0_CC_Reg, &UART_1_CC_Reg,
                                    &UART_2_CC_Reg, &UART_3_CC_Reg,
                                    &UART_4_CC_Reg, &UART_5_CC_Reg,
                                    &UART_6_CC_Reg, &UART_7_CC_Reg, };

volatile u32 *UART_IM_Reg_Arr[] = { &UART_0_IM_Reg, &UART_1_IM_Reg,
                                    &UART_2_IM_Reg, &UART_3_IM_Reg,
                                    &UART_4_IM_Reg, &UART_5_IM_Reg,
                                    &UART_6_IM_Reg, &UART_7_IM_Reg, };

u16 BaudRateInt_Arr[] = { 833, 208, 104, 52, 8 };
u16 BaudRateFrc_Arr[] = { 21, 21, 11, 5, 44 };

typedef void (*function)(void);
static function UART_Noti_Arr[8]={dummy_func,dummy_func,dummy_func,dummy_func,dummy_func,dummy_func,dummy_func,dummy_func};

IntCtrNum_t UART_InterruptNum_Arr[] = { _INT5, _INT6, _INT33, _INT59, _INT60,
                                        _INT61, _INT62, _INT63 };

u8 RxBuffer[] = { 0, 0, 0, 0, 0, 0, 0, 0 };


/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
extern UART_Cfg_t UART_Cfg_Arr[];

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/******************************************************************************
 * \Syntax          : void UART_Init(void)
 * \Description     : initializing All of UART (Universal Asynchronous Receiver/Transmitter) interfaces
 *                    based on the configuration parameters defined in another source file ("UART_cfg.c").
 * \Sync\Async      : Asynchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : None
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
void UART_Init(void)
{

    u8 count;
    for (count = 0; count <= 7; count++)
    {

        if (UART_Cfg_Arr[count].INT_state)
        {
            IntEnable(UART_InterruptNum_Arr[count]);
            *UART_IM_Reg_Arr[count] |= (1 << 4);
        }
        else
        {
            IntDisable(UART_InterruptNum_Arr[count]);
            *UART_IM_Reg_Arr[count] &= ~(1 << 4);
        }

        *UART_CTL_Reg_Arr[count] &= ~(1 << 0); // Disable UART

        *UART_IBRD_Reg_Arr[count] =
                BaudRateInt_Arr[UART_Cfg_Arr[count].BaudRate]; // integer Baud-Rate Divisor

        *UART_FBRD_Reg_Arr[count] =
                BaudRateFrc_Arr[UART_Cfg_Arr[count].BaudRate]; //Fractional Baud-Rate Divisor

        *UART_LCRH_Reg_Arr[count] &= ~(3 << 5); //clear the word length
        *UART_LCRH_Reg_Arr[count] |= (UART_Cfg_Arr[count].data << 5); //select the word length

        *UART_LCRH_Reg_Arr[count] &= ~(1 << 3); //clear stop bit
        *UART_LCRH_Reg_Arr[count] |= (UART_Cfg_Arr[count].stopBits << 3); //select stop bit

        switch (UART_Cfg_Arr[count].Parity_Bit)
        //select parity check
        {
        case _EVEN_PARITY_CHECK:
            *UART_LCRH_Reg_Arr[count] |= (1 << 1);
            *UART_LCRH_Reg_Arr[count] |= (1 << 2);
            *UART_LCRH_Reg_Arr[count] |= (1 << 7);
            break;
        case _ODD_PARITY_CHECK:
            *UART_LCRH_Reg_Arr[count] |= (1 << 1);
            *UART_LCRH_Reg_Arr[count] &= ~(1 << 2);
            *UART_LCRH_Reg_Arr[count] |= (1 << 7);
            break;
        case _NO_PARITY:
            *UART_LCRH_Reg_Arr[count] &= ~(1 << 1);
            break;
        case _DISABLE_PARITY:
            *UART_LCRH_Reg_Arr[count] &= ~(1 << 7);
            break;
        default:
            *UART_LCRH_Reg_Arr[count] &= ~(1 << 1);
        }

        //      *UART_LCRH_Reg_Arr[count] |= (1 << 4); //UART Enable FIFOs

        *UART_CTL_Reg_Arr[count] |= (1 << 8); //UART Transmit Enable
        *UART_CTL_Reg_Arr[count] |= (1 << 9); //UART Receive Enable

        *UART_CTL_Reg_Arr[count] |= (1 << 0); // Enable UART
    }
}


/******************************************************************************
 * \Syntax          : void UART_SendChr(UART_Num_t UART_Number, u8 data)
 * \Description     : sending a single character over a UART (Universal Asynchronous Receiver/Transmitter) interface.
 *                    The function takes two arguments: "UART_Number", which specifies which UART interface to use,
 *                    and "data", which is the character to send.
 *
 * \Sync\Async      : Asynchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : UART_Num_t UART_Number, u8 data
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/

void UART_SendChr(UART_Num_t UART_Number, u8 data)
{
    while (((*UART_FR_Reg_Arr[UART_Number] >> 5) & 0x01))
    {
        //waiting
    }
    *UART_DR_Reg_Arr[UART_Number] = data;
}


/******************************************************************************
 * \Syntax          : u8 UART_ReceiveChr(UART_Num_t UART_Number)
 * \Description     : receiving a single character over a UART (Universal Asynchronous Receiver/Transmitter) interface.
 *                    The function takes a single argument: "UART_Number", which specifies which UART interface to use.
 *
 * \Sync\Async      : Asynchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : UART_Num_t UART_Number
 * \Parameters (out): u8
 * \Return value:   : unsigned 8 bits (0:255)
 *******************************************************************************/

u8 UART_ReceiveChr(UART_Num_t UART_Number)
{
    while (((*UART_FR_Reg_Arr[UART_Number] >> 4) & 0x01))
    {
        //waiting
    }
    return (*UART_DR_Reg_Arr[UART_Number]);
}


/******************************************************************************
 * \Syntax          : void UART_SendStr(UART_Num_t UART_Number, u8 *str)
 * \Description     : sending a null-terminated string over a UART (Universal Asynchronous Receiver/Transmitter) interface.
 *                    The function takes two arguments: "UART_Number",which specifies which UART interface to use, and "str",
 *                    which is a pointer to the null-terminated string to send.
 *
 * \Sync\Async      : Asynchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : UART_Num_t UART_Number, u8 *str
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/

void UART_SendStr(UART_Num_t UART_Number, u8 *str)
{
    while (*str != '\0')
    {
        UART_SendChr(UART_Number, *str);
        str++;
    }
}


/******************************************************************************
 * \Syntax          : void UART_SetNotification(UART_Num_t UART_Number, void (*UART_Notfi)(void))
 * \Description     : The function simply sets the UART_Noti_Arr array element for the given UART_Number
 *                    to the UART_Notfi function pointer. This means that whenever a UART interrupt occurs
 *                    for that particular UART, the corresponding notification function (UART_Notfi) will be called.
 *
 * \Sync\Async      : ASynchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : UART_Num_t UART_Number, void (*UART_Notfi)(void)
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/

void UART_SetNotification(UART_Num_t UART_Number, void (*UART_Notfi)(void))
{
    UART_Noti_Arr[UART_Number] = UART_Notfi;
}


/******************************************************************************
 * \Syntax          : u8 UART_readBuffer(UART_Num_t UART_Number)
 * \Description     : The function first reads the data from the receive buffer
 *                    corresponding to the given UART_Number and stores it in a variable bf.
 *
 * \Sync\Async      : Asynchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : UART_Num_t UART_Number
 * \Parameters (out): u8
 * \Return value:   : unsigned 8 bits (0:255)
 *******************************************************************************/

u8 UART_readBuffer(UART_Num_t UART_Number)
{
    u8 bf = RxBuffer[UART_Number];
    RxBuffer[UART_Number] = 0;
    return bf;
}


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

void UART_readStr(UART_Num_t UART_Number, u8 *str)
{
    u8 count=0,data = 0;
    do
    {
        data= UART_readBuffer(UART_Number);
        if(data!=0){
            *(str + count) =data;
            count++;

        }
    }
    while (data != '\n' && data != '\r');
    *(str + count) = 0;

}


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

void UART_SendNum(UART_Num_t UART_Number, u32 num)
{
    u8 loc_digit1 = (num % 10);
    u8 loc_digit2 = (num / 10) % 10;
    u8 loc_digit3 = (num / 100) % 10;
    u8 loc_digit4 = (num / 1000) % 10;
    u8 loc_digit5 = (num / 10000) % 10;
    u8 loc_digit6 = (num / 100000) % 10;
    u8 loc_digit7 = (num / 1000000) % 10;
    u8 loc_digit8 = (num / 10000000) % 10;
    u8 loc_digit9 = (num / 100000000) % 10;
    u8 loc_digit10 = (num / 1000000000);

    if (num < 10)
    {
        UART_SendChr(UART_Number, loc_digit1 + 48);
    }
    else if (num < 100 && num > 9)
    {
        UART_SendChr(UART_Number, loc_digit2 + 48);
        UART_SendChr(UART_Number, loc_digit1 + 48);
    }
    else if (num < 1000 && num > 99)
    {
        UART_SendChr(UART_Number, loc_digit3 + 48);
        UART_SendChr(UART_Number, loc_digit2 + 48);
        UART_SendChr(UART_Number, loc_digit1 + 48);
    }
    else if (num < 10000 && num > 999)
    {
        UART_SendChr(UART_Number, loc_digit4 + 48);
        UART_SendChr(UART_Number, loc_digit3 + 48);
        UART_SendChr(UART_Number, loc_digit2 + 48);
        UART_SendChr(UART_Number, loc_digit1 + 48);
    }
    else if (num < 100000 && num > 9999)
    {
        UART_SendChr(UART_Number, loc_digit5 + 48);
        UART_SendChr(UART_Number, loc_digit4 + 48);
        UART_SendChr(UART_Number, loc_digit3 + 48);
        UART_SendChr(UART_Number, loc_digit2 + 48);
        UART_SendChr(UART_Number, loc_digit1 + 48);
    }
    else if (num < 1000000 && num > 99999)
    {
        UART_SendChr(UART_Number, loc_digit6 + 48);
        UART_SendChr(UART_Number, loc_digit5 + 48);
        UART_SendChr(UART_Number, loc_digit4 + 48);
        UART_SendChr(UART_Number, loc_digit3 + 48);
        UART_SendChr(UART_Number, loc_digit2 + 48);
        UART_SendChr(UART_Number, loc_digit1 + 48);
    }
    else if (num < 10000000 && num > 999999)
    {
        UART_SendChr(UART_Number, loc_digit7 + 48);
        UART_SendChr(UART_Number, loc_digit6 + 48);
        UART_SendChr(UART_Number, loc_digit5 + 48);
        UART_SendChr(UART_Number, loc_digit4 + 48);
        UART_SendChr(UART_Number, loc_digit3 + 48);
        UART_SendChr(UART_Number, loc_digit2 + 48);
        UART_SendChr(UART_Number, loc_digit1 + 48);
    }
    else if (num < 100000000 && num > 9999999)
    {
        UART_SendChr(UART_Number, loc_digit8 + 48);
        UART_SendChr(UART_Number, loc_digit7 + 48);
        UART_SendChr(UART_Number, loc_digit6 + 48);
        UART_SendChr(UART_Number, loc_digit5 + 48);
        UART_SendChr(UART_Number, loc_digit4 + 48);
        UART_SendChr(UART_Number, loc_digit3 + 48);
        UART_SendChr(UART_Number, loc_digit2 + 48);
        UART_SendChr(UART_Number, loc_digit1 + 48);
    }
    else if (num < 1000000000 && num > 99999999)
    {
        UART_SendChr(UART_Number, loc_digit9 + 48);
        UART_SendChr(UART_Number, loc_digit8 + 48);
        UART_SendChr(UART_Number, loc_digit7 + 48);
        UART_SendChr(UART_Number, loc_digit6 + 48);
        UART_SendChr(UART_Number, loc_digit5 + 48);
        UART_SendChr(UART_Number, loc_digit4 + 48);
        UART_SendChr(UART_Number, loc_digit3 + 48);
        UART_SendChr(UART_Number, loc_digit2 + 48);
        UART_SendChr(UART_Number, loc_digit1 + 48);
    }
    else
    {
        UART_SendChr(UART_Number, loc_digit10 + 48);
        UART_SendChr(UART_Number, loc_digit9 + 48);
        UART_SendChr(UART_Number, loc_digit8 + 48);
        UART_SendChr(UART_Number, loc_digit7 + 48);
        UART_SendChr(UART_Number, loc_digit6 + 48);
        UART_SendChr(UART_Number, loc_digit5 + 48);
        UART_SendChr(UART_Number, loc_digit4 + 48);
        UART_SendChr(UART_Number, loc_digit3 + 48);
        UART_SendChr(UART_Number, loc_digit2 + 48);
        UART_SendChr(UART_Number, loc_digit1 + 48);
    }
}


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

void UART0_Handler(void)
{
    RxBuffer[0] = *UART_DR_Reg_Arr[0];
    UART_Noti_Arr[0]();

}


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

void UART1_Handler(void)
{
    RxBuffer[1] = *UART_DR_Reg_Arr[1];
    UART_Noti_Arr[1]();

}


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

void UART2_Handler(void)
{
    RxBuffer[2] = *UART_DR_Reg_Arr[2];
    UART_Noti_Arr[2]();

}


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

void UART3_Handler(void)
{
    RxBuffer[3] = *UART_DR_Reg_Arr[3];
    UART_Noti_Arr[3]();

}


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

void UART4_Handler(void)
{
    RxBuffer[4] = *UART_DR_Reg_Arr[4];
    UART_Noti_Arr[4]();

}


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

void UART5_Handler(void)
{
    RxBuffer[5] = *UART_DR_Reg_Arr[5];
    UART_Noti_Arr[5]();

}


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

void UART6_Handler(void)
{
    RxBuffer[6] = *UART_DR_Reg_Arr[6];
    UART_Noti_Arr[6]();

}


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

void UART7_Handler(void)
{
    RxBuffer[7] = *UART_DR_Reg_Arr[7];
    UART_Noti_Arr[7]();

}


/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
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


static void dummy_func(void){

}
/**********************************************************************************************************************
 *  END OF FILE: UART.c
 *********************************************************************************************************************/
