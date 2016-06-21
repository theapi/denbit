/*
   Temperature Server

   Install the library from https://github.com/Links2004/arduinoWebSockets
*/

// Set the WiFi access details
#define WIFI_SSID ".........."
#define WIFI_PASS ".........."


#include <Arduino.h>

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <WebSocketsServer.h>
#include <ESP8266WebServer.h>



// Include the file that has the html.
#include "html.h"
// Include the Denbit library.
#include <Denbit.h>
// Initialize the denbit.
Denbit denbit;



// Assign readable names to the led pin numbers
const int ledRed =  15;
const int ledGreen =  14;
const int ledBlue =  10;

const char* ssid = WIFI_SSID;
const char* password = WIFI_PASS;

// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0;        // will store last time the temperature was updated

// How long to wait before temperature readings.
const long interval = 1000;


ESP8266WebServer server = ESP8266WebServer(80);
WebSocketsServer webSocket = WebSocketsServer(81);

void webSocketEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t length) {

  switch (type) {
    case WStype_DISCONNECTED:
      Serial.printf("[%u] Disconnected!\n", num);
      break;
    case WStype_CONNECTED: {
        IPAddress ip = webSocket.remoteIP(num);
        Serial.printf("[%u] Connected from %d.%d.%d.%d url: %s\n", num, ip[0], ip[1], ip[2], ip[3], payload);

        // send message to client
        webSocket.sendTXT(num, "Connected");
      }
      break;
  }

}

void setup() {
  Serial.begin(115200);
  //Serial.setDebugOutput(true);

  WiFi.begin(ssid, password);
  Serial.println("Connecting");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  // start webSocket server
  webSocket.begin();
  webSocket.onEvent(webSocketEvent);

  // handle index
  server.on("/", []() {
    // send index.html
    server.send(200, "text/html", index_html);
  });

  server.begin();
}

/**
   Do a bunch of mathmatics on the voltage reading from the sensor.

   @see http://playground.arduino.cc/ComponentLib/Thermistor2
*/
double thermistor(int raw_adc) {
  double temp;
  temp = log(10000.0 * ((1024.0 / raw_adc - 1)));
  temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * temp * temp )) * temp );
  temp = temp - 273.15;            // Convert Kelvin to Celcius

  return temp;
}

void loop() {
  webSocket.loop();
  server.handleClient();

  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    // save the last time the temperature was read
    previousMillis = currentMillis;
    double temperature = thermistor(analogRead(A0));
    // Convert the number to a string to 1 decimal place.
    String str = String(temperature, 1);
    str += "°C";
    webSocket.broadcastTXT(str);

    if (temperature > 25) {
      // Red
      digitalWrite(ledRed, HIGH);
      digitalWrite(ledGreen, LOW);
      digitalWrite(ledBlue, LOW);
    } else if (temperature > 20) {
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

}

