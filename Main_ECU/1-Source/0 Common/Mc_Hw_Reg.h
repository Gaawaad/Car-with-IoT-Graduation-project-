/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Mc_Hw_Reg.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef MC_HW_REG
#define MC_HW_REG

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_types.h"
#include "SysCtr_Cfg.h"
#include "WDT_Cfg.h"
#include "GPIO_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define _CORTEXM4_PIRF_BASE_ADD             (0xE000E000)
#define _SYSTEM_CTR_BASE_ADD                (0x400FE000)

#define _APB_GPIO_A_BASE_ADD                (0x40004000)
#define _AHB_GPIO_A_BASE_ADD                (0x40058000)
#define _APB_GPIO_B_BASE_ADD                (0x40005000)
#define _AHB_GPIO_B_BASE_ADD                (0x40059000)
#define _APB_GPIO_C_BASE_ADD                (0x40006000)
#define _AHB_GPIO_C_BASE_ADD                (0x4005A000)
#define _APB_GPIO_D_BASE_ADD                (0x40007000)
#define _AHB_GPIO_D_BASE_ADD                (0x4005B000)
#define _APB_GPIO_E_BASE_ADD                (0x40024000)
#define _AHB_GPIO_E_BASE_ADD                (0x4005C000)
#define _APB_GPIO_F_BASE_ADD                (0x40025000)
#define _AHB_GPIO_F_BASE_ADD                (0x4005D000)
#define _GPIO_DATA_MASK                     (0x3FC)    //use all bits

#define _WDT_1_BASE_ADD                     (0x40000000)
#define _WDT_2_BASE_ADD                     (0x40001000)

#define _TIMER0_16_32_BASE_ADD              (0x40030000)
#define _TIMER1_16_32_BASE_ADD              (0x40031000)
#define _TIMER2_16_32_BASE_ADD              (0x40032000)
#define _TIMER3_16_32_BASE_ADD              (0x40033000)
#define _TIMER4_16_32_BASE_ADD              (0x40034000)
#define _TIMER5_16_32_BASE_ADD              (0x40035000)

#define _TIMER0_32_64_BASE_ADD              (0x4003000)

#define _ADC0_BASE_ADD                      (0x40038000)
#define _ADC1_BASE_ADD                      (0x40039000)

#define _PWM0_BASE_ADD                      (0x40028000)
#define _PWM1_BASE_ADD                      (0x40029000)

#define _UART_0_BASE_ADD                    (0x4000C000)
#define _UART_1_BASE_ADD                    (0x4000D000)
#define _UART_2_BASE_ADD                    (0x4000E000)
#define _UART_3_BASE_ADD                    (0x4000F000)
#define _UART_4_BASE_ADD                    (0x40010000)
#define _UART_5_BASE_ADD                    (0x40011000)
#define _UART_6_BASE_ADD                    (0x40012000)
#define _UART_7_BASE_ADD                    (0x40013000)

#define _I2C_0_BASE_ADD                     (0x40020000)
#define _I2C_1_BASE_ADD                     (0x40021000)
#define _I2C_2_BASE_ADD                     (0x40022000)
#define _I2C_3_BASE_ADD                     (0x40023000)

#define APINT_Reg                           *((volatile u32*)(_CORTEXM4_PIRF_BASE_ADD + 0xD0C))
#define CONTROL_Reg                         *((volatile u32*)(_CORTEXM4_PIRF_BASE_ADD + 0xD04))
#define PRI0_Reg                            *((volatile u32*)(_CORTEXM4_PIRF_BASE_ADD + 0x400))
#define PRI1_Reg                            *((volatile u32*)(_CORTEXM4_PIRF_BASE_ADD + 0x404))
#define PRI2_Reg                            *((volatile u32*)(_CORTEXM4_PIRF_BASE_ADD + 0x408))
#define PRI3_Reg                            *((volatile u32*)(_CORTEXM4_PIRF_BASE_ADD + 0x40C))
#define PRI4_Reg                            *((volatile u32*)(_CORTEXM4_PIRF_BASE_ADD + 0x410))
#define PRI5_Reg                            *((volatile u32*)(_CORTEXM4_PIRF_BASE_ADD + 0x414))
#define PRI6_Reg                            *((volatile u32*)(_CORTEXM4_PIRF_BASE_ADD + 0x418))
#define PRI7_Reg                            *((volatile u32*)(_CORTEXM4_PIRF_BASE_ADD + 0x41C))
#define PRI8_Reg                            *((volatile u32*)(_CORTEXM4_PIRF_BASE_ADD + 0x420))
#define PRI9_Reg                            *((volatile u32*)(_CORTEXM4_PIRF_BASE_ADD + 0x424))
#define PRI10_Reg                           *((volatile u32*)(_CORTEXM4_PIRF_BASE_ADD + 0x428))
#define PRI11_Reg                           *((volatile u32*)(_CORTEXM4_PIRF_BASE_ADD + 0x42C))
#define PRI12_Reg                           *((volatile u32*)(_CORTEXM4_PIRF_BASE_ADD + 0x430))
#define PRI13_Reg                           *((volatile u32*)(_CORTEXM4_PIRF_BASE_ADD + 0x434))
#define PRI14_Reg                           *((volatile u32*)(_CORTEXM4_PIRF_BASE_ADD + 0x438))
#define PRI15_Reg                           *((volatile u32*)(_CORTEXM4_PIRF_BASE_ADD + 0x43C))
#define SYSPRI1_Reg                         *((volatile u32*)(_CORTEXM4_PIRF_BASE_ADD + 0xD18))
#define SYSPRI2_Reg                         *((volatile u32*)(_CORTEXM4_PIRF_BASE_ADD + 0xD1C))
#define SYSPRI3_Reg                         *((volatile u32*)(_CORTEXM4_PIRF_BASE_ADD + 0xD20))
#define EN0_Reg                             *((volatile u32*)(_CORTEXM4_PIRF_BASE_ADD + 0x100))
#define EN1_Reg                             *((volatile u32*)(_CORTEXM4_PIRF_BASE_ADD + 0x104))
#define EN2_Reg                             *((volatile u32*)(_CORTEXM4_PIRF_BASE_ADD + 0x108))
#define EN3_Reg                             *((volatile u32*)(_CORTEXM4_PIRF_BASE_ADD + 0x10C))
#define EN4_Reg                             *((volatile u32*)(_CORTEXM4_PIRF_BASE_ADD + 0x110))
#define DIS0_Reg                            *((volatile u32*)(_CORTEXM4_PIRF_BASE_ADD + 0x180))
#define DIS1_Reg                            *((volatile u32*)(_CORTEXM4_PIRF_BASE_ADD + 0x184))
#define DIS2_Reg                            *((volatile u32*)(_CORTEXM4_PIRF_BASE_ADD + 0x188))
#define DIS3_Reg                            *((volatile u32*)(_CORTEXM4_PIRF_BASE_ADD + 0x18C))
#define DIS4_Reg                            *((volatile u32*)(_CORTEXM4_PIRF_BASE_ADD + 0x190))
#define RCC_Reg                             *((volatile u32*)(_SYSTEM_CTR_BASE_ADD + 0x060))

