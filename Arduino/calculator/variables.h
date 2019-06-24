/******************************************************************
 Created with PROGRAMINO IDE for Arduino - 04.03.2019 20:22:06
 Project     : Profession calculator
 Libraries   :
 Author      : Mivallion
 Description : Mechanium project for ICAE
******************************************************************/


#ifndef VARIABLES
#define VARIABLES

unsigned long currentTime, lastActionTime = 0;
int in = 0, s = 0, t = 0, volume = 10;
int n0 = LOW, n1 = LOW, n2 = LOW;
int encoder0PinALast, encoder1PinALast, encoder2PinALast;
unsigned long encoderCounterTimer = 0;
int encoderCounter = 0;
int encoderDirection = 0;
bool sleeping = false;
int buttonPressed[] = { 0, 0 };
int buttonStates[] = { 0, 0 };
bool volumeChanged = false;
bool new_obj = true;
bool first = true;
bool tmp_bool = false;
bool tmp_bool_1 = false;
bool changed = true;
#endif
