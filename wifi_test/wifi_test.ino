#include <SoftwareSerial.h>
SoftwareSerial softSerial(8, 9); // RX, TX

const int pin3 = 3;
const int pin5 = 5;

const int jacina = 195;


void setup() 
{
  
  pinMode(pin3, OUTPUT); 
  pinMode(pin5, OUTPUT);
  analogWrite(pin3, jacina);
  analogWrite(pin5, jacina);

  uint32_t baud = 9600;
  Serial.begin(baud);
  softSerial.begin(baud);
  Serial.print("SETUP!! @");
  Serial.println(baud);
}

void loop() 
{
    while(softSerial.available() > 0) 
    {
      char a = softSerial.read();
      if(a == '\0')
        continue;
      if(a != '\r' && a != '\n' && (a < 32))
        continue;
      Serial.print(a);
    }
    
    if(Serial.available() > 0)
    {
      String a = Serial.readString();
      Serial.print(a);
      softSerial.print(a);
    }
}
