import RPi.GPIO as GPIO

LED = 18
# wPi. 1(GPIO.1),BCM.18, Physical-Pin.12

GPIO.setmode(GPIO.BCM)
# BCM ��� ����
GPIO.setwarnings(False)
GPIO.setup(LED, GPIO.OUT)
# LED OUTPUT(���) ����

pwm = GPIO.PWM(LED, 100)
# GPIO.PWM(BCM ��ȣ, Frequency(Hz))
pwm.start(0)
# Duty cycle = 0%

try :   # �����۵���
    while True : # ���ѷ���
        pwm.ChangeDutyCycle(50)
# ChangeDutyCycle(0~100)

except :    # �����
    pwm.stop()  # pwm����
    GPIO.cleanup()  # GPIO �ʱ�ȭ