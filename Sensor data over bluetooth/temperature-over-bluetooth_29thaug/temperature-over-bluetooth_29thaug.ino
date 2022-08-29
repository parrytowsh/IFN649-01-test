#include "DHT.h"
//#include <SoftwareSerial.h>

#define DHTPIN 21      // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11   // DHT 11

#define LEDPIN 11

DHT dht(DHTPIN, DHTTYPE);

// Teensy 5V <--> HC-05 Vcc
// Teensy Ground <--> HC-05 GND
#define rxPin 7 // Teensy pin 7 <--> HC-05 Tx
#define txPin 8 // Teensy pin 8 <--> HC-05 Rx
//SoftwareSerial BTSerial =  SoftwareSerial(rxPin, txPin);

void setup() {
  // Setup serial for monitor
  Serial.begin(9600); 

  // Setup DHT Sensor
  pinMode(DHTPIN, INPUT);
  dht.begin();

  // Setup Serial1 for BlueTooth
  Serial1.begin(9600); // Default communication rate of the Bluetooth module
}

void loop() {
  if(Serial1.available() > 0){ // Checks whether data is comming from the serial port
    digitalWrite(LEDPIN, HIGH);

    float h = dht.readHumidity();
    float t = dht.readTemperature();
    float f = dht.readTemperature(true);
    float hif = dht.computeHeatIndex(f, h);
    float hic = dht.computeHeatIndex(t, h, false); 

    
    float allData[5] = {h,t,f,hif,hic};

      Serial.print(allData[0]);
      Serial1.print(allData[0]);
      Serial.print(",");
      Serial1.print(",");
      Serial.print(allData[1]);
      Serial1.print(allData[1]);
      Serial.print(",");
      Serial1.print(",");
      Serial.print(allData[2]);
      Serial1.print(allData[2]);
      Serial.print(",");
      Serial1.print(",");
      Serial.print(allData[3]);
      Serial1.print(allData[3]);
      Serial.print(",");
      Serial1.print(",");
      Serial.println(allData[4]);
      Serial1.println(allData[4]);
    
    delay(1000);
    digitalWrite(LEDPIN, LOW);
    delay(1000);
 }
}
