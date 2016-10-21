
/**
 * Create a WiFi access point and provide a web server on it. 
 */

#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>

// Include the Denbit library.
#include <Denbit.h>
// Initialize the denbit.
Denbit denbit;

// Assign readable names to the led pin numbers
const int ledRgbRed   =  15; 
const int ledRgbGreen =  14; 
const int ledRgbBlue  =  10; 

/* Set these to your desired credentials. */
const char *ssid = "ESPap";
const char *password = "12345678";

ESP8266WebServer server(80);

/* Just a little test message.  Go to http://192.168.4.1 in a web browser
 * connected to this access point to see it.
 */
void handleRoot() {
	server.send(200, "text/html", "<h1>You are connected</h1>");
}

void handleLed() {
  if (digitalRead(ledRgbGreen)) {
    digitalWrite(ledRgbRed, LOW); 
    digitalWrite(ledRgbGreen, LOW); 
    digitalWrite(ledRgbBlue, LOW); 
    server.send(200, "text/html", "<h1>LED OFF</h1><h2><a href=\"/led\">reload</a></h2>");
  } else {
    digitalWrite(ledRgbRed, HIGH); 
    digitalWrite(ledRgbGreen, HIGH); 
    digitalWrite(ledRgbBlue, HIGH); 
    server.send(200, "text/html", "<h1>LED ON</h1><h2><a href=\"/led\">reload</a></h2>");
  }
  
}

void setup() {
  
	Serial.begin(115200);
	Serial.println();
	Serial.print("Configuring access point...");
	/* You can remove the password parameter if you want the AP to be open. */
	//WiFi.softAP(ssid, password);
  WiFi.softAP(ssid);

	IPAddress myIP = WiFi.softAPIP();
 
	Serial.print("AP IP address: ");
	Serial.println(myIP);
	server.on("/", handleRoot);
  server.on("/led", handleLed);
	server.begin();
 
	Serial.println("HTTP server started");
  
}

void loop() {
	server.handleClient();
}
