/*
 * This example shows how to read the Internal Voltage of 
 * the MCU. Absolute supply voltage range is between 1.8V 
 * and 3.6V. Comment out the analog source you don't want
 * to use.
 */
#include<HardwareSerial.h>
void setup() {
  
//  pinMode(PIN_dc_vib1,OUTPUT);//power vib.1 pad
//  pinMode(PIN_V1_onoff,OUTPUT); //Turn on VIB1
//  pinMode(PIN_V1_ret_GND, OUTPUT); //enable short/open circuit check VIB1
//  pinMode(PIN_check_vib1, OUTPUT); //enable plug check VIB1
//  digitalWrite(PIN_dc_vib1, LOW);
//  digitalWrite(PIN_V1_onoff,HIGH); //HIGH=off
//  digitalWrite(PIN_check_vib1, LOW);
//  digitalWrite(PIN_V1_ret_GND,LOW); 
Serial.begin(9600);
}

void loop() {
  Serial.print("Internal MCU Voltage: ");

 //A11 voltage check
//  int volt = panstamp.getVcc();
//  int v = volt/1000;
//  int dec = volt%1000;
//  Serial.print(v);Serial.print(".");Serial.print(dec);Serial.println(" V");

 //A12 voltage check
  int volt2 = analogRead(A12);
  int v2 = volt2/1000;
  int dec2 = volt2%1000;
  Serial.print(v2);Serial.print(".");Serial.print(dec2);Serial.println(" V");
  
  delay(500);

}
