#include<HardwareSerial.h>
STORAGE nvMem;
uint8_t hdd;
uint8_t uid[8];
int i;

void setup() {
Serial.begin(9600);
show_data();
}

void loop() {

}

void show_data(){
Serial.print("The D bank section is: ");
  for (i=0;i<=127;i++){
  nvMem.read(&hdd, INFOMEM_SECTION_D, i, sizeof(hdd));
  PrintHex8(&hdd,1);
  }
Serial.println("");

Serial.print("The C bank section is: ");
  for (i=0;i<=127;i++){
  nvMem.read(&hdd, INFOMEM_SECTION_C, i, sizeof(hdd));
  PrintHex8(&hdd,1);
  }
Serial.println("");

Serial.print("The B bank section is: ");
  for (i=0;i<=127;i++){
  nvMem.read(&hdd, INFOMEM_SECTION_B, i, sizeof(hdd));
  PrintHex8(&hdd,1);
  }
Serial.println("");

Serial.print("The A bank section is: ");
  for (i=0;i<=127;i++){
  nvMem.read(&hdd, INFOMEM_SECTION_A, i, sizeof(hdd));
  PrintHex8(&hdd,1);
  }
Serial.println("");

Serial.print("Long UID: ");
  panstamp.core.getUID(uid); //pass the UID to uid variable
  PrintHex8(uid,8);
Serial.println("");

Serial.print("Short UID: ");
  Serial.print(panstamp.core.getShortUID());Serial.print(" = ");Serial.print(panstamp.core.getShortUID(),HEX);

}




void PrintHex8(uint8_t *data, uint8_t length) // prints 8-bit data in hex with leading zeroes
{    
     char tmp[16];
       for (int i=0; i<length; i++) { 
         sprintf(tmp, "%.2X",data[i]); 
         Serial.print(tmp); Serial.print(" ");
       }
       //Serial.println("");
}

void PrintHex16(uint16_t *data, uint8_t length) // prints 16-bit data in hex with leading zeroes
{
       char tmp[16];
       for (int i=0; i<length; i++)
       { 
         sprintf(tmp, "0x%.4X",data[i]); 
         Serial.print(tmp); Serial.print(" ");
       }
}
