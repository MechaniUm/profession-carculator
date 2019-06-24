/******************************************************************
 Created with PROGRAMINO IDE for Arduino - 04.03.2019 20:22:06
 Project     : Profession calculator
 Libraries   :
 Author      : Mivallion
 Description : Mechanium project for ICAE
******************************************************************/

#ifndef AUDIO
#define AUDIO

#define SOUND_ON 1
#define SOUND_OFF 0

void soundSetup() {
    pinMode(mutePin, OUTPUT);
}

void setSoundState(int s) {
    switch (s) {
        case SOUND_ON:
            digitalWrite(mutePin, LOW);
            break;

        case SOUND_OFF:
            digitalWrite(mutePin, HIGH);
            break;

        default:

            break;
    }
}

#endif
