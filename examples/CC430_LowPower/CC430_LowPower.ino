/*
 * Low-power example. Check it more on:
 * https://github.com/panStamp/panstamp/wiki/Low-power-mode
 * http://www.argenox.com/library/msp430/msp430-interrupts-and-low-power-chapter-7/
 * The following instructions can be used for separately disabling Radio and Core.
 * panstamp.radio.setPowerDownState();
 * panstamp.core.setLowPowerMode(true);
 * panstamp.core.setNormalMode();
 * panstamp.radio.wakeUp();
 * panstamp.radio.setRxState();
 * panstamp.sleep();
 * panstamp.wakeUp();
 */

const uint8_t ledPin = LED_RED1;
                       //23;
const uint8_t buttonPin = BUTTON_LEARN;
                          //4;

void setup() {//17 OUT, 5 IN, 2 IN-PUL = 24GPIO (3 port x 8 bits)
  pinMode(BUTTON_LEARN,INPUT_PULLUP);
  pinMode(BUTTON_TEST,INPUT_PULLUP);
pinMode(LED_GREEN, OUTPUT);
pinMode(LED_YELLOW, OUTPUT);
pinMode(LED_RED2, OUTPUT);
pinMode(LED_RED1, OUTPUT);
  pinMode(PIN_dc_vib1, OUTPUT);
  pinMode(PIN_V1_onoff,OUTPUT); //Turn on VIB1
  pinMode(PIN_V2_onoff,OUTPUT); //Turn on VIB2
  pinMode(PIN_V1_ret, INPUT); //check short/open VIB1
  pinMode(PIN_V2_ret, INPUT); //check short/open VIB2
  pinMode(PIN_V1_ret_GND, OUTPUT); //enable short/open circuit check VIB1
  pinMode(PIN_V2_ret_GND, OUTPUT); //enable short/open circuit check VIB2
  pinMode(PIN_VIB_2,OUTPUT); //UNKNOWN VIB2
  pinMode(PIN_Flash_LED_2,OUTPUT); //UNKNOWN VIB2
  pinMode(PIN_ADC2, INPUT); //check plug VIB1
  pinMode(PIN_ADC3, INPUT); //check plug VIB2
  pinMode(PIN_check_vib1, OUTPUT); //enable plug check VIB1
  pinMode(PIN_check_vib2, OUTPUT); //enable plug check VIB2
  pinMode(PIN_BAT_VAU, OUTPUT); //enable battery voltage check
  pinMode(PIN_BAT_VAU_GND, INPUT); //check battery voltage
pinMode(PIN_Flash_LED_1, OUTPUT); //LED Switch (not stable, better use dc_str1)
pinMode(PIN_dc_str1, OUTPUT); //LED power
  pinMode(PIN_ac_power_onoff, OUTPUT); //unused
//  pinMode(PIN_AC_power, INPUT); //same as Flash_LED_2

//17 pins
digitalWrite(LED_GREEN, LOW);
digitalWrite(LED_YELLOW, LOW);
digitalWrite(LED_RED2, LOW);
digitalWrite(LED_RED1, LOW);
  digitalWrite(PIN_dc_vib1,LOW); //VIB1 & 2 are powered
  digitalWrite(PIN_V1_onoff,LOW); //HIGH=off
  digitalWrite(PIN_V2_onoff,LOW); //HIGH=off
  digitalWrite(PIN_VIB_2,LOW);  //VIB2 UNKNOWN/circuit breaker=must be on
  digitalWrite(PIN_Flash_LED_2,LOW); //VIB2 UNKNOWN/circuit breaker=must be on
  digitalWrite(PIN_check_vib1, LOW);
  digitalWrite(PIN_check_vib2, LOW);
  digitalWrite(PIN_V1_ret_GND,LOW); 
  digitalWrite(PIN_V2_ret_GND,LOW);
digitalWrite(PIN_Flash_LED_1, LOW);
digitalWrite(PIN_dc_str1, LOW); //off
digitalWrite(PIN_BAT_VAU, LOW); //battery check
digitalWrite(PIN_ac_power_onoff, LOW);
digitalWrite(buttonPin, HIGH);

  attachInterrupt(buttonPin, myISR, FALLING);

}

void loop() {
  panstamp.sleep();
}

void myISR(){
if (digitalRead(buttonPin)==LOW){
digitalWrite(ledPin,HIGH);
panstamp.sleepSec(1);
digitalWrite(ledPin,LOW);
} else {
  digitalWrite(ledPin,LOW);
}
}
