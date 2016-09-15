#include <SoftwareSerial.h>

SoftwareSerial Genotronex(10, 11); // RX, TX

//const int pin1 = 1;
//const int pin2 = 2;
const int pin3 = 3;
//const int pin4 = 4;
const int pin5 = 5;
//const int pin6 = 6;


//const int analogOut1 = A0;
//const int analogOut2 = A1;

const int jacina = 185;

int BluetoothData; // the data given from Computer


void setup() {
    //pinMode(pin1, OUTPUT);
    //pinMode(pin2, OUTPUT);
    pinMode(pin3, OUTPUT);
    //pinMode(pin4, OUTPUT);
    pinMode(pin5, OUTPUT);
    //pinMode(pin6, OUTPUT); 

    //pinMode(analogOut1, OUTPUT);
    //pinMode(analogOut2, OUTPUT); 

  
    //analogWrite(pin1, jacina);
    //analogWrite(pin2, jacina);
    analogWrite(pin3, jacina);
    //analogWrite(pin4, jacina);
    analogWrite(pin5, jacina);
    //analogWrite(pin6, jacina);
  
    //analogWrite(analogOut1, jacina);
    //analogWrite(analogOut1, jacina);
    
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
