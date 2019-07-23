import RPi.GPIO as GPIO
import time

#wpi.0(GPIO.0),BCM.17,Physical-Pin.11
GPIO.setmode(GPIO.BCM)
print ("Use BCM 17")
GPIO.setup(17,GPIO.OUT)
GPIO.output(17, False)

count=0
	
while count<3:
	GPIO.output(17,True)
	time.sleep(1)
	GPIO.output(17,False)
	time.sleep(2)
	count+=1

	print("LED Test End")
GPIO.cleanup()