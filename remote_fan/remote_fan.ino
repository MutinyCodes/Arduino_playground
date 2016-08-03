#include <IRremote.h>

int RECV_PIN = 2;
int OUT_PIN = 4;
bool radi = false;

IRrecv irrecv(RECV_PIN);

decode_results results;

int promjena() {
  if(radi) {
    radi = false;
    return LOW;
  }

  radi = true;
  return HIGH;
}

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  pinMode(OUT_PIN,OUTPUT);
  //pinMode(RECV_PIN,OUTPUT);
}

void loop() {
  //digitalWrite(RECV_PIN, HIGH);
  if (irrecv.decode(&results)) {
    Serial.println(results.value);
    if(results.value == 16761405 || results.value == 32959)
      digitalWrite(OUT_PIN, promjena());  
    irrecv.resume(); // Receive the next value
  }
  delay(100);
}
