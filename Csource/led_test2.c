#include <wiringPi.h>
#include <softPwm.h>
// software [Pulse Width Modulation] Module
#include <stdio.h>

#define LED 1
//wPi. 1(GPIO.1), BCM.18, Physical-Pin.12

int main (void){

    if(wiringPiSetup() == -1) return -1;

    unsigned int value = 0;
    softPwmCreate(LED, 0, 100);
    //softPwmCreate(WPi번호, 초기 값, pwm 범위)

    for (value = 0; value <101 ; value++){
        softPwmWrite(LED,value);
        //softPwmWrite(WOi 번호, pwm 값)
        delay(5); //5ms 대기
    }
}