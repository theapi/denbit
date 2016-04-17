
#define LED_S_GREEN   13 // D7
#define LED_S_RED     12 // D6
#define LED_RGB_RED   15 // D8
#define LED_RGB_GREEN 10 // SD3
#define LED_RGB_BLUE  14 // D5
#define SW1 2
#define SW2 0

void setup() {

  pinMode(LED_S_GREEN, OUTPUT);
  pinMode(LED_S_RED, OUTPUT);

// RGB led
  pinMode(LED_RGB_RED, OUTPUT);
  pinMode(LED_RGB_GREEN, OUTPUT);
  pinMode(LED_RGB_BLUE, OUTPUT);

// Switches
  pinMode(SW1, INPUT_PULLUP);
  pinMode(SW2, INPUT_PULLUP);
}

void loop() {

  digitalWrite(LED_S_GREEN, HIGH);
  digitalWrite(LED_S_RED, HIGH);

  digitalWrite(LED_RGB_RED, HIGH);
  digitalWrite(LED_RGB_GREEN, HIGH);
  digitalWrite(LED_RGB_BLUE, HIGH);
  
  delay(1000);      

 byte sw1_state = digitalRead(SW1);
 byte sw2_state = digitalRead(SW2);

  // Do not flash if the button is not held down.
  if (sw1_state) {
    digitalWrite(LED_S_GREEN, LOW);  
  }
  if (sw2_state) {
    digitalWrite(LED_S_RED, LOW); 
  }
  
  digitalWrite(LED_RGB_RED, LOW); 
  digitalWrite(LED_RGB_GREEN, LOW); 
  digitalWrite(LED_RGB_BLUE, LOW); 
  
  delay(1000);
}

