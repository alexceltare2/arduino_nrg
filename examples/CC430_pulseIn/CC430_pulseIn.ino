#include<HardwareSerial.h>

uint8_t pin = IO26;
unsigned long duration;

void setup() {
 Serial.begin(9600);
 pinMode(pin, INPUT);
}

void loop() {
//if (digitalRead(pin)==HIGH){
duration = pulseIn(pin, HIGH,3000);
Serial.print("Duration (us): ");Serial.println(duration);
//delay(500);
//}
}
