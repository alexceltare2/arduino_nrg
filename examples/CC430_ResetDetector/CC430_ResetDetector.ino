/*
 * A simple example program to detect the last cause of reset. It reads register SYSRSTIV
 * and then it clears it. Refer to the TI's User manual on 1.15.10 for information on 
 * the last reset cause. The most likely causes you can encounter are: Brownout/Complete
 * power-off (02), Reset via pin/NMI/RST (04), Partial power-off/SVSL (0C), Low supply/ 
 * battery/SVSH (0E), Reset via panstamp/WDT code (18)
 */
#include<HardwareSerial.h>

const uint8_t ledPin = LED_RED;
const uint8_t buttonPin = BUTTON;
uint8_t sys_reset;
STORAGE nvMem;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  attachInterrupt(buttonPin, Reset_ISR, FALLING); //Reset by button ISR test.

  //Use this code for LED output
  nvMem.read(&sys_reset, SYSRSTIV_, 0, sizeof(sys_reset)); //Low Byte
  for (int i = 1; i <= sys_reset; i++){
  digitalWrite(ledPin, HIGH); //An LED indicator to show that the board reset itself.
  delay(500);
  digitalWrite(ledPin, LOW);
  delay(500);
  }
  /*
   //Use this code for serial output
   Serial.begin(9600);  
   Serial.print("Last reset cause (ID): ");
   nvMem.read(&sys_reset, SYSRSTIV_, 0, sizeof(sys_reset)); //Low Byte
   if(sys_reset<=15){Serial.print("0");}Serial.print(sys_reset,HEX);Serial.println(" ");
   Serial.print("Clearning... ");
   sys_reset = 0;
   nvMem.write(&sys_reset, SYSRSTIV_, 0, sizeof(sys_reset)); //Low Byte
   Serial.print("Last reset cause (ID): ");
   nvMem.read(&sys_reset, SYSRSTIV_, 0, sizeof(sys_reset)); //Low Byte
   if(sys_reset<=15){Serial.print("0");}Serial.print(sys_reset,HEX);Serial.println(" ");
   Serial.end();  
   */
}

void loop() {
  panstamp.sleep();
}

void Reset_ISR() {
 panstamp.reset();
}
