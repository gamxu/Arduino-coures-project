#include <WiFi.h>

// Set to your network SSID/Password
const char ssid[] = "Galaxy A239587";
const char pass[] = "123456789";

WiFiClient net;  // creat the wifi object

void connect() {
  Serial.print("checking wifi...");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }

  Serial.println("\nwifi connected!");
}

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, pass);

  connect();
}

void loop() {
// Your main code goes here
}