#define input 14
// the number of the LED pin
const int ledPin = 16;  // 16 corresponds to GPIO16

// setting PWM properties
const int freq = 1000;
const int ledChannel = 0;
const int resolution = 8;
int level = 0;
 
void setup(){
  // attach the channel to the GPIO to be controlled
  ledcAttachPin(ledPin, ledChannel);

  // configure LED PWM functionalitites
  ledcSetup(ledChannel, freq, resolution);

  pinMode(input, INPUT);
}
 
void loop(){

  if(digitalRead(input)==LOW){
    if(level==0){
      ledcWrite(ledChannel, 0);
    }else if(level==1){
      ledcWrite(ledChannel, 52);
    }else if(level==2){
      ledcWrite(ledChannel, 103);
    }else if(level==3){
      ledcWrite(ledChannel, 154);
    }else if(level==4){
      ledcWrite(ledChannel, 205);
    }
    level++;
    if(level==5) level=0;
    while(digitalRead(input)==LOW){}
  }

}