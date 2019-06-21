/******************************************************************
 Created with PROGRAMINO IDE for Arduino - 04.03.2019 20:22:06
 Project     : Profession calculator
 Libraries   :
 Author      : Mivallion
 Description : Mechanium project for ICAE
******************************************************************/

#ifndef ENCODERS
#define ENCODERS

void encodersSetup() {
    for (int i = 0; i < 6; i++) {
        pinMode(encoderPins[i], INPUT);
    }
    Serial.println("ENCODERS LAUNCH SUCCESSFULL");
}


void displayNewObj() {
    if (new_obj) {
        new_obj = false;
        changed = true;
        digitalWrite(buttonLampPins[0], LOW);
        displaysWakeUp();
        newObjectEventJSON();
        tmp_bool_1 = false;
        digitalWrite(buttonLampPins[1], HIGH);
    }
}

void readEncoders() {
    // subjects and volume
    n0 = digitalRead(encoderPins[0]);
    if ((encoder0PinALast == LOW) && (n0 == HIGH)) {
        unsigned long curTime = millis();
        if ((curTime - encoderCounterTimer < timeForEncoderCounter) || (encoderCounterTimer == 0)) {
            if (digitalRead(encoderPins[1]) == LOW) {
                if (encoderDirection == 0) {
                    encoderCounterTimer = millis();
                    encoderDirection = -1;
                    encoderCounter = 0;
                    encoderCounterTimer = 0;
                } else if (encoderDirection != -1) {
                    encoderDirection = -1;
                    encoderCounter = 0;
                    encoderCounterTimer = 0;
                } else {
                    encoderCounter++;
                    if (encoderCounter == encoderCounterLimit) {
                        encoderCounter = 0;
                        encoderDirection = 0;
                        encoderCounterTimer = 0;
                        updateTimer();
                        displayNewObj();
                         if (changed && buttonPressed[0] == 1) {
                            if (volume < 10) {
                                volume++;
                                updateDisplay(4);
                                updateTimer();
                                volumeEventJSON();
                            }
                        } else {
                            if (s < subjects_len - 1) {
                                s++;
                            } else {
                                s = 0;
                            }
                            updateDisplay(1);
                            updateTimer();
                        }
                    }
                }
            } else {
                if (encoderDirection == 0) {
                    encoderCounterTimer = millis();
                    encoderDirection = 1;
                    encoderCounter = 0;
                    encoderCounterTimer = 0;
                } else if (encoderDirection != 1) {
                    encoderDirection = 1;
                    encoderCounter = 0;
                    encoderCounterTimer = 0;
                } else {
                    encoderCounter++;
                    if (encoderCounter == encoderCounterLimit) {
                        updateTimer();
                        encoderCounter = 0;
                        encoderDirection = 0;
                        encoderCounterTimer = 0;
                        displayNewObj();
                        if (changed && buttonPressed[0] == 1) {
                            if (volume > 0) {
                                volume--;
                                updateDisplay(4);
                                updateTimer();
                                volumeEventJSON();
                            }
                        } else {
                            if (s > 0) {
                                s--;
                            } else {
                                s = subjects_len - 1;
                            }
                            updateDisplay(1);
                            updateTimer();
                        }
                    }
                }
            }
        } else {
            encoderCounter = 0;
            encoderDirection = 0;
            encoderCounterTimer = 0;
        }
    }
    encoder0PinALast = n0;
    //traits
    n1 = digitalRead(encoderPins[2]);
    if ((encoder1PinALast == LOW) && (n1 == HIGH)) {
        unsigned long curTime = millis();
        if ((curTime - encoderCounterTimer < timeForEncoderCounter) || (encoderCounterTimer == 0)) {
            if (digitalRead(encoderPins[3]) == LOW) {
                if (encoderDirection == 0) {
                    encoderCounterTimer = millis();
                    encoderDirection = -1;
                    encoderCounter = 0;
                    encoderCounterTimer = 0;
                } else if (encoderDirection != -1) {
                    encoderDirection = -1;
                    encoderCounter = 0;
                    encoderCounterTimer = 0;
                } else {
                    encoderCounter++;
                    if (encoderCounter == encoderCounterLimit) {
                        if (t < traits_len - 1) {
                            t++;
                        } else {
                            t = 0;
                        }
                        updateDisplay(2);
                        updateTimer();
                        displayNewObj();
                        encoderCounter = 0;
                        encoderDirection = 0;
                        encoderCounterTimer = 0;
                    }
                }
            } else {
                if (encoderDirection == 0) {
                    encoderCounterTimer = millis();
                    encoderDirection = 1;
                    encoderCounter = 0;
                    encoderCounterTimer = 0;
                } else if (encoderDirection != 1) {
                    encoderDirection = 1;
                    encoderCounter = 0;
                    encoderCounterTimer = 0;
                } else {
                    encoderCounter++;
                    if (encoderCounter == encoderCounterLimit) {
                        encoderCounter = 0;
                        encoderDirection = 0;
                        encoderCounterTimer = 0;
                        updateTimer();
                        if (t > 0) {
                            t--;
                        } else {
                            t = traits_len - 1;
                        }
                        updateDisplay(2);
                        updateTimer();
                        displayNewObj();
                    }
                }
            }
        } else {
            encoderCounter = 0;
            encoderDirection = 0;
            encoderCounterTimer = 0;
        }
    }
    encoder1PinALast = n1;
    // interests
    n2 = digitalRead(encoderPins[4]);
    if ((encoder2PinALast == LOW) && (n2 == HIGH)) {
        unsigned long curTime = millis();
        if ((curTime - encoderCounterTimer < timeForEncoderCounter) || (encoderCounterTimer == 0)) {
            if (digitalRead(encoderPins[5]) == LOW) {
                if (encoderDirection == 0) {
                    encoderCounterTimer = millis();
                    encoderDirection = -1;
                    encoderCounter = 0;
                    encoderCounterTimer = 0;
                } else if (encoderDirection != -1) {
                    encoderDirection = -1;
                    encoderCounter = 0;
                    encoderCounterTimer = 0;
                } else {
                    encoderCounter++;
                    if (encoderCounter == encoderCounterLimit) {
                        encoderCounter = 0;
                        encoderDirection = 0;
                        encoderCounterTimer = 0;
                       if (in < interests_len - 1) {
                            in++;
                        } else {
                            in = 0;
                        }
                        updateDisplay(3);
                        updateTimer();
                        displayNewObj();
                    }
                }
            } else {
                if (encoderDirection == 0) {
                    encoderCounterTimer = millis();
                    encoderDirection = 1;
                    encoderCounter = 0;
                    encoderCounterTimer = 0;
                } else if (encoderDirection != 1) {
                    encoderDirection = 1;
                    encoderCounter = 0;
                    encoderCounterTimer = 0;
                } else {
                    encoderCounter++;
                    if (encoderCounter == encoderCounterLimit) {
                        encoderCounter = 0;
                        encoderDirection = 0;
                        encoderCounterTimer = 0;
                         if (in > 0) {
                            in--;
                        } else {
                            in = interests_len - 1;
                        }
                        
                        updateDisplay(3);
                        updateTimer();
                        displayNewObj();
                    }
                }
            }
        } else {
            encoderCounter = 0;
            encoderDirection = 0;
            encoderCounterTimer = 0;
        }
    }
    encoder2PinALast = n2;
}


#endif
