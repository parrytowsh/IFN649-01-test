import serial
import time
import paho.mqtt.publish as publish
import string

# reading and writing data from and to arduino serially.
# rfcomm0 -> this could be different
ser = serial.Serial("/dev/rfcomm0", 9600)
ser.write(str.encode('Start\r\n'))

while True:
        if ser.in_waiting > 0:
                rawserial = ser.readline()
                cookedserial = rawserial.decode('utf-8').strip('\r\n')
                publish.single("sensorData",cookedserial , hostname="54.193.208.193")
                print("Data sent!")
