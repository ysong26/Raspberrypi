# LED1 : DATA IN(���� + GPIO ����, Ȥ�� ���� LED�� DATA OUT���κ��� ����.)
# LED2 : 5V+
# LED3 : GND(���� �� ��)
# LED4 : DATA OUT (���� LED�� DATA IN���� ����)

import neopixel, time, sys

LED_COUNT =8 # LED����
LED_PIN = 18 #BCM 18(Physical 12) (BCM 10(Physical 19) �� �� SPI ���)
LED_BRIGHTNESS = 255
# 0~255. ������ �����ؼ� �Ķ����� �� ������ �ʴ� ��� ���ݾ� ���纼 ��.
LED_CHANNEL = 0
# 0�� �� BCM 18(Physical 12), 1�� �� BCM 13, 19, 41 ,45, 53 ���� ����(Physical 33, 35)

def SetColor(strip, num, color, milli_sec) : #���� �����ؾ� ���� ����.
    for i in range(milli_sec) : #1�� = 1000
        strip.setPixelColor(num, color) #LED ��ȣ, neo pixel.Color(r, g, b)
        strip.show()
        time.sleep(0.001)

strip = neopixel.Adafruit_NeoPixel(LED_COUNT, LED_PIN, 800000, 10, False, LED_BRIGHTNESS,
LED_CHANNEL, 1050624)
strip.begin()

def OneByOne() :
    for i in range(LED_COUNT) :
        if i % 3 == 1 :
            for j in range(256) :
                SetColor(strip, i, neopixel.Color(j, 0, 255 - j), 1) #Blue ~ Red
            for j in range(256) :
                SetColor(strip, i, neopixel.Color(255 - j, j, 0), 1) #Red ~ Green
            for j in range(256) :
                SetColor(strip, i, neopixel.Color(0, 255 - j, j), 1) #Green ~ Blue
        if i % 3 == 2 :
            for j in range(256) :
                SetColor(strip, i, neopixel.Color(255 -j, j, 0), 1) #Red ~ Green
            for j in range(256) :
                SetColor(strip, i, neopixel.Color(0, 255 - j, j), 1) #Green ~ Blue
            for j in range(256) :
                SetColor(strip, i, neopixel.Color(j, 0, 255 -j), 1) #Blue ~ Red
        if i % 3 == 0 :
            for j in range(256) :
                SetColor(strip, i, neopixel.Color(0, 255 - j, j), 1) #Green ~ Blue
            for j in range(256) :
                SetColor(strip, i, neopixel.Color(j, 0, 255 -j), 1) #Blue ~ Red
            for j in range(256) :
                SetColor(strip, i, neopixel.Color(255 -j, j, 0), 1) #Red ~ Green

def All() :
    for j in range(256) :
        for i in range(LED_COUNT) :
            if i % 3 == 1 :
                SetColor(strip, i, neopixel.Color(j, 0, 255-j), 1) #Blue ~ Red
            if i % 3 == 2 :
                SetColor(strip, i, neopixel.Color(255 -j, j, 0), 1) #Red ~ Green
            if i % 3 == 0 :
                SetColor(strip, i, neopixel.Color(0, 255 - j, j), 1) #Green ~ Blue
    for j in range(256) :
        for i in range(LED_COUNT) :
            if i % 3 == 1 :
                SetColor(strip, i, neopixel.Color(255 -j, j, 0), 1) #Red ~ Green
            if i % 3 == 2 :
                SetColor(strip, i, neopixel.Color(0, 255 - j, j), 1) #Green ~ Blue
            if i % 3 == 0 :
                SetColor(strip, i, neopixel.Color(j, 0, 255-j), 1) #Blue ~ Red
    for j in range(256) :
        for i in range(LED_COUNT) :
            if i % 3 == 1 :
                SetColor(strip, i, neopixel.Color(0, 255 - j, j), 1) #Green ~ Blue
            if i % 3 == 2 :
                SetColor(strip, i, neopixel.Color(j, 0, 255-j), 1) #Blue ~ Red
            if i % 3 == 0 :
                SetColor(strip, i, neopixel.Color(255 -j, j, 0), 1) #Red ~ Green

try :
    print("Ctrl-C �� ���� �����մϴ�.")

    while True :
        All() #��ü�� �ѹ��� ���� �ٲ�

        for i in range(LED_COUNT) :
            SetColor(strip, i, neopixel.Color(0, 0, 0), 1) #Black(off)

        OneByOne() #�ϳ��� ���ư��� ���� �ٲ�

except : # Press Ctrl-C
    print("\nCtrl-C�� �����̽��ϴ�. ����˴ϴ�.")

    for i in range(LED_COUNT) :
        SetColor(strip, i, neopixel.Color(0, 0, 0), 1) #Black(off)

    sys.exit(0)