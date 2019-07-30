import RPi.GPIO as GPIO
import time

R = 17
G = 18
B = 27

GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)
GPIO.setup(R,GPIO.OUT)
GPIO.setup(G,GPIO.OUT)
GPIO.setup(B,GPIO.OUT)

pwm_R = GPIO.PWM(R, 60)
pwm_G = GPIO.PWM(G, 60)
pwm_B = GPIO.PWM(B, 60)

pwm_R.start(100)
pwm_G.start(100)
pwm_B.start(100)

def LedColorSet(r, g, b) :
    pwm_R.ChangeDutyCycle((0xff - r) / 2.55)
    pwm_G.ChangeDutyCycle((0xff - g) / 2.55)
    pwm_B.ChangeDutyCycle((0xff - b) / 2.55)

try :
    while True :
        LedColorSet(0xff, 0x00, 0x00)
        time.sleep(1)
        LedColorSet(0x00, 0xff, 0x00)
        time.sleep(1)
        LedColorSet(0x00, 0x00, 0xff)
        time.sleep(1)
        LedColorSet(0xff, 0xff, 0xff)
        time.sleep(1)
        LedColorSet(0x00, 0xff, 0xff)
        time.sleep(1)
        LedColorSet(0xff, 0x00, 0xff)
        time.sleep(1)
        LedColorSet(0xff, 0xff, 0x00)
        time.sleep(1)
        LedColorSet(0x00, 0x00, 0x00)
        time.sleep(1)
        LedColorSet(0xff, 0xa2, 0xff)
        time.sleep(1)
        LedColorSet(0xff, 0x7d, 0xe5)
        time.sleep(1)

except :
    pwm_R.stop()
    pwm_G.stop()
    pwm_B.stop()
    GPIO.cleanup()
    print("end")