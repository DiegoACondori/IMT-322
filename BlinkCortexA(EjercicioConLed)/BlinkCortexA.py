
import RPi.GPIO as GPIO
import time

LED=18 

GPIO.setmode (GPIO.BOARD)
GPIO.setup (LED, GPIO.OUT)

while(True):
    GPIO. output (LED, GPIO.HIGH) 
    time.sleep (2)
    GPIO.output (LED, GPIO.LOW) 
    time.sleep(2)

GPIO.cleanup ()