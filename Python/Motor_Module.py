import time

def Left_2_Second(GPIO, FAN_IA, FAN_IB) :
    GPIO.output(FAN_IA, True)
    GPIO.output(FAN_IB, False)
    time.sleep(2)

def Right_2_Second(GPIO, FAN_IA, FAN_IB) :
    GPIO.output(FAN_IA, False)
    GPIO.output(FAN_IB, True)
    time.sleep(2)

def Wait_2_Second(GPIO, FAN_IA, FAN_IB) :
    GPIO.output(FAN_IA, False)
    GPIO.output(FAN_IB, False)
    time.sleep(2)