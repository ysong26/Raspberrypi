#include <wiringPi.h>
#include <stdio.h>

#define INFRARED 11 // wPi. 11(BCM. 7, Physical.26)
#define BUZZER 0 // wPi. 0(BCM. 17, Physical.11)
#define LED 1 // wPi. 1(BCM. 18, Physical.12)

int main (void) {

    if (wiringPiSetup() == -1) { return 1; }


    pinMode(INFRARED, INPUT);

    pinMode(BUZZER, OUTPUT);
    pinMode(LED, OUTPUT);

    for (;;) {


        if (digitalRead(INFRARED) == HIGH) {

            digitalWrite(BUZZER, HIGH);
            digitalWrite(LED, HIGH);
        } else {

            digitalWrite(BUZZER, LOW);
            digitalWrite(LED, LOW);
        }

    }

    return 0;
}
