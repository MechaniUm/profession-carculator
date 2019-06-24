/******************************************************************
 Created with PROGRAMINO IDE for Arduino - 04.03.2019 20:22:06
 Project     : Profession calculator
 Libraries   :
 Author      : Mivallion
 Description : Mechanium project for ICAE
******************************************************************/
#include <Adafruit_NeoPixel.h>
#include <RBDdimmer.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd1(0x3D, 20, 4);
LiquidCrystal_I2C lcd2(0x3E, 20, 4);
LiquidCrystal_I2C lcd3(0x3B, 20, 4);
dimmerLamp dimmer1(6);

#include "properties.h"
#include "variables.h"
#include "displays.h"
#include "json.h"
#include "audio.h"
#include "light.h"
#include "sleep.h"
#include "buttons.h"

#include "encoders.h"
#include "rpi.h"

uint32_t audioStartTime = 0;

int btn1Light = 0;
void info() {
    unsigned long tmp = millis();
    while (1) {
        currentTime = millis();
        if (currentTime - tmp > delayAfterSleep) {
            digitalWrite(buttonLampPins[0], LOW);
            btn1Light = 0;
            break;
        }
        else if (currentTime - tmp > timeBeforeSkip) {
            if (!btn1Light) {
                digitalWrite(buttonLampPins[0], HIGH);
                btn1Light = 1;
            }
            readButtons();
            if (buttonPressed[0]) {
                digitalWrite(buttonLampPins[0], LOW);
                btn1Light = 0;
                stopInfoEventJSON();
                break;
            }
        }
        delay(1);
    }
}

void wakeUp() {
    if (sleeping) {
        digitalWrite(buttonLampPins[0], LOW);
        wakeUpEventJSON();
        sleeping = false;
        in = 0;
        s = 0;
        t = 0;

        setSoundState(SOUND_ON);
        // delay(delayAfterSleep);
        info();
        displaysWakeUp();
        digitalWrite(buttonLampPins[1], HIGH);
        //setSoundState(SOUND_OFF);
    }
}

void setup()
{
    Serial.begin(9600);
    dimmer1.begin(NORMAL_MODE, OFF);
    dimmer1.setPower(10); // setPower(0-100%);
    dimmer1.setState(ON);
    displaysON();
    ledSetup();
    soundSetup();
    buttonsSetup();
    encodersSetup();
    rpiSetup();
    setSoundState(SOUND_OFF);
    Serial.println("SYSTEM LAUNCH SUCCESSFULL");
    Serial.println("GOING TO SLEEP");
    goToSleep();
}

void loop()
{
    readButtons();
    if (buttonPressed[0] && sleeping) {
        wakeUp();
    }
    if (!sleeping) {
        checkTimer();
        if (changed && buttonPressed[1]) {
            new_obj = true;
            changed = false;
            delay(10);
            digitalWrite(buttonLampPins[1], LOW);
            digitalWrite(buttonLampPins[0], LOW);
            buttonEventJSON(1);
            //setSoundState(SOUND_ON);
            lightShow();
            //audioStartTime = millis();
            delay(delayAfterSynth);
            //digitalWrite(buttonLampPins[1], HIGH);
            digitalWrite(buttonLampPins[0], HIGH);
        } else if (!changed && buttonPressed[0]) {
            //digitalWrite(buttonLampPins[1], LOW);
            digitalWrite(buttonLampPins[0], LOW);
            nextObjEventJSON();
            delay(1500);
            digitalWrite(buttonLampPins[0], HIGH);
        }
        /*if (audioStartTime) {
            uint32_t tmp = millis();
            if (tmp - audioStartTime > delayForAudio) {
                audioStartTime = 0;
                setSoundState(SOUND_OFF);
            }
        }*/
        readEncoders();
        dimmer_waiting(50, 33);
    }
}
