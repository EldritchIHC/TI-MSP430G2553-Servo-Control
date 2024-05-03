/*
 * PWM.c
 *
 *  Created on: 1 mai 2024
 *      Author: Paul
 */

/* Project Headers */

/* System Headers*/
#include <msp430.h>
#include "SYSPARAM.h"
/* Own Headers */
#include "PWM.h"
#include "TIMERA.h"
#include "GPIO.h"

/* External Headers */

/* Function Prototypes */
void PWM_vPWM0ConfigSingle(unsigned int u16Period, unsigned int u16PeriodOn, unsigned char u8Divider, unsigned char u8Pin, unsigned char u8Port, unsigned char u8CountMode, unsigned char u8InterruptEnable);
void PWM_vPWM0ConfigComplementary(unsigned int u16Period, unsigned int u16PeriodOn,  unsigned int u16DeadBand, unsigned char u8Divider, unsigned char u8Pin1, unsigned char u8Port1, unsigned char u8Pin2, unsigned char u8Port2, unsigned char u8InterruptEnable);
void PWM_vPWM0UpdateSingle(unsigned int u16PeriodOn);
void PWM_vPWM0UpdateComplementary(unsigned int u16PeriodOn, unsigned int u16DeadBand);

void PWM_vPWM1ConfigSingle(unsigned int u16Period, unsigned int u16PeriodOn, unsigned char u8Divider, unsigned char u8Pin, unsigned char u8Port, unsigned char u8CountMode, unsigned char u8InterruptEnable);
void PWM_vPWM1ConfigComplementary(unsigned int u16Period, unsigned int u16PeriodOn, unsigned int u16DeadBand, unsigned char u8Divider, unsigned char u8Pin1, unsigned char u8Port1, unsigned char u8Pin2, unsigned char u8Port2, unsigned char u8InterruptEnable);
void PWM_vPWM1UpdateSingle(unsigned int u16PeriodOn);
void PWM_vPWM1UpdateComplementary(unsigned int u16PeriodOn, unsigned int u16DeadBand);
/* Global Variables */
/*Timer0*/
void PWM_vPWM0ConfigSingle(unsigned int u16Period, unsigned int u16PeriodOn, unsigned char u8Divider, unsigned char u8Pin, unsigned char u8Port, unsigned char u8CountMode, unsigned char u8InterruptEnable)
{
    unsigned char u8PinMaskTemp = 0x00;
    unsigned char u8PinListTemp[1] = {u8Pin};
    GPIO_vPinMaskGenerator(u8PinListTemp, 1, &u8PinMaskTemp);
    if(u8Port)
    {
        GPIO_vPort2FunctionSelect(u8PinListTemp, 1, FUN_PRIMARY);
        GPIO_vPort2OutputConfig(u8PinMaskTemp);
    }
    else
    {
        GPIO_vPort1FunctionSelect(u8PinListTemp, 1, FUN_PRIMARY);
        GPIO_vPort1OutputConfig(u8PinMaskTemp);
    }
    TIMERA_vTimer0Config(SMCLK, u8CountMode, u8Divider, u8InterruptEnable);
    TIMERA_vTimer0Compare0Config(u16Period, NOCAP, CCIA, DISABLE, RESET, DISABLE);
    TIMERA_vTimer0Compare1Config(u16PeriodOn, NOCAP, CCIA, DISABLE, RESET_SET, DISABLE);
}

void PWM_vPWM0ConfigComplementary(unsigned int u16Period, unsigned int u16PeriodOn, unsigned int u16DeadBand, unsigned char u8Divider, unsigned char u8Pin1, unsigned char u8Port1, unsigned char u8Pin2, unsigned char u8Port2, unsigned char u8InterruptEnable)
{
    /*First Pin Configuration*/
    unsigned char u8PinMaskTemp = 0x00;
    unsigned char u8PinListTemp1[1] = {u8Pin1};
    GPIO_vPinMaskGenerator(u8PinListTemp1, 1, &u8PinMaskTemp);
    if(u8Port1)
    {
        GPIO_vPort2FunctionSelect(u8PinListTemp1, 1, FUN_PRIMARY);
        GPIO_vPort2OutputConfig(u8PinMaskTemp);
    }
    else
    {
        GPIO_vPort1FunctionSelect(u8PinListTemp1, 1, FUN_PRIMARY);
        GPIO_vPort1OutputConfig(u8PinMaskTemp);
    }
    /*Second Pin Configuration*/
    u8PinMaskTemp = 0x00;
    unsigned char u8PinListTemp2[1] = {u8Pin2};
    GPIO_vPinMaskGenerator(u8PinListTemp2, 1, &u8PinMaskTemp);
    if(u8Port2)
    {
        GPIO_vPort2FunctionSelect(u8PinListTemp2, 1, FUN_PRIMARY);
        GPIO_vPort2OutputConfig(u8PinMaskTemp);
    }
    else
    {
        GPIO_vPort1FunctionSelect(u8PinListTemp2, 1, FUN_PRIMARY);
        GPIO_vPort1OutputConfig(u8PinMaskTemp);
    }
    volatile unsigned int u16PeriodOnTemp = u16PeriodOn;
    volatile unsigned int u16PeriodOffTemp = u16Period - u16PeriodOn - u16DeadBand;
    TIMERA_vTimer0Config(SMCLK, MODE_UPDOWN, u8Divider, u8InterruptEnable);
    TIMERA_vTimer0Compare0Config(u16Period, NOCAP, CCIA, DISABLE, DISABLE, DISABLE);
    TIMERA_vTimer0Compare1Config(u16PeriodOnTemp, NOCAP, CCIA, DISABLE, TOGGLE_SET, DISABLE);
    TIMERA_vTimer0Compare2Config(u16PeriodOffTemp, NOCAP, CCIA, DISABLE, TOGGLE_RESET, DISABLE);
}

