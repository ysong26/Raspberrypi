import RPi.GPIO as GPIO
import time

LED = 18

GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)
GPIO.setup(LED,GPIO.OUT)

pwm = GPIO.PWM(LED, 100) # GPIO.PWM(BCM ��ȣ, Frequency)
pwm.start(0) # Duty Cycle = 0

try :   #���� �۵���
    while True :    #���ѷ���
        for value in range(0,1024) :
# 0 <= value < 1024 �ݺ���
            pwm.ChangeDutyCycle(value/10.23)
# ChangeDutyCycle(pwm��)
            time.sleep(0.005)

except :    #���� ��
    pwm.stop()  #pwm ����
    GPIO.cleanup    #GPIO �ʱ�ȭ