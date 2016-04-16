
#define LED_S_GREEN   12 // D6
#define LED_S_RED     13 // D7
#define LED_RGB_RED   15 // D8
#define LED_RGB_GREEN 10 // SD3
#define LED_RGB_BLUE  14 // D5


void setup() {
  pinMode(LED_S_GREEN, OUTPUT);
  pinMode(LED_S_RED, OUTPUT);

  pinMode(LED_RGB_RED, OUTPUT);
  pinMode(LED_RGB_GREEN, OUTPUT);
  pinMode(LED_RGB_BLUE, OUTPUT);
}

void loop() {
  digitalWrite(LED_S_GREEN, HIGH);
  digitalWrite(LED_S_RED, HIGH);

  digitalWrite(LED_RGB_RED, HIGH);
  digitalWrite(LED_RGB_GREEN, HIGH);
  digitalWrite(LED_RGB_BLUE, HIGH);
  
  delay(1000);      

  
  digitalWrite(LED_S_GREEN, LOW);  
  digitalWrite(LED_S_RED, LOW); 

  digitalWrite(LED_RGB_RED, LOW); 
  digitalWrite(LED_RGB_GREEN, LOW); 
  digitalWrite(LED_RGB_BLUE, LOW); 
  
  delay(1000);
}

