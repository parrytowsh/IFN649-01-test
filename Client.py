import serial
import time
import paho.mqtt.client as mqtt
import string

# reading and writing data from and to arduino serially.
# rfcomm1 -> this could be different
#ser = serial.Serial("/dev/rfcomm1", 9600)


def on_connect(client, userdata, flags, rc): # func for making connection
        print("Connected to MQTT")
        print("Connection returned result: " + str(rc) )

        client.subscribe("ifn649")

def on_message(client, userdata, msg): # Func for Sending msg
        # to convey the message to LED Teensy
        ser = serial.Serial("/dev/rfcomm1", 9600)

        # To convert byte to string for further converting it to float
        s = ''.join(map(chr, msg.payload))
        m = float(s)

        # The condition to turn on and turn off LED
        if m >= 25:
                print("LED Status: ON" + " | " + "Current Temp.: " + s  + "C" )
                ser.write(str.encode('LLED_ON'))
        else:
                print("LED Status: OFF" + " | " + "Current Temp.: " + s + "C" )
                ser.write(str.encode('LLED_OFF'))
