/******************************************************************
 Created with PROGRAMINO IDE for Arduino - 04.03.2019 20:22:06
 Project     : Profession calculator
 Libraries   :
 Author      : Mivallion
 Description : Mechanium project for ICAE
******************************************************************/

#ifndef DISPLAYS
#define DISPLAYS

char matematica[] = "\xEC""\xE0""\xF2""\xE5""\xEC""\xE0""\xF2""\xE8""\xEA""\xE0";
char literatura[] = "\xEB""\xE8""\xF2""\xE5""\xF0""\xE0""\xF2""\xF3""\xF0""\xE0";
char russkiy[] = "\xF0""\xF3""\xF1""\xF1""\xEA""\xE8""\xE9"" ""\xFF""\xE7""\xFB""\xEA";
char fizika[] = "\xF4""\xE8""\xE7""\xE8""\xEA""\xE0";
char obzh[] = "\xCE""\xC1""\xC6";
char geographia[] = "\xE3""\xE5""\xEE""\xE3""\xF0""\xE0""\xF4""\xE8""\xFF";
char cherchenie[] = "\xF7""\xE5""\xF0""\xF7""\xE5""\xED""\xE8""\xE5";
char biologia[] = "\xE1""\xE8""\xEE""\xEB""\xEE""\xE3""\xE8""\xFF";
char informatica[] = "\xE8""\xED""\xF4""\xEE""\xF0""\xEC""\xE0""\xF2""\xE8""\xEA""\xE0";
char istoria[] = "\xE8""\xF1""\xF2""\xEE""\xF0""\xE8""\xFF";
char obshestvoznanie[] = "\xEE""\xE1""\xF9""\xE5""\xF1""\xF2""\xE2""\xEE""\xE7""\xED""\xE0""\xED""\xE8""\xE5";
char himia[] = "\xF5""\xE8""\xEC""\xE8""\xFF";
char tehnologii[] = "\xF2""\xE5""\xF5""\xED""\xEE""\xEB""\xEE""\xE3""\xE8""\xE8";
const int arr_s[] = {1, 4, 4, 3, 5, 9, 6, 7, 1, 8, 8, 10, 2};
//traits
char akkuratniy[] = "\xE0""\xEA""\xEA""\xF3""\xF0""\xE0""\xF2""\xED""\xEE""\xF1""\xF2""\xFC";
char disciplina[] = "\xE4""\xE8""\xF1""\xF6""\xE8""\xEF""\xEB""\xE8""\xED""\xE0";
char iniciativnost[] = "\xE8""\xED""\xE8""\xF6""\xE8""\xE0""\xF2""\xE8""\xE2""\xED""\xEE""\xF1""\xF2""\xFC";
char kreativnost[] = "\xEA""\xF0""\xE5""\xE0""\xF2""\xE8""\xE2""\xED""\xEE""\xF1""\xF2""\xFC";
char obshitelnost[] = "\xEE""\xE1""\xF9""\xE8""\xF2""\xE5""\xEB""\xFC""\xED""\xEE""\xF1""\xF2""\xFC";
char optimizm[] = "\xEE""\xEF""\xF2""\xE8""\xEC""\xE8""\xE7""\xEC";
char ostroumie[] = "\xEE""\xF1""\xF2""\xF0""\xEE""\xF3""\xEC""\xE8""\xE5";
char smelost[] = "\xF1""\xEC""\xE5""\xEB""\xEE""\xF1""\xF2""\xFC";
char terpenie[] = "\xF2""\xE5""\xF0""\xEF""\xE5""\xED""\xE8""\xE5";
char celeustremlennost[] = "\xF6""\xE5""\xEB""\xE5""\xF3""\xF1""\xF2""\xF0""\xE5""\xEC""\xEB""\xE5""\xED""\xED""\xEE""\xF1""\xF2""\xFC";
const int arr_t[] = {5, 10, 6, 1, 3, 8, 2, 7, 9, 4};
//interests
char knigi[] = "\xEA""\xED""\xE8""\xE3""\xE8";
char beg[] = "\xE1""\xE5""\xE3";
char vishivanie[] = "\xE2""\xFB""\xF8""\xE8""\xE2""\xE0""\xED""\xE8""\xE5";
char kulinaria[] = "\xEA""\xF3""\xEB""\xE8""\xED""\xE0""\xF0""\xE8""\xFF";
char kollekcionirovanie[] = "\xEA""\xEE""\xEB""\xEB""\xE5""\xEA""\xF6""\xE8""\xEE""\xED""\xE8""\xF0""\xEE""\xE2""\xE0""\xED""\xE8""\xE5";
char pitomcy[] = "\xE4""\xEE""\xEC""\xE0""\xF8""\xED""\xE8""\xE5"" ""\xE6""\xE8""\xE2""\xEE""\xF2""\xED""\xFB""\xE5";
char sadovodstvo[] = "\xF1""\xE0""\xE4""\xEE""\xE2""\xEE""\xE4""\xF1""\xF2""\xE2""\xEE";
char kino[] = "\xEA""\xE8""\xED""\xEE";
char konstruirovanie[] = "\xEA""\xEE""\xED""\xF1""\xF2""\xF0""\xF3""\xE8""\xF0""\xEE""\xE2""\xE0""\xED""\xE8""\xE5";
char komp_igri[] = "\xEA""\xEE""\xEC""\xEF""\xFC""\xFE""\xF2""\xE5""\xF0""\xED""\xFB""\xE5"" ""\xE8""\xE3""\xF0""\xFB";
const int arr_i[] = {1, 7, 9, 10, 6, 4, 8, 5, 3, 2};
//headers
char subjects_header[] = "\xB3""\xCF""\xD0""\xC5""\xC4""\xCC""\xC5""\xD2""\xDB""\xB3";
char traits_header[] = "\xB3""\xCA""\xC0""\xD7""\xC5""\xD1""\xD2""\xC2""\xC0""\xB3";
char interests_header[] = "\xB3""\xC8""\xCD""\xD2""\xC5""\xD0""\xC5""\xD1""\xDB""\xB3";

