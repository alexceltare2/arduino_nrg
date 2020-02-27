/*
 * Program to use the integrated timer Timer1A0 to generate 1 second
 * delay for LED swiching.
 */
#include <timer0a5.h>
const uint8_t ledPin = LED_RED;
const uint8_t buttonPin = BUTTON;
int i;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  //timer0a5.attachInterrupt(isrTimer);
  timer0a5.start(1000); //Launch the ISR timer every 1 sec, max 2 sec.
}

void loop() {
if (timer0a5.overflow() == true){
  digitalWrite(ledPin, HIGH);
  delay(200);
  digitalWrite(ledPin, LOW);
} else {
  digitalWrite(ledPin, LOW);
}
}

//call the ISR timer ever 1 sec
void isrTimer (){
  digitalWrite(ledPin, !digitalRead(ledPin));
}
