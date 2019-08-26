import RPi.GPIO as GPIO
import Motor_Module2 as MOTOR

#BCM. 23, wPi. 4, Physical. 16
FAN_IA = 23

GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)
GPIO.setup(FAN_IA, GPIO.OUT)
pwm = GPIO.PWM(FAN_IA, 60)
pwm.start(0)

if __name__ == "__main__":
    try:
        while True:
            press=input("??")
            if press == 'w':
                MOTOR.Weak(pwm,FAN_IA) 
            elif press == 'm':
                MOTOR.Medium(pwm,FAN_IA)
            elif press == 's':
                MOTOR.Strong(pwm,FAN_IA)
    except:
        GPIO.cleanup()