void PWM_vPWM0UpdateSingle(unsigned int u16PeriodOn)
{
    TIMERA_vTimer0Compare1ValueUpdate(u16PeriodOn);
}
void PWM_vPWM0UpdateComplementary(unsigned int u16PeriodOn, unsigned int u16DeadBand)
{
    /*Check for shorts during update*/
    volatile unsigned int u16PeriodOffTemp = TA0CCR0 - u16PeriodOn - u16DeadBand;
    TIMERA_vTimer0Compare1ValueUpdate(u16PeriodOn);
    TIMERA_vTimer0Compare2ValueUpdate(u16PeriodOffTemp);
}
/*Timer1*/
void PWM_vPWM1ConfigSingle(unsigned int u16Period, unsigned int u16PeriodOn, unsigned char u8Divider, unsigned char u8Pin, unsigned char u8Port, unsigned char u8CountMode, unsigned char u8InterruptEnable)
{
    unsigned char u8PinMaskTemp = 0x00;
    unsigned char u8PinListTemp[1] = {u8Pin};
    GPIO_vPinMaskGenerator(u8PinListTemp, 1, &u8PinMaskTemp);
    if(u8Port)
    {
        GPIO_vPort2FunctionSelect(u8PinListTemp, 1, FUN_PRIMARY);
        GPIO_vPort2OutputConfig(u8PinMaskTemp);
    }
    else
    {
        GPIO_vPort1FunctionSelect(u8PinListTemp, 1, FUN_PRIMARY);
        GPIO_vPort1OutputConfig(u8PinMaskTemp);
    }
    TIMERA_vTimer1Config(SMCLK, u8CountMode, u8Divider, u8InterruptEnable);
    TIMERA_vTimer1Compare0Config(u16Period, NOCAP, CCIA, DISABLE, RESET, DISABLE);
    TIMERA_vTimer1Compare1Config(u16PeriodOn, NOCAP, CCIA, DISABLE, RESET_SET, DISABLE);
}

void PWM_vPWM1ConfigComplementary(unsigned int u16Period, unsigned int u16PeriodOn, unsigned int u16DeadBand, unsigned char u8Divider, unsigned char u8Pin1, unsigned char u8Port1, unsigned char u8Pin2, unsigned char u8Port2, unsigned char u8InterruptEnable)
{
    /*First Pin Configuration*/
    unsigned char u8PinMaskTemp = 0x00;
    unsigned char u8PinListTemp1[1] = {u8Pin1};
    GPIO_vPinMaskGenerator(u8PinListTemp1, 1, &u8PinMaskTemp);
    if(u8Port1)
    {
        GPIO_vPort2FunctionSelect(u8PinListTemp1, 1, FUN_PRIMARY);
        GPIO_vPort2OutputConfig(u8PinMaskTemp);
    }
    else
    {
        GPIO_vPort1FunctionSelect(u8PinListTemp1, 1, FUN_PRIMARY);
        GPIO_vPort1OutputConfig(u8PinMaskTemp);
    }
    /*Second Pin Configuration*/
    u8PinMaskTemp = 0x00;
    unsigned char u8PinListTemp2[1] = {u8Pin2};
    GPIO_vPinMaskGenerator(u8PinListTemp2, 1, &u8PinMaskTemp);
    if(u8Port2)
    {
        GPIO_vPort2FunctionSelect(u8PinListTemp2, 1, FUN_PRIMARY);
        GPIO_vPort2OutputConfig(u8PinMaskTemp);
    }
    else
    {
        GPIO_vPort1FunctionSelect(u8PinListTemp2, 1, FUN_PRIMARY);
        GPIO_vPort1OutputConfig(u8PinMaskTemp);
    }
    volatile unsigned int u16PeriodOnTemp = u16PeriodOn;
    volatile unsigned int u16PeriodOffTemp = u16Period - u16PeriodOn - u16DeadBand;
    TIMERA_vTimer1Config(SMCLK, MODE_UPDOWN, u8Divider, u8InterruptEnable);
    TIMERA_vTimer1Compare0Config(u16Period, NOCAP, CCIA, DISABLE, DISABLE, DISABLE);
    TIMERA_vTimer1Compare1Config(u16PeriodOnTemp, NOCAP, CCIA, DISABLE, TOGGLE_SET, DISABLE);
    TIMERA_vTimer1Compare2Config(u16PeriodOffTemp, NOCAP, CCIA, DISABLE, TOGGLE_RESET, DISABLE);
}

void PWM_vPWM1UpdateSingle(unsigned int u16PeriodOn)
{
    TIMERA_vTimer1Compare1ValueUpdate(u16PeriodOn);
}

void PWM_vPWM1UpdateComplementary(unsigned int u16PeriodOn, unsigned int u16DeadBand)
{
    /*Check for shorts during update*/
    volatile unsigned int u16PeriodOffTemp = TA1CCR0 - u16PeriodOn - u16DeadBand;
    TIMERA_vTimer1Compare1ValueUpdate(u16PeriodOn);
    TIMERA_vTimer1Compare2ValueUpdate(u16PeriodOffTemp);
}
