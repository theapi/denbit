/*
 * Servo WebSocketServer
 *
 * Install the library from https://github.com/Links2004/arduinoWebSockets
 */

#include <Arduino.h>

#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <WebSocketsServer.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <Hash.h>

#include <Servo.h>

// Include the configuration file.
#include "wifi_config.h"
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

int servoPosition; // Where to move the servo to.

Servo servoA;  // create servo object to control a servo

ESP8266WiFiMulti WiFiMulti;

ESP8266WebServer server = ESP8266WebServer(80);
WebSocketsServer webSocket = WebSocketsServer(81);

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

            if(payload[0] == '#') {
                // we get RGB data

                // decode rgb data
                uint32_t rgb = (uint32_t) strtol((const char *) &payload[1], NULL, 16);

                analogWrite(ledRed,    ((rgb >> 16) & 0xFF));
                analogWrite(ledGreen,  ((rgb >> 8) & 0xFF));
                analogWrite(ledBlue,   ((rgb >> 0) & 0xFF));

                // Move the servo to according to the red value.
                int redVal = (rgb >> 16) & 0xFF;
                servoPosition = map(redVal, 0, 255, 0, 180); // scale it to use it with the servo (value between 0 and 180)
                servoA.write(servoPosition);             // sets the servo position according to the scaled value
            }

            break;
    }

}

void setup() {
    Serial.begin(115200);

    Serial.setDebugOutput(true);

    Serial.println();
    Serial.println();
    Serial.println();

    for(uint8_t t = 4; t > 0; t--) {
        Serial.printf("[SETUP] BOOT WAIT %d...\n", t);
        Serial.flush();
        delay(1000);
    }

    digitalWrite(ledRed, 0);
    digitalWrite(ledGreen, 0);
    digitalWrite(ledBlue, 0);

    WiFiMulti.addAP(WIFI_SSID, WIFI_PASS);

    while(WiFiMulti.run() != WL_CONNECTED) {
        delay(100);
    }

    // start webSocket server
    webSocket.begin();
    webSocket.onEvent(webSocketEvent);

    if(MDNS.begin("esp8266")) {
        Serial.println("MDNS responder started");
    }

    // handle index
    server.on("/", []() {
        // send index.html
        server.send(200, "text/html", index_html);
    });

    server.begin();

    // Add service to MDNS
    MDNS.addService("http", "tcp", 80);
    MDNS.addService("ws", "tcp", 81);

    digitalWrite(ledRed, 0);
    digitalWrite(ledGreen, 0);
    digitalWrite(ledBlue, 0);

}

void loop() {
    webSocket.loop();
    server.handleClient();
}

