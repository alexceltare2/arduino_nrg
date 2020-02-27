#include<HardwareSerial.h>
STORAGE nvMem;
uint8_t data = 3;

void setup() {
pinMode(LED_GREEN,OUTPUT);
pinMode(LED_RED,OUTPUT);
digitalWrite(LED_GREEN,LOW);
digitalWrite(LED_RED,HIGH);
Serial.begin(9600);
write_data();
digitalWrite(LED_RED,LOW);
digitalWrite(LED_GREEN,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:

}

void write_data(){
  nvMem.write(&data, INFOMEM_SECTION_A, 2, sizeof(data));
  // don't use numerals as they behave unusually, use variables.  
}
