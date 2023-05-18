/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  GPT.c
 *        \brief
 *
 *      \details
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "GPT.h"

/**********************************************************************************************************************
 *  LOCAL MACROS CONSTANT\FUNCTION
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
extern GptChannelConfigSet GptChannelCfg_Arr[];
typedef void (*func)(void);
volatile u32 *GPTMCTL_Reg_Arr[] = { &GPTMCTL_0A_Reg, &GPTMCTL_1A_Reg,
                                    &GPTMCTL_2A_Reg, &GPTMCTL_3A_Reg,
                                    &GPTMCTL_4A_Reg, &GPTMCTL_5A_Reg };
volatile u32 *GPTMTAMR_Reg_Arr[] = { &GPTMTAMR_0A_Reg, &GPTMTAMR_1A_Reg,
                                     &GPTMTAMR_2A_Reg, &GPTMTAMR_3A_Reg,
                                     &GPTMTAMR_4A_Reg, &GPTMTAMR_5A_Reg };
volatile u32 *GPTMTAILR_Reg_Arr[] = { &GPTMTAILR_0A_Reg, &GPTMTAILR_1A_Reg,
                                      &GPTMTAILR_2A_Reg, &GPTMTAILR_3A_Reg,
                                      &GPTMTAILR_4A_Reg, &GPTMTAILR_5A_Reg };
volatile u32 *GPTMCFG_Reg_Arr[] = { &GPTMCFG_0A_Reg, &GPTMCFG_1A_Reg,
                                    &GPTMCFG_2A_Reg, &GPTMCFG_3A_Reg,
                                    &GPTMCFG_4A_Reg, &GPTMCFG_5A_Reg };
volatile u32 *GPTMIMR_Reg_Arr[] = { &GPTMIMR_0A_Reg, &GPTMIMR_1A_Reg,
                                    &GPTMIMR_2A_Reg, &GPTMIMR_3A_Reg,
                                    &GPTMIMR_4A_Reg, &GPTMIMR_5A_Reg };
volatile u32 *GPTMICR_Reg_Arr[] = { &GPTMICR_0A_Reg, &GPTMICR_1A_Reg,
                                    &GPTMICR_2A_Reg, &GPTMICR_3A_Reg,
                                    &GPTMICR_4A_Reg, &GPTMICR_5A_Reg, };
volatile u32 *GPTMTAPR_Reg_Arr[] = { &GPTMTAPR_0A_Reg, &GPTMTAPR_1A_Reg,
                                     &GPTMTAPR_2A_Reg, &GPTMTAPR_3A_Reg,
                                     &GPTMTAPR_4A_Reg, &GPTMTAPR_5A_Reg, };
IntCtrNum_t InterruptNum_Arr[] = { _INT19, _INT21, _INT23, _INT35, _INT70,
                                   _INT92 };
static func Noti_Arr[6];
u32 Counts_Arr[] = { 0, 0, 0, 0, 0, 0 };
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
void Gpt_Init(GPTChannelId_t GptChannelId, void (*GptNotification)(void))
{
    intCtr_init();

#if (_GPT_PREDEF_TIMER_100US_32BIT == 1)
    *GPTMCTL_Reg_Arr[GPT_PREDF] &= ~(1 << 0);
    *GPTMTAMR_Reg_Arr[GPT_PREDF] |= 0x2;
    *GPTMTAMR_Reg_Arr[GPT_PREDF] |= (1 << 4);
    *GPTMTAILR_Reg_Arr[GPT_PREDF] = 1600;
    *GPTMCFG_Reg_Arr[GPT_PREDF] |= (0x04);
    *GPTMIMR_Reg_Arr[GPT_PREDF] |= (1 << 0);
    Noti_Arr[GPT_PREDF] = GptNotification;
    IntEnable(InterruptNum_Arr[GPT_PREDF]);
#else
    *GPTMCTL_Reg_Arr[GptChannelId] &= ~(1 << 0);
    *GPTMTAMR_Reg_Arr[GptChannelId] |=
            GptChannelCfg_Arr[GptChannelId].ChannelMode;
    *GPTMCFG_Reg_Arr[GptChannelId] |= (0x04);
    *GPTMIMR_Reg_Arr[GptChannelId] |= (1 << 0);
    *GPTMICR_Reg_Arr[GptChannelId] |= (1 << 0);
    Noti_Arr[GptChannelId] = GptNotification;
    if (GptChannelCfg_Arr[GptChannelId].CountDirection == COUNTS_UP)
    {
        *GPTMTAMR_Reg_Arr[GptChannelId] |= (1 << 4) | (1 << 4);
    }
    else
    {
        *GPTMTAMR_Reg_Arr[GptChannelId] |= (1 << 4);
    }

    IntEnable(InterruptNum_Arr[GptChannelId]);
#endif
}
void GPT_StartTimer(GPTChannelId_t GptChannelId)
{
#if (_GPT_PREDEF_TIMER_100US_32BIT == 1)
    *GPTMCTL_Reg_Arr[GPT_PREDF] |= (1 << 0);
    *GPTMTAILR_Reg_Arr[GPT_PREDF] = 1600;
#else
    *GPTMTAILR_Reg_Arr[GptChannelId] =
            GptChannelCfg_Arr[GptChannelId].GptChannelTickMaxValue;
    *GPTMCTL_Reg_Arr[GptChannelId] |= (1 << 0);
#endif
}

void GPT_StopTimer(GPTChannelId_t GptChannelId)
{
#if (_GPT_PREDEF_TIMER_100US_32BIT == 1)
    *GPTMCTL_Reg_Arr[GPT_PREDF] &= ~(1 << 0);
    Counts_Arr[GPT_PREDF] = 0;
#else
    *GPTMCTL_Reg_Arr[GptChannelId] &= ~(1 << 0);
    Counts_Arr[GptChannelId] = 0;
#endif
}

u32 GPT_GetTime(GPTChannelId_t GptChannelId)
{

    return Counts_Arr[GptChannelId];
}

void GPT_RestTimer(GPTChannelId_t GptChannelId)
{
#if (_GPT_PREDEF_TIMER_100US_32BIT == 1)
    Counts_Arr[GPT_PREDF] = 0;
    *GPTMTAILR_Reg_Arr[GPT_PREDF] = 1600;
#else
    Counts_Arr[GptChannelId] = 0;
    *GPTMTAILR_Reg_Arr[GptChannelId] =
            GptChannelCfg_Arr[GptChannelId].GptChannelTickMaxValue;
#endif
}

void GPT0_CaptureMode_Init(void)
{

    /* make PB6 an input pin */
    /* make PB6 as digital pin */
    /* use PB6 alternate function */
    /* configure PB6 for T0CCP0 */
    GPTMCTL_0A_Reg &= ~1; /* disable GPTr0A  */
    GPTMCFG_0A_Reg |= 4; /* 16-bit */
    GPTMTAMR_0A_Reg |= 0x17; /* up-count, edge-time, capture mode */
    GPTMCTL_0A_Reg |= 0x0C;/* capture the rising edge */
    GPTMCTL_0A_Reg |= (1 << 0);/* enable GPT0A */
}