/*(Clock Gating Registers)*******************************************************/

#define RCGCGPIO_Reg                        *((volatile u32*)(_SYSTEM_CTR_BASE_ADD + 0x608))
#define RCGCWD_Reg                          *((volatile u32*)(_SYSTEM_CTR_BASE_ADD + 0x600))
#define RCGCTIMER_Reg                       *((volatile u32*)(_SYSTEM_CTR_BASE_ADD + 0x604))
#define RCGCPWM_Reg                         *((volatile u32*)(_SYSTEM_CTR_BASE_ADD + 0x640))
#define RCGCUART_REG                        *((volatile u32*)(_SYSTEM_CTR_BASE_ADD + 0x618))
#define RCGCI2C_Reg                         *((volatile u32*)(_SYSTEM_CTR_BASE_ADD + 0x620))

/*(GPIO Ports (AHB,APB) Registers)*******************************************************/
#if(_GPIO_PORT_A_BUS == 1)
#define GPIODEN_A_Reg                       *((volatile u32*)(_AHB_GPIO_A_BASE_ADD + 0x51C))
#define GPIODIR_A_Reg                       *((volatile u32*)(_AHB_GPIO_A_BASE_ADD + 0x400))
#define GPIODATA_A_Reg                      *((volatile u32*)(_AHB_GPIO_A_BASE_ADD + 0x000 + _GPIO_DATA_MASK))
#define GPIOLOCK_A_Reg                      *((volatile u32*)(_AHB_GPIO_A_BASE_ADD + 0x520))
#define GPIOCR_A_Reg                        *((volatile u32*)(_AHB_GPIO_A_BASE_ADD + 0x524))

#define GPIOIM_A_Reg                        *((volatile u32*)(_AHB_GPIO_A_BASE_ADD + 0x410))
#define GPIOICR_A_Reg                       *((volatile u32*)(_AHB_GPIO_A_BASE_ADD + 0x41C))
#define GPIOIEV_A_Reg                       *((volatile u32*)(_AHB_GPIO_A_BASE_ADD + 0x40C))
#define GPIOIBE_A_Reg                       *((volatile u32*)(_AHB_GPIO_A_BASE_ADD + 0x408))
#define GPIORIS_A_Reg                       *((volatile u32*)(_AHB_GPIO_A_BASE_ADD + 0x414))
#define GPIOPDR_A_Reg                       *((volatile u32*)(_AHB_GPIO_A_BASE_ADD + 0x514))
#define GPIOPUR_A_Reg                       *((volatile u32*)(_AHB_GPIO_A_BASE_ADD + 0x510))    
#define GPIOODR_A_Reg                       *((volatile u32*)(_AHB_GPIO_A_BASE_ADD + 0x50C))
#define GPIOAFSEL_A_Reg                     *((volatile u32*)(_AHB_GPIO_A_BASE_ADD + 0x420))
#define GPIOPCTL_A_Reg                      *((volatile u32*)(_AHB_GPIO_A_BASE_ADD + 0x52C))
#else
#define GPIODEN_A_Reg                       *((volatile u32*)(_APB_GPIO_A_BASE_ADD + 0x51C))
#define GPIODIR_A_Reg                       *((volatile u32*)(_APB_GPIO_A_BASE_ADD + 0x400))
#define GPIODATA_A_Reg                      *((volatile u32*)(_APB_GPIO_A_BASE_ADD + 0x000 + _GPIO_DATA_MASK))
#define GPIOLOCK_A_Reg                      *((volatile u32*)(_APB_GPIO_A_BASE_ADD + 0x520))
#define GPIOCR_A_Reg                        *((volatile u32*)(_APB_GPIO_A_BASE_ADD + 0x524))
#define GPIOIS_A_Reg                        *((volatile u32*)(_APB_GPIO_A_BASE_ADD + 0x404))
#define GPIOIBE_A_Reg                       *((volatile u32*)(_APB_GPIO_A_BASE_ADD + 0x408))

#define GPIOIM_A_Reg                        *((volatile u32*)(_APB_GPIO_A_BASE_ADD + 0x410))
#define GPIOICR_A_Reg                       *((volatile u32*)(_APB_GPIO_A_BASE_ADD + 0x41C))
#define GPIOIEV_A_Reg                       *((volatile u32*)(_APB_GPIO_A_BASE_ADD + 0x40C))
#define GPIOIBE_A_Reg                       *((volatile u32*)(_APB_GPIO_A_BASE_ADD + 0x408))
#define GPIORIS_A_Reg                       *((volatile u32*)(_APB_GPIO_A_BASE_ADD + 0x414))
#define GPIOPDR_A_Reg                       *((volatile u32*)(_APB_GPIO_A_BASE_ADD + 0x514))
#define GPIOPUR_A_Reg                       *((volatile u32*)(_APB_GPIO_A_BASE_ADD + 0x510))    
#define GPIOODR_A_Reg                       *((volatile u32*)(_APB_GPIO_A_BASE_ADD + 0x50C))
#define GPIOAFSEL_A_Reg                     *((volatile u32*)(_APB_GPIO_A_BASE_ADD + 0x420))
#define GPIOPCTL_A_Reg                      *((volatile u32*)(_APB_GPIO_A_BASE_ADD + 0x52C))
#endif

#if(_GPIO_PORT_B_BUS == 1)
#define GPIODEN_B_Reg                       *((volatile u32*)(_AHB_GPIO_B_BASE_ADD + 0x51C))
#define GPIODIR_B_Reg                       *((volatile u32*)(_AHB_GPIO_B_BASE_ADD + 0x400))
#define GPIODATA_B_Reg                      *((volatile u32*)(_AHB_GPIO_B_BASE_ADD + 0x000 + _GPIO_DATA_MASK))
#define GPIOLOCK_B_Reg                      *((volatile u32*)(_AHB_GPIO_B_BASE_ADD + 0x520))
#define GPIOCR_B_Reg                        *((volatile u32*)(_AHB_GPIO_B_BASE_ADD + 0x524))

