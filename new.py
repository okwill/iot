import RPi.GPIO as GPIO
import time
GPIO.setmode(GPIO.BCM)
GPIO.setup(18, GPIO.OUT)
let int(input('press a key'))
if let ==1:
    GPIO.output(18,GPIO.HIGH)
    time.sleep(1)
    while (True):
        let1=int(input())
        if let1==0:
            GPIO.output(18, GPIO.LOW)
            break
    GPIO.cleanup()
        
