#include "Arduino.h"
#include "Denbit.h"
#include "config.h"

Denbit::Denbit()
{
  // Single LEDs
  pinMode(DENBIT_GREEN, OUTPUT);
  pinMode(DENBIT_RED, OUTPUT);

  // RGB led
  pinMode(DENBIT_RGB_RED, OUTPUT);
  pinMode(DENBIT_RGB_GREEN, OUTPUT);
  pinMode(DENBIT_RGB_BLUE, OUTPUT);

  // Switches
  pinMode(DENBIT_SW1, INPUT_PULLUP);
  pinMode(DENBIT_SW2, INPUT); // No pullup on pin 16


  digitalWrite(DENBIT_GREEN, LOW);
  digitalWrite(DENBIT_RED, LOW);

  digitalWrite(DENBIT_RGB_RED, LOW);
  digitalWrite(DENBIT_RGB_GREEN, LOW);
  digitalWrite(DENBIT_RGB_BLUE, LOW);
}


/**
 * Turn off the RGB led.
 */
void Denbit::RGBoff() {
  digitalWrite(DENBIT_RGB_RED, LOW);
  digitalWrite(DENBIT_RGB_GREEN, LOW);
  digitalWrite(DENBIT_RGB_BLUE, LOW);
}

/**
 * Let this library control All the OTA setup.
 */
void Denbit::OTAsetup() { 

  // First connect to the WiFi network.
  WiFi.mode(WIFI_STA);
  WiFi.begin(denbit_wifi_ssid, denbit_wifi_password);
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    // Show the connection failure with a red led.
    digitalWrite(DENBIT_RGB_RED, HIGH);
    delay(1000);
    // Try again...
    ESP.restart();
  }

  // denbit_name comes from config.h
  ArduinoOTA.setHostname(denbit_name);

  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    // Flash the RGB led.
    byte val = (progress / (total / 100)) * 2;
    analogWrite(DENBIT_RGB_RED, val);
    analogWrite(DENBIT_RGB_GREEN, val);
    analogWrite(DENBIT_RGB_BLUE, val);
  });

  ArduinoOTA.onError([](ota_error_t error) {
    // Restart on failure.
    ESP.restart();
  });

  // When programming starts.
  ArduinoOTA.onStart([]() {
    digitalWrite(DENBIT_RGB_RED, LOW);
    digitalWrite(DENBIT_RGB_GREEN, LOW);
    digitalWrite(DENBIT_RGB_BLUE, LOW);
    // Turn on the red led.
    digitalWrite(12, HIGH);
    // Turn off the green led.
    digitalWrite(13, LOW);
  });

  // When programming ends..
  ArduinoOTA.onEnd([]() {
    digitalWrite(DENBIT_RGB_RED, LOW);
    digitalWrite(DENBIT_RGB_GREEN, LOW);
    digitalWrite(DENBIT_RGB_BLUE, LOW);
    // Turn off the red led.
    digitalWrite(12, LOW);
    // Turn on the green led.
    digitalWrite(13, HIGH);
  });

  // Start the Over The Air service.
  ArduinoOTA.begin();
}

/**
 * Setup and initialise OTA.
 */
void Denbit::OTAinit() {
  ArduinoOTA.setHostname(denbit_name);

  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    // Flash the RGB led.
    byte val = (progress / (total / 100)) * 2;
    analogWrite(DENBIT_RGB_RED, val);
    analogWrite(DENBIT_RGB_GREEN, val);
    analogWrite(DENBIT_RGB_BLUE, val);
  });

  ArduinoOTA.onError([](ota_error_t error) {
    // Restart on failure.
    ESP.restart();
  });

}

/**
 * Alias for ArduinoOTA.handle();
 */
void Denbit::OTAloop() {
  ArduinoOTA.handle();
}