u32 GPT0_PulseWidthTime(void)
{
    u32 PrevEdge=0, CurrEdge=0, diff=0;
    GPTMICR_0A_Reg |= 4; /* clear GPT0A capture flag */
    while ((GPTMRIS_0A_Reg & 4) == 0)
        ; /* wait for capturing */
    if (GPIODATA_B_Reg & (1 << 6))
    {
        PrevEdge = GPTMTAILR_0A_Reg;
    }
    GPTMICR_0A_Reg |= 4; /* clear GPT0A capture flag */
    while ((GPTMRIS_0A_Reg & 4) == 0)
        ; /* wait for capturing */
    CurrEdge = GPTMTAILR_0A_Reg;
    diff = CurrEdge - PrevEdge;
    return diff;
}

void GPT_delay(GPTChannelId_t GptChannelId, u32 delay)
{
    Gpt_Init(GptChannelId, 0);
    GPT_StartTimer(GptChannelId);
    u32 Ctime = 0;
    while (Ctime < delay)
    {
        Ctime = GPT_GetTime(GptChannelId);
    }
}
void TIMER0A_Handler(void)
{
    *GPTMICR_Reg_Arr[0] |= (1 << 0);
    if (Noti_Arr[0] != 0)
    {
        Noti_Arr[0]();
    }
    Counts_Arr[0]++;
}

void TIMER1A_Handler(void)
{
    *GPTMICR_Reg_Arr[1] |= (1 << 0);
    if (Noti_Arr[1] != 0)
    {
        Noti_Arr[1]();
    }
    Counts_Arr[1]++;
}

void TIMER2A_Handler(void)
{
    *GPTMICR_Reg_Arr[2] |= (1 << 0);
    if (Noti_Arr[2] != 0)
    {
        Noti_Arr[2]();
    }
    Counts_Arr[2]++;
}

void TIMER3A_Handler(void)
{
    *GPTMICR_Reg_Arr[3] |= (1 << 0);
    if (Noti_Arr[3] != 0)
    {
        Noti_Arr[3]();
    }
    Counts_Arr[3]++;
}

void TIMER4A_Handler(void)
{
    *GPTMICR_Reg_Arr[4] |= (1 << 0);
    if (Noti_Arr[4] != 0)
    {
        Noti_Arr[4]();
    }
    Counts_Arr[4]++;
}
void TIMER5A_Handler(void)
{
    *GPTMICR_Reg_Arr[5] |= (1 << 0);
    if (Noti_Arr[5] != 0)
    {
        Noti_Arr[5]();
    }
    Counts_Arr[5]++;
}

/**********************************************************************************************************************
 *  END OF FILE: GPT.c
 *********************************************************************************************************************/
