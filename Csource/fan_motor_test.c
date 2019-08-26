#include <wiringPi.h>
#include <stdio.h>

#define FAN_IA 4 // wPi.4(BCM. 23, Physical. 16)
#define FAN_IB 5 // wPi.5(BCM. 24, Physical. 18)

//Left rotation 2second
static void Left_2_Second() {
    digitalWrite(FAN_IA, HIGH);
    digitalWrite(FAN_IB, LOW);
    delay(2000);
}

//right rotation 2second
static void Right_2_Second() {
    digitalWrite(FAN_IA, LOW);
    digitalWrite(FAN_IB, HIGH);
    delay(2000);
}

// wait 2second
static void Wait_2_Second(){
    digitalWrite(FAN_IA, LOW);
    digitalWrite(FAN_IB, LOW);
    delay(2000);
}

int main (void) {

    if (wiringPiSetup() == -1) { return 1; }

    pinMode(FAN_IA, OUTPUT);
    pinMode(FAN_IB, OUTPUT);

    while (1) {
        Left_2_Second();
        Wait_2_Second();
        Right_2_Second();
        Wait_2_Second();
    }

    return 0;
}
