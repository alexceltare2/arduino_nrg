const uint8_t ledPin = LED_RED;
const uint8_t buttonPin = BUTTON;
bool buttonState = 1; // Initial button state
bool state;
bool mem;

void setup() {
 pinMode(ledPin, OUTPUT);
 pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  
state_button();

}



void state_button(){
  state = mem;
  if (digitalRead(buttonPin) && !buttonState){
      if (state == 0){mem = 1;}
      if (state == 1){mem = 0;}
      delay (10); //debounce
  }
  buttonState = digitalRead(buttonPin);

   if (state == 0){
      digitalWrite(LED,LOW);}
   if (state == 1){
      digitalWrite(LED, HIGH);}
}

void standard_button(){
    if (digitalRead(buttonPin) == LOW){
    digitalWrite(ledPin, HIGH);
  }
  else {
    digitalWrite(ledPin, LOW);
  }
}
