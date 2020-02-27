/*
*Welcome to the CC430 Serial Monitor program. To make the program display your results
*on the serial monitor you need to ground DTR when you've oppened the Serial Monitor
*applet. Ground the RTS pin to reset the MCU (applies to the WCH CH430 UART families).
*/

#include <HardwareSerial.h>

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("Hello World");
}
