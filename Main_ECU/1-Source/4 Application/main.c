#include "SysCtr.h"
#include "GPIO.h"
#include "PORT.h"
#include "intCtr.h"
#include "UART.h"
#include "Dio.h"
#include "Mc_Hw_Reg.h"
#include "PWM.h"
#include <string.h>
u8 ch;
void delay(void)
{
    u32 count = 0;
    for (count = 0; count <= 400000; count++)
    {

    }
}
void call()
{
//    ch = UART_readBuffer(UART1);

}
int main(void)
{

    SysCtr_Init();
    intCtr_init();
    GPIO_Unlock();
    PORT_Init();
    UART_Init();
    UART_SetNotification(UART1, call);
    PWM_Init();
    PWM_Start(M0PWM0);
    u8 count = 0;
    u8 ch = 0;
    UART_SendStr(UART1, "Ready !!! \n\r");
    PWM_Set_Duty(M0PWM0, 0);
    while (1)
    {

        ch = UART_readBuffer(UART1);
        if (ch != 0)
        {
            Dio_ToggleChannel(Dio_PORTF, Dio_Pin2);
            if (ch == 'a')
            {
                count++;
            }

            else if (ch == 'b')
            {
                count--;
            }

            else if (ch == 's')
            {
                count = 0;
            }
            PWM_Set_Duty(M0PWM0, count);
                  UART_SendStr(UART1, "dutycicle = ");
                  UART_SendNum(UART1, count);
                  UART_SendStr(UART1, " \n\r");
        }



    }
}
