#include "GPT.h"
#include "Dio.h"
#include "PWM.h"
#include "GPIO.h"
#include "PORT.h"
#include "UART.h"
#include "intCtr.h"
#include "SysCtr.h"
#include "MotorDriver.h"
#define SlowRitio 0.8
void uart1_int(void);
void timer1_int(void);
void timer2_int(void);
void timer3_int(void);

u8 ReceivedByte = 99;
Level_t Conn_State = LOW;
MotorDirection_t LastDirction = STOP;
u8 Speed=99;
u8 RatioSpeed=89;
int main(void)
{
    SysCtr_Init();
    intCtr_init();
    GPIO_Unlock();
    GPIO_Init();
    PORT_Init();
    UART_Init();
    MotorDriver_Init();
    MotorDriver_Move(STOP);
    MotoDriver_Speed(Speed);
    RatioSpeed = Speed-(Speed * SlowRitio);
    UART_SetNotification(UART1, uart1_int);
    Gpt_Init(GPT_CH_A1, timer1_int);
    Gpt_Init(GPT_CH_A2, timer2_int);
    Gpt_Init(GPT_CH_A3, timer3_int);
    GPT_StartTimer(GPT_CH_A1);
    GPT_StartTimer(GPT_CH_A2);

    while (1)
    {
    }
}

void uart1_int(void)
{
    ReceivedByte = UART_readBuffer(UART1);
    if (ReceivedByte != 0)
    {
        switch (ReceivedByte)
        {
        case 2:
          //  MotorDriver_Move(FOREWORD);
            MotorDriver_RightSpeed(RatioSpeed);
            UART_SendChr(UART1, 111);
            break;
        case 4:
          //  MotorDriver_Move(BACKWORD);
            MotorDriver_LeftSpeed(RatioSpeed);
            UART_SendChr(UART1, 111);
            break;
        case 1:
            MotorDriver_Move(LEFT);
            UART_SendChr(UART1, 111);
            LastDirction = LEFT;
            break;
        case 3:
            MotorDriver_Move(RIGHT);
            UART_SendChr(UART1, 111);
            LastDirction = RIGHT;
            break;
        case 5:
            MotorDriver_Move(STOP);
            UART_SendChr(UART1, 112);
            LastDirction = STOP;
            break;
        case 6 :
            MotoDriver_Speed(Speed);
            MotorDriver_Move(LastDirction);
            break;
        case 'n':
            Conn_State = HIGH;
            GPT_RestTimer(GPT_CH_A1);
            break;
        default:
            break;
        }
        if (ReceivedByte < 100 && ReceivedByte > 9)
        {
            MotoDriver_Speed(ReceivedByte);  // Remember decrease by 4 :)
            Speed = ReceivedByte;
            RatioSpeed = Speed-(Speed * SlowRitio);
            if (ReceivedByte == 99 || ReceivedByte == 10)
            {
                UART_SendChr(UART1, 113);
                GPT_StartTimer(GPT_CH_A3); //on led
            }

        }
    }
}

void timer1_int(void)
{
    u32 time = GPT_GetTime(GPT_CH_A1);
    if (time >= 2500)
    {
        MotorDriver_Move(STOP);
        Conn_State = LOW;
        GPT_RestTimer(GPT_CH_A1);
    }
}

void timer2_int(void)
{
    u32 time = GPT_GetTime(GPT_CH_A2);
    if (time >= 100)
    {
        Dio_WriteChannel(Dio_PORTF, Dio_Pin2, Conn_State);
        GPT_RestTimer(GPT_CH_A2);
    }
}

void timer3_int(void)
{
    u32 time = GPT_GetTime(GPT_CH_A3);
    if (time >= 1000)
    {
        UART_SendChr(UART1, 114);
        GPT_StopTimer(GPT_CH_A3);
    }
}
