import time

# weak
def Weak(pwm,FAN_IA) :
    pwm.ChangeDutyCycle(0)
    print("weak")
    time.sleep(5)

# medium
def Medium(pwm,FAN_IA) :
    pwm.ChangeDutyCycle(33)
    print("Medium")
    time.sleep(5)

# strong
def Strong(pwm,FAN_IA) :
    pwm.ChangeDutyCycle(60)
    print("Strong")
    time.sleep(5)