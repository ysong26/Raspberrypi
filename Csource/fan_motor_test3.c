#include <wiringPi.h>
#include <softPwm.h>
#include <stdio.h>
#include "motor.h" //�������� ������ "" ���̺귯���� �־�θ� <>

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