#!/usr/bin/env python

import time

import serial

tic = time.time()
toc = time.time()

ser = serial.Serial(

    port='COM4',

    baudrate = 9600,

    parity=serial.PARITY_NONE,

    stopbits=serial.STOPBITS_ONE,

    bytesize=serial.EIGHTBITS,

    timeout=1             

 )

counter=0       

      

while True:
    counter+=1
    ser.write(str.encode('%d \n'%(counter)))




    y=ser.readline().strip()
    if(y.decode('ascii')==str(2*counter)):
        print(y)
        toc = time.time()
        print(toc-tic)
        tic = toc
    else:
        print(y)
        print("error")

    time.sleep(0.01)
