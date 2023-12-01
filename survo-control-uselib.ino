#include <ESP32Servo.h>
#define input 14
#define led 16
Servo myservo;
// Recommended PWM GPIO pins on the ESP32 include 2,4,12-19,21-23,25-27,32-33
int servoPin = 18;
int pos = 0;

void IRAM_ATTR IO_INT_ISR()
{
  // Toggle The LED
  digitalWrite(led, !digitalRead(led));
}

void setup() {
  myservo.attach(servoPin);
  pinMode(input,INPUT);
  pinMode(led,OUTPUT);
  attachInterrupt(input, IO_INT_ISR, RISING); // interrupt on rising edge
}
void loop() {

  if(digitalRead(input)==LOW){
    for (pos = 0; pos <= 90; pos += 1) {
      myservo.write(pos);
      delay(15);
    }
    for (pos = 90; pos >= 0; pos -= 1) {
      myservo.write(pos);
      delay(15);
    } 

    while(digitalRead(input)==LOW){}
  }
 
}