#include <stdio.h>
#include <wiringPi.h>
#include <softPwm.h>

#define SERVO 1

int main()
{
    char sel;

    if(wiringPiSetup()==-1)
    return 1;

    softPwmCreate(FAN_IA,0,1000);

    while(1){
    fputs("select q, w, m, s: ", stdout);
    scanf("%c", &sel);
    getchar();
        
    if(sel == 'q'){
        Stop();
    }
    if(sel == 'w')
        Weak();
    }

    if(sel == 'm')
        Medium();
    }

    if(sel == 's')
        Strong();
    }
    return 0;
}