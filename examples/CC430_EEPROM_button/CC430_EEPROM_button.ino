// State machine with LED showing if state is 1 or 0 from EEPROM (permanent memory).

//#include <EEPROM.h>

STORAGE nvMem;
uint8_t val;
uint8_t state;
const uint8_t ledPin = LED; //LED_BUILTIN
const uint8_t buttonPin = BUTTON; //BUTTON PIN
bool buttonState = 1; // Initial button state


void setup() {
   pinMode(buttonPin, INPUT_PULLUP);
   pinMode(ledPin, OUTPUT);
}

void loop() {
int button = digitalRead(buttonPin);
nvMem.read(&state, INFOMEM_SECTION_D, 0, sizeof(state));
    if (button && !buttonState){
      if (state == 0){val=1;nvMem.write(&val, INFOMEM_SECTION_D, 0, sizeof(val));}
      if (state == 1){val=0;nvMem.write(&val, INFOMEM_SECTION_D, 0, sizeof(val));}
        delay(10);
    }
    buttonState = button;

   if (state == 0){
      digitalWrite(ledPin,LOW);}
   if (state == 1){
      digitalWrite(ledPin, HIGH);}
}
