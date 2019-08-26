import RPi.GPIO as GPIO
import time

#BCM. 23, wPi. 4, Physical. 16
FAN_IA = 23

GPIO.setmode(GPIO.BCM)
GPIO.setup(FAN_IA, GPIO.OUT)

pwm = GPIO.PWM(FAN_IA, 60)
pwm.start(0)

# weak
def weak() :
    pwm.ChangeDutyCycle(66)
    print("weak")
    time.sleep(5)

# medium
def Medium() :
    pwm.ChangeDutyCycle(33)
    print("Medium")
    time.sleep(5)

# strong
def Strong() :
    pwm.ChangeDutyCycle(0)
    print("Strong")
    time.sleep(5)


if __name__ == "__main__":
    try :
        while True:
            weak()
            Medium()
            Strong()
    except:
        GPIO.cleanup()
        print("end")
        