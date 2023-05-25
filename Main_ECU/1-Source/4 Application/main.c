#include "SCM.h"
#include "Dio.h"
#include "GPIO.h"
#include "PORT.h"
#include "UART.h"
#include "intCtr.h"
#include "SysCtr.h"
#include "MotorDriver.h"

#define SlowRitio 0.1

void uart1_int(void);
void Task1_Stop_DisConnect(void);
void Task2_ConnState_LED(void);
void Task3_Remote_LED(void);
void System_Init(void);

u8 ReceivedByte = 99;
Level_t Conn_State = LOW;
MotorDirection_t LastDirction = STOP;
u8 Speed = 99;
u8 RatioSpeed = 89;
boolen LED_Flag = FALSE;

int main(void)
{
    System_Init();

    MotorDriver_Move(STOP);
    MotoDriver_Speed(Speed);
    RatioSpeed = Speed - (Speed * SlowRitio);
    UART_SetNotification(UART1, uart1_int);

    SCM_CreateTask(0, 4000, Task1_Stop_DisConnect);
    SCM_CreateTask(1, 100, Task2_ConnState_LED);
    SCM_CreateTask(2, 1000, Task3_Remote_LED);

    SCM_Start();

    while (1)
    {
    }
}

void System_Init(void)
{
    SysCtr_Init();
    intCtr_init();
    GPIO_Unlock();
    GPIO_Init();
    PORT_Init();
    UART_Init();
    MotorDriver_Init();
    SCM_Init();
}

void Task1_Stop_DisConnect(void)
{
    if (!Conn_State)
    {
        MotorDriver_Move(STOP);
    }
    Conn_State = LOW;
}

void Task2_ConnState_LED(void)
{
    Dio_WriteChannel(Dio_PORTF, Dio_Pin2, Conn_State);
}

void Task3_Remote_LED(void)
{
    if (LED_Flag)
    {
        UART_SendChr(UART1, 114);
        LED_Flag = FALSE;
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
        case 6:
            MotoDriver_Speed(Speed);
            MotorDriver_Move(LastDirction);
            break;
        case 'n':
            Conn_State = HIGH;
            break;
        default:
            break;
        }
        if (ReceivedByte < 100 && ReceivedByte > 9)
        {
            MotoDriver_Speed(ReceivedByte);  // Remember decrease by 4 :)
            Speed = ReceivedByte;
            RatioSpeed = Speed - (Speed * SlowRitio);
            if (ReceivedByte == 99 || ReceivedByte == 10)
            {
                UART_SendChr(UART1, 113);
                LED_Flag = TRUE;  //on led
            }
        }
    }
}
