#include <WiFi.h>
#include <MQTT.h>

const char ssid[] = "Galaxy A239587";
const char pass[] = "123456789";

const char mqtt_broker[]="test.mosquitto.org";
const char mqtt_topic[]="group12/command";
int MQTT_PORT=1883;

int counter=0;

WiFiClient net;
MQTTClient client;

unsigned long lastMillis = 0;

void connect() {
  Serial.print("checking wifi...");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }

  Serial.print("\nconnecting...");
  while (!client.connect("arduino_group_12")) {  // connection ID should be unique
    Serial.print(".");
    delay(1000);
  }

  Serial.println("\nconnected!");

  client.subscribe(mqtt_topic);
  // client.unsubscribe("/hello");
}

void messageReceived(String &topic, String &payload) {
  Serial.println("incoming: " + topic + " - " + payload);
  if(payload=="On"){
    Serial.println("turn on");
    digitalWrite(14,HIGH);
  }
  else if(payload=="Off"){
    Serial.println("turn off");
    digitalWrite(14,LOW);
  } 
}

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, pass);
  client.begin(mqtt_broker, MQTT_PORT, net);
  client.onMessage(messageReceived);

  connect();
}

void loop() {
  client.loop();
  delay(10);  //this fixes some issues with WiFi stability

  if (!client.connected()) {
    connect();
  }

}
