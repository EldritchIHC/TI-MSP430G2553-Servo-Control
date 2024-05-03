/*
 * SYSTEM.h
 *
 *  Created on: 11 feb. 2024
 *      Author: ihate
 */

#ifndef SYSPARAM_H_
#define SYSPARAM_H_

/*Defines*/
#define ENABLE 1
#define DISABLE 0
#define RED_LED_PIN 0
#define GREEN_LED_PIN 6
#define RED_LED_PIN_MASK 0x01 << RED_LED_PIN
#define GREEN_LED_PIN_MASK 0x01 << GREEN_LED_PIN

#define BUTTON_PIN 3
#define BUTTON_PIN_MASK 0x01 << BUTTON_PIN

#define MAX_UINT16 65535
#define SYSCLK 16000U;//16MHz system clock
//#define DEBUG

#endif /* SYSPARAM_H_ */
