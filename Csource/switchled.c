#include <wiringPi.h>
#include <stdio.h>
#define SWITCH 1
#define LED 4

int main(void){
    if (wiringPiSetup() == -1){ //wiringPi를 불러오지 못했을 경우
        printf("setup wiringPi failed!");
        return 1;
    }

    pinMode(SWITCH,INPUT);
    pinMode(SWITCH,PUD_DOWN); //플로팅 상태의 값을 다운
    pinMode(LED,OUTPUT);

    for (;;) {
        if (digitalRead(SWITCH) == 1){
            digitalWrite(LED, HIGH);
        } else{ //SWITCH를 누르고 있지 않을때
            digitalWrite(LED, LOW);
        }
    }
    return 0;
}