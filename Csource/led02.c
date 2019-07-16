#include <wiringPi.h>
#include <stdio.h>
#define LED_Y 0 
#define LED_G 2
#define LED_R 3

int main (void) {
if (wiringPiSetup() == -1) {
printf("setup wiringPi failed!");
return 1;
}

pinMode(LED_Y, OUTPUT);
pinMode(LED_G, OUTPUT);
pinMode(LED_R, OUTPUT);

while (1) {

digitalWrite(LED_Y, HIGH);
printf("YELLOW LED ON...\n");

delay(1000);

digitalWrite(LED_Y, LOW);
printf("YELLOW LED OFF...\n");

delay(1000);

digitalWrite(LED_G, HIGH);
printf("GREEN LED ON...\n");

delay(1000);

digitalWrite(LED_G, LOW);
printf("GREEN LED OFF...\n");

delay(1000);

digitalWrite(LED_R, HIGH);
printf("RED LED ON...\n");

delay(1000);

digitalWrite(LED_R, LOW);
printf("RED LED OFF...\n");

delay(1000);

}
return 0;
}


