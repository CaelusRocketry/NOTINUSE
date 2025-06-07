#!/usr/bin/env python

import time

import serial

import RPi.GPIO as GPIO

GPIO.setmode(GPIO.BCM)

GPIO.setwarnings(False)

GPIO.setup(23,GPIO.OUT)



ser2 = serial.Serial(

    port='/dev/ttyUSB1',

    baudrate = 9600,

    parity=serial.PARITY_NONE,

    stopbits=serial.STOPBITS_ONE,

    bytesize=serial.EIGHTBITS,

    timeout=1             

 )

counter=0       

      

while True:




    x=ser2.readline().strip()
    if(x!=str.encode("")):
        print(x)
        ser2.write(str.encode(str(2*int(x))))
    print(x)

    time.sleep(0.01)
