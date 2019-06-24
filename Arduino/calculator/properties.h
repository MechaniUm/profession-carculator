
/******************************************************************
 Created with PROGRAMINO IDE for Arduino - 04.03.2019 20:22:06
 Project     : Profession calculator
 Libraries   :
 Author      : Mivallion
 Description : Mechanium project for ICAE
******************************************************************/


#ifndef PROPERTIES
#define PROPERTIES
#include <Arduino.h>
#define timeForEncoderCounter 150
#define encoderCounterLimit 2
#define ledPin 4
#define symbolsPin 17
#define nixiesCount 3
#define dimmerPin 6
#define dimmerMaxPower 40
#define dimmerMinPower 10
#define infoButtonPin 8
#define synthButtonPin 9
#define buttonLamp1 18
#define buttonLamp2 17
#define ledNumPixels 31
#define symbolsNumPixels 3
#define lightshowTime 2
#define alertLightshowTime 0.2
#define timeBeforeSleep 50000
#define mutePin 7
#define delayAfterSleep 30500
#define rpiPinsCount 4
#define delayAfterSynth 5000
#define subjects_len 13
#define traits_len 10
#define interests_len 10
#define timeBeforeSkip 5000
const int sda[] = {28, 30, 32};
const int scl[] = {29, 31, 33};
const int nixiesPins[] = {14, 15, 16};
const int buttonPins[] = { synthButtonPin, infoButtonPin };
const int buttonLampPins[] = { buttonLamp1, buttonLamp2 };
const int numbers[10][7] = {
    {1, 1, 1, 1, 1, 1, 0}, //0
    {0, 1, 1, 0, 0, 0, 0}, //1
    {1, 1, 0, 1, 1, 0, 1}, //2
    {1, 1, 1, 1, 0, 0, 1}, //3
    {0, 1, 1, 0, 0, 1, 1}, //4
    {1, 0, 1, 1, 0, 1, 1}, //5
    {1, 0, 1, 1, 1, 1, 1}, //6
    {1, 1, 1, 0, 0, 0, 0}, //7
    {1, 1, 1, 1, 1, 1, 1}, //8
    {1, 1, 1, 1, 0, 1, 1}  //9
};
const int rpiPins[] = {2, 3};
//const int encoderPins[] = {22, 23, 24, 25, 26, 27};
const int encoderPins[] = {24, 25, 26, 27, 22, 23};
#endif
