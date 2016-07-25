/*
   Temperature sensor over MQTT

   mosquitto_sub -i foo -t temperature
*/

// Set the WiFi access details
#define WIFI_SSID "*****"
#define WIFI_PASS "*****"
// Set the MQTT server details
#define MQTT_SERVER "*****"
#define MQTT_PORT 1883

#include <ESP8266WiFi.h>
// From the libray manager
#include <PubSubClient.h>

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

char msg[30];


WiFiClient espClient;
PubSubClient client(espClient);

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

  client.setServer(mqtt_server, mqtt_port);
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect("ESP8266Client")) {
      Serial.println("connected");
      // Once connected, publish an announcement...
      client.publish("temperature", "hello world");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
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
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    // save the last time the temperature was read
    previousMillis = currentMillis;
    double temperature = thermistor(analogRead(A0));
    // Convert the number to a string to 1 decimal place.
    String str = String(temperature, 1);
    str += "°C";
    str += " : ";
    str += WiFi.localIP().toString();
    str.toCharArray(msg, 30);
    Serial.print("Publish message: ");
    Serial.println(str);
    client.publish("temperature", msg);

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

