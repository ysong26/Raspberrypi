#include <wiringPi.h>
#include <softPwm.h>
#include <stdio.h>

// wPi. 4 (BCM. 23, Physical. 16)
#define FAN_IA 4

// ��ǳ
static void Weak(){
    softPwmWrite(FAN_IA, 666);
    printf("Weak\n");
    delay(5000);
}

//��ǳ
static void Medium(){
    softPwmWrite(FAN_IA, 333);
    printf("Medium\n");
    delay(5000);
}

//��ǳ
static void Strong(){
    softPwmWrite(FAN_IA, 0);
    printf("Strong\n");
    delay(5000);
}

int main (void) {

    if (wiringPiSetup() == -1) { return 1; }

    softPwmCreate(FAN_IA,0,1000);
    
    // ���ѷ���
    while (1) {
        Weak(); //��ǳ 5��
        Medium(); //��ǳ 5��
        Strong(); //��ǳ 5��
    }

    return 0;
}