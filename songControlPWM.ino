#define LED 21
hw_timer_t *My_timer = NULL;

// This is the Timer ISR. It is automatically called 
// on a timer alarm event.
void IRAM_ATTR onTimer(){
  digitalWrite(LED, !digitalRead(LED));
}

void setup() {
  pinMode(LED, OUTPUT);
  My_timer = timerBegin(0, 80, true);  // use tiemr 0 and set prescale to 80 so 1 tick is 1 uSec
  timerAttachInterrupt(My_timer, &onTimer, true); // point to the ISR
  timerAlarmWrite(My_timer, 1000000, true);  // set alarm every 1 sec
  timerAlarmEnable(My_timer);  // enable the alarm
}

void loop() {
  timerAlarmWrite(My_timer, 379, true);//E
  delay(500);
  timerAlarmWrite(My_timer, 1000000, true);
  delay(50);
  timerAlarmWrite(My_timer, 379, true); //E
  delay(500);
  timerAlarmWrite(My_timer, 1000000, true);
  delay(50);
  timerAlarmWrite(My_timer, 379, true); //E
  delay(1000);
  timerAlarmWrite(My_timer, 1000000, true);
  delay(50);
  timerAlarmWrite(My_timer, 379, true); //E
  delay(500);
  timerAlarmWrite(My_timer, 1000000, true);
  delay(50);
  timerAlarmWrite(My_timer, 379, true); //E
  delay(500);
  timerAlarmWrite(My_timer, 1000000, true);
  delay(50);
  timerAlarmWrite(My_timer, 379, true); //E
  delay(1000);
  timerAlarmWrite(My_timer, 1000000, true);
  delay(50);
  timerAlarmWrite(My_timer, 379, true); //E
  delay(500);
  timerAlarmWrite(My_timer, 318, true); //G
  delay(500);
  timerAlarmWrite(My_timer, 477, true); //C
  delay(500);
  timerAlarmWrite(My_timer, 425, true); //D
  delay(500);
  timerAlarmWrite(My_timer, 379, true); //E
  delay(1500);
  timerAlarmWrite(My_timer, 357, true); //F
  delay(500);
  timerAlarmWrite(My_timer, 1000000, true);
  delay(50);
  timerAlarmWrite(My_timer, 357, true); //F
  delay(500);
  timerAlarmWrite(My_timer, 1000000, true);
  delay(50);
  timerAlarmWrite(My_timer, 357, true); //F
  delay(500);
  timerAlarmWrite(My_timer, 1000000, true);
  delay(50);
  timerAlarmWrite(My_timer, 357, true); //F
  delay(500);
  timerAlarmWrite(My_timer, 1000000, true);
  delay(50);
  timerAlarmWrite(My_timer, 357, true); //F
  delay(500);
  timerAlarmWrite(My_timer, 379, true); //E
  delay(500);
  timerAlarmWrite(My_timer, 1000000, true);
  delay(50);
  timerAlarmWrite(My_timer, 379, true); //E
  delay(500);
  timerAlarmWrite(My_timer, 1000000, true);
  delay(50);
  timerAlarmWrite(My_timer, 379, true); //E
  delay(250);
  timerAlarmWrite(My_timer, 1000000, true);
  delay(50);
  timerAlarmWrite(My_timer, 379, true); //E
  delay(500);
  timerAlarmWrite(My_timer, 318, true); //G
  delay(500);
  timerAlarmWrite(My_timer, 1000000, true);
  delay(50);
  timerAlarmWrite(My_timer, 318, true); //G
  delay(500);
  timerAlarmWrite(My_timer, 357, true); //F
  delay(500);
  timerAlarmWrite(My_timer, 425, true); //D
  delay(500);
  timerAlarmWrite(My_timer, 477, true); //C
  delay(1500);

}
