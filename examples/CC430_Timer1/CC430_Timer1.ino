/*
 * Program to use the integrated timer Timer1A0 to generate 1 second
 * delay for LED swiching.
 */
#include <timer1a0.h>
const uint8_t ledPin = LED_RED;

void setup() {
  pinMode(ledPin, OUTPUT);
  timer1a0.attachInterrupt(isrTimer);
  attachInterrupt(BUTTON, myISR, CHANGE);
  timer1a0.start(1000); //Launch the ISR timer every 1 sec, max 2 sec.
}

void loop() {

}

//call the ISR timer ever 1 sec
void isrTimer (){
  digitalWrite(ledPin, !digitalRead(ledPin));
}

void myISR(){
if (digitalRead(BUTTON)==LOW){
TA1CTL |= TACLR; //reset timer to 0;
}
}
