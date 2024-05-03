/*
 * PWM.h
 *
 *  Created on: 1 mai 2024
 *      Author: Paul
 */

#ifndef PWM_H_
#define PWM_H_

/*Defines*/
#define PORT1 0
#define PORT2 1
/*Structures*/


/*Function prototypes*/
void PWM_vPWM0ConfigSingle(unsigned int u16Period, unsigned int u16PeriodOn, unsigned char u8Divider, unsigned char u8Pin, unsigned char u8Port, unsigned char u8CountMode, unsigned char u8InterruptEnable);
void PWM_vPWM0ConfigComplementary(unsigned int u16Period, unsigned int u16PeriodOn, unsigned int u16DeadBand, unsigned char u8Divider, unsigned char u8Pin1, unsigned char u8Port1, unsigned char u8Pin2, unsigned char u8Port2, unsigned char u8InterruptEnable);
void PWM_vPWM0UpdateSingle(unsigned int u16PeriodOn);
void PWM_vPWM0UpdateComplementary(unsigned int u16PeriodOn, unsigned int u16DeadBand);

void PWM_vPWM1ConfigSingle(unsigned int u16Period, unsigned int u16PeriodOn, unsigned char u8Divider, unsigned char u8Pin, unsigned char u8Port, unsigned char u8CountMode, unsigned char u8InterruptEnable);
void PWM_vPWM1ConfigComplementary(unsigned int u16Period, unsigned int u16PeriodOn, unsigned int u16DeadBand, unsigned char u8Divider, unsigned char u8Pin1, unsigned char u8Port1, unsigned char u8Pin2, unsigned char u8Port2, unsigned char u8InterruptEnable);
void PWM_vPWM1UpdateSingle(unsigned int u16PeriodOn);
void PWM_vPWM1UpdateComplementary(unsigned int u16PeriodOn, unsigned int u16DeadBand);

/*Variables*/


#endif /* PWM_H_ */
