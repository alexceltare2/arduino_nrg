/*
 * Test to see if CC430 wakes up during sleepSec.
 * Result: success
 */
void setup() {
  pinMode(BUTTON, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
  attachInterrupt(BUTTON, myISR, CHANGE);
  
}

void loop() {
  digitalWrite(LED, HIGH);
  delay(300);
  digitalWrite(LED, LOW);
  panstamp.sleepSec(5);
}

void myISR(){
  
}
