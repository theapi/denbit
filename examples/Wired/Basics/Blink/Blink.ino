
/** 
   Blink

   This is the "Hello World" of the microcontoller world.
   Turns on an LED on for one second, then off for one second, repeatedly.
*/

/**
 * The setup function runs once when you press reset or power the board
 */
void setup() {
  // Initialize pin 13 as an output (the GREEN light on the denbit).
  pinMode(13, OUTPUT);
}

/**
 * The loop function runs over and over again forever
 */
void loop() {
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);              // wait for a second (1000 milliseconds)
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);              // wait for a second (1000 milliseconds)
}

