import RPi.GPIO as GPIO

INFRARED = 7 #BCM.7 (wPi. 11, Physical.26)
BUZZER = 17 #BCM.17 (wPi. 0, Physical.11)
LED = 18 #BCM.18 (wPi. 1, Physical.12)

GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)
GPIO.setup(INFRARED, GPIO.IN)
GPIO.setup(BUZZER, GPIO.OUT)
GPIO.setup(LED, GPIO.OUT)

try:
    while True:
        if GPIO.input(INFRARED) == 1:
            GPIO.output(BUZZER, True)
            GPIO.output(LED, True)
        else :
            GPIO.output(BUZZER, False)
            GPIO.output(LED, False)
except:
    GPIO.cleanup()
    print("end")