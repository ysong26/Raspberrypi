import RPi.GPIO as GPIO
import time

LED=17
#wpi.0(GPIO.0),BCM.17,Physical-Pin.11
GPIO.setmode(GPIO.BCM)
GPIO.setup(LED,GPIO.OUT)

try:
	while True:
		GPIO.output(LED,False)
		print("LED OFF...")
		time.sleep(0.5)

		GPIO.output(LED,True)
                print("LED ON...")
		time.sleep(0.5)

except:
	GPIO.cleanup()
	print("end")
