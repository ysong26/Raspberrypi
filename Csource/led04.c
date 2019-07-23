#include <wiringPi.h>
#include <stdio.h>
#define LED_Y 0 
#define LED_G 2
#define LED_R 3

int i;
 
int main (void) {
if (wiringPiSetup() == -1) {
printf("setup wiringPi failed!");
return 1;
}


pinMode(LED_R, OUTPUT);
pinMode(LED_G, OUTPUT);
pinMode(LED_Y, OUTPUT);

while (1) {

digitalWrite(LED_R, HIGH);
delay(1000);

digitalWrite(LED_R, LOW);
delay(1);


digitalWrite(LED_G, HIGH);
delay(1000);
digitalWrite(LED_G, LOW);
delay(1);

digitalWrite(LED_Y, HIGH);
delay(1000);

digitalWrite(LED_Y, LOW);
delay(1);

digitalWrite(LED_G, HIGH);
delay(1000);
digitalWrite(LED_G, LOW);
delay(1);


}
return 0;
}
