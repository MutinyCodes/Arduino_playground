#include <Keypad.h>

const byte ROWS = 4; 
const byte COLS = 4; 
char keys[ROWS][COLS] = {
{'1','2','3', 'A'},
{'4','5','6', 'B'},
{'7','8','9', 'C'},
{'*','0','#', 'D'}
};
byte colPins[COLS] = {5, 4, 3, 2}; //connect to the row pinouts of the kpd
byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the column pinouts of the kpd

Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

unsigned long loopCount;
unsigned long startTime;
String msg;

const byte duljina_lozinke = 4;
char lozinka[duljina_lozinke] = {'1','2','3','4'};
char stisnuti[duljina_lozinke];
byte popunjeno;

const int buttonPin = 11;     // the number of the pushbutton pin
const int ledPinTocno =  12;      // the number of the LED pin
const int ledPinNetocno =  13;
int buttonState = 0;         // variable for reading the pushbutton status

int provjeri() {
  if(duljina_lozinke != popunjeno) {
      popunjeno = 0;
      return 0;
  }

  popunjeno = 0;
    
  for(int i=0; i<duljina_lozinke; i++)
      if(stisnuti[i] != lozinka[i])
          return 0;

  return 1;
}

void setup() {
    Serial.begin(9600);
    loopCount = 0;
    startTime = millis();
    msg = "";
    popunjeno = 0;
    // initialize the LED pin as an output:
    pinMode(ledPinTocno, OUTPUT);
    pinMode(ledPinNetocno, OUTPUT);
    // initialize the pushbutton pin as an input:
    pinMode(buttonPin, INPUT);
}

void ispisi_stanje() {
    Serial.print("Dosad su stisnuti: ");
    for(int i=0; i<popunjeno; i++) {
        Serial.print(stisnuti[i]);
        Serial.print(" ");
    }
    Serial.println();
}

void lampica(int ledPin){
    digitalWrite(ledPin, HIGH);
    delay(888);
    digitalWrite(ledPin, LOW);
}

int stisnuta(char tipka) {    
    switch (tipka) {
        case '*':
            Serial.println("Brisanje zadnjeg unosa.");
            if(popunjeno)
                popunjeno--;
            break;
        case '#':
            Serial.println("Brisanje svih unesenih znakova.");
            popunjeno = 0;
            break;
        case 'D':
            Serial.println("Provjera sifre.");
            if(provjeri()){
                Serial.println("Bravo pogodio si sifru");
                lampica(ledPinTocno);
                return 1;
            }
            Serial.println("Sifra nije ispravna");
            lampica(ledPinNetocno);
            break;
        default:
            if(popunjeno < duljina_lozinke)
                stisnuti[popunjeno++] = tipka;
              
    }
    ispisi_stanje();
    return 0;
}

void loop() {
   
    if(digitalRead(buttonPin))
        stisnuta('D');
        
    // Fills kpd.key[ ] array with up-to 10 active keys.
    // Returns true if there are ANY active keys.
    else if (kpd.getKeys())
    {
        for (int i=0; i<LIST_MAX; i++)   // Scan the whole key list.
        {
            if ( kpd.key[i].stateChanged )   // Only find keys that have changed state.
            {
                switch (kpd.key[i].kstate) {  // Report active key state : IDLE, PRESSED, HOLD, or RELEASED
                    case PRESSED:
                        //msg = " PRESSED.";
                        stisnuta(kpd.key[i].kchar);
                    break;
                    /*case HOLD:
                    msg = " HOLD.";
                break;
                    case RELEASED:
                    msg = " RELEASED.";
                break;
                    case IDLE:
                    msg = " IDLE.";*/
                }
                /*Serial.print("Key ");
                Serial.print(kpd.key[i].kchar);
                Serial.println(msg);*/
            }
        }
    }
}  // End loop
