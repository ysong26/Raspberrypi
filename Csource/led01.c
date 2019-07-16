#include <wiringPi.h>
#include <stdio.h>
#define LED 0

int main (void) {
if (wiringPiSetup() == -1) {
printf("setup wiringPi failed!");
return 1;
}

pinMode(LED, OUTPUT);
while (1) {
digitalWrite(LED, LOW);
printf("LED OFF...\n");

delay(1000);

digitalWrite(LED, HIGH);
printf("LED ON...\n");

delay (1000);
}
return 0;
}

