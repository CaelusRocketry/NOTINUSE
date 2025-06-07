#!/usr/bin/env python

import time

import serial

import RPi.GPIO as GPIO

GPIO.setmode(GPIO.BCM)

GPIO.setwarnings(False)

GPIO.setup(23,GPIO.OUT)

ser = serial.Serial(

    port='/dev/ttyUSB0',

    baudrate = 9600,

    parity=serial.PARITY_NONE,

    stopbits=serial.STOPBITS_ONE,

    bytesize=serial.EIGHTBITS,

    timeout=1             

 )


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
    counter+=1
    ser.write(str.encode('%d eeee\n'%(counter)))



    x=ser2.readline().strip()

    if(x.decode('ascii')==str(counter)+" eeee"):
        ser2.write(str.encode(str(2*int(counter))))

        y=ser.readline().strip()
        if(y.decode('ascii')==str(2*counter)):
            print(y)
        else:
            print(y+"e")
    else:
        print(x)
        print(x.decode('ascii'))
        print(str(counter))

    time.sleep(0.01)
