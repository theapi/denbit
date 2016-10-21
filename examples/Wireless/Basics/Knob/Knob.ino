
/** 
   Knob (potentiometer)

   This sketch reads value of the knob (potentiometer)
   and changes the brightness of the LED.

   

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

int led = 12;           // the PWM pin the LED is attached to
int brightness = 0;    // how bright the LED is

void setup() {
  // Start the Over The Air programming.
  denbit.OTAsetup();
}

void loop() {
  // Check for any Over The Air updates.
  denbit.OTAhandle();
  
  // read the sensor and store it in the variable sensorReading:
  potValue = analogRead(pot);

  // Scale the value to fit into the range of brightness (0 - 255)
  brightness = map(potValue, 0, 1023, 0, 255);
  
  // set the brightness of the LED:
  analogWrite(led, brightness);
  
 }

