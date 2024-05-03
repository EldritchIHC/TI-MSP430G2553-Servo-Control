/*
 * TIMERA.c
 *
 *  Created on: 20 apr. 2024
 *      Author: Paul
 */

/* Project Headers */

/* System Headers*/
#include <msp430.h>
#include "SYSPARAM.h"
/* Own Headers */
#include "TIMERA.h"

/* External Headers */

/* Function Prototypes */
void TIMERA_vTimer0Config(unsigned char u8ClockSource, unsigned char u8CountMode, unsigned char u8Divider, unsigned char u8InterruptEnable);
void TIMERA_vTimer0Compare0Config(unsigned int u16CompareValue, unsigned char u8CaptureMode, unsigned char u8InputSelect, unsigned char u8Synchronized, unsigned char u8OutMode, unsigned char u8InterruptEnable);
void TIMERA_vTimer0Compare0ValueUpdate(unsigned int u16CompareValue);
void TIMERA_vTimer0Compare1Config(unsigned int u16CompareValue, unsigned char u8CaptureMode, unsigned char u8InputSelect, unsigned char u8Synchronized, unsigned char u8OutMode, unsigned char u8InterruptEnable);
void TIMERA_vTimer0Compare1ValueUpdate(unsigned int u16CompareValue);
void TIMERA_vTimer0Compare2Config(unsigned int u16CompareValue, unsigned char u8CaptureMode, unsigned char u8InputSelect, unsigned char u8Synchronized, unsigned char u8OutMode, unsigned char u8InterruptEnable);
void TIMERA_vTimer0Compare2ValueUpdate(unsigned int u16CompareValue);
/*Timer0 Interrupt Template*/
/*
#pragma vector=TIMER0_A1_VECTOR
__interrupt void ISR_TimerA0()
{

}
*/
/*Timer1*/
void TIMERA_vTimer1Config(unsigned char u8ClockSource, unsigned char u8CountMode, unsigned char u8Divider, unsigned char u8InterruptEnable);
void TIMERA_vTimer1Compare0Config(unsigned int u16CompareValue, unsigned char u8CaptureMode, unsigned char u8InputSelect, unsigned char u8Synchronized, unsigned char u8OutMode, unsigned char u8InterruptEnable);
void TIMERA_vTimer1Compare0ValueUpdate(unsigned int u16CompareValue);
void TIMERA_vTimer1Compare1Config(unsigned int u16CompareValue, unsigned char u8CaptureMode, unsigned char u8InputSelect, unsigned char u8Synchronized, unsigned char u8OutMode, unsigned char u8InterruptEnable);
void TIMERA_vTimer1Compare1ValueUpdate(unsigned int u16CompareValue);
void TIMERA_vTimer1Compare2Config(unsigned int u16CompareValue, unsigned char u8CaptureMode, unsigned char u8InputSelect, unsigned char u8Synchronized, unsigned char u8OutMode, unsigned char u8InterruptEnable);
void TIMERA_vTimer1Compare2ValueUpdate(unsigned int u16CompareValue);
/*Timer1 Interrupt Template*/
/*
#pragma vector=TIMER1_A1_VECTOR
__interrupt void ISR_TimerA1()
{

}
*/

/*Timer0 Functions*/
void TIMERA_vTimer0Config(unsigned char u8ClockSource, unsigned char u8CountMode, unsigned char u8Divider, unsigned char u8InterruptEnable)
{
    TA0CTL |= 0x0004;//Clear
    TA0CTL |= u8ClockSource << 8;
    TA0CTL |= u8CountMode << 4;
    TA0CTL |= u8Divider << 6;
    if(u8InterruptEnable)
        TA0CTL |=  0x0002;
    else
        TA0CTL &=  0xFFFD;
    TA0CTL |= 0x0004;//Clear
}


void TIMERA_vTimer0Compare0Config(unsigned int u16CompareValue, unsigned char u8CaptureMode, unsigned char u8InputSelect, unsigned char u8Synchronized, unsigned char u8OutMode, unsigned char u8InterruptEnable)
{
    TA0CCR0 = u16CompareValue;
    TA0CCTL0 |= u8CaptureMode << 14;
    TA0CCTL0 |= u8InputSelect  << 12;

    if(u8Synchronized)
        TA0CCTL0 |= 0x0800;//Synchronized capture source
    else
        TA0CCTL0 &= 0xF7FF;//Synchronized capture source

    if(u8CaptureMode == NOCAP)
        TA0CCTL0 &= 0xFEFF;//Compare mode
    else
        TA0CCTL0 |= 0x0100;//Capture mode

    TA0CCTL0 |= u8OutMode << 5;
    if(u8InterruptEnable)
        TA0CCTL0 |= 0x0010;//Interrupt enable
    else
        TA0CCTL0 &= 0xFFEF;//Interrupt enable

}

void TIMERA_vTimer0Compare0ValueUpdate(unsigned int u16CompareValue)
{
    TA0CCR0 = u16CompareValue;
}

void TIMERA_vTimer0Compare1Config(unsigned int u16CompareValue, unsigned char u8CaptureMode, unsigned char u8InputSelect, unsigned char u8Synchronized, unsigned char u8OutMode, unsigned char u8InterruptEnable)
{
    TA0CCR1 = u16CompareValue;
    TA0CCTL1 |= u8CaptureMode << 14;
    TA0CCTL1 |= u8InputSelect  << 12;

    if(u8Synchronized)
        TA0CCTL1 |= 0x0800;//Synchronized capture source
    else
        TA0CCTL1 &= 0xF7FF;//Synchronized capture source

    if(u8CaptureMode == NOCAP)
        TA0CCTL1 &= 0xFEFF;//Compare mode
    else
        TA0CCTL1 |= 0x0100;//Capture mode

    TA0CCTL1 |= u8OutMode << 5;
    if(u8InterruptEnable)
        TA0CCTL1 |= 0x0010;//Interrupt enable
    else
        TA0CCTL1 &= 0xFFEF;//Interrupt enable

}

