#include <WiFi.h>
#include <MQTT.h>
#include <LCD_I2C.h>

LCD_I2C lcd(0x27, 16, 2);

const char ssid[] = "@JumboPlusIoT";
const char pass[] = "didgusryu";

const char mqtt_broker[]="test.mosquitto.org";
const char mqtt_topic[]="group12/command";

const char mqtt_client_id[]="arduino_group_12"; // must change this string to a unique value

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
  while (!client.connect(mqtt_client_id)) {  
    Serial.print(".");
    delay(1000);
  }

  Serial.println("\nconnected!");

  client.subscribe(mqtt_topic);
  // client.unsubscribe("/hello");
}

void messageReceived(String &topic, String &payload) {
  Serial.println("incoming: " + topic + " - " + payload);
  if(payload=="front"){
    
    Serial.println("forward now");
    digitalWrite(32,HIGH);
    digitalWrite(33,LOW);
    lcd.setCursor(5, 0);
    lcd.print("FORWARD");
    lcd.setCursor(5, 1);
    lcd.print("Group12");
  }
  else if(payload=="back"){
    Serial.println("reverse now");
    digitalWrite(32,LOW);
    digitalWrite(33,HIGH);
    lcd.setCursor(5, 0);
    lcd.print("REVERSE");
    lcd.setCursor(5, 1);
    lcd.print("Group12");
  }else if(payload=="close"){
    Serial.println("close now");
    digitalWrite(32,LOW);
    digitalWrite(33,LOW);
    lcd.setCursor(5, 0);
    lcd.print("CLOSE");
    lcd.setCursor(5, 1);
    lcd.print("Group12");
  }else{
    Serial.println("test");
    digitalWrite(32,HIGH);
    digitalWrite(33,LOW);
  }
 
}

void setup() {
  Serial.begin(9600);
  lcd.begin(); 
  lcd.backlight();
  WiFi.begin(ssid, pass);
  pinMode(32,OUTPUT);
  pinMode(33,OUTPUT);

  // Note: Local domain names (e.g. "Computer.local" on OSX) are not supported
  // by Arduino. You need to set the IP address directly.
  client.begin(mqtt_broker, MQTT_PORT, net);
  client.onMessage(messageReceived);

  connect();
}

void loop() {
  client.loop();
  delay(10);  // <- fixes some issues with WiFi stability

  if (!client.connected()) {
    connect();
  }
  
}
