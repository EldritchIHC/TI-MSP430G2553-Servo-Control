/*
 * TIMERA.h
 *
 *  Created on: 20 apr. 2024
 *      Author: Paul
 */

#ifndef TIMERA_H_
#define TIMERA_H_

/*Defines*/
/*Clock source*/
#define TACLK 0
#define ACLK  1
#define SMCLK 2
#define INCLK 3
/*Division value*/
#define DIV1 0
#define DIV2 1
#define DIV4 2
#define DIV8 3
/*Count Mode*/
#define MODE_STOP   0
#define MODE_UP     1
#define MODE_CONT   2
#define MODE_UPDOWN 3
/*Capture Mode*/
#define NOCAP 0
#define REDGE 1//Falling
#define FEDGE 2//Rising
#define BEDGE 3//Both
/*Capture/Compare input select*/
#define CCIA 0
#define CCIB 1
#define GND  2
#define VCC  3
/*Output Mode*/
//#define OUT 0
#define SET          1
#define TOGGLE_RESET 2
#define SET_RESET    3
#define TOGGLE       4
#define RESET        5
#define TOGGLE_SET 6
#define RESET_SET    7
/*Structures*/


/*Function prototypes*/
/*Timer0*/
void TIMERA_vTimer0Config(unsigned char u8ClockSource, unsigned char u8CountMode, unsigned char u8Divider, unsigned char u8InterruptEnable);
void TIMERA_vTimer0Compare0Config(unsigned int u16CompareValue, unsigned char u8CaptureMode, unsigned char u8InputSelect, unsigned char u8Synchronized, unsigned char u8OutMode, unsigned char u8InterruptEnable);
void TIMERA_vTimer0Compare0ValueUpdate(unsigned int u16CompareValue);
void TIMERA_vTimer0Compare1Config(unsigned int u16CompareValue, unsigned char u8CaptureMode, unsigned char u8InputSelect, unsigned char u8Synchronized, unsigned char u8OutMode, unsigned char u8InterruptEnable);
void TIMERA_vTimer0Compare1ValueUpdate(unsigned int u16CompareValue);
void TIMERA_vTimer0Compare2Config(unsigned int u16CompareValue, unsigned char u8CaptureMode, unsigned char u8InputSelect, unsigned char u8Synchronized, unsigned char u8OutMode, unsigned char u8InterruptEnable);
void TIMERA_vTimer0Compare2ValueUpdate(unsigned int u16CompareValue);
/*Timer1*/
void TIMERA_vTimer1Config(unsigned char u8ClockSource, unsigned char u8CountMode, unsigned char u8Divider, unsigned char u8InterruptEnable);
void TIMERA_vTimer1Compare0Config(unsigned int u16CompareValue, unsigned char u8CaptureMode, unsigned char u8InputSelect, unsigned char u8Synchronized, unsigned char u8OutMode, unsigned char u8InterruptEnable);
void TIMERA_vTimer1Compare0ValueUpdate(unsigned int u16CompareValue);
void TIMERA_vTimer1Compare1Config(unsigned int u16CompareValue, unsigned char u8CaptureMode, unsigned char u8InputSelect, unsigned char u8Synchronized, unsigned char u8OutMode, unsigned char u8InterruptEnable);
void TIMERA_vTimer1Compare1ValueUpdate(unsigned int u16CompareValue);
void TIMERA_vTimer1Compare2Config(unsigned int u16CompareValue, unsigned char u8CaptureMode, unsigned char u8InputSelect, unsigned char u8Synchronized, unsigned char u8OutMode, unsigned char u8InterruptEnable);
void TIMERA_vTimer1Compare2ValueUpdate(unsigned int u16CompareValue);
/*Variables*/




#endif /* TIMERA_H_ */
