import sys, os, time
import serial 

ser = serial.Serial('COM4', baudrate=115200)  # Change COM number accordingly 

# b'c' means that 'c' string is encoded with bytes(ASCII)
ser.write(b'c')

# before you can control the iLimb there's a warm up of hand, written by I don;t know who
print("everything is fine, just to checkout if the time gap is enough")
time.sleep(5)

# testing on the writing part
ser.write(b'o')
time.sleep(0.5)
ser.write(b'r')

# here test whether you can control the angle of motion by setting up the timing 
time.sleep(0.4)
ser.write(b's')

ser.close()