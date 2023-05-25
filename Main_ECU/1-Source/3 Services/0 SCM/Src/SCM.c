/*
 * SCM.c
 *
 *  Created on: May 18, 2023
 *      Author: Ahmed Abdel Gawad
 */
#include "SCM.h"

Task_t SCM_Tasks_Arr[MAX_TASKS_COUNT];
u32 SCM_tick=0;


void SCM_Init(void){
    Gpt_Init(USED_TIMER, SCM_timer_Handler);
}


void SCM_CreateTask(u8 Priority, u16 periodicity ,void(*TaskCode)(void) ){
    SCM_Tasks_Arr[Priority].periodicity=periodicity;
    SCM_Tasks_Arr[Priority].TaskCode=TaskCode;
}


void SCM_Start(void){
GPT_StartTimer(USED_TIMER);
}


static void SCM_Handler(void){
    u16 count;
for( count=0;count<MAX_TASKS_COUNT;count++){
    if(SCM_tick % SCM_Tasks_Arr[count].periodicity==0){
        SCM_Tasks_Arr[count].TaskCode();
    }
}
}


 void SCM_timer_Handler(void){
    SCM_tick++;
    SCM_Handler();
    GPT_RestTimer(USED_TIMER);

}
