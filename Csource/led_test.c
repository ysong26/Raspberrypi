#include <wiringPi.h>
#include <softPwm.h>
//sofrware [Pulse Width Modulation] Module
#include <stdio.h>

#define LED 1
// wPi.1(GPIO.1), BCM.18, Physical-pin.12

int main (void) {
    if (wiringPiSetup() == -1) return -1;

    softPwmCreate(LED, 0, 1023);
    // softPwmCreate(WPi��ȣ, �ʱⰪ, pwm����)

    for (;;){
        softPwmWrite(LED,80);
        //softPwmWrite(WPi��ȣ,pwm��)
    }
}
