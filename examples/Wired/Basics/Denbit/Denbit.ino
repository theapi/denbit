
/** 
   Denbit Demo

   Uses the denbit library to configure the Denbit.
*/

// Include the Denbit library.
#include <Denbit.h>
// Initialize the denbit.
Denbit denbit;


// Assign readable names to the LED pin numbers
const int ledGreen = 13; 
const int ledRed   = 12;
// Assign readable names to the RGB LED pin numbers
const int rgbRed   = 15; 
const int rgbGreen = 14; 
const int rgbBlue  = 10; 
// Assign readable names to the switch pin numbers
const int sw1 = 2; 
const int sw2 = 16; 


void setup() {
  // Send info to the serial monitor.
  Serial.begin(115200);
}

void loop() {

  // Turn the red & green leds on.
  digitalWrite(ledGreen, HIGH);
  digitalWrite(ledRed, HIGH);

  // Make the RGB led White.
  digitalWrite(rgbRed, HIGH);
  digitalWrite(rgbGreen, HIGH);
  digitalWrite(rgbBlue, HIGH);
  
  delay(1000);      

  // Read the switches.
  byte sw1_state = digitalRead(sw1);
  byte sw2_state = digitalRead(sw2);

  // Do not flash if the button is not held down.
  if (sw1_state) {
    digitalWrite(ledGreen, LOW);  
  }
  if (sw2_state) {
    digitalWrite(ledRed, LOW); 
  }

  // Read the analog pin.
  int analog = analogRead(A0);

  // Send all the info to the serial monitor.
  Serial.print("SW1: ");
  Serial.print(sw1_state);
  Serial.print("  SW2: ");
  Serial.print(sw2_state);
  Serial.print("  A0: ");
  Serial.print(analog);
  Serial.println();

  // Turn off the RGB led.
  digitalWrite(rgbRed, LOW); 
  digitalWrite(rgbGreen, LOW); 
  digitalWrite(rgbBlue, LOW); 

  // Wait a second
  delay(1000);
}