#define GPIOIM_B_Reg                        *((volatile u32*)(_AHB_GPIO_B_BASE_ADD + 0x410))
#define GPIOICR_B_Reg                       *((volatile u32*)(_AHB_GPIO_B_BASE_ADD + 0x41C))
#define GPIOIEV_B_Reg                       *((volatile u32*)(_AHB_GPIO_B_BASE_ADD + 0x40C))
#define GPIOIBE_B_Reg                       *((volatile u32*)(_AHB_GPIO_B_BASE_ADD + 0x408))
#define GPIORIS_B_Reg                       *((volatile u32*)(_AHB_GPIO_B_BASE_ADD + 0x414))
#define GPIOPDR_B_Reg                       *((volatile u32*)(_AHB_GPIO_B_BASE_ADD + 0x514))
#define GPIOPUR_B_Reg                       *((volatile u32*)(_AHB_GPIO_B_BASE_ADD + 0x510))    
#define GPIOODR_B_Reg                       *((volatile u32*)(_AHB_GPIO_B_BASE_ADD + 0x50C))
#define GPIOAFSEL_B_Reg                     *((volatile u32*)(_AHB_GPIO_B_BASE_ADD + 0x420))
#define GPIOPCTL_B_Reg                      *((volatile u32*)(_AHB_GPIO_B_BASE_ADD + 0x52C))
#else
#define GPIODEN_B_Reg                       *((volatile u32*)(_APB_GPIO_B_BASE_ADD + 0x51C))
#define GPIODIR_B_Reg                       *((volatile u32*)(_APB_GPIO_B_BASE_ADD + 0x400))
#define GPIODATA_B_Reg                      *((volatile u32*)(_APB_GPIO_B_BASE_ADD + 0x000 + _GPIO_DATA_MASK))
#define GPIOLOCK_B_Reg                      *((volatile u32*)(_APB_GPIO_B_BASE_ADD + 0x520))
#define GPIOCR_B_Reg                        *((volatile u32*)(_APB_GPIO_B_BASE_ADD + 0x524))

#define GPIOIM_B_Reg                        *((volatile u32*)(_APB_GPIO_B_BASE_ADD + 0x410))
#define GPIOICR_B_Reg                       *((volatile u32*)(_APB_GPIO_B_BASE_ADD + 0x41C))
#define GPIOIEV_B_Reg                       *((volatile u32*)(_APB_GPIO_B_BASE_ADD + 0x40C))
#define GPIOIBE_B_Reg                       *((volatile u32*)(_APB_GPIO_B_BASE_ADD + 0x408))
#define GPIORIS_B_Reg                       *((volatile u32*)(_APB_GPIO_B_BASE_ADD + 0x414))
#define GPIOPDR_B_Reg                       *((volatile u32*)(_APB_GPIO_B_BASE_ADD + 0x514))
#define GPIOPUR_B_Reg                       *((volatile u32*)(_APB_GPIO_B_BASE_ADD + 0x510))    
#define GPIOODR_B_Reg                       *((volatile u32*)(_APB_GPIO_B_BASE_ADD + 0x50C))
#define GPIOAFSEL_B_Reg                     *((volatile u32*)(_APB_GPIO_B_BASE_ADD + 0x420))
#define GPIOPCTL_B_Reg                      *((volatile u32*)(_APB_GPIO_B_BASE_ADD + 0x52C))

#define GPIOAMSEL_B_Reg                     *((volatile u32*)(_APB_GPIO_B_BASE_ADD + 0x528))
#endif

#if(_GPIO_PORT_C_BUS == 1)
#define GPIODEN_C_Reg                       *((volatile u32*)(_AHB_GPIO_C_BASE_ADD + 0x51C))
#define GPIODIR_C_Reg                       *((volatile u32*)(_AHB_GPIO_C_BASE_ADD + 0x400))
#define GPIODATA_C_Reg                      *((volatile u32*)(_AHB_GPIO_C_BASE_ADD + 0x000 + _GPIO_DATA_MASK))
#define GPIOLOCK_C_Reg                      *((volatile u32*)(_AHB_GPIO_C_BASE_ADD + 0x520))
#define GPIOCR_C_Reg                        *((volatile u32*)(_AHB_GPIO_C_BASE_ADD + 0x524))

#define GPIOIM_C_Reg                        *((volatile u32*)(_AHB_GPIO_C_BASE_ADD + 0x410))
#define GPIOICR_C_Reg                       *((volatile u32*)(_AHB_GPIO_C_BASE_ADD + 0x41C))
#define GPIOIEV_C_Reg                       *((volatile u32*)(_AHB_GPIO_C_BASE_ADD + 0x40C))
#define GPIOIBE_C_Reg                       *((volatile u32*)(_AHB_GPIO_C_BASE_ADD + 0x408))
#define GPIORIS_C_Reg                       *((volatile u32*)(_AHB_GPIO_C_BASE_ADD + 0x414))
#define GPIOPDR_C_Reg                       *((volatile u32*)(_AHB_GPIO_C_BASE_ADD + 0x514))
#define GPIOPUR_C_Reg                       *((volatile u32*)(_AHB_GPIO_C_BASE_ADD + 0x510))    
#define GPIOODR_C_Reg                       *((volatile u32*)(_AHB_GPIO_C_BASE_ADD + 0x50C))
#define GPIOAFSEL_C_Reg                     *((volatile u32*)(_AHB_GPIO_C_BASE_ADD + 0x420))
#define GPIOPCTL_C_Reg                      *((volatile u32*)(_AHB_GPIO_C_BASE_ADD + 0x52C))
#else
#define GPIODEN_C_Reg                       *((volatile u32*)(_APB_GPIO_C_BASE_ADD + 0x51C))
#define GPIODIR_C_Reg                       *((volatile u32*)(_APB_GPIO_C_BASE_ADD + 0x400))
#define GPIODATA_C_Reg                      *((volatile u32*)(_APB_GPIO_C_BASE_ADD + 0x000 + _GPIO_DATA_MASK))
#define GPIOLOCK_C_Reg                      *((volatile u32*)(_APB_GPIO_C_BASE_ADD + 0x520))
#define GPIOCR_C_Reg                        *((volatile u32*)(_APB_GPIO_C_BASE_ADD + 0x524))

#define GPIOIM_C_Reg                        *((volatile u32*)(_APB_GPIO_C_BASE_ADD + 0x410))
#define GPIOICR_C_Reg                       *((volatile u32*)(_APB_GPIO_C_BASE_ADD + 0x41C))
#define GPIOIEV_C_Reg                       *((volatile u32*)(_APB_GPIO_C_BASE_ADD + 0x40C))
#define GPIOIBE_C_Reg                       *((volatile u32*)(_APB_GPIO_C_BASE_ADD + 0x408))
#define GPIORIS_C_Reg                       *((volatile u32*)(_APB_GPIO_C_BASE_ADD + 0x414))
#define GPIOPDR_C_Reg                       *((volatile u32*)(_APB_GPIO_C_BASE_ADD + 0x514))
#define GPIOPUR_C_Reg                       *((volatile u32*)(_APB_GPIO_C_BASE_ADD + 0x510))    
#define GPIOODR_C_Reg                       *((volatile u32*)(_APB_GPIO_C_BASE_ADD + 0x50C))
#define GPIOAFSEL_C_Reg                     *((volatile u32*)(_APB_GPIO_C_BASE_ADD + 0x420))
#define GPIOPCTL_C_Reg                      *((volatile u32*)(_APB_GPIO_C_BASE_ADD + 0x52C))
#endif

#if(_GPIO_PORT_D_BUS == 1)
#define GPIODEN_D_Reg                       *((volatile u32*)(_AHB_GPIO_D_BASE_ADD + 0x51C))
#define GPIODIR_D_Reg                       *((volatile u32*)(_AHB_GPIO_D_BASE_ADD + 0x400))
#define GPIODATA_D_Reg                      *((volatile u32*)(_AHB_GPIO_D_BASE_ADD + 0x000 + _GPIO_DATA_MASK))
#define GPIOLOCK_D_Reg                      *((volatile u32*)(_AHB_GPIO_D_BASE_ADD + 0x520))
#define GPIOCR_D_Reg                        *((volatile u32*)(_AHB_GPIO_D_BASE_ADD + 0x524))

