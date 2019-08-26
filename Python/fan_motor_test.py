import RPi.GPIO as GPIO
import time

FAN_IA = 23 #BCM 23, wPi. 4, Physical.16
FAN_IB = 24 #BCM 24, wPi. 5, Physical.18

GPIO.setmode(GPIO.BCM)
GPIO.setup(FAN_IA, GPIO.OUT)
GPIO.setup(FAN_IB, GPIO.OUT)

#Left rotation 2second
def Left_2_Second():
    GPIO.output(FAN_IA, True)
    GPIO.output(FAN_IB, False)
    time.sleep(2)

#right rotation 2second
def Right_2_Second():
    GPIO.output(FAN_IA, False)
    GPIO.output(FAN_IB, True)
    time.sleep(2)

#wait 2second
def Wait_2_Second():
    GPIO.output(FAN_IA, False)
    GPIO.output(FAN_IB, False)
    time.sleep(2)


if __name__ == "__main__":
    try:
        while True:
            Left_2_Second()
            Wait_2_Second()
            Right_2_Second()
            Wait_2_Second()

    #Ctrl-C end
    except:
        GPIO.cleanup()
        print("end")