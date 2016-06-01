/*
 * Servo WebSocketServer
 *
 * Install the library from https://github.com/Links2004/arduinoWebSockets/releases
 */

#include <ESP8266WiFi.h>
#include <WebSocketsServer.h>
#include <ESP8266WebServer.h>
#include <Hash.h>
#include <WiFiClient.h> 
#include <Servo.h>

// Include the file that has the html.
#include "html.h"
// Include the Denbit library.
#include <Denbit.h>
// Initialize the denbit.
Denbit denbit;

/* Set these to your desired credentials. */
const char *ssid = "ESPap";
const char *password = "12345678";

// Assign readable names to the led pin numbers
const int ledRed =  15; 
const int ledGreen =  14; 
const int ledBlue =  10; 

int servoPosition; // Where to move the servo to.

Servo servoA;  // create servo object to control a servo

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
            Serial.printf("[%u]: %s\n", num, payload);

            if (payload[0] == '#') {
                String csv = String((const char *) &payload[1]);
                int commaIndex = csv.indexOf(',');
                //  Search for the next comma just after the first
                int secondCommaIndex = csv.indexOf(',', commaIndex+1);
                String firstValue = csv.substring(0, commaIndex);
                String secondValue = csv.substring(commaIndex+1, secondCommaIndex);
                String thirdValue = csv.substring(secondCommaIndex+1);
//Serial.print(firstValue); Serial.print(","); Serial.print(secondValue); Serial.print(","); Serial.print(thirdValue);
                Serial.printf(" Parsed: %d,%d,%d\n", firstValue.toInt(), secondValue.toInt(), thirdValue.toInt());

                analogWrite(ledRed, abs(firstValue.toInt()));
                analogWrite(ledGreen, abs(secondValue.toInt()));
                analogWrite(ledBlue, abs(thirdValue.toInt()));
              
                // we get RGB data


/*
                // decode rgb data
                uint32_t rgb = (uint32_t) strtol((const char *) &payload[1], NULL, 16);

                analogWrite(ledRed,    ((rgb >> 16) & 0xFF));
                analogWrite(ledGreen,  ((rgb >> 8) & 0xFF));
                analogWrite(ledBlue,   ((rgb >> 0) & 0xFF));
*/
                // Move the servo to according to the red value.
                //int redVal = (rgb >> 16) & 0xFF;
                /*
                int newServoPosition = map(redVal, 0, 255, 0, 180); // scale it to use it with the servo (value between 0 and 180)
                if (newServoPosition > servoPosition) {
                  servoPosition++;
                } else if (newServoPosition < servoPosition) {
                  servoPosition--;
                }
                */
                //servoPosition = map(redVal, 0, 255, 0, 180);
                //servoPosition = redVal;
                //servoA.write(servoPosition);             // sets the servo position according to the scaled value
                //Serial.printf("[%u]: %d\n", num, servoPosition);
                delay(15); // Wait for the servo to move
            }

            break;
    }

}

void setup() {
    Serial.begin(115200);

    servoA.attach(4);

    //Serial.setDebugOutput(true);

    digitalWrite(ledRed, 0);
    digitalWrite(ledGreen, 0);
    digitalWrite(ledBlue, 0);

    Serial.print("Configuring access point...");
    WiFi.softAP(ssid);
    IPAddress myIP = WiFi.softAPIP();
    Serial.print("AP IP address: ");
    Serial.println(myIP);

    // start webSocket server
    webSocket.begin();
    webSocket.onEvent(webSocketEvent);

    // handle index
    server.on("/", []() {
        // send index.html
        server.send(200, "text/html", index_html);
    });

    server.begin();
    Serial.println("HTTP server started");

}

void loop() {
    webSocket.loop();
    server.handleClient();
}

