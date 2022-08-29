onvey the message to LED Teensy
        ser = serial.Serial("/dev/rfcomm1", 9600)

        arr= str(msg.payload).split(',')

        # The condition to turn on and turn off LED
        if float(arr[1])>= 25:
                print("LED Status: ON" + " | " + "Current Temp.: " + arr[1]  + >
                ser.write(str.encode('LLED_ON'))
        else:
                print("LED Status: OFF" + " | " + "Current Temp.: " + arr[1] + >
                ser.write(str.encode('LLED_OFF'))

client = mqtt.Client()
client.on_connect = on_connect
client.on_message = on_message
client.connect("54.193.208.193", 1883, 60)
client.loop_forever()
