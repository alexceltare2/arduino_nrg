#include<cc430i2c.h>
CC430I2C ccI2C;
const uint8_t buffer=0;
uint16_t length=0;
int write_res, read_res;

void setup() {
  ccI2C.begin();
  ccI2C.beginTransmission(0xFFFF); //Slave address
  write_res = ccI2C.write(buffer, length, true);
  read_res = ccI2C.read(buffer, length, true);

}

void loop() {
  

}
