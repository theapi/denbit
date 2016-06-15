
/** 
   Knob (potentiometer)

   This sketch reads value of the knob (potentiometer)
   and sends the value to the serial output.

   View the data in either the serial monitor or the serial plotter.

   The circuit:
	 - connect the middle pin of the potentiometer to the analog pin A0
	 - connect one of the outer pins of the potentiometer to the 3V3 (power)
	 - connect the other outer pin of the potentiometer to the GND (ground)

   An image & more info on the setup is at https://github.com/theapi/denbit/blob/master/docs/examples/Basics/Knob.md
*/

// Include the Denbit library.
#include <Denbit.h>
// Initialize the denbit.
Denbit denbit;

// these constants won't change:
const int pot = A0; // the potentiometer is connected to analog pin 0

// these variables will change:
int potValue = 0;      // variable to store the value read from the sensor pin


void setup() {
  // Inital the serial port to output sensor values.
  Serial.begin(115200);  
}

void loop() {
  // read the sensor and store it in the variable sensorReading:
  potValue = analogRead(pot);
  Serial.println(potValue);
  
  delay(100);  // delay to avoid overloading the serial port buffer
}

