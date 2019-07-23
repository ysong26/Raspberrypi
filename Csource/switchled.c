#include <wiringPi.h>
#include <stdio.h>
#define SWITCH 1
#define LED 4

int main(void){
    if (wiringPiSetup() == -1){ //wiringPi�� �ҷ����� ������ ���
        printf("setup wiringPi failed!");
        return 1;
    }

    pinMode(SWITCH,INPUT);
    pinMode(SWITCH,PUD_DOWN); //�÷��� ������ ���� �ٿ�
    pinMode(LED,OUTPUT);

    for (;;) {
        if (digitalRead(SWITCH) == 1){
            digitalWrite(LED, HIGH);
        } else{ //SWITCH�� ������ ���� ������
            digitalWrite(LED, LOW);
        }
    }
    return 0;
}