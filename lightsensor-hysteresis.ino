#define LDR 35
#define LED 22
int LDR_Value=0;
int ON_Threshhold = 1600;
int OFF_Threshhold = 1400;

void setup() {
  Serial.begin(9600);
  pinMode(LED,OUTPUT);
}

void loop() {
  LDR_Value = analogRead(LDR);

  Serial.print("Variable_1:");
  Serial.print(LDR_Value);
  Serial.print(",");
  Serial.print("ON_Threshhold:");
  Serial.println(ON_Threshhold);
  Serial.print("OFF_Threshhold:");
  Serial.println(OFF_Threshhold);
  if(LDR_Value>ON_Threshhold) digitalWrite(LED,HIGH);
  else if(LDR_Value<OFF_Threshhold) digitalWrite(LED,LOW);

  delay(20);
}