#define GPIOIM_D_Reg                        *((volatile u32*)(_AHB_GPIO_D_BASE_ADD + 0x410))
#define GPIOICR_D_Reg                       *((volatile u32*)(_AHB_GPIO_D_BASE_ADD + 0x41C))
#define GPIOIEV_D_Reg                       *((volatile u32*)(_AHB_GPIO_D_BASE_ADD + 0x40C))
#define GPIOIBE_D_Reg                       *((volatile u32*)(_AHB_GPIO_D_BASE_ADD + 0x408))
#define GPIORIS_D_Reg                       *((volatile u32*)(_AHB_GPIO_D_BASE_ADD + 0x414))
#define GPIOPDR_D_Reg                       *((volatile u32*)(_AHB_GPIO_D_BASE_ADD + 0x514))
#define GPIOPUR_D_Reg                       *((volatile u32*)(_AHB_GPIO_D_BASE_ADD + 0x510))    
#define GPIOODR_D_Reg                       *((volatile u32*)(_AHB_GPIO_D_BASE_ADD + 0x50C))
#define GPIOAFSEL_D_Reg                     *((volatile u32*)(_AHB_GPIO_D_BASE_ADD + 0x420))
#define GPIOPCTL_D_Reg                      *((volatile u32*)(_AHB_GPIO_D_BASE_ADD + 0x52C))
#else
#define GPIODEN_D_Reg                       *((volatile u32*)(_APB_GPIO_D_BASE_ADD + 0x51C))
#define GPIODIR_D_Reg                       *((volatile u32*)(_APB_GPIO_D_BASE_ADD + 0x400))
#define GPIODATA_D_Reg                      *((volatile u32*)(_APB_GPIO_D_BASE_ADD + 0x000 + _GPIO_DATA_MASK))
#define GPIOLOCK_D_Reg                      *((volatile u32*)(_APB_GPIO_D_BASE_ADD + 0x520))
#define GPIOCR_D_Reg                        *((volatile u32*)(_APB_GPIO_D_BASE_ADD + 0x524))

#define GPIOIM_D_Reg                        *((volatile u32*)(_APB_GPIO_D_BASE_ADD + 0x410))
#define GPIOICR_D_Reg                       *((volatile u32*)(_APB_GPIO_D_BASE_ADD + 0x41C))
#define GPIOIEV_D_Reg                       *((volatile u32*)(_APB_GPIO_D_BASE_ADD + 0x40C))
#define GPIOIBE_D_Reg                       *((volatile u32*)(_APB_GPIO_D_BASE_ADD + 0x408))
#define GPIORIS_D_Reg                       *((volatile u32*)(_APB_GPIO_D_BASE_ADD + 0x414))
#define GPIOPDR_D_Reg                       *((volatile u32*)(_APB_GPIO_D_BASE_ADD + 0x514))
#define GPIOPUR_D_Reg                       *((volatile u32*)(_APB_GPIO_D_BASE_ADD + 0x510))    
#define GPIOODR_D_Reg                       *((volatile u32*)(_APB_GPIO_D_BASE_ADD + 0x50C))
#define GPIOAFSEL_D_Reg                     *((volatile u32*)(_APB_GPIO_D_BASE_ADD + 0x420))
#define GPIOPCTL_D_Reg                      *((volatile u32*)(_APB_GPIO_D_BASE_ADD + 0x52C))
#endif

#if(_GPIO_PORT_E_BUS == 1)
#define GPIODEN_E_Reg                       *((volatile u32*)(_AHB_GPIO_E_BASE_ADD + 0x51C))
#define GPIODIR_E_Reg                       *((volatile u32*)(_AHB_GPIO_E_BASE_ADD + 0x400))
#define GPIODATA_E_Reg                      *((volatile u32*)(_AHB_GPIO_E_BASE_ADD + 0x000 + _GPIO_DATA_MASK))
#define GPIOLOCK_E_Reg                      *((volatile u32*)(_AHB_GPIO_E_BASE_ADD + 0x520))
#define GPIOCR_E_Reg                        *((volatile u32*)(_AHB_GPIO_E_BASE_ADD + 0x524))

#define GPIOIM_E_Reg                        *((volatile u32*)(_AHB_GPIO_E_BASE_ADD + 0x410))
#define GPIOICR_E_Reg                       *((volatile u32*)(_AHB_GPIO_E_BASE_ADD + 0x41C))
#define GPIOIEV_E_Reg                       *((volatile u32*)(_AHB_GPIO_E_BASE_ADD + 0x40C))
#define GPIOIBE_E_Reg                       *((volatile u32*)(_AHB_GPIO_E_BASE_ADD + 0x408))
#define GPIORIS_E_Reg                       *((volatile u32*)(_AHB_GPIO_E_BASE_ADD + 0x414))
#define GPIOPDR_E_Reg                       *((volatile u32*)(_AHB_GPIO_E_BASE_ADD + 0x514))
#define GPIOPUR_E_Reg                       *((volatile u32*)(_AHB_GPIO_E_BASE_ADD + 0x510))    
#define GPIOODR_E_Reg                       *((volatile u32*)(_AHB_GPIO_E_BASE_ADD + 0x50C))
#define GPIOAFSEL_E_Reg                     *((volatile u32*)(_AHB_GPIO_E_BASE_ADD + 0x420))
#define GPIOPCTL_E_Reg                      *((volatile u32*)(_AHB_GPIO_E_BASE_ADD + 0x52C))
#else
#define GPIODEN_E_Reg                       *((volatile u32*)(_APB_GPIO_E_BASE_ADD + 0x51C))
#define GPIODIR_E_Reg                       *((volatile u32*)(_APB_GPIO_E_BASE_ADD + 0x400))
#define GPIODATA_E_Reg                      *((volatile u32*)(_APB_GPIO_E_BASE_ADD + 0x000 + _GPIO_DATA_MASK))
#define GPIOLOCK_E_Reg                      *((volatile u32*)(_APB_GPIO_E_BASE_ADD + 0x520))
#define GPIOCR_E_Reg                        *((volatile u32*)(_APB_GPIO_E_BASE_ADD + 0x524))

