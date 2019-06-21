/******************************************************************
 Created with PROGRAMINO IDE for Arduino - 04.03.2019 20:22:06
 Project     : Profession calculator
 Libraries   :
 Author      : Mivallion
 Description : Mechanium project for ICAE
******************************************************************/


#ifndef SLEEP
#define SLEEP



void goToSleep() {
    if (!sleeping) {
        dimmer1.setPower(10);
        digitalWrite(buttonLampPins[0], HIGH);
        digitalWrite(buttonLampPins[1], LOW);
        sleepEventJSON();
        sleeping = true;
        changed = true;
        displayLed(0);
        displaysSleep();
        dim_timer = 0;
    }
}



void updateTimer() {
    lastActionTime = millis();
}

void checkTimer() {
    currentTime = millis();
    if (currentTime - lastActionTime > timeBeforeSleep & !sleeping) {
        goToSleep();
        setSoundState(SOUND_OFF);
    }
}

#endif
