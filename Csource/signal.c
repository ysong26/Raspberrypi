#include <wiringPi.h>
#include <stdio.h>
#define LED_Y 0 //차 노란불
#define LED_G 2 //차 초록불
#define LED_R 3 //차 노란불
#define LED_RP 21 //사람 빨간불
#define LED_GP 22 //사람 초록불

int i;

int main (void) {
if (wiringPiSetup() == -1) {
printf("setup wiringPi failed!");
return 1;
}

pinMode(LED_R, OUTPUT);
pinMode(LED_G, OUTPUT);
pinMode(LED_Y, OUTPUT);
pinMode(LED_RP, OUTPUT);
pinMode(LED_GP, OUTPUT);

digitalWrite(LED_R, LOW);
digitalWrite(LED_G, LOW);
digitalWrite(LED_Y, LOW);
digitalWrite(LED_RP, LOW);
digitalWrite(LED_GP, LOW);



while (1) {

digitalWrite(LED_GP, LOW); //사람 초록불OFF
digitalWrite(LED_RP, HIGH); //사람 빨간불ON 
digitalWrite(LED_G, HIGH); //차 초록불ON 
digitalWrite(LED_R, LOW); //차 빨간불OFF
delay(2000);

digitalWrite(LED_G, LOW); //차 초록불OFF
digitalWrite(LED_Y, HIGH); //차 노란불 ON
delay(2000);

digitalWrite(LED_RP, LOW); //사람 빨간불OFF
digitalWrite(LED_Y, LOW); //차 노란불OFF
digitalWrite(LED_R, HIGH); //차 빨간불ON
digitalWrite(LED_GP, HIGH); //사람 초록불ON
delay(2000);

}

return 0;
}
