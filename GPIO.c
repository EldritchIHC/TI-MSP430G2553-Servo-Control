/*
 * GPIO.c
 *
 *  Created on: 11 feb. 2024
 *      Author: Paul
 */

/* Project Headers */

/* System Headers*/
#include <msp430.h>
#include "SYSPARAM.h"
/* Own Headers */
#include "GPIO.h"

/* External Headers */

/* Function Prototypes */
/*General Functions*/
void GPIO_vPinMaskGenerator(unsigned char u8PinList[], unsigned char u8Pins, unsigned char *u8PinMask);
/*Port 1 Functions*/
void GPIO_vPort1InputConfig(unsigned char u8PinMask, unsigned char u8ResistorEnable, unsigned char u8ResistorType, unsigned char u8InterruptEnable, unsigned char u8InterruptEdge);
void GPIO_vPort1OutputConfig(unsigned char u8PinMask);
void GPIO_vPort1OutputPortSet(unsigned char u8PinMask);
void GPIO_vPort1OutputPortClear(unsigned char u8PinMask);
void GPIO_vPort1OutputPortToggle(unsigned char u8PinMask);
void GPIO_vPort1FunctionSelect(unsigned char u8PinList[], unsigned char u8Pins, unsigned char u8PinFunction);
unsigned char GPIO_u8Port1InputPinRead(unsigned char u8PinMask);
unsigned char GPIO_u8Port1InputPortRead();
/*Port1 Interrupt Template*/
/*
#pragma vector = PORT1_VECTOR;
__interrupt void ISR_Port1(void)
{

}
*/

/*Port 2 Functions*/
void GPIO_vPort2InputConfig(unsigned char u8PinMask, unsigned char u8ResistorEnable, unsigned char u8ResistorType, unsigned char u8InterruptEnable, unsigned char u8InterruptEdge);
void GPIO_vPort2OutputConfig(unsigned char u8PinMask);
void GPIO_vPort2OutputPortSet(unsigned char u8PinMask);
void GPIO_vPort2OutputPortClear(unsigned char u8PinMask);
void GPIO_vPort2OutputPortToggle(unsigned char u8PinMask);
void GPIO_vPort2FunctionSelect(unsigned char u8PinList[], unsigned char u8Pins, unsigned char u8PinFunction);
unsigned char GPIO_u8Port2InputPinRead(unsigned char u8PinMask);
unsigned char GPIO_u8Port2InputPortRead();
/*Port2 Interrupt Template*/
/*
#pragma vector = PORT2_VECTOR;
__interrupt void ISR_Port2(void)
{

}
*/

/* Global Variables */

/*General Functions*/
void GPIO_vPinMaskGenerator(unsigned char u8PinList[], unsigned char u8Pins, unsigned char *u8PinMask)
{
    volatile unsigned char i;
    volatile unsigned char u8PinMaskTemp = 0x00;
    for( i = 0; i < u8Pins; i++ )
    {
        u8PinMaskTemp |= ( 1 << u8PinList[i]);
    }
    *u8PinMask = u8PinMaskTemp;
}

/*Port 1 Functions*/
void GPIO_vPort1OutputConfig(unsigned char u8PinMask)
{
    P1DIR |= u8PinMask;
}

void GPIO_vPort1InputConfig(unsigned char u8PinMask, unsigned char u8ResistorEnable, unsigned char u8ResistorType, unsigned char u8InterruptEnable, unsigned char u8InterruptEdge)
{
    P1DIR &= ~u8PinMask;
    if(u8ResistorEnable)
    {
        P1REN |=  u8PinMask;
        if(u8ResistorType == PULLUP)
            P1OUT |= u8PinMask;
        else
            P1OUT &= ~u8PinMask;
    }
    if(u8InterruptEnable == ENABLE)
    {
        P1IE |= u8PinMask;
        if(u8InterruptEdge == HIGH_TO_LOW)
            P1IES |= u8PinMask;//Write 1
        else
            P1IES &= ~u8PinMask;//Write 0
    }
}

void GPIO_vPort1OutputPortSet(unsigned char u8PinMask)
{
    P1OUT |= u8PinMask;
}

void GPIO_vPort1OutputPortClear(unsigned char u8PinMask)
{
    P1OUT &= ~u8PinMask;
}

void GPIO_vPort1OutputPortToggle(unsigned char u8PinMask)
{
    P1OUT ^= u8PinMask;
}

