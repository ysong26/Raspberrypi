#include <wiringPi.h>
#include <softPwm.h>
#include <stdio.h>
#define FAN_IA 4

// ��ǳ
static void Weak(){
    printf("Weak\n");
    softPwmWrite(FAN_IA, 666);
}

//��ǳ
static void Medium(){
    printf("Medium\n");
    softPwmWrite(FAN_IA, 333);
}

//��ǳ
static void Strong(){
    printf("Strong\n");
    softPwmWrite(FAN_IA, 0);
}

//stop
static void Stop(){
    printf("Stop\n");
    softPwmWrite(FAN_IA, 999);
}