
/** 
   Knock Sensor

   This sketch reads a piezo element to detect a knocking sound.
   It reads an analog pin and compares the result to a set threshold.
   If the result is greater than the threshold, it writes
   "knock" to the serial port, and toggles the LED on pin 13.

   The circuit:
	 + connection of the piezo attached to analog in 0
	 - connection of the piezo attached to ground
	 1-megohm resistor attached from analog in 0 to ground

   http://www.arduino.cc/en/Tutorial/Knock

*/

// Include the Denbit library.
#include <Denbit.h>
// Initialize the denbit.
Denbit denbit;

// these constants won't change:
const int knockSensor = A0; // the piezo is connected to analog pin 0
const int threshold = 100;  // threshold value to decide when the detected sound is a knock or not


// these variables will change:
int sensorReading = 0;      // variable to store the value read from the sensor pin
int ledState = LOW;         // variable used to store the last LED status, to toggle the light


void setup() {
  // Inital the serial port to output sensor values.
  Serial.begin(115200);
   
}

void loop() {
  // read the sensor and store it in the variable sensorReading:
  sensorReading = analogRead(knockSensor);
  analogWrite(DENBIT_RED, sensorReading);
  Serial.println(sensorReading);
  
  
  // if the sensor reading is greater than the threshold:
  if (sensorReading >= threshold) {
    // toggle the status of the ledPin:
    ledState = !ledState;
    // update the LED pin itself:
    digitalWrite(DENBIT_GREEN, ledState);
    // send the string "Knock!" back to the computer, followed by newline
    Serial.println("Knock!");
  }
  delay(100);  // delay to avoid overloading the serial port buffer
}

