
#define DENBIT_GREEN     13 // D7
#define DENBIT_RED       12 // D6
#define DENBIT_RGB_RED   15 // D8
#define DENBIT_RGB_GREEN 14 // D5
#define DENBIT_RGB_BLUE  10 // SD3
#define DENBIT_SW1 2
#define DENBIT_SW2 16

void setup() {
  // Single LEDs
  pinMode(DENBIT_GREEN, OUTPUT);
  pinMode(DENBIT_RED, OUTPUT);

  // RGB led
  pinMode(DENBIT_RGB_RED, OUTPUT);
  pinMode(DENBIT_RGB_GREEN, OUTPUT);
  pinMode(DENBIT_RGB_BLUE, OUTPUT);

  // Switches
  pinMode(DENBIT_SW1, INPUT_PULLUP);
  pinMode(DENBIT_SW2, INPUT);

  Serial.begin(115200);
}

void loop() {

  digitalWrite(DENBIT_GREEN, HIGH);
  digitalWrite(DENBIT_RED, HIGH);

  digitalWrite(DENBIT_RGB_RED, HIGH);
  digitalWrite(DENBIT_RGB_GREEN, HIGH);
  digitalWrite(DENBIT_RGB_BLUE, HIGH);
  
  delay(1000);      

 byte sw1_state = digitalRead(DENBIT_SW1);
 byte sw2_state = digitalRead(DENBIT_SW2);

  // Do not flash if the button is not held down.
  if (sw1_state) {
    digitalWrite(DENBIT_GREEN, LOW);  
  }
  if (sw2_state) {
    digitalWrite(DENBIT_RED, LOW); 
  }

  int analog = analogRead(A0);

  Serial.print("SW1: ");
  Serial.print(sw1_state);
  Serial.print("  SW2: ");
  Serial.print(sw2_state);
  Serial.print("  A0: ");
  Serial.print(analog);
  Serial.println();
  
  digitalWrite(DENBIT_RGB_RED, LOW); 
  digitalWrite(DENBIT_RGB_GREEN, LOW); 
  digitalWrite(DENBIT_RGB_BLUE, LOW); 
  
  delay(1000);
}

