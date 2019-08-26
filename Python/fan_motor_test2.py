import RPi.GPIO as GPIO
import Motor_Module as MOTOR

FAN_IA = 23 #BCM 23, wPi. 4, Physical.16
FAN_IB = 24 #BCM 24, wPi. 5, Physical.18

GPIO.setmode(GPIO.BCM)
GPIO.setup(FAN_IA, GPIO.OUT)
GPIO.setup(FAN_IB, GPIO.OUT)


if __name__ == "__main__":
    try:
        while True:
            MOTOR.Left_2_Second(GPIO, FAN_IA, FAN_IB)
            MOTOR.Wait_2_Second(GPIO, FAN_IA, FAN_IB)
            MOTOR.Right_2_Second(GPIO, FAN_IA, FAN_IB)
            MOTOR.Wait_2_Second(GPIO, FAN_IA, FAN_IB)

    #Ctrl-C end
    except:
        GPIO.cleanup()
        print("end")