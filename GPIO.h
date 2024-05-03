/*
 * GPIO.h
 *
 *  Created on: 11 feb. 2024
 *      Author: Paul
 */

#ifndef GPIO_H_
#define GPIO_H_

/*Defines*/
#define PULLDOWN 0
#define PULLUP 1

#define LOW_TO_HIGH 0
#define HIGH_TO_LOW 1

#define FUN_GPIO      0
#define FUN_PRIMARY   1
#define FUN_SECONDARY 2
#define FUN_TERTIARY  3
/*Structures*/

/*Function prototypes*/
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
/*Port 2 Functions*/
void GPIO_vPort2InputConfig(unsigned char u8PinMask, unsigned char u8ResistorEnable, unsigned char u8ResistorType, unsigned char u8InterruptEnable, unsigned char u8InterruptEdge);
void GPIO_vPort2OutputConfig(unsigned char u8PinMask);
void GPIO_vPort2OutputPortSet(unsigned char u8PinMask);
void GPIO_vPort2OutputPortClear(unsigned char u8PinMask);
void GPIO_vPort2OutputPortToggle(unsigned char u8PinMask);
void GPIO_vPort2FunctionSelect(unsigned char u8PinList[], unsigned char u8Pins, unsigned char u8PinFunction);
unsigned char GPIO_u8Port2InputPinRead(unsigned char u8PinMask);
unsigned char GPIO_u8Port2InputPortRead();
/*Variables*/
extern unsigned char u8PinMask1;
extern unsigned char u8PinMask2;
extern unsigned char u8PinMask3;
extern unsigned char u8PinMask4;

#endif /* GPIO_H_ */
