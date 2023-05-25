/*
 * SCM.h
 *
 *  Created on: May 18, 2023
 *      Author: Ahmed Abdel Gawad
 */

#ifndef SOURCE_3_SERVICES_0_SCM_INC_SCM_H_
#define SOURCE_3_SERVICES_0_SCM_INC_SCM_H_
#include "Std_types.h"
#include "SCM_Cfg.h"
#include "SCM_types.h"
#include "GPT.h"

void SCM_Init(void);
void SCM_CreateTask(u8 Priority, u16 periodicity , void(*TaskCode)(void) );
void SCM_Start(void);
void SCM_timer_Handler(void);

#endif /* 1_SOURCE_3_SERVICES_0_SCM_INC_SCM_H_ */
