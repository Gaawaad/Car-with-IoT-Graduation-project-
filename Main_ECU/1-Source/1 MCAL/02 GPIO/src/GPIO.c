/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  FileName.c
 *        \brief
 *
 *      \details
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "GPIO.h"

/**********************************************************************************************************************
 *  LOCAL MACROS CONSTANT\FUNCTION
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
typedef void (*funcNoti)(void);
volatile u32 *GPIOIM_Arr[] = {
    &GPIOIM_A_Reg,
    &GPIOIM_B_Reg,
    &GPIOIM_C_Reg,
    &GPIOIM_D_Reg,
    &GPIOIM_E_Reg,
    &GPIOIM_F_Reg};
volatile u32 *GPIOIEV_Arr[] = {&GPIOIEV_A_Reg, &GPIOIEV_B_Reg, &GPIOIEV_C_Reg, &GPIOIEV_D_Reg, &GPIOIEV_E_Reg, &GPIOIEV_F_Reg};
volatile u32 *GPIOICR_Arr[] = {&GPIOICR_A_Reg, &GPIOICR_B_Reg, &GPIOICR_C_Reg, &GPIOICR_D_Reg, &GPIOICR_E_Reg, &GPIOICR_F_Reg};
volatile u32 *GPIOIBE_Arr[] = {&GPIOIBE_A_Reg, &GPIOIBE_B_Reg, &GPIOIBE_C_Reg, &GPIOIBE_D_Reg, &GPIOIBE_E_Reg, &GPIOIBE_F_Reg};
volatile u32 *GPIORIS_Arr[] = {
    &GPIORIS_A_Reg,
    &GPIORIS_B_Reg,
    &GPIORIS_C_Reg,
    &GPIORIS_D_Reg,
    &GPIORIS_E_Reg,
    &GPIORIS_F_Reg};

funcNoti FuncArr[] = {0, 0, 0, 0, 0, 0};
u8 IntFlage[6][8];
extern PORT_INT_Cfg_t InterruptCfg_Arr[];
IntCtrNum_t PortIntNum_Arr[] = {_INT0, _INT1, _INT2, _INT3, _INT4, _INT30};
/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
void GPIO_Init(void)
{

    u8 count1;
    for (count1 = 0; count1 <= 44; count1++)
    {
        if (InterruptCfg_Arr[count1].IntMskEn == INT_ENABLE)
        {
            IntEnable(PortIntNum_Arr[InterruptCfg_Arr[count1].Port]);
            *GPIOIM_Arr[InterruptCfg_Arr[count1].Port] |= (1 << InterruptCfg_Arr[count1].Pin);
        }
        else
        {
            *GPIOIM_Arr[InterruptCfg_Arr[count1].Port] &= ~(1 << InterruptCfg_Arr[count1].Pin);
        }

        if (InterruptCfg_Arr[count1].IntEvent == _FALLING_EDGE)
        {
            *GPIOIBE_Arr[InterruptCfg_Arr[count1].Port] &= ~(1 << InterruptCfg_Arr[count1].Pin);
            *GPIOIEV_Arr[InterruptCfg_Arr[count1].Port] &= ~(1 << InterruptCfg_Arr[count1].Pin);
        }
        else if (InterruptCfg_Arr[count1].IntEvent == _RISING_EDGE)
        {
            *GPIOIBE_Arr[InterruptCfg_Arr[count1].Port] &= ~(1 << InterruptCfg_Arr[count1].Pin);
            *GPIOIEV_Arr[InterruptCfg_Arr[count1].Port] |= (1 << InterruptCfg_Arr[count1].Pin);
        }
        else
        {
            *GPIOIBE_Arr[InterruptCfg_Arr[count1].Port] |= (1 << InterruptCfg_Arr[count1].Pin);
        }
        *GPIOICR_Arr[InterruptCfg_Arr[count1].Port] |= (1 << InterruptCfg_Arr[count1].Pin);
    }
}

void GPIOInterruptEvent(Dio_PortType Port, Dio_ChannelType Pin, InterruptEvent_t Event)
{
    if (Event == _FALLING_EDGE)
    {
        *GPIOIBE_Arr[Port] &= ~(1 << Pin);
        *GPIOIEV_Arr[Port] &= ~(1 << Pin);
    }
    else if (Event == _RISING_EDGE)
    {
        *GPIOIBE_Arr[Port] &= ~(1 << Pin);
        *GPIOIEV_Arr[Port] |= (1 << Pin);
    }
    else if (Event == _ANY_EDGE)
    {
        *GPIOIBE_Arr[Port] |= (1 << Pin);
    }
    *GPIOICR_Arr[Port] |= (1 << Pin);
    *GPIOIM_Arr[Port] |= (1 << Pin);
}

void GPIO_InterruptCallBack(Dio_PortType Port, void *func(void))
{
    FuncArr[Port] = func;
}

static void GetIntNum(u8 port)
{
    u8 PinCount;
    for (PinCount = 0; PinCount <= 7; PinCount++)
    {
        IntFlage[port][PinCount] = ((*GPIORIS_Arr[port] >> PinCount) & 0x01);
    }
}

void GPIOA_Handler(void)
{
    GetIntNum(0);
    *GPIOICR_Arr[0] |= 0xFF;
    if (FuncArr[0] != 0)
    {
        FuncArr[0]();
    }
}
void GPIOB_Handler(void)
{
    GetIntNum(1);
    *GPIOICR_Arr[1] |= 0xFF;
    if (FuncArr[1] != 0)
    {
        FuncArr[1]();
    }
}
void GPIOC_Handler(void)
{
    GetIntNum(2);
    *GPIOICR_Arr[2] |= 0xFF;
    if (FuncArr[2] != 0)
    {
        FuncArr[2]();
    }
}
void GPIOD_Handler(void)
{
    GetIntNum(3);
    *GPIOICR_Arr[3] |= 0xFF;
    if (FuncArr[3] != 0)
    {
        FuncArr[3]();
    }
}
void GPIOE_Handler(void)
{
    GetIntNum(4);
    *GPIOICR_Arr[4] |= 0xFF;
    if (FuncArr[4] != 0)
    {
        FuncArr[4]();
    }
}
void GPIOF_Handler(void)
{
    GetIntNum(5);
    *GPIOICR_Arr[5] |= 0xFF;
    if (FuncArr[5] != 0)
    {
        FuncArr[5]();
    }
}
/**********************************************************************************************************************
 *  END OF FILE: GPIO.c
 *********************************************************************************************************************/