char *subjects[] = {matematica, literatura, russkiy, fizika, obzh, cherchenie, geographia, biologia, informatica, istoria, obshestvoznanie, himia, tehnologii};
char *traits[] = {akkuratniy, disciplina, iniciativnost, kreativnost, obshitelnost, optimizm, ostroumie, smelost, terpenie, celeustremlennost};
char *interests[] = {knigi, beg, vishivanie, kulinaria, kollekcionirovanie, pitomcy, sadovodstvo, kino, konstruirovanie, komp_igri};
char *headers[] = {subjects_header, traits_header, interests_header};

void updateDisplay(int m) {

    switch (m) {
        case 1:
            lcd1.clear();
            lcd1.command(0b101010);
            lcd1.setCursor(5, 0);
            lcd1.print(headers[0]);
            lcd1.setCursor(0, 1);
            lcd1.print("\x7c");
            if (s == 0) {
                lcd1.print(subjects[subjects_len - 1]);
            } else {
                lcd1.print(subjects[s - 1]);
            }
            lcd1.setCursor(0, 2);
            lcd1.print("\x7c");
            lcd1.print("\x90");
            lcd1.print(subjects[s]);
            lcd1.setCursor(0, 3);
            lcd1.print("\x7c");
            if (s == subjects_len - 1) {
                lcd1.print(subjects[0]);
            } else {
                lcd1.print(subjects[s + 1]);
            }
            break;

        case 2:
            lcd2.clear();
            lcd2.command(0b101010);
            lcd2.setCursor(5, 0);
            lcd2.print(headers[1]);
            lcd2.setCursor(0, 1);
            lcd2.print("\x7c");
            if (t == 0) {
                lcd2.print(traits[traits_len - 1]);
            } else {
                lcd2.print(traits[t - 1]);
            }
            lcd2.setCursor(0, 2);
            lcd2.print("\x7c");
            lcd2.print("\x90");
            lcd2.print(traits[t]);
            lcd2.setCursor(0, 3);
            lcd2.print("\x7c");
            if (t == traits_len - 1) {
                lcd2.print(traits[0]);
            } else {
                lcd2.print(traits[t + 1]);
            }
            break;

        case 3:
            lcd3.clear();
            lcd3.command(0b101010);
            lcd3.setCursor(5, 0);
            lcd3.print(headers[2]);
            lcd3.setCursor(0, 1);
            lcd3.print("\x7c");
            if (in == 0) {
                lcd3.print(interests[interests_len - 1]);
            } else {
                lcd3.print(interests[in - 1]);
            }
            lcd3.setCursor(0, 2);
            lcd3.print("\x7c");
            lcd3.print("\x90");
            lcd3.print(interests[in]);
            lcd3.setCursor(0, 3);
            lcd3.print("\x7c");
            if (in == interests_len - 1) {
                lcd3.print(interests[0]);
            } else {
                lcd3.print(interests[in + 1]);
            }
            break;

        case 4:
            lcd1.clear();
            lcd1.command(0b101010);
            lcd1.setCursor(0, 0);
            lcd1.print(String(volume));
            break;
    }
}

void displaysON() {
    lcd1.init();
    lcd2.init();
    lcd3.init();
    lcd1.backlight();
    lcd2.backlight();
    lcd3.backlight();
}

void displaysSleep() {
    lcd1.noBacklight();
    lcd2.noBacklight();
    lcd3.noBacklight();
    lcd1.clear();
    lcd2.clear();
    lcd3.clear();
}
void displaysWakeUp() {
    lcd1.backlight();
    lcd2.backlight();
    lcd3.backlight();
    updateDisplay(1);
    updateDisplay(2);
    updateDisplay(3);
}

#endif
