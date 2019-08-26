#include <wiringPi.h>
#include <softPwm.h>
#include <stdio.h>
#include "motor.h" //내폴더에 있을땐 "" 라이브러리에 넣어두면 <>

int main (void) {

    if (wiringPiSetup() == -1) { return 1; }

    softPwmCreate(FAN_IA,0,1000);
    
    // 무한루프
    while (1) {
        Weak(); //미풍 5초
        Medium(); //약풍 5초
        Strong(); //강풍 5초
    }

    return 0;
}