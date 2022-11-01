/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  intCtr.c
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_types.h"
#include "intCtr.h"
/******************************************************************************
 * \Syntax          : void intCtr_init(void)
 * \Description     : control the interrupts
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : None
 * \Parameters (out): None
 * \Return value:   : No return
 *******************************************************************************/
extern IntCtrCfg_t IntCfg_Arr[];
extern ExceptionCtr_t FaultsCfg_Arr[];
volatile u32 *PRIx_Reg_Arr[] = {
    &PRI0_Reg,
    &PRI1_Reg,
    &PRI2_Reg,
    &PRI3_Reg,
    &PRI4_Reg,
    &PRI5_Reg,
    &PRI6_Reg,
    &PRI7_Reg,
    &PRI8_Reg,
    &PRI9_Reg,
    &PRI10_Reg,
    &PRI11_Reg,
    &PRI12_Reg,
    &PRI13_Reg,
    &PRI14_Reg,
    &PRI15_Reg,
};
volatile u32 *ENx_Reg_Arr[] = {
    &EN0_Reg,
    &EN1_Reg,
    &EN2_Reg,
    &EN3_Reg,
    &EN4_Reg,
};

void intCtr_init(void)
{

#if (_INT_SET_GROUP_AND_SGROUB_NUMBERS == X_X_X)
    APINT_Reg = 0x05FA0000 | 0x400;
#elif (_INT_SET_GROUP_AND_SGROUB_NUMBERS == X_X_Y)
    APINT_Reg = 0x05FA0000 | 0x500;
#elif (_INT_SET_GROUP_AND_SGROUB_NUMBERS == X_Y_Y)
    APINT_Reg = 0x05FA0000 | 0x600;
#elif (_INT_SET_GROUP_AND_SGROUB_NUMBERS == Y_Y_Y)
    APINT_Reg = 0x05FA0000 | 0x700;
#else
    APINT_Reg = 0x05FA0000 | 0x700;
#endif
    u8 IntStop = 0;
    u8 count;
    for (count = 0; count <= 15; count++)
    {

        *PRIx_Reg_Arr[count] |= ((IntCfg_Arr[IntStop + 0].IntGroupPri << (_INT_SET_GROUP_AND_SGROUB_NUMBERS - 1)) << 05) | (IntCfg_Arr[IntStop + 0].IntSubGroupPri << 5);
        *PRIx_Reg_Arr[count] |= ((IntCfg_Arr[IntStop + 1].IntGroupPri << (_INT_SET_GROUP_AND_SGROUB_NUMBERS - 1)) << 13) | (IntCfg_Arr[IntStop + 1].IntSubGroupPri << 13);
        *PRIx_Reg_Arr[count] |= ((IntCfg_Arr[IntStop + 2].IntGroupPri << (_INT_SET_GROUP_AND_SGROUB_NUMBERS - 1)) << 21) | (IntCfg_Arr[IntStop + 2].IntSubGroupPri << 21);
        *PRIx_Reg_Arr[count] |= ((IntCfg_Arr[IntStop + 3].IntGroupPri << (_INT_SET_GROUP_AND_SGROUB_NUMBERS - 1)) << 29) | (IntCfg_Arr[IntStop + 3].IntSubGroupPri << 29);
        IntStop = IntStop + 4;
    }

    SYSPRI1_Reg |= ((FaultsCfg_Arr[Memory_Management_Fault].ExcepGroupPri << (_INT_SET_GROUP_AND_SGROUB_NUMBERS - 1)) << 5) | (FaultsCfg_Arr[Memory_Management_Fault].ExcepSubGroupPri << 5);
    SYSPRI1_Reg |= ((FaultsCfg_Arr[Bus_Fault].ExcepGroupPri << (_INT_SET_GROUP_AND_SGROUB_NUMBERS - 1)) << 13) | (FaultsCfg_Arr[Bus_Fault].ExcepSubGroupPri << 13);
    SYSPRI1_Reg |= ((FaultsCfg_Arr[Usage_Fault].ExcepGroupPri << (_INT_SET_GROUP_AND_SGROUB_NUMBERS - 1)) << 21) | (FaultsCfg_Arr[Usage_Fault].ExcepSubGroupPri << 21);

    SYSPRI2_Reg |= ((FaultsCfg_Arr[SVCall].ExcepGroupPri << (_INT_SET_GROUP_AND_SGROUB_NUMBERS - 1)) << 29) | (FaultsCfg_Arr[SVCall].ExcepSubGroupPri << 29);

    SYSPRI3_Reg |= ((FaultsCfg_Arr[Debug].ExcepGroupPri << (_INT_SET_GROUP_AND_SGROUB_NUMBERS - 1)) << 5) | (FaultsCfg_Arr[Debug].ExcepSubGroupPri << 5);
    SYSPRI3_Reg |= ((FaultsCfg_Arr[PendSV].ExcepGroupPri << (_INT_SET_GROUP_AND_SGROUB_NUMBERS - 1)) << 21) | (FaultsCfg_Arr[PendSV].ExcepSubGroupPri << 21);
    SYSPRI3_Reg |= ((FaultsCfg_Arr[SysTick_Exception].ExcepGroupPri << (_INT_SET_GROUP_AND_SGROUB_NUMBERS - 1)) << 29) | (FaultsCfg_Arr[SysTick_Exception].ExcepSubGroupPri << 29);
    u8 count2;
    for (count2 = 0; count2 <= 138; count2++)
    {

        if (IntCfg_Arr[count2].State != _RESERVED_INT)
        {
            if (count2 < 32)
            {
                if (IntCfg_Arr[count2].State == _ENABLE)
                {
                    *ENx_Reg_Arr[0] |= (1 << count2);
                }
                else
                {
                    *ENx_Reg_Arr[0] &= ~(1 << count2);
                }
            }
            else if (count2 >= 32 && count2 <= 63)
            {
                if (IntCfg_Arr[count2].State == _ENABLE)
                {
                    *ENx_Reg_Arr[1] |= (1 << (count2 - 32));
                }
                else
                {
                    *ENx_Reg_Arr[1] &= ~(1 << (count2 - 32));
                }
            }
            else if (count2 >= 64 && count2 <= 95)
            {
                if (IntCfg_Arr[count2].State == _ENABLE)
                {
                    *ENx_Reg_Arr[2] |= (1 << (count2 - 64));
                }
                else
                {
                    *ENx_Reg_Arr[2] &= ~(1 << (count2 - 64));
                }
            }
            else if (count2 >= 96 && count2 <= 127)
            {
                if (IntCfg_Arr[count2].State == _ENABLE)
                {
                    *ENx_Reg_Arr[3] |= (1 << (count2 - 96));
                }
                else
                {
                    *ENx_Reg_Arr[3] &= ~(1 << (count2 - 96));
                }
            }
            else if (count2 >= 128 && count2 <= 138)
            {
                if (IntCfg_Arr[count2].State == _ENABLE)
                {
                    *ENx_Reg_Arr[4] |= (1 << (count2 - 128));
                }
                else
                {
                    *ENx_Reg_Arr[4] &= ~(1 << (count2 - 128));
                }
            }
        }
    }
}
void IntEnable(IntCtrNum_t Int_Id)
{
    if (Int_Id < 32 )
    {
        EN0_Reg |= (1 << Int_Id);
    }
    else if (Int_Id >= 32 && Int_Id <= 63)
    {
        EN1_Reg |= (1 << (Int_Id - 32));
    }
    else if (Int_Id >= 64 && Int_Id <= 95)
    {
        EN2_Reg |= (1 << (Int_Id - 64));
    }
    else if (Int_Id >= 96 && Int_Id <= 127)
    {
        EN3_Reg |= (1 << (Int_Id - 96));
    }
    else if (Int_Id >= 128 && Int_Id <= 138)
    {
        EN4_Reg |= (1 << (Int_Id - 128));
    }
}

void IntDisable(IntCtrNum_t Int_Id)
{
    if (Int_Id < 32 )
    {
        DIS0_Reg = (1 << Int_Id);
    }
    else if (Int_Id >= 32 && Int_Id <= 63)
    {
        DIS1_Reg = (1 << (Int_Id - 32));
    }
    else if (Int_Id >= 64 && Int_Id <= 95)
    {
        DIS2_Reg = (1 << (Int_Id - 64));
    }
    else if (Int_Id >= 96 && Int_Id <= 127)
    {
        DIS3_Reg = (1 << (Int_Id - 96));
    }
    else if (Int_Id >= 128 && Int_Id <= 138)
    {
        DIS4_Reg = (1 << (Int_Id - 128));
    }
}

/**********************************************************************************************************************
 *  END OF FILE: intCtr.c
 *********************************************************************************************************************/
