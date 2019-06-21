/******************************************************************
 Created with PROGRAMINO IDE for Arduino - 04.03.2019 20:22:06
 Project     : Profession calculator
 Libraries   :
 Author      : Mivallion
 Description : Mechanium project for ICAE
******************************************************************/


#ifndef LIGHT
#define LIGHT

Adafruit_NeoPixel led = Adafruit_NeoPixel(ledNumPixels, ledPin, NEO_GRB + NEO_KHZ800);

uint32_t currentColor, ColorNumber;
int dim_power = 10;
int dim_dir = 1;
uint32_t dim_timer = 0;

void dimmer_waiting(int t, int p) {
    if (dim_timer == 0) {
        dim_timer = millis();
    }
    uint32_t tmp_timer = millis();
    if (tmp_timer - dim_timer > t) {
        dim_timer = 0;
        if (dim_power == p)
            dim_dir = -1;
        else if (dim_power == 10)
            dim_dir = 1;
        dim_power += dim_dir;
        dimmer1.setPower(dim_power);
    }
}

void displayLed(int mode) {
    if (mode == 0) {
        for (int i = 0; i < ledNumPixels; i++)
            led.setPixelColor(i, led.Color(0, 0, 0));
    } else {
        for (int i = 0; i < ledNumPixels; i++)
            led.setPixelColor(i, led.Color(255, 255, 255));
    }
    led.show();
}


void smoothLampsOn(int t, char c) {
    for (int i = dimmerMinPower; i < dimmerMaxPower; i++) {
        dimmer1.setPower(i);
        for (int j = 0; j < ledNumPixels; j++)
            switch (c) {
                case 'r':
                    led.setPixelColor(j, led.Color(abs( i * 255 / dimmerMaxPower - i), 0, 0));
                    break;
                case 'g':
                    led.setPixelColor(j, led.Color(0, abs( i * 255 / dimmerMaxPower - i), 0));
                    break;
                default:

                    break;
            }
            digitalWrite(nixiesPins[0], HIGH);
            digitalWrite(nixiesPins[1], LOW);
            digitalWrite(nixiesPins[2], HIGH);
        //analogWrite(nixiesPins[0], abs( i * 255 / dimmerMaxPower - i));
       // analogWrite(nixiesPins[1], abs( i * 255 / dimmerMaxPower - i));
       // analogWrite(nixiesPins[2], abs( i * 255 / dimmerMaxPower - i));
        //for (int j = 0; j < nixiesCount; j++) {
        //    analogWrite(nixiesPins[j], abs( i * 255 / dimmerMaxPower - i));
        //}
        led.show();
        delay(t);
    }
}
void smoothLampsOff(int t, char c) {

    for (int i = dimmerMaxPower; i > dimmerMinPower; i--) {
        dimmer1.setPower(i);
        for (int j = 0; j < ledNumPixels; j++)
            switch (c) {
                case 'r':
                    led.setPixelColor(j, led.Color(abs( i * 255 / dimmerMaxPower - i), 0, 0));
                    break;
                case 'g':
                    led.setPixelColor(j, led.Color(0, abs( i * 255 / dimmerMaxPower - i), 0));
                    break;
                default:

                    break;
            }
        digitalWrite(nixiesPins[0], LOW);
        digitalWrite(nixiesPins[1], HIGH);
        digitalWrite(nixiesPins[2], LOW);
        //for (int j = 0; j < nixiesCount; j++) {
        //    analogWrite(nixiesPins[j], abs( i * 255 / dimmerMaxPower - i));
        //}
        led.show();
        delay(t);
    }
    for (int i = 0; i < nixiesCount; i++) {
        analogWrite(nixiesPins[i], 0);
    }

}
void lightShow() {
    smoothLampsOn(20, 'g');
    delay(100);
    smoothLampsOff(10, 'g');
    smoothLampsOn(10, 'g');
    delay(100);
    smoothLampsOff(20, 'g');
    smoothLampsOn(10, 'g');
    delay(100);
    smoothLampsOff(5, 'g');
    smoothLampsOn(20, 'g');
    delay(100);
    smoothLampsOff(10, 'g');
    smoothLampsOn(20, 'g');
    delay(100);
    smoothLampsOff(10, 'g');
    smoothLampsOn(20, 'g');
    delay(100);
    smoothLampsOff(10, 'g');
    smoothLampsOn(20, 'g');
    smoothLampsOff(10, 'g');
    digitalWrite(nixiesPins[1], LOW);
    displayLed(0);
    dim_timer = 0;
}

void alertLightShow() {
    smoothLampsOn(20, 'g');
    delay(50);
    smoothLampsOff(10, 'g');
    digitalWrite(nixiesPins[1], LOW);
}

void ledSetup() {
    led.begin();
    displayLed(0);
    for (int i = 0; i < nixiesCount; i++) {
        pinMode(nixiesPins[i], OUTPUT);
    }
    Serial.println("LIGHT LAUNCH SUCCESSFULL");
}

#endif
