/**
  Temperature

  The circuit:
  - GND to one end of a 10K resistor(Brown - Black - Orange - Gold)
  - One leg of the thermistor (temperature sensor) to the other end of the resistor
  - 3V3 to the other leg of the thermistor
  - A0 to the point where the thermistor & resitor are connected

   (GND) ---- (10k-Resistor) -------|------- (Thermistor) ---- (3V3)
                                    |
                               Analog Pin A0

  An image & more info on the setup is at 
  https://github.com/theapi/denbit/blob/master/docs/examples/Sensors/Temperature.md
  

  To see the serial monitor, click the magnifiying class icon in the top right.
  The serial monitor needs to be listening at "115200 baud", 
  so set the value in the bottom left to 115200 baud.
  If the wrong value is set, only gibberish will appear on the monitor.
  
  Graphical representation is available using serial plotter (Tools > Serial Plotter menu)

*/

// Include the Denbit library.
#include <Denbit.h>
// Initialize the denbit.
Denbit denbit;

// Assign readable names to the led pin numbers
const int ledRed =  15;
const int ledGreen =  14;
const int ledBlue =  10;

/**
 * The setup function runs once when you press reset.
 */
void setup() {
  // Start the Over The Air programming.
  denbit.OTAsetup();
}


/**
 * Do a bunch of mathmatics on the voltage reading from the sensor.
 * 
 * @see http://playground.arduino.cc/ComponentLib/Thermistor2
 */
double thermistor(int raw_adc) {   
 double temp;
 temp = log(10000.0 * ((1024.0/raw_adc-1))); 
 temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * temp * temp ))* temp );
 temp = temp - 273.15;            // Convert Kelvin to Celcius
 
 return temp;
}

/**
 * The loop function runs over and over again forever.
 */
void loop() {
  // Check for any Over The Air updates.
  denbit.OTAhandle();
  
  // Read the input on analog A0 pin 
  // and store it in a variable that is large enough to hold it
  double temperature = thermistor(analogRead(A0));
  
  // Change the LEDs for temperature ranges
  if (temperature > 25) {
      // Red
      digitalWrite(ledRed, HIGH);
      digitalWrite(ledGreen, LOW);
      digitalWrite(ledBlue, LOW);
    } else if (temperature > 21) {
      // Green
      digitalWrite(ledRed, LOW);
      digitalWrite(ledGreen, HIGH);
      digitalWrite(ledBlue, LOW);
    } else {
      // Blue
      digitalWrite(ledRed, LOW);
      digitalWrite(ledGreen, LOW);
      digitalWrite(ledBlue, HIGH);
    }
  
}