void GPIO_vPort1FunctionSelect(unsigned char u8PinList[], unsigned char u8Pins, unsigned char u8PinFunction)
{
    volatile unsigned char u8P1SELTemp1 = 0x00;
    volatile unsigned char u8P1SELTemp2 = 0x00;
    volatile unsigned char i;
    switch(u8PinFunction)
    {
    case FUN_GPIO://00
        u8P1SELTemp1 = 0x00;
        u8P1SELTemp2 = 0x00;
    break;

    case FUN_PRIMARY://01
        for( i = 0; i < u8Pins; i++ )
        {
            u8P1SELTemp1 |= ( 1 << u8PinList[i]);
        }
        u8P1SELTemp2 = 0x00;
    break;

    case FUN_SECONDARY://10
        for( i = 0; i < u8Pins; i++ )
        {
            u8P1SELTemp2 |= ( 1 << u8PinList[i]);
        }
        u8P1SELTemp1 = 0x00;
    break;

    case FUN_TERTIARY://11
        for( i = 0; i < u8Pins; i++ )
        {
            u8P1SELTemp1 |= ( 1 << u8PinList[i]);
            u8P1SELTemp2 |= ( 1 << u8PinList[i]);
        }
    break;

    default:
        u8P1SELTemp1 = 0x00;
        u8P1SELTemp2 = 0x00;
    break;
    }
    P1SEL |= u8P1SELTemp1;
    P1SEL2 |= u8P1SELTemp2;
}

unsigned char GPIO_u8Port1InputPinRead(unsigned char u8PinMask)
{
    if( (P1IN & u8PinMask) ==  u8PinMask)
        return 1;
    else
        return 0;
}

unsigned char GPIO_u8Port1InputPortRead()
{
    return P1IN;
}

/*Port 2 Functions*/
void GPIO_vPort2OutputConfig(unsigned char u8PinMask)
{
    P2DIR |= u8PinMask;
}

void GPIO_vPort2InputConfig(unsigned char u8PinMask, unsigned char u8ResistorEnable, unsigned char u8ResistorType, unsigned char u8InterruptEnable, unsigned char u8InterruptEdge)
{
    P2DIR &= ~u8PinMask;
    if(u8ResistorEnable)
    {
        P2REN |=  u8PinMask;
        if(u8ResistorType == PULLUP)
            P2OUT |= u8PinMask;
        else
            P2OUT &= ~u8PinMask;
    }
    if(u8InterruptEnable == ENABLE)
    {
        P2IE |= u8PinMask;
        if(u8InterruptEdge == HIGH_TO_LOW)
            P2IES |= u8PinMask;//Write 1
        else
            P2IES &= ~u8PinMask;//Write 0
    }
}

void GPIO_vPort2OutputPortSet(unsigned char u8PinMask)
{
    P2OUT |= u8PinMask;
}

void GPIO_vPort2OutputPortClear(unsigned char u8PinMask)
{
    P2OUT &= ~u8PinMask;
}

void GPIO_vPort2OutputPortToggle(unsigned char u8PinMask)
{
    P2OUT ^= u8PinMask;
}

void GPIO_vPort2FunctionSelect(unsigned char u8PinList[], unsigned char u8Pins, unsigned char u8PinFunction)
{
    volatile unsigned char u8P2SELTemp1 = 0x00;
    volatile unsigned char u8P2SELTemp2 = 0x00;
    volatile unsigned char i;
    switch(u8PinFunction)
    {
    case FUN_GPIO://00
        u8P2SELTemp1 = 0x00;
        u8P2SELTemp2 = 0x00;
    break;

    case FUN_PRIMARY://01
        for( i = 0; i < u8Pins; i++ )
        {
            u8P2SELTemp1 |= ( 1 << u8PinList[i]);
        }
        u8P2SELTemp2 = 0x00;
    break;

    case FUN_SECONDARY://10
        for( i = 0; i < u8Pins; i++ )
        {
            u8P2SELTemp2 |= ( 1 << u8PinList[i]);
        }
        u8P2SELTemp1 = 0x00;
    break;

    case FUN_TERTIARY://11
        for( i = 0; i < u8Pins; i++ )
        {
            u8P2SELTemp1 |= ( 1 << u8PinList[i]);
            u8P2SELTemp2 |= ( 1 << u8PinList[i]);
        }
    break;

    default:
        u8P2SELTemp1 = 0x00;
        u8P2SELTemp2 = 0x00;
    break;
    }
    P2SEL |= u8P2SELTemp1;
    P2SEL2 |= u8P2SELTemp2;
}

unsigned char GPIO_u8Port2InputPinRead(unsigned char u8PinMask)
{
    if( (P2IN & u8PinMask) ==  u8PinMask)
        return 1;
    else
        return 0;
}

unsigned char GPIO_u8Port2InputPortRead()
{
    return P2IN;
}
