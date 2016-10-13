
/**
 *  This is the basic Blink sketch with programming over the air under your control.
 */

// Include the Denbit library.
#include <Denbit.h>
// Initialize the denbit.
Denbit denbit;


// Assign readable names to the RGB LED pin numbers
const int rgbRed   = 15;
const int rgbGreen = 14;
const int rgbBlue  = 10;


// Variables will change :
int ledState = LOW;             // ledState used to set the LED

// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0;        // will store last time LED was updated

// constants won't change :
const long interval = 1000;           // interval at which to blink (milliseconds)


void setup() {
  // Turn off the RGB led.
  denbit.RGBoff();

  // Indicate that all is good with the green led.
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);

  // Connect to the WiFi network.
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    // Show the connection failure with a red led.
    digitalWrite(rgbRed, HIGH);
    delay(1000);
    // Try again...
    ESP.restart();
  }

  // Configure & start Over The Air programming.
  denbit.OTAinit(name);
  // When programming starts.
  ArduinoOTA.onStart([]() {
    denbit.RGBoff();
    // Turn on the red led.
    digitalWrite(12, HIGH);
    // Turn off the green led.
    digitalWrite(13, LOW);
  });
  // When programming ends..
  ArduinoOTA.onEnd([]() {
    denbit.RGBoff();
    // Turn off the red led.
    digitalWrite(12, LOW);
  });
  // Start the Over The Air service.
  ArduinoOTA.begin();

}

void loop() {
  // Check for any Over The Air updates.
  ArduinoOTA.handle();

  // check to see if it's time to blink the LED; that is, if the
  // difference between the current time and last time you blinked
  // the LED is bigger than the interval at which you want to
  // blink the LED.
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }

    // set the LED with the ledState of the variable:
    digitalWrite(rgbGreen, ledState);
  }
}
