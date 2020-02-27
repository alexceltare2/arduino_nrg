/*
 * This example retreives the device UID and shortUID or Device Descriptor.
 */
#include<HardwareSerial.h>
uint8_t uid[8];
uint8_t id_rf[2];
uint8_t dev_addr = 0;

STORAGE nvMem;      // EEPROM object
void setup() {
  
  Serial.begin(9600);
  
  Serial.print("MSP430 Long UID: ");
  panstamp.core.getUID(uid); //pass the UID to uid variable
  PrintHex8(uid,8);
  //display_uid_as_address();
  //display_uid_as_tlv();
  display_uid_as_api();
}

void loop() {

}

void PrintHex8(uint8_t *data, uint8_t length) // prints 8-bit data in hex with leading zeroes
{    
     char tmp[16];
      for (int i=0; i<length; i++) { 
         sprintf(tmp, "%.2X",data[i]); 
         Serial.print(tmp); Serial.print(" ");
       }
       Serial.println("");
}
void display_uid_as_api(){
  Serial.print("MSP 430 Short UID: ");// Last byte of Long UID
  Serial.println(panstamp.core.getShortUID());

  Serial.print("CC1101 PartNo + Ver: ");
  id_rf[0] = ReadSingleReg(PARTNUM);
  id_rf[1] = ReadSingleReg(VERSION);
  PrintHex8(id_rf,2);
}

void display_uid_as_adress(){
   Serial.print("UID via Address: ");
   nvMem.read(&dev_addr, 0x1A0A, 3, sizeof(dev_addr));
   Serial.print(dev_addr,HEX);Serial.print(" ");
   nvMem.read(&dev_addr, 0x1A0A, 2, sizeof(dev_addr));
   Serial.print(dev_addr,HEX);Serial.print(" ");
   nvMem.read(&dev_addr, 0x1A0A, 1, sizeof(dev_addr));
   Serial.print(dev_addr,HEX);Serial.print(" ");
   nvMem.read(&dev_addr, 0x1A0A, 0, sizeof(dev_addr));
   Serial.print(dev_addr,HEX);Serial.print(" ");
   nvMem.read(&dev_addr, 0x1A0A, 7, sizeof(dev_addr));
   Serial.print(dev_addr,HEX);Serial.print(" ");
   nvMem.read(&dev_addr, 0x1A0A, 6, sizeof(dev_addr));
   Serial.print(dev_addr,HEX);Serial.print(" ");
   nvMem.read(&dev_addr, 0x1A0A, 5, sizeof(dev_addr));
   Serial.print(dev_addr,HEX);Serial.print(" ");
   nvMem.read(&dev_addr, 0x1A0A, 4, sizeof(dev_addr));
   Serial.print(dev_addr,HEX);Serial.println("");
}

void display_uid_as_tlv(){
   Serial.print("UID via TLV: ");
   nvMem.read(&dev_addr, TLV_START, TLV_BLANK, sizeof(dev_addr)); //always 47
   Serial.print(dev_addr,HEX);Serial.print(" ");
   nvMem.read(&dev_addr, TLV_START, TLV_Reserved4, sizeof(dev_addr));
   Serial.print(dev_addr,HEX);Serial.print(" ");
   nvMem.read(&dev_addr, TLV_START, TLV_Reserved3, sizeof(dev_addr));
   Serial.print(dev_addr,HEX);Serial.print(" ");
   nvMem.read(&dev_addr, TLV_START, TLV_PDTAG, sizeof(dev_addr));
   Serial.print(dev_addr,HEX);Serial.print(" ");
   nvMem.read(&dev_addr, TLV_START, 0x09, sizeof(dev_addr));//always 0
   Serial.print(dev_addr,HEX);Serial.print(" ");
   nvMem.read(&dev_addr, TLV_START, TLV_DIERECORD, sizeof(dev_addr));
   Serial.print(dev_addr,HEX);Serial.print(" ");
   nvMem.read(&dev_addr, TLV_START, TLV_Reserved7, sizeof(dev_addr));//always 0
   Serial.print(dev_addr,HEX);Serial.print(" ");
   nvMem.read(&dev_addr, TLV_START, TLV_Reserved6, sizeof(dev_addr));
   Serial.print(dev_addr,HEX);Serial.println("");
}
