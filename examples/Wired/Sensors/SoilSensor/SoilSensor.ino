
/** 
  Soil Sensor

    16 ----*
        |
        \
        /
        \ 10K
        /
        |
        |
   A0 ----*
        |
        |
        *--------> nail 1
            
        *--/\/\--> nail 2
        |   470Ω
        |
        |
   GND ----*

The 470Ω resistor on the second is protection against a short circuit.
If the nail, or its wire, were to touch the 3.3v power, the current will be
limited to 7mA (milliamps) as the NodeMCU can only handle a maximum of 12mA.
  
*/


// Include the Denbit library.
#include <Denbit.h>
// Initialize the denbit.
Denbit denbit;


// Constants won't change.
const int sensorPin = A0;       // the number of the sensor pin
const int powerPin  = 16;       // the number of the power pin
const int indicatorLed = 13;    // the green LED will indicate when a reading is being made
const long interval = 1000;     // how often to take a reading (milliseconds)

// Variables will change.
int sensorReading = 0;          // will store the reading from the senso

// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0;   // will store last time the sensor was read

void setup() {
  // Start the serial output to monitor the sensor values.
  Serial.begin(115200);

  // Configure the power pin as an output
  pinMode(powerPin, OUTPUT);
  // Configure the led pin as an output
  pinMode(indicatorLed, OUTPUT);
}

void loop() {
  // Here is where you put code that needs to be running all the time.

  // Check to see if it's time to take a reading; that is, if the
  // difference between the current time and last time you took a reading
  // is bigger than the interval at which you want to take readings.
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    // Save this as the last time you took a reading.
    previousMillis = currentMillis;

    // Turn on the sensor power.
    // Power to the sensor is turned off when not taking a reading
    // to minimize corrosion  due to electromigration.
    digitalWrite(powerPin, HIGH);

    // Turn on the indicator LED
    digitalWrite(indicatorLed, HIGH);

    // Read the voltage passing through the soil.
    sensorReading = analogRead(sensorPin);
    // Send the value to the serial monitor.
    Serial.println(sensorReading);

    // Turn off the sensor power
    digitalWrite(powerPin, LOW);
    
    // Turn off the indicator LED
    digitalWrite(indicatorLed, LOW);
  }
}

