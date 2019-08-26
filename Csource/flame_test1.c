#include <wiringPi.h>
#include <stdio.h>
#define LED 15
#define FlamePin 0

int main (void){
    if(wiringPiSetup() == -1) {return 1;}

    pinMode(FlamePin, INPUT);
    pinMode(LED,OUTPUT);

    while(1){
        if(digitalRead(FlamePin)==HIGH){
            digitalWrite(LED,LOW);
            printf("safe\n");
        
        }else if(digitalRead(FlamePin)==LOW) {
            digitalWrite(LED,HIGH);
            printf("danger\n");
        }

        delay(1000);
    }
    return 0;
}