#define GPIOIM_E_Reg                        *((volatile u32*)(_APB_GPIO_E_BASE_ADD + 0x410))
#define GPIOICR_E_Reg                       *((volatile u32*)(_APB_GPIO_E_BASE_ADD + 0x41C))
#define GPIOIEV_E_Reg                       *((volatile u32*)(_APB_GPIO_E_BASE_ADD + 0x40C))
#define GPIOIBE_E_Reg                       *((volatile u32*)(_APB_GPIO_E_BASE_ADD + 0x408))
#define GPIORIS_E_Reg                       *((volatile u32*)(_APB_GPIO_E_BASE_ADD + 0x414))
#define GPIOPDR_E_Reg                       *((volatile u32*)(_APB_GPIO_E_BASE_ADD + 0x514))
#define GPIOPUR_E_Reg                       *((volatile u32*)(_APB_GPIO_E_BASE_ADD + 0x510))    
#define GPIOODR_E_Reg                       *((volatile u32*)(_APB_GPIO_E_BASE_ADD + 0x50C))
#define GPIOAFSEL_E_Reg                     *((volatile u32*)(_APB_GPIO_E_BASE_ADD + 0x420))
#define GPIOPCTL_E_Reg                      *((volatile u32*)(_APB_GPIO_E_BASE_ADD + 0x52C))
#endif

#if(_GPIO_PORT_F_BUS == 1)
#define GPIODEN_F_Reg                       *((volatile u32*)(_AHB_GPIO_F_BASE_ADD + 0x51C))
#define GPIODIR_F_Reg                       *((volatile u32*)(_AHB_GPIO_F_BASE_ADD + 0x400))
#define GPIODATA_F_Reg                      *((volatile u32*)(_AHB_GPIO_F_BASE_ADD + 0x000 + _GPIO_DATA_MASK))
#define GPIOLOCK_F_Reg                      *((volatile u32*)(_AHB_GPIO_F_BASE_ADD + 0x520))
#define GPIOCR_F_Reg                        *((volatile u32*)(_AHB_GPIO_F_BASE_ADD + 0x524))

#define GPIOIM_F_Reg                        *((volatile u32*)(_AHB_GPIO_F_BASE_ADD + 0x410))
#define GPIOICR_F_Reg                       *((volatile u32*)(_AHB_GPIO_F_BASE_ADD + 0x41C))
#define GPIOIEV_F_Reg                       *((volatile u32*)(_AHB_GPIO_F_BASE_ADD + 0x40C))
#define GPIOIBE_F_Reg                       *((volatile u32*)(_AHB_GPIO_F_BASE_ADD + 0x408))
#define GPIORIS_F_Reg                       *((volatile u32*)(_AHB_GPIO_F_BASE_ADD + 0x414))
#define GPIOPDR_F_Reg                       *((volatile u32*)(_AHB_GPIO_F_BASE_ADD + 0x514))
#define GPIOPUR_F_Reg                       *((volatile u32*)(_AHB_GPIO_F_BASE_ADD + 0x510))    
#define GPIOODR_F_Reg                       *((volatile u32*)(_AHB_GPIO_F_BASE_ADD + 0x50C))
#define GPIOAFSEL_F_Reg                     *((volatile u32*)(_AHB_GPIO_F_BASE_ADD + 0x420))
#define GPIOPCTL_F_Reg                      *((volatile u32*)(_AHB_GPIO_F_BASE_ADD + 0x52C))
#else
#define GPIODEN_F_Reg                       *((volatile u32*)(_APB_GPIO_F_BASE_ADD + 0x51C))
#define GPIODIR_F_Reg                       *((volatile u32*)(_APB_GPIO_F_BASE_ADD + 0x400))
#define GPIODATA_F_Reg                      *((volatile u32*)(_APB_GPIO_F_BASE_ADD + 0x000 + _GPIO_DATA_MASK))
#define GPIOLOCK_F_Reg                      *((volatile u32*)(_APB_GPIO_F_BASE_ADD + 0x520))
#define GPIOCR_F_Reg                        *((volatile u32*)(_APB_GPIO_F_BASE_ADD + 0x524))

#define GPIOIM_F_Reg                        *((volatile u32*)(_APB_GPIO_F_BASE_ADD + 0x410))
#define GPIOICR_F_Reg                       *((volatile u32*)(_APB_GPIO_F_BASE_ADD + 0x41C))
#define GPIOIEV_F_Reg                       *((volatile u32*)(_APB_GPIO_F_BASE_ADD + 0x40C))
#define GPIOIBE_F_Reg                       *((volatile u32*)(_APB_GPIO_F_BASE_ADD + 0x408))
#define GPIORIS_F_Reg                       *((volatile u32*)(_APB_GPIO_F_BASE_ADD + 0x414))
#define GPIOPDR_F_Reg                       *((volatile u32*)(_APB_GPIO_F_BASE_ADD + 0x514))
#define GPIOPUR_F_Reg                       *((volatile u32*)(_APB_GPIO_F_BASE_ADD + 0x510))    
#define GPIOODR_F_Reg                       *((volatile u32*)(_APB_GPIO_F_BASE_ADD + 0x50C))
#define GPIOAFSEL_F_Reg                     *((volatile u32*)(_APB_GPIO_F_BASE_ADD + 0x420))
#define GPIOPCTL_F_Reg                      *((volatile u32*)(_APB_GPIO_F_BASE_ADD + 0x52C))
#endif

/*(WDT 1 and 2 Registers)*******************************************************/
#if(_WDT_SELECT_NUMBER == 1)
#define WDTLOAD_Reg                         *((volatile u32*)(_WDT_1_BASE_ADD + 0x000))
#define WDTVALUE_Reg                        *((volatile u32*)(_WDT_1_BASE_ADD + 0x004))
#define WDTCTL_Reg                          *((volatile u32*)(_WDT_1_BASE_ADD + 0x008))

#else
#define WDTLOAD_Reg                         *((volatile u32*)(_WDT_2_BASE_ADD + 0x000))
#define WDTVALUE_Reg                        *((volatile u32*)(_WDT_2_BASE_ADD + 0x004))
#define WDTCTL_Reg                          *((volatile u32*)(_WDT_2_BASE_ADD + 0x008))
#endif
/*(GPT Registers)**************************************************************/
#define GPTMTAMR_0A_Reg                      *((volatile u32*)(_TIMER0_16_32_BASE_ADD + 0x004))
#define GPTMTAMR_1A_Reg                      *((volatile u32*)(_TIMER1_16_32_BASE_ADD + 0x004))
#define GPTMTAMR_2A_Reg                      *((volatile u32*)(_TIMER2_16_32_BASE_ADD + 0x004))
#define GPTMTAMR_3A_Reg                      *((volatile u32*)(_TIMER3_16_32_BASE_ADD + 0x004))
#define GPTMTAMR_4A_Reg                      *((volatile u32*)(_TIMER4_16_32_BASE_ADD + 0x004))
#define GPTMTAMR_5A_Reg                      *((volatile u32*)(_TIMER5_16_32_BASE_ADD + 0x004))

#define GPTMCFG_0A_Reg                       *((volatile u32*)(_TIMER0_16_32_BASE_ADD + 0x000))
#define GPTMCFG_1A_Reg                       *((volatile u32*)(_TIMER1_16_32_BASE_ADD + 0x000))
#define GPTMCFG_2A_Reg                       *((volatile u32*)(_TIMER2_16_32_BASE_ADD + 0x000))
#define GPTMCFG_3A_Reg                       *((volatile u32*)(_TIMER3_16_32_BASE_ADD + 0x000))
#define GPTMCFG_4A_Reg                       *((volatile u32*)(_TIMER4_16_32_BASE_ADD + 0x000))
#define GPTMCFG_5A_Reg                       *((volatile u32*)(_TIMER5_16_32_BASE_ADD + 0x000))

