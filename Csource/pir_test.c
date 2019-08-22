#include <wiringPi.h>
#include <stdio.h>

#define INFRARED 11// wPi. 11(BCM. 7, Physical. 26)
#define LED 12// wPi. 12(BCM. 10, Physical. 19)

int main (void) {

    if (wiringPiSetup() == -1) { return 1; }

    
    pinMode(INFRARED, INPUT);

    pinMode(LED, OUTPUT);

    for (;;) {


        if (digitalRead(INFRARED) == HIGH) {

            digitalWrite(LED, HIGH);
        } else {

            digitalWrite(LED, LOW);
        }

    }

    return 0;
}