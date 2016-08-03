

// These constants won't change.  They're used to give names
// to the pins used:  // Analog input pin that the potentiometer is attached to
const int analogOutPin1 =2; // Analog output pin that the LED is attached to
const int analogOutPin2 =3;
const int analogOutPin3 =4;
const int analogOutPin4 =5;
const int analogOutPin5 =6;
const int analogOutPin6 =7;
const int analogOutPin7 =8;
const int analogOutPin8 =9;
const int analogOutPin9 =10;
const int analogOutPin11 =11;
const int analogOutPin12 =12;
const int analogOutPin13 =13;


int jacina = HIGH;
int smjer = 0;
int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600); 
  pinMode(analogOutPin1, OUTPUT);
  pinMode(analogOutPin2, OUTPUT);
  pinMode(analogOutPin3, OUTPUT);
  pinMode(analogOutPin4, OUTPUT);
  pinMode(analogOutPin5, OUTPUT);
  pinMode(analogOutPin6, OUTPUT);
  pinMode(analogOutPin7, OUTPUT);
  pinMode(analogOutPin8, OUTPUT);
  pinMode(analogOutPin9, OUTPUT);
  pinMode(analogOutPin11, OUTPUT);
  pinMode(analogOutPin12, OUTPUT);
  pinMode(analogOutPin13, OUTPUT);

}

void loop() {
  // map it to the range of the analog out:
  // change the analog out value:
  digitalWrite(analogOutPin1, jacina);
  analogWrite(analogOutPin2, jacina);
  digitalWrite(analogOutPin3, jacina);
  digitalWrite(analogOutPin4, jacina);
  digitalWrite(analogOutPin5, jacina);
  digitalWrite(analogOutPin6, jacina);
  digitalWrite(analogOutPin7, jacina);
  digitalWrite(analogOutPin8, jacina);
  digitalWrite(analogOutPin9, jacina);
  digitalWrite(analogOutPin11, jacina);
  digitalWrite(analogOutPin12, jacina);
  digitalWrite(analogOutPin13, jacina);
  
  if(smjer == 0)
    jacina++;  
  else
    jacina--;
  if(jacina == 0 || jacina == 255)
    smjer = 1 - smjer;
  // print the results to the serial monitor:
  Serial.print("jacina = " );                          
  Serial.println(jacina);   

  // wait 2 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:
  delay(150);                     
}
