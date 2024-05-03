#include <msp430.h>
#include "SYSPARAM.h"
#include "GPIO.h"
#include "TIMERA.h"
#include "PWM.h"

unsigned char u8PinMask1 = 0x00;
unsigned char u8PinMask2 = 0x00;
unsigned char u8PinMask3 = 0x00;
unsigned char u8Test = 0;
unsigned char u8Update = 0;
int main(void)
{
    WDTCTL = WDTPW + WDTHOLD;   // Stop watchdog timer
    volatile unsigned int i;
    _EINT();
    unsigned char u8PinList1[1] = {GREEN_LED_PIN};
    unsigned char u8PinList2[1] = {RED_LED_PIN};
    unsigned char u8PinList3[1] = {BUTTON_PIN};
    GPIO_vPinMaskGenerator(u8PinList1, 1, &u8PinMask1);
    GPIO_vPinMaskGenerator(u8PinList2, 1, &u8PinMask2);
    GPIO_vPinMaskGenerator(u8PinList3, 1, &u8PinMask3);
    PWM_vPWM0ConfigSingle(3000, 150, DIV8, 2, PORT1, MODE_UP, ENABLE);
    //PWM_vPWM1ConfigComplementary(160, 80, 10, DIV1, 1, PORT2, 4, PORT2, DISABLE);
    GPIO_vPort1OutputConfig(u8PinMask1);//Green LED
    GPIO_vPort1OutputConfig(u8PinMask2);//Red LED
    GPIO_vPort1InputConfig(u8PinMask3, ENABLE, PULLUP, ENABLE, HIGH_TO_LOW);

    while(1)
    {
        if(u8Update)
        {
            u8Update = 0;
            switch(u8Test)
            {
            case 0:
                PWM_vPWM0UpdateSingle(100);
            break;
            case 1:
                PWM_vPWM0UpdateSingle(150);
            break;
            case 2:
                PWM_vPWM0UpdateSingle(225);
            break;
            case 3:
                PWM_vPWM0UpdateSingle(300);
            break;
            case 4:
                PWM_vPWM0UpdateSingle(350);
            break;
            }
        }

    }
}

#pragma vector = PORT1_VECTOR;
__interrupt void ISR_Port1(void)
{
   if( (P1IFG & u8PinMask3) == u8PinMask3 )
   {
       //PWM_vPWM1UpdateComplementary(120, 10);
       u8Test++;
       if(u8Test == 5)u8Test = 0;
       u8Update = 1;

   }
   P1IFG &=  ~u8PinMask3;
}

#pragma vector=TIMER0_A1_VECTOR
__interrupt void ISR_TimerA0()
{
    TA0CTL &= 0xFFFE;
    GPIO_vPort1OutputPortToggle(u8PinMask1);

}
/*
#pragma vector=TIMER1_A1_VECTOR
__interrupt void ISR_TimerA1()
{
    TA1CTL &= 0xFFFE;
    GPIO_vPort1OutputPortToggle(u8PinMask2);
}
*/
