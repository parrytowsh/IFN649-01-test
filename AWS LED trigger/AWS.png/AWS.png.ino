#define LEDPIN 21

void setup() {
  // put your setup code here, to run once:
  // Setup serial for monitor and Setup Serial1 for BlueTooth
  Serial.begin(9600);
  Serial1.begin(9600);
  pinMode(LEDPIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // Process commands from bluetooth first.
  if(Serial1.available() > 0){
  String str = Serial1.readString().substring(1);
  Serial.println(str);
  if(str == "LED_ON"){
  digitalWrite(LEDPIN, HIGH);
  Serial.println("LED ON");
  } else if(str == "LED_OFF"){
  digitalWrite(LEDPIN, LOW);
  Serial.println("LED OFF");
  }
  } 

}
