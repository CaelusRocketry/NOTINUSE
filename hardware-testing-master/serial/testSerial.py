import serial
import threading

ser = serial.Serial('COM4', 19200)

def readStuff(thing):
   while True:
      if thing.in_waiting:
         print(thing.read())

thread = threading.Thread(target=readStuff, args=(ser,))
thread.daemon = True
thread.start()

while True:
   inp = input()
   ser.write(bytes([int(inp)]))
