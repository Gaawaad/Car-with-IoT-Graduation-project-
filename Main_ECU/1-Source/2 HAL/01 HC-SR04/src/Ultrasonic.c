/*
 * Ultrasonic.c
 *
 *  Created on: Mar 29, 2023
 *      Author: Ahmed Abdel Gawad
 */
#include "Ultrasonic.h"

static void Timer_int(void);
static u32 TimerOfPulse = 0;
static f32 Distance = 0;

void Ultrasonic_Init(void)
{

    GPT0_CaptureMode_Init();
}

f32 Ultrasonic_GetDistance(void)
{
    Dio_WriteChannel(Trig_Port, Trig_Pin, HIGH);
    GPT_delay(GPT_CH_A4, 1); //delay_1ms
    Dio_WriteChannel(Trig_Port, Trig_Pin, LOW);
    TimerOfPulse= GPT0_PulseWidthTime();
    Distance =(TimerOfPulse * 10625)/10000000;
    return Distance;
}

static void Timer_int(void)
{

}
