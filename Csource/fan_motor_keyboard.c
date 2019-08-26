#include <wiringPi.h>
#include <softPwm.h>
#include <stdio.h>
#include "motor2.h"

int main (void) {
    if(wiringPiSetup()== -1) {
        return 1;
    }
    softPwmCreate(FAN_IA, 0, 1000);

    while (1){
    int press;
    fputs("select q, w, m, s: ", stdout);
    scanf("%c", &press);
    getchar();

    if(press == 'q'){
        Stop();
    }
    if(press == 'w'){
        Weak();
    }
    if(press == 'm'){
        Medium();
    }
    if(press == 's'){
        Strong();
    }
}
    return 0;
}