void TIMERA_vTimer0Compare1ValueUpdate(unsigned int u16CompareValue)
{
    TA0CCR1 = u16CompareValue;
}

void TIMERA_vTimer0Compare2Config(unsigned int u16CompareValue, unsigned char u8CaptureMode, unsigned char u8InputSelect, unsigned char u8Synchronized, unsigned char u8OutMode, unsigned char u8InterruptEnable)
{
    TA0CCR2 = u16CompareValue;
    TA0CCTL2 |= u8CaptureMode << 14;
    TA0CCTL2 |= u8InputSelect  << 12;

    if(u8Synchronized)
        TA0CCTL2 |= 0x0800;//Synchronized capture source
    else
        TA0CCTL2 &= 0xF7FF;//Synchronized capture source

    if(u8CaptureMode == NOCAP)
        TA0CCTL2 &= 0xFEFF;//Compare mode
    else
        TA0CCTL2 |= 0x0100;//Capture mode

    TA0CCTL2 |= u8OutMode << 5;
    if(u8InterruptEnable)
        TA0CCTL2 |= 0x0010;//Interrupt enable
    else
        TA0CCTL2 &= 0xFFEF;//Interrupt enable

}

void TIMERA_vTimer0Compare2ValueUpdate(unsigned int u16CompareValue)
{
    TA0CCR2 = u16CompareValue;
}

/*Timer1 Functions*/
void TIMERA_vTimer1Config(unsigned char u8ClockSource, unsigned char u8CountMode, unsigned char u8Divider, unsigned char u8InterruptEnable)
{
    TA1CTL |= 0x0004;//Clear
    TA1CTL |= u8ClockSource << 8;
    TA1CTL |= u8CountMode << 4;
    TA1CTL |= u8Divider << 6;
    if(u8InterruptEnable)
        TA1CTL |=  0x0002;
    else
        TA1CTL &=  0xFFFD;
    TA1CTL |= 0x0004;//Clear
}


void TIMERA_vTimer1Compare0Config(unsigned int u16CompareValue, unsigned char u8CaptureMode, unsigned char u8InputSelect, unsigned char u8Synchronized, unsigned char u8OutMode, unsigned char u8InterruptEnable)
{
    TA1CCR0 = u16CompareValue;
    TA1CCTL0 |= u8CaptureMode << 14;
    TA1CCTL0 |= u8InputSelect  << 12;

    if(u8Synchronized)
        TA1CCTL0 |= 0x0800;//Synchronized capture source
    else
        TA1CCTL0 &= 0xF7FF;//Synchronized capture source

    if(u8CaptureMode == NOCAP)
        TA1CCTL0 &= 0xFEFF;//Compare mode
    else
        TA1CCTL0 |= 0x0100;//Capture mode

    TA1CCTL0 |= u8OutMode << 5;
    if(u8InterruptEnable)
        TA1CCTL0 |= 0x0010;//Interrupt enable
    else
        TA1CCTL0 &= 0xFFEF;//Interrupt enable

}

void TIMERA_vTimer1Compare0ValueUpdate(unsigned int u16CompareValue)
{
    TA1CCR0 = u16CompareValue;
}

void TIMERA_vTimer1Compare1Config(unsigned int u16CompareValue, unsigned char u8CaptureMode, unsigned char u8InputSelect, unsigned char u8Synchronized, unsigned char u8OutMode, unsigned char u8InterruptEnable)
{
    TA1CCR1 = u16CompareValue;
    TA1CCTL1 |= u8CaptureMode << 14;
    TA1CCTL1 |= u8InputSelect  << 12;

    if(u8Synchronized)
        TA1CCTL1 |= 0x0800;//Synchronized capture source
    else
        TA1CCTL1 &= 0xF7FF;//Synchronized capture source

    if(u8CaptureMode == NOCAP)
        TA1CCTL1 &= 0xFEFF;//Compare mode
    else
        TA1CCTL1 |= 0x0100;//Capture mode

    TA1CCTL1 |= u8OutMode << 5;
    if(u8InterruptEnable)
        TA1CCTL1 |= 0x0010;//Interrupt enable
    else
        TA1CCTL1 &= 0xFFEF;//Interrupt enable

}

void TIMERA_vTimer1Compare1ValueUpdate(unsigned int u16CompareValue)
{
    TA1CCR1 = u16CompareValue;
}

void TIMERA_vTimer1Compare2Config(unsigned int u16CompareValue, unsigned char u8CaptureMode, unsigned char u8InputSelect, unsigned char u8Synchronized, unsigned char u8OutMode, unsigned char u8InterruptEnable)
{
    TA1CCR2 = u16CompareValue;
    TA1CCTL2 |= u8CaptureMode << 14;
    TA1CCTL2 |= u8InputSelect  << 12;

    if(u8Synchronized)
        TA1CCTL2 |= 0x0800;//Synchronized capture source
    else
        TA1CCTL2 &= 0xF7FF;//Synchronized capture source

    if(u8CaptureMode == NOCAP)
        TA1CCTL2 &= 0xFEFF;//Compare mode
    else
        TA1CCTL2 |= 0x0100;//Capture mode

    TA1CCTL2 |= u8OutMode << 5;
    if(u8InterruptEnable)
        TA1CCTL2 |= 0x0010;//Interrupt enable
    else
        TA1CCTL2 &= 0xFFEF;//Interrupt enable

}

void TIMERA_vTimer1Compare2ValueUpdate(unsigned int u16CompareValue)
{
    TA1CCR2 = u16CompareValue;
}