#define GPTMCTL_0A_Reg                       *((volatile u32*)(_TIMER0_16_32_BASE_ADD + 0x00C))
#define GPTMCTL_1A_Reg                       *((volatile u32*)(_TIMER1_16_32_BASE_ADD + 0x00C))
#define GPTMCTL_2A_Reg                       *((volatile u32*)(_TIMER2_16_32_BASE_ADD + 0x00C))
#define GPTMCTL_3A_Reg                       *((volatile u32*)(_TIMER3_16_32_BASE_ADD + 0x00C))
#define GPTMCTL_4A_Reg                       *((volatile u32*)(_TIMER4_16_32_BASE_ADD + 0x00C))
#define GPTMCTL_5A_Reg                       *((volatile u32*)(_TIMER5_16_32_BASE_ADD + 0x00C))

#define GPTMIMR_0A_Reg                       *((volatile u32*)(_TIMER0_16_32_BASE_ADD + 0x018))
#define GPTMIMR_1A_Reg                       *((volatile u32*)(_TIMER1_16_32_BASE_ADD + 0x018))
#define GPTMIMR_2A_Reg                       *((volatile u32*)(_TIMER2_16_32_BASE_ADD + 0x018))
#define GPTMIMR_3A_Reg                       *((volatile u32*)(_TIMER3_16_32_BASE_ADD + 0x018))
#define GPTMIMR_4A_Reg                       *((volatile u32*)(_TIMER4_16_32_BASE_ADD + 0x018))
#define GPTMIMR_5A_Reg                       *((volatile u32*)(_TIMER5_16_32_BASE_ADD + 0x018))

#define GPTMTAV_0A_Reg                       *((volatile u32*)(_TIMER0_16_32_BASE_ADD + 0x050))
#define GPTMTAV_1A_Reg                       *((volatile u32*)(_TIMER1_16_32_BASE_ADD + 0x050))
#define GPTMTAV_2A_Reg                       *((volatile u32*)(_TIMER2_16_32_BASE_ADD + 0x050))
#define GPTMTAV_3A_Reg                       *((volatile u32*)(_TIMER3_16_32_BASE_ADD + 0x050))
#define GPTMTAV_4A_Reg                       *((volatile u32*)(_TIMER4_16_32_BASE_ADD + 0x050))
#define GPTMTAV_5A_Reg                       *((volatile u32*)(_TIMER5_16_32_BASE_ADD + 0x050))

#define GPTMTAILR_0A_Reg                     *((volatile u32*)(_TIMER0_16_32_BASE_ADD + 0x028))
#define GPTMTAILR_1A_Reg                     *((volatile u32*)(_TIMER1_16_32_BASE_ADD + 0x028))
#define GPTMTAILR_2A_Reg                     *((volatile u32*)(_TIMER2_16_32_BASE_ADD + 0x028))
#define GPTMTAILR_3A_Reg                     *((volatile u32*)(_TIMER3_16_32_BASE_ADD + 0x028))
#define GPTMTAILR_4A_Reg                     *((volatile u32*)(_TIMER4_16_32_BASE_ADD + 0x028))
#define GPTMTAILR_5A_Reg                     *((volatile u32*)(_TIMER5_16_32_BASE_ADD + 0x028))

#define GPTMICR_0A_Reg                       *((volatile u32*)(_TIMER0_16_32_BASE_ADD + 0x024))
#define GPTMICR_1A_Reg                       *((volatile u32*)(_TIMER1_16_32_BASE_ADD + 0x024))
#define GPTMICR_2A_Reg                       *((volatile u32*)(_TIMER2_16_32_BASE_ADD + 0x024))
#define GPTMICR_3A_Reg                       *((volatile u32*)(_TIMER3_16_32_BASE_ADD + 0x024))
#define GPTMICR_4A_Reg                       *((volatile u32*)(_TIMER4_16_32_BASE_ADD + 0x024))
#define GPTMICR_5A_Reg                       *((volatile u32*)(_TIMER5_16_32_BASE_ADD + 0x024))

#define GPTMTAPR_0A_Reg                      *((volatile u32*)(_TIMER0_16_32_BASE_ADD + 0x038))
#define GPTMTAPR_1A_Reg                      *((volatile u32*)(_TIMER1_16_32_BASE_ADD + 0x038))
#define GPTMTAPR_2A_Reg                      *((volatile u32*)(_TIMER2_16_32_BASE_ADD + 0x038))
#define GPTMTAPR_3A_Reg                      *((volatile u32*)(_TIMER3_16_32_BASE_ADD + 0x038))
#define GPTMTAPR_4A_Reg                      *((volatile u32*)(_TIMER4_16_32_BASE_ADD + 0x038))
#define GPTMTAPR_5A_Reg                      *((volatile u32*)(_TIMER5_16_32_BASE_ADD + 0x038))

#define GPTMRIS_0A_Reg                       *((volatile u32*)(_TIMER0_16_32_BASE_ADD + 0x01C))
#define GPTMRIS_1A_Reg                       *((volatile u32*)(_TIMER1_16_32_BASE_ADD + 0x01C))
#define GPTMRIS_2A_Reg                       *((volatile u32*)(_TIMER2_16_32_BASE_ADD + 0x01C))
#define GPTMRIS_3A_Reg                       *((volatile u32*)(_TIMER3_16_32_BASE_ADD + 0x01C))
#define GPTMRIS_4A_Reg                       *((volatile u32*)(_TIMER4_16_32_BASE_ADD + 0x01C))
#define GPTMRIS_5A_Reg                       *((volatile u32*)(_TIMER5_16_32_BASE_ADD + 0x01C))

#define GPTMTAR_0A_Reg                       *((volatile u32*)(_TIMER0_16_32_BASE_ADD + 0x048))
#define GPTMTAR_1A_Reg                       *((volatile u32*)(_TIMER1_16_32_BASE_ADD + 0x048))
#define GPTMTAR_2A_Reg                       *((volatile u32*)(_TIMER2_16_32_BASE_ADD + 0x048))
#define GPTMTAR_3A_Reg                       *((volatile u32*)(_TIMER3_16_32_BASE_ADD + 0x048))
#define GPTMTAR_4A_Reg                       *((volatile u32*)(_TIMER4_16_32_BASE_ADD + 0x048))
#define GPTMTAR_5A_Reg                       *((volatile u32*)(_TIMER5_16_32_BASE_ADD + 0x048))

/*(ADC Registers)**************************************************************/

#define ADCACTSS_ADC0_Rrg                    *((volatile u32*)(_ADC0_BASE_ADD + 0x000))
#define ADCACTSS_ADC1_Rrg                    *((volatile u32*)(_ADC1_BASE_ADD + 0x000))

/*(PWM Registers)**************************************************************/

