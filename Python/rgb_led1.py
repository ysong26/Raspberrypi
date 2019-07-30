import RPi.GPIO as GPIO #���� ���
import time # time ���

R = 17 # wPi. 0(GPIO. 0), BCM. 17, Physical-Pin. 11(LED 4)
G = 18 # wPi. 1(GPIO. 1), BCM. 18, Physical-Pin. 12(LED 2)
B = 27 # wPi. 2(GPIO. 2), BCM. 27, Physical-Pin. 13(LED 1)
        # ���� �� ��(LED 3)�� Phical-Pin. 1(3.3v)�� ����

GPIO.setmode(GPIO.BCM) # BCM ��� ����
GPIO.setwarnings(False)
GPIO.setup(R,GPIO.OUT) # OUTPUT(���) ����
GPIO.setup(G,GPIO.OUT) # OUTPUT(���) ����
GPIO.setup(B,GPIO.OUT) # OUTPUT(���) ����

# �ʴ� 60Hz�� �����Ÿ��� ������ ����(��ȣ(?)�� ���� �� �÷��� ������)
pwm_R = GPIO.PWM(R, 60)
pwm_G = GPIO.PWM(G, 60)
pwm_B = GPIO.PWM(B, 60)

# ����ĳ�ҵ��̹Ƿ� �ݴ�� �־������, �� 0�� ����.
pwm_R.start(100)
pwm_G.start(100)
pwm_B.start(100)

# 0xff(255)���� 2.55�� ������ 100�� ��(Duty Cycle�� ���밪�� 100)
# �׸��� 0xff(255)�� ���� ������ ����ĳ�ҵ��̹Ƿ� �ݴ밪�� ���� ��
def LedColorSet(r, g, b) :
    pwm_R.ChangeDutyCycle((0xff - r) / 2.55)
    pwm_G.ChangeDutyCycle((0xff - g) / 2.55)
    pwm_B.ChangeDutyCycle((0xff - b) / 2.55)

try :   #���� �۵��� ��
    while True :    #���ѷ���
        LedColorSet(0xff, 0x00, 0x00) #Red(ff0000)
        time.sleep(1)   #1�� ���
        LedColorSet(0x00, 0xff, 0x00) #Green(00ff00)
        time.sleep(1)   #1�� ���
        LedColorSet(0x00, 0x00, 0xff) #Blue(0000ff)
        time.sleep(1)   #1�� ���
        LedColorSet(0xff, 0xff, 0xff) #White(ffffff)
        time.sleep(1)   #1�� ���
        LedColorSet(0x00, 0xff, 0xff) #Cyan(00ffff)
        time.sleep(1)   #1�� ���
        LedColorSet(0xff, 0x00, 0xff) #Magenta(ff00ff)
        time.sleep(1)   #1�� ���
        LedColorSet(0xff, 0xff, 0x00) #Yellow(ffff00)
        time.sleep(1)   #1�� ���
        LedColorSet(0x00, 0x00, 0x00) #Black(000000)
        time.sleep(1)   #1�� ���
        LedColorSet(0xff, 0xa2, 0xff) #Orange(ffa200)
        time.sleep(1)   #1�� ���
        LedColorSet(0xff, 0x7d, 0xe5) #Pink(ff7de5)
        time.sleep(1)   #1�� ���

except :    #�����
    pwm_R.stop()    # pwm ����
    pwm_G.stop()    # pwm ����
    pwm_B.stop()    # pwm ����
    GPIO.cleanup()  # GPIO �ʱ�ȭ
    print("end")    # "end" �޽��� ���