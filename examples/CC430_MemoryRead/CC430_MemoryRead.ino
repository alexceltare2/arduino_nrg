#include<HardwareSerial.h>
#define MEMORY_LOCATION 0x1A0A
STORAGE nvMem;
uint8_t memb;
int i;

void setup() {
  Serial.begin(9600);
  Serial.print("Reading from memory location+7: 0x");Serial.println(MEMORY_LOCATION,HEX);
  for (i=0;i<=7;i++){
  nvMem.read(&memb, MEMORY_LOCATION, i, sizeof(memb));
  Serial.print(memb,HEX);Serial.print(" ");;
  }
  Serial.println("");

}

void loop() {
  

}
