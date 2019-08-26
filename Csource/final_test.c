//ȭ�簨�� (Flame sensor)
#include <wiringPi.h>
#include <stdio.h>
#include <time.h>
#include <softPwm.h>

#define Flame 0 //wPi. 0, BCM.17, Physical. 11 //ȭ�簨��
#define BUZZER 29 // wPi. 0(BCM. 21, Physical.40) //����
#define FAN_IA 4 // wPi.4(BCM. 23, Physical. 16) //��������
#define FAN_IB 3 // wPi.3 (BCM. 22, Physical.15) // ����
#define SERVO 1 // wPi.1 (BCM. 18, Physical.12) // ����
int timestamp(void){
    time_t time_now;
    struct tm *tm;
    time(&time_now);
    tm = localtime(&time_now);
    return (printf("%d-%02d-%02d %02d:%02d:%02d",
    tm->tm_year+1900, tm->tm_mon+1, tm->tm_mday,
    tm->tm_hour, tm->tm_min, tm->tm_sec));
}
static void Angle(int angle){
        softPwmWrite(SERVO,15-angle/10);
        delay(50);
}
int main (void){ //ȭ�簨��
    if(wiringPiSetup() == -1) {return 1;}
    softPwmCreate(SERVO,0,180);
    pinMode(Flame, INPUT);
    pinMode(BUZZER,OUTPUT);
    pinMode(FAN_IA,OUTPUT);
    for (;;) { //�˶��溸
        if (digitalRead(Flame) == HIGH) {
            Angle(0);
            digitalWrite(FAN_IA,HIGH);
            digitalWrite(FAN_IB,LOW);
            digitalWrite(BUZZER,LOW);
        } else {
            Angle(90);
            digitalWrite(FAN_IA,LOW);
            digitalWrite(FAN_IB,LOW);
            digitalWrite(BUZZER, HIGH);
        }
    }
    return 0;
}
