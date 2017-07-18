import sys, os
import serial 


ser = serial.Serial('COM4', baudrate=115200)  # Change COM number accordingly 
print(ser.read(70))

# b'c' means that 'c' string is encoded with bytes(ASCII)
ser.write(b'y\r')
ser.write(b'0')
ser.write(b'1')
ser.write(b'f')
ser.write(b'd')
ser.write(b'o')
ser.write(b'c')
ser.write(b't')
ser.write(b'i')
ser.write(b'm')
ser.write(b'r')

ser.close()