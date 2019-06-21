/******************************************************************
 Created with PROGRAMINO IDE for Arduino - 04.03.2019 20:22:06
 Project     : Profession calculator
 Libraries   :
 Author      : Mivallion
 Description : Mechanium project for ICAE
******************************************************************/


#ifndef JSON
#define JSON

void nextObjEventJSON() {
    Serial.write("{\"event\": \"show_next\"}\n");
}

void writeIntToSerial(int i) {
    char charBufVar[50];
    String(i, DEC).toCharArray(charBufVar, 50);
    Serial.write(charBufVar);
}

void stopInfoEventJSON() {
    Serial.write("{\"event\": \"stop_info\"}\n");
}

void buttonEventJSON(int id) {
    Serial.write("{\"event\": \"button_pressed\", \"options\": {\"buttonID\":");
    writeIntToSerial(id);
    Serial.write(",\"t\":");
    writeIntToSerial(arr_t[t]);
    Serial.write(",\"i\":");
    writeIntToSerial(arr_i[in]);
    Serial.write(",\"s\":");
    writeIntToSerial(arr_s[s]);
    Serial.write(",\"delay\":");
    writeIntToSerial(lightshowTime);
    Serial.write("}}\n");
}

void newObjectEventJSON() {
    Serial.write("{\"event\": \"new_object\"}\n");
}

void sleepEventJSON() {
    Serial.write("{\"event\": \"sleep\"}\n");
}

void wakeUpEventJSON() {
    Serial.write("{\"event\": \"wake_up\"}\n");
}

void volumeEventJSON() {
    Serial.write("{\"event\": \"set_volume\", \"options\": {\"volume\":");
    writeIntToSerial(volume * 10);
    Serial.write("}}\n");
}


#endif
