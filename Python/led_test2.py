import RPi.GPIO as GPIO
import time
# delay ����� ���� ���

LED = 18
# wPi. 1(GPIO. 1), BCM.18, Physical-Pin.12

GPIO.setmode(GPIO.BCM)
# BCM��� ����
GPIO.setwarnings(False)
GPIO.setup(LED,GPIO.OUT)
# LED OUTPUT(���) ����

pwm = GPIO.PWM(LED,100)
# GPIO.PWM(BCM��ȣ,Hz)
pwm.start(0)

for value in range(0, 1024):
# 0<= value <1024 �ݺ���
    pwm.ChangeDutyCycle(value / 10.23)
    # changeDutyCycle(0~100)
    time.sleep(0.005)   # 5ms(0.005��) ���

pwm.stop()  # pwm����
GPIO.cleanup()  # GPIO �ʱ�ȭ