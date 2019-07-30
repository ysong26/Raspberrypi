#include <wiringPi.h>
#include <softPwm.h>
#include <stdio.h>

#define uchar unsigned char

#define R 0 //wPi. 0(GPIO. 0), BCM. 17, Physical-Pin. 11(LED 4)
#define G 1 //wPi. 1(GPIO. 1), BCM. 18, Physical-Pin. 12(LED 2)
#define B 2 //wPi. 2(GPIO. 2), BCM. 27, Physical-Pin. 13(LED 1)
            // ���� �� ��(LED 3)�� Phical-Pin. 1(3.3v)�� ����

// 0xff = 255
void SetLed(void) {
    softPwmCreate(R, 0, 225);
    softPwmCreate(G, 0, 225);
    softPwmCreate(B, 0, 225);
}

//���� ĳ�ҵ�� ���� �ݴ�� �־������
void LedColorSet (uchar r, uchar g, uchar b){
    softPwmWrite(R, 0xff - r);
    softPwmWrite(G, 0xff - g);
    softPwmWrite(B, 0xff - b);
}

int main (void){
    
    if (wiringPiSetup() == -1) return -1;

    SetLed(); //�տ� ������ �Լ� ȣ��

    while (1) { //���ѷ���
        LedColorSet(0xff, 0x00, 0x00); //Red (ff0000);
        delay(1000);
        LedColorSet(0x00, 0xff, 0x00); //Green (00ff00);
        delay(1000);
        LedColorSet(0x00, 0x00, 0xff); //Blue (0000ff);
        delay(1000);
        LedColorSet(0xff, 0xff, 0xff); //White (ffffff);
        delay(1000);
        LedColorSet(0x00, 0xff, 0xff); //Cyan (00ffff);
        delay(1000);
        LedColorSet(0xff, 0x00, 0xff); //Magenta (ff00ff);
        delay(1000);
        LedColorSet(0xff, 0xff, 0x00); //Yellow (ffff00);
        delay(1000);
        LedColorSet(0x00, 0x00, 0x00); //Black(����) (000000);
        delay(1000);
        LedColorSet(0xff, 0xa2, 0x00); //orange (ffa200);
        delay(1000);
        LedColorSet(0xff, 0x7d, 0xe5); //Pink (ff7de5);
        delay(1000);
    }
}
