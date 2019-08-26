#include <wiringPi.h>
#include <stdio.h>
#include <time.h>

#define Flame 0 //wPi. 0, BCM.17, Physical. 11

int timestamp(void){
    time_t time_now;
    struct tm *tm;
    time(&time_now);
    tm = localtime(&time_now);
    return (printf("%d-%02d-%02d %02d:%02d:%02d",
    tm->tm_year+1900, tm->tm_mon+1, tm->tm_mday,
    tm->tm_hour, tm->tm_min, tm->tm_sec));
}

int main (void){
    if(wiringPiSetup() == -1) {return 1;}

    pinMode(Flame, INPUT);

    while(1){
        timestamp();


        if(digitalRead(Flame)==HIGH){
            printf("safe\n");
        }else {
            printf("danger\n");
        }
        delay(1000);
    }
    
    return 0;
}