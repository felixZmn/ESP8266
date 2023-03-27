#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include "rgb.h"

ESP8266WebServer server(80);

const char *ssid = "<<set ssid>>";
const char *password = "<<set wifi password>>";

const byte BLUE = D0;
const byte GREEN = D1;
const byte RED = D2;

bool interrupt = true;
int angle = 0;

void writeColors(RGB rgb) {
  analogWrite(RED, rgb.red);
  analogWrite(GREEN, rgb.green);
  analogWrite(BLUE, rgb.blue);
}

void nextColor() {
  if (!interrupt) {
    RGB colors = HSV(angle);
    writeColors(colors);
    if (angle > 360) {
      angle = 0;
    }
    angle++;
  }
}

void setup() {
  Serial.begin(9600);
  analogWriteRange(255);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  Serial.printf("trying to connect to %s\r\n", ssid);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.printf(".");
  }
  Serial.printf("\nConnected!\n");
  Serial.printf("IP address: %s\n", WiFi.localIP().toString().c_str());

  server.on("/start", HTTP_GET, []() {
    server.send(200, "text/plain", "started\r\n");
    interrupt = false;
    Serial.printf("loop started\n");
  });

  server.on("/stop", HTTP_GET, []() {
    interrupt = true;
    server.send(200, "text/plain", "stopped\n");
    Serial.printf("loop stopped\n");
  });

  server.begin();
  Serial.printf("HTTP server started\n");
}

void loop() {
  server.handleClient();
  nextColor();
  delay(30);
}
