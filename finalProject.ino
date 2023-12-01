#define relay1 22 
#define relay2 23
#define PullInput 18 //A
#define ReleaseInput 19 //B

void setup() {
  pinMode(ReleaseInput,INPUT);
  pinMode(PullInput,INPUT);
  pinMode(relay1,OUTPUT);
  pinMode(relay2,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if(digitalRead(ReleaseInput)==HIGH) {
    Serial.println("RELEASE");
    digitalWrite(relay1, HIGH);
    digitalWrite(relay2, LOW);
    delay(1000);
    digitalWrite(relay1, LOW);    
  }

  else if(digitalRead(PullInput)==HIGH) {
    Serial.println("ROLLUP");
    digitalWrite(relay1, LOW);
    digitalWrite(relay2, HIGH);
    delay(1000);
    digitalWrite(relay2, LOW);
  }
  digitalWrite(relay1, LOW);
  digitalWrite(relay2, LOW);
}
