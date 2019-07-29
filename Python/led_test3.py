import RPi.GPIO as GPIO
import time

LED = 18

GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)
GPIO.setup(LED,GPIO.OUT)

pwm = GPIO.PWM(LED, 100) # GPIO.PWM(BCM 번호, Frequency)
pwm.start(0) # Duty Cycle = 0

try :   #정상 작동시
    while True :    #무한루프
        for value in range(0,1024) :
# 0 <= value < 1024 반복문
            pwm.ChangeDutyCycle(value/10.23)
# ChangeDutyCycle(pwm값)
            time.sleep(0.005)

except :    #종료 시
    pwm.stop()  #pwm 중지
    GPIO.cleanup    #GPIO 초기화