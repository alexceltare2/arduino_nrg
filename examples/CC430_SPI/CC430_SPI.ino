#include<cc430spi.h>
CC430SPI ccSPI;
uint16_t length;
uint8_t my_data;

void setup() {
  ccSPI.begin();
  ccSPI.transfer(&my_data, length);

}

void loop() {

}
