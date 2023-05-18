/*
 * Ultrasonic.h
 *
 *  Created on: Mar 29, 2023
 *      Author: Ahmed Abdel Gawad
 */

#ifndef OURCE_2_HAL_01_HC_SR04_INC_ULTRASONIC_H_
#define OURCE_2_HAL_01_HC_SR04_INC_ULTRASONIC_H_

#include "Ultrasonic_cfg.h"
#include "GPT.h"
#include "Dio.h"
void Ultrasonic_Init(void);
f32 Ultrasonic_GetDistance(void);


#endif /* 1_SOURCE_2_HAL_01_HC_SR04_INC_ULTRASONIC_H_ */
