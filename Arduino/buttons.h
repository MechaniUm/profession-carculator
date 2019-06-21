/******************************************************************
 Created with PROGRAMINO IDE for Arduino - 04.03.2019 20:22:06
 Project     : Profession calculator
 Libraries   :
 Author      : Mivallion
 Description : Mechanium project for ICAE
******************************************************************/

#ifndef BUTTONS
#define BUTTONS


void buttonsSetup() {
    for (int i = 0; i < 2; i++) {
        pinMode(buttonPins[i], INPUT);
        pinMode(buttonLampPins[i], OUTPUT);
    }
    Serial.println("BUTTONS LAUNCH SUCCESSFULL");
}

void readButtons() {
    if (digitalRead(buttonPins[0]) == LOW) {
        if (buttonPressed[0] == 0) {
            updateTimer();
            buttonPressed[0] = 1;
        }
    } else {
        if (buttonPressed[0] == 1) {
            updateTimer();
            buttonPressed[0] = 0;
        }
    }
    if (digitalRead(buttonPins[1]) == LOW) {
        if (buttonPressed[1] == 0) {
            updateTimer();
            buttonPressed[1] = 1;
        }
    } else {
        if (buttonPressed[1] == 1) {
            updateTimer();
            buttonPressed[1] = 0;
        }
    }
}

#endif