#define PWM0CTL_M0_Reg                       *((volatile u32*)(_PWM0_BASE_ADD + 0x040))
#define PWM1CTL_M0_Reg                       *((volatile u32*)(_PWM0_BASE_ADD + 0x080))
#define PWM2CTL_M0_Reg                       *((volatile u32*)(_PWM0_BASE_ADD + 0x0C0))
#define PWM3CTL_M0_Reg                       *((volatile u32*)(_PWM0_BASE_ADD + 0x100))

#define PWM0LOAD_M0_Reg                      *((volatile u32*)(_PWM0_BASE_ADD + 0x050))
#define PWM1LOAD_M0_Reg                      *((volatile u32*)(_PWM0_BASE_ADD + 0x090))
#define PWM2LOAD_M0_Reg                      *((volatile u32*)(_PWM0_BASE_ADD + 0x0D0))
#define PWM3LOAD_M0_Reg                      *((volatile u32*)(_PWM0_BASE_ADD + 0x110))

#define PWM0CMPA_M0_Reg                      *((volatile u32*)(_PWM0_BASE_ADD + 0x058))
#define PWM1CMPA_M0_Reg                      *((volatile u32*)(_PWM0_BASE_ADD + 0x098))
#define PWM2CMPA_M0_Reg                      *((volatile u32*)(_PWM0_BASE_ADD + 0x0D8))
#define PWM3CMPA_M0_Reg                      *((volatile u32*)(_PWM0_BASE_ADD + 0x118))

#define PWM0GENA_M0_Reg                      *((volatile u32*)(_PWM0_BASE_ADD + 0x060))
#define PWM1GENA_M0_Reg                      *((volatile u32*)(_PWM0_BASE_ADD + 0x0A0))
#define PWM2GENA_M0_Reg                      *((volatile u32*)(_PWM0_BASE_ADD + 0x0E0))
#define PWM3GENA_M0_Reg                      *((volatile u32*)(_PWM0_BASE_ADD + 0x120))

#define PWMENABLE_M0_Reg                     *((volatile u32*)(_PWM0_BASE_ADD + 0x008))

#define PWM0CTL_M1_Reg                       *((volatile u32*)(_PWM1_BASE_ADD + 0x040))
#define PWM1CTL_M1_Reg                       *((volatile u32*)(_PWM1_BASE_ADD + 0x080))
#define PWM2CTL_M1_Reg                       *((volatile u32*)(_PWM1_BASE_ADD + 0x0C0))
#define PWM3CTL_M1_Reg                       *((volatile u32*)(_PWM1_BASE_ADD + 0x100))

#define PWM0LOAD_M1_Reg                      *((volatile u32*)(_PWM1_BASE_ADD + 0x050))
#define PWM1LOAD_M1_Reg                      *((volatile u32*)(_PWM1_BASE_ADD + 0x090))
#define PWM2LOAD_M1_Reg                      *((volatile u32*)(_PWM1_BASE_ADD + 0x0D0))
#define PWM3LOAD_M1_Reg                      *((volatile u32*)(_PWM1_BASE_ADD + 0x110))

#define PWM0CMPA_M1_Reg                      *((volatile u32*)(_PWM1_BASE_ADD + 0x058))
#define PWM1CMPA_M1_Reg                      *((volatile u32*)(_PWM1_BASE_ADD + 0x098))
#define PWM2CMPA_M1_Reg                      *((volatile u32*)(_PWM1_BASE_ADD + 0x0D8))
#define PWM3CMPA_M1_Reg                      *((volatile u32*)(_PWM1_BASE_ADD + 0x118))

#define PWM0GENA_M1_Reg                      *((volatile u32*)(_PWM1_BASE_ADD + 0x060))
#define PWM1GENA_M1_Reg                      *((volatile u32*)(_PWM1_BASE_ADD + 0x0A0))
#define PWM2GENA_M1_Reg                      *((volatile u32*)(_PWM1_BASE_ADD + 0x0E0))
#define PWM3GENA_M1_Reg                      *((volatile u32*)(_PWM1_BASE_ADD + 0x120))

#define PWMENABLE_M1_Reg                     *((volatile u32*)(_PWM1_BASE_ADD + 0x008))

/*(UART Registers)**************************************************************/

#define UART_0_CTL_Reg                       *((volatile u32*)(_UART_0_BASE_ADD + 0x030))
#define UART_1_CTL_Reg                       *((volatile u32*)(_UART_1_BASE_ADD + 0x030))
#define UART_2_CTL_Reg                       *((volatile u32*)(_UART_2_BASE_ADD + 0x030))
#define UART_3_CTL_Reg                       *((volatile u32*)(_UART_3_BASE_ADD + 0x030))
#define UART_4_CTL_Reg                       *((volatile u32*)(_UART_4_BASE_ADD + 0x030))
#define UART_5_CTL_Reg                       *((volatile u32*)(_UART_5_BASE_ADD + 0x030))
#define UART_6_CTL_Reg                       *((volatile u32*)(_UART_6_BASE_ADD + 0x030))
#define UART_7_CTL_Reg                       *((volatile u32*)(_UART_7_BASE_ADD + 0x030))

#define UART_0_IBRD_Reg                      *((volatile u32*)(_UART_0_BASE_ADD + 0x024))
#define UART_1_IBRD_Reg                      *((volatile u32*)(_UART_1_BASE_ADD + 0x024))
#define UART_2_IBRD_Reg                      *((volatile u32*)(_UART_2_BASE_ADD + 0x024))
#define UART_3_IBRD_Reg                      *((volatile u32*)(_UART_3_BASE_ADD + 0x024))
#define UART_4_IBRD_Reg                      *((volatile u32*)(_UART_4_BASE_ADD + 0x024))
#define UART_5_IBRD_Reg                      *((volatile u32*)(_UART_5_BASE_ADD + 0x024))
#define UART_6_IBRD_Reg                      *((volatile u32*)(_UART_6_BASE_ADD + 0x024))
#define UART_7_IBRD_Reg                      *((volatile u32*)(_UART_7_BASE_ADD + 0x024))

#define UART_0_FBRD_Reg                      *((volatile u32*)(_UART_0_BASE_ADD + 0x028))
#define UART_1_FBRD_Reg                      *((volatile u32*)(_UART_1_BASE_ADD + 0x028))
#define UART_2_FBRD_Reg                      *((volatile u32*)(_UART_2_BASE_ADD + 0x028))
#define UART_3_FBRD_Reg                      *((volatile u32*)(_UART_3_BASE_ADD + 0x028))
#define UART_4_FBRD_Reg                      *((volatile u32*)(_UART_4_BASE_ADD + 0x028))
#define UART_5_FBRD_Reg                      *((volatile u32*)(_UART_5_BASE_ADD + 0x028))
#define UART_6_FBRD_Reg                      *((volatile u32*)(_UART_6_BASE_ADD + 0x028))
#define UART_7_FBRD_Reg                      *((volatile u32*)(_UART_7_BASE_ADD + 0x028))

