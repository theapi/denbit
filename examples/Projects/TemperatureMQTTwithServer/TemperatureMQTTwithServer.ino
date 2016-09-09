/*
   Temperature Server

   Install the library from https://github.com/Links2004/arduinoWebSockets
*/

// Set the WiFi access details
#define WIFI_SSID "******"
#define WIFI_PASS "******"
// Set the MQTT server details
#define MQTT_SERVER "******"
#define MQTT_PORT 1883

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <WebSocketsServer.h>
#include <ESP8266WebServer.h>
#include <PubSubClient.h>


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
const char* mqtt_server = MQTT_SERVER;
uint16_t mqtt_port = MQTT_PORT;

// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0;        // will store last time the temperature was updated

// How long to wait before temperature readings.
const long interval = 5000;

// The mqtt message
char msg[30];
// The mqtt client id
char client_id[20];

WiFiClient espClient;
PubSubClient mqtt_client(espClient);

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

    // Ensure that previous wifi settings are removed 
  WiFi.disconnect();
  WiFi.softAPdisconnect(true);

  // "Station" mode
  WiFi.mode(WIFI_STA);

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

  String str = WiFi.localIP().toString();
  str.toCharArray(client_id, 30);

  mqtt_client.setServer(mqtt_server, mqtt_port);
 
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

void reconnect() {
  // Loop until we're reconnected
  while (!mqtt_client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (mqtt_client.connect(client_id)) {
      Serial.println("connected");
      // Once connected, publish an announcement...
      mqtt_client.publish("temperature", "hello world");
    } else {
      Serial.print("failed, rc=");
      Serial.print(mqtt_client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
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
if (!mqtt_client.connected()) {
    reconnect();
  }
  mqtt_client.loop();
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

    str += " : ";
    str += WiFi.localIP().toString();
    str.toCharArray(msg, 30);
    Serial.print("Publish message: ");
    Serial.println(str);
    mqtt_client.publish("temperature", msg);

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

