#define CLKWISE 22 //pin 2
#define COUNTERCLKWISE 23 //pin 7
#define BUTTON  14
bool dir;
bool Enabled = true;
void setup() {
  pinMode(BUTTON, INPUT); 
  pinMode(CLKWISE, OUTPUT);
  pinMode(COUNTERCLKWISE, OUTPUT);
}

void loop() {
  if(digitalRead(BUTTON)==LOW){
    Enabled = !Enabled;
    while(digitalRead(BUTTON)==LOW){}
  }
  if(Enabled){
    if(dir){
      digitalWrite(CLKWISE, HIGH);
      digitalWrite(COUNTERCLKWISE, LOW);
    }else{
      digitalWrite(CLKWISE, LOW);
      digitalWrite(COUNTERCLKWISE, HIGH);    
    }
    delay(5000);
    dir = !dir;    
  }

}