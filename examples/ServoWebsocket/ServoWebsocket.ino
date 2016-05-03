
/** 
  Servo Sweep
*/

#include <Arduino.h>

#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <WebSocketsServer.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <Hash.h>

#include <Servo.h>

// Include the Denbit library.
#include <Denbit.h>
// Initialize the denbit.
Denbit denbit;

Servo myservo;  // create servo object to control a servo

// Create a wifi object.
ESP8266WiFiMulti WiFiMulti;
// Create a webserver object.
ESP8266WebServer server = ESP8266WebServer(80);
// Create the websocket server.
WebSocketsServer webSocket = WebSocketsServer(81);

// Assign readable names to the led pin numbers
const int ledRed =  15; 
const int ledGreen =  14; 
const int ledBlue =  10; 

int servoPosition; // Where to move the servo to.

/**
 * Called when something happens on the websocket.
 */
void webSocketEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t lenght) {

    switch(type) {
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
        case WStype_TEXT:
            Serial.printf("[%u] get Text: %s\n", num, payload);

            if (payload[0] == '#') {
                // we get RGB data

                // decode rgb data
                uint32_t rgb = (uint32_t) strtol((const char *) &payload[1], NULL, 16);

                analogWrite(ledRed,    ((rgb >> 16) & 0xFF));
                analogWrite(ledGreen,  ((rgb >> 8) & 0xFF));
                analogWrite(ledBlue,   ((rgb >> 0) & 0xFF));

                // Move the servo to according to the red value.
                int redVal = (rgb >> 16) & 0xFF;
                servoPosition = map(redVal, 0, 255, 0, 180); // scale it to use it with the servo (value between 0 and 180)
                myservo.write(servoPosition);             // sets the servo position according to the scaled value

            }

            break;
    }

}

void setup() {
    Serial.begin(115200);
    myservo.attach(12);  // attaches the servo to the output pin

    Serial.setDebugOutput(true);
    Serial.println();
    Serial.println();
    Serial.println();

    for(uint8_t t = 4; t > 0; t--) {
        Serial.printf("[SETUP] BOOT WAIT %d...\n", t);
        Serial.flush();
        delay(1000);
    }

    digitalWrite(ledRed, 1);
    digitalWrite(ledGreen, 1);
    digitalWrite(ledBlue, 1);

}

void loop() {
    webSocket.loop();
    server.handleClient();
}

