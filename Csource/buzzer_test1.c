#include <wiringPi.h>
#include <stdio.h>

#define Flame 0 //wPi. 0, BCM.17, Physical. 11 //화재감지
#define BUZZER 29 // wPi. 0(BCM. 21, Physical.40) //부저

int main (void) {

    if (wiringPiSetup() == -1) { return 1; }


    pinMode(Flame, INPUT);

    pinMode(BUZZER, OUTPUT);


    for (;;) {


        if (digitalRead(Flame) == HIGH) {

            digitalWrite(BUZZER, HIGH);
        } else {

            digitalWrite(BUZZER, LOW);
        }

    }

    return 0;
}
