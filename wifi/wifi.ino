#include <SoftwareSerial.h>

SoftwareSerial Genotronex(10, 11); // RX, TX


const int pin1 = 3;
const int pin2 = 4;

const int jacina = 185;

int BluetoothData; // the data given from Computer


void setup() {
    pinMode(pin1, OUTPUT);
    pinMode(pin1, OUTPUT); 
  
    analogWrite(pin2, jacina);
    analogWrite(pin1, jacina);
    
      Serial.begin(9600);
  Genotronex.begin(9600);


}

void loop() {
  // iterate over the pins:
  
  if (Genotronex.available() > 0){
    BluetoothData=Genotronex.read();
    Serial.println(char(BluetoothData));
    Genotronex.println("LED  On D13 ON ! ");
  }
  
  if(Serial.available() > 0)
  {
    String a = Serial.readString();
    Serial.println(a);
    Genotronex.println(a); 
  }
  delay(10);// prepare for next data ...
  
}
