
const uint8_t ledPin = LED_RED;
int i;

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(ledPin, OUTPUT);
}

void loop() {
  digitalWrite(ledPin, HIGH);// 1 sec standard
  delay(1000); 
  digitalWrite(ledPin, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);
  
 for (i = 1;i <= 200; i++){// 1 sec PWM 
  digitalWrite(ledPin, HIGH);   // turn the LED on (HIGH is the voltage level)
  delayMicroseconds(250);                     // wait for a second
  digitalWrite(ledPin, LOW);
  delayMicroseconds(9750); 
 }
  digitalWrite(ledPin, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}
