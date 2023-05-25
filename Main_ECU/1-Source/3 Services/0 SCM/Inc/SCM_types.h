/*
 * SCM_types.h
 *
 *  Created on: May 18, 2023
 *      Author: Ahmed Abdel Gawad
 */

#ifndef SOURCE_3_SERVICES_0_SCM_INC_SCM_TYPES_H_
#define SOURCE_3_SERVICES_0_SCM_INC_SCM_TYPES_H_


typedef struct{
    u16 periodicity;
    void(*TaskCode)(void);
}Task_t;


#endif /* 1_SOURCE_3_SERVICES_0_SCM_INC_SCM_TYPES_H_ */
