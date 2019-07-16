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
 
pinMode(LED_Y, OUTPUT);
pinMode(LED_G, OUTPUT);
pinMode(LED_R, OUTPUT);

while (1) {

digitalWrite(LED_G, HIGH);
delay(3000);

digitalWrite(LED_G, LOW);
delay(1000);

for (i=0; i<5;i++){
digitalWrite(LED_Y, HIGH);
delay(500);
digitalWrite(LED_Y, LOW);
delay(60);
}

digitalWrite(LED_R, HIGH);
delay(3000);

digitalWrite(LED_R, LOW);
delay(1000);

}
return 0;
}



