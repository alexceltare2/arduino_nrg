/*
 * CC430 Interrupt example where the LED pin is lit up by the buttom interrupt
 * changing states.The MCU is asleep (Low Power) while this action occurs.
 */

const uint8_t ledPin = LED_RED;
const uint8_t buttonPin = BUTTON;

void myISR()
{ 
 digitalWrite(ledPin, !digitalRead(ledPin));
}

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  attachInterrupt(buttonPin, myISR, RISING);  

}

void loop() {
  panstamp.sleep();
}