#define UART_0_FR_Reg                        *((volatile u32*)(_UART_0_BASE_ADD + 0x018))
#define UART_1_FR_Reg                        *((volatile u32*)(_UART_1_BASE_ADD + 0x018))
#define UART_2_FR_Reg                        *((volatile u32*)(_UART_2_BASE_ADD + 0x018))
#define UART_3_FR_Reg                        *((volatile u32*)(_UART_3_BASE_ADD + 0x018))
#define UART_4_FR_Reg                        *((volatile u32*)(_UART_4_BASE_ADD + 0x018))
#define UART_5_FR_Reg                        *((volatile u32*)(_UART_5_BASE_ADD + 0x018))
#define UART_6_FR_Reg                        *((volatile u32*)(_UART_6_BASE_ADD + 0x018))
#define UART_7_FR_Reg                        *((volatile u32*)(_UART_7_BASE_ADD + 0x018))

#define UART_0_DR_Reg                        *((volatile u32*)(_UART_0_BASE_ADD + 0x000))
#define UART_1_DR_Reg                        *((volatile u32*)(_UART_1_BASE_ADD + 0x000))
#define UART_2_DR_Reg                        *((volatile u32*)(_UART_2_BASE_ADD + 0x000))
#define UART_3_DR_Reg                        *((volatile u32*)(_UART_3_BASE_ADD + 0x000))
#define UART_4_DR_Reg                        *((volatile u32*)(_UART_4_BASE_ADD + 0x000))
#define UART_5_DR_Reg                        *((volatile u32*)(_UART_5_BASE_ADD + 0x000))
#define UART_6_DR_Reg                        *((volatile u32*)(_UART_6_BASE_ADD + 0x000))
#define UART_7_DR_Reg                        *((volatile u32*)(_UART_7_BASE_ADD + 0x000))

#define UART_0_LCRH_Reg                      *((volatile u32*)(_UART_0_BASE_ADD + 0x02C))
#define UART_1_LCRH_Reg                      *((volatile u32*)(_UART_1_BASE_ADD + 0x02C))
#define UART_2_LCRH_Reg                      *((volatile u32*)(_UART_2_BASE_ADD + 0x02C))
#define UART_3_LCRH_Reg                      *((volatile u32*)(_UART_3_BASE_ADD + 0x02C))
#define UART_4_LCRH_Reg                      *((volatile u32*)(_UART_4_BASE_ADD + 0x02C))
#define UART_5_LCRH_Reg                      *((volatile u32*)(_UART_5_BASE_ADD + 0x02C))
#define UART_6_LCRH_Reg                      *((volatile u32*)(_UART_6_BASE_ADD + 0x02C))
#define UART_7_LCRH_Reg                      *((volatile u32*)(_UART_7_BASE_ADD + 0x02C))

#define UART_0_CC_Reg                        *((volatile u32*)(_UART_0_BASE_ADD + 0xFC8))
#define UART_1_CC_Reg                        *((volatile u32*)(_UART_1_BASE_ADD + 0xFC8))
#define UART_2_CC_Reg                        *((volatile u32*)(_UART_2_BASE_ADD + 0xFC8))
#define UART_3_CC_Reg                        *((volatile u32*)(_UART_3_BASE_ADD + 0xFC8))
#define UART_4_CC_Reg                        *((volatile u32*)(_UART_4_BASE_ADD + 0xFC8))
#define UART_5_CC_Reg                        *((volatile u32*)(_UART_5_BASE_ADD + 0xFC8))
#define UART_6_CC_Reg                        *((volatile u32*)(_UART_6_BASE_ADD + 0xFC8))
#define UART_7_CC_Reg                        *((volatile u32*)(_UART_7_BASE_ADD + 0xFC8))

#define UART_0_IM_Reg                        *((volatile u32*)(_UART_0_BASE_ADD + 0x038))
#define UART_1_IM_Reg                        *((volatile u32*)(_UART_1_BASE_ADD + 0x038))
#define UART_2_IM_Reg                        *((volatile u32*)(_UART_2_BASE_ADD + 0x038))
#define UART_3_IM_Reg                        *((volatile u32*)(_UART_3_BASE_ADD + 0x038))
#define UART_4_IM_Reg                        *((volatile u32*)(_UART_4_BASE_ADD + 0x038))
#define UART_5_IM_Reg                        *((volatile u32*)(_UART_5_BASE_ADD + 0x038))
#define UART_6_IM_Reg                        *((volatile u32*)(_UART_6_BASE_ADD + 0x038))
#define UART_7_IM_Reg                        *((volatile u32*)(_UART_7_BASE_ADD + 0x038))


/*(I2C Registers)**************************************************************/

#define I2CMCR_0_Reg                        *((volatile u32*)(_I2C_0_BASE_ADD + 0x020))
#define I2CMCR_1_Reg                        *((volatile u32*)(_I2C_1_BASE_ADD + 0x020))
#define I2CMCR_2_Reg                        *((volatile u32*)(_I2C_2_BASE_ADD + 0x020))
#define I2CMCR_3_Reg                        *((volatile u32*)(_I2C_3_BASE_ADD + 0x020))

#define I2CMTPR_0_Reg                       *((volatile u32*)(_I2C_0_BASE_ADD + 0x00C))
#define I2CMTPR_1_Reg                       *((volatile u32*)(_I2C_1_BASE_ADD + 0x00C))
#define I2CMTPR_2_Reg                       *((volatile u32*)(_I2C_2_BASE_ADD + 0x00C))
#define I2CMTPR_3_Reg                       *((volatile u32*)(_I2C_3_BASE_ADD + 0x00C))

#define I2CMSA_0_Reg                        *((volatile u32*)(_I2C_0_BASE_ADD + 0x000))
#define I2CMSA_1_Reg                        *((volatile u32*)(_I2C_1_BASE_ADD + 0x000))
#define I2CMSA_2_Reg                        *((volatile u32*)(_I2C_2_BASE_ADD + 0x000))
#define I2CMSA_3_Reg                        *((volatile u32*)(_I2C_3_BASE_ADD + 0x000))

#define I2CMDR_0_Reg                        *((volatile u32*)(_I2C_0_BASE_ADD + 0x008))
#define I2CMDR_1_Reg                        *((volatile u32*)(_I2C_1_BASE_ADD + 0x008))
#define I2CMDR_2_Reg                        *((volatile u32*)(_I2C_2_BASE_ADD + 0x008))
#define I2CMDR_3_Reg                        *((volatile u32*)(_I2C_3_BASE_ADD + 0x008))

#define I2CMCS_0_Reg                        *((volatile u32*)(_I2C_0_BASE_ADD + 0x004))
#define I2CMCS_1_Reg                        *((volatile u32*)(_I2C_1_BASE_ADD + 0x004))
#define I2CMCS_2_Reg                        *((volatile u32*)(_I2C_2_BASE_ADD + 0x004))
#define I2CMCS_3_Reg                        *((volatile u32*)(_I2C_3_BASE_ADD + 0x004))

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

#endif  /* MC_HW_REG */

/**********************************************************************************************************************
 *  END OF FILE: Mc_Hw_Reg.h
 *********************************************************************************************************************/
