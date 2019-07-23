#include <wiringPi.h>
#include <stdio.h>
#define LED_Y 0 //�� �����
#define LED_G 2 //�� �ʷϺ�
#define LED_R 3 //�� �����
#define LED_RP 21 //��� ������
#define LED_GP 22 //��� �ʷϺ�

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

digitalWrite(LED_GP, LOW); //��� �ʷϺ�OFF
digitalWrite(LED_RP, HIGH); //��� ������ON 
digitalWrite(LED_G, HIGH); //�� �ʷϺ�ON 
digitalWrite(LED_R, LOW); //�� ������OFF
delay(2000);

digitalWrite(LED_G, LOW); //�� �ʷϺ�OFF
digitalWrite(LED_Y, HIGH); //�� ����� ON
delay(2000);

digitalWrite(LED_RP, LOW); //��� ������OFF
digitalWrite(LED_Y, LOW); //�� �����OFF
digitalWrite(LED_R, HIGH); //�� ������ON
digitalWrite(LED_GP, HIGH); //��� �ʷϺ�ON
delay(2000);

}

return 0;